#include <gtest/gtest.h>
#include <glib-object.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <memory>
#include <sigc++/signal.h>
#include <sigc++/trackable.h>


#include <UnityCore/Variant.h>
#include <UnityCore/HomeLens.h>

#include "test_utils.h"
#include "mock-lenses.h"

using namespace std;
using namespace unity;
using namespace unity::dash;
using namespace testmocks;

namespace
{

TEST(TestHomeLens, TestConstruction)
{
  HomeLens home_lens_("name", "description", "searchhint");

  EXPECT_EQ(home_lens_.id(), "home.lens");
  EXPECT_EQ(home_lens_.connected, false);
  EXPECT_EQ(home_lens_.search_in_global, false);
  EXPECT_EQ(home_lens_.name, "name");
  EXPECT_EQ(home_lens_.description, "description");
  EXPECT_EQ(home_lens_.search_hint, "searchhint");
}

TEST(TestHomeLens, TestInitiallyEmpty)
{
  HomeLens home_lens_("name", "description", "searchhint");
  DeeModel* results = home_lens_.results()->model();
  DeeModel* categories = home_lens_.categories()->model();;
  DeeModel* filters = home_lens_.filters()->model();;

  EXPECT_EQ(dee_model_get_n_rows(results), 0);
  EXPECT_EQ(dee_model_get_n_rows(categories), 0);
  EXPECT_EQ(dee_model_get_n_rows(filters), 0);

  EXPECT_EQ(home_lens_.count(), 0);
}

TEST(TestHomeLens, TestTwoStaticLenses)
{
  HomeLens home_lens_("name", "description", "searchhint");
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();

  home_lens_.AddLenses(lenses_);

  EXPECT_EQ(home_lens_.count, (size_t) 2);

  /* Test iteration of registered lensess */
  map<string,string> remaining;
  remaining["first.lens"] = "";
  remaining["second.lens"] = "";
  for (auto lens : home_lens_.GetLenses())
  {
    remaining.erase(lens->id());
  }

  EXPECT_EQ(remaining.size(), 0);

  /* Test sorting and GetAtIndex */
  EXPECT_EQ(home_lens_.GetLensAtIndex(0)->id(), "first.lens");
  EXPECT_EQ(home_lens_.GetLensAtIndex(1)->id(), "second.lens");
}

TEST(TestHomeLens, TestCategoryMergingDisplayName)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::DISPLAY_NAME);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  DeeModel* cats = home_lens_.categories()->model();
  DeeModelIter* iter;
  unsigned int cat0_first = 0,
                cat1_first = 1,
                cat_shared = 2,
                cat0_second = 3,
                cat1_second = 4;
  const unsigned int NAME_COLUMN = 0;

  home_lens_.AddLenses(lenses_);

  EXPECT_EQ(dee_model_get_n_rows(cats), 5); // 5 because each lens has 3 cats, but 1 is shared between them

  /* Validate the merged categories */
  iter = dee_model_get_iter_at_row(cats, cat0_first);
  EXPECT_EQ("cat0+first.lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));

  iter = dee_model_get_iter_at_row(cats, cat1_first);
  EXPECT_EQ("cat1+first.lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));

  iter = dee_model_get_iter_at_row(cats, cat_shared);
  EXPECT_EQ("Shared cat", string(dee_model_get_string(cats, iter, NAME_COLUMN)));

  iter = dee_model_get_iter_at_row(cats, cat0_second);
  EXPECT_EQ("cat0+second.lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));

  iter = dee_model_get_iter_at_row(cats, cat1_second);
  EXPECT_EQ("cat1+second.lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));
}

TEST(TestHomeLens, TestCategoryMergingPerLens)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  DeeModel* cats = home_lens_.categories()->model();
  DeeModelIter* iter;
  const unsigned int NAME_COLUMN = 0;

  home_lens_.AddLenses(lenses_);

  EXPECT_EQ(dee_model_get_n_rows(cats), 2); // just two lenses

  /* Validate the merged categories */
  iter = dee_model_get_iter_at_row(cats, 0);
  EXPECT_EQ("First Lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));

  iter = dee_model_get_iter_at_row(cats, 1);
  EXPECT_EQ("Second Lens", string(dee_model_get_string(cats, iter, NAME_COLUMN)));
}

// It's not that we must not support filters. It is just not implemented yet.
// But we actively test against it to make sure we don't end up with broken
// filters in the UI. When/if we land support for filters on the home screen
// this test should obviously be removed
TEST(TestHomeLens, TestIgnoreFilters)
{
  HomeLens home_lens_("name", "description", "searchhint");
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  DeeModel* filters = home_lens_.filters()->model();

  EXPECT_EQ(dee_model_get_n_rows(filters), 0);
}

TEST(TestHomeLens, TestOneSearch)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::DISPLAY_NAME);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  DeeModel* results = home_lens_.results()->model();
  DeeModel* cats = home_lens_.categories()->model();
  DeeModel* filters = home_lens_.filters()->model();
  DeeModelIter* iter;
  unsigned int cat0_first = 0,
                cat1_first = 1,
                cat_shared = 2,
                cat0_second = 3,
                cat1_second = 4;
  const unsigned int URI_COLUMN = 0;
  const unsigned int CAT_COLUMN = 2;

  home_lens_.AddLenses(lenses_);

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });

  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(dee_model_get_n_rows(results), 6); // 3 hits from each lens
  EXPECT_EQ(dee_model_get_n_rows(cats), 5); // 5 because each lens has 3 cats, but 1 is shared between them
  EXPECT_EQ(dee_model_get_n_rows(filters), 0); // We ignore filters deliberately currently

  /* Validate results. In particular that we get the correct merged
   * category offsets assigned */
  iter = dee_model_get_iter_at_row(results, 0);
  EXPECT_EQ(string("uri+a+first.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat0_first, dee_model_get_uint32(results, iter, CAT_COLUMN));

  iter = dee_model_get_iter_at_row(results, 1);
  EXPECT_EQ(string("uri+p+first.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat1_first, dee_model_get_uint32(results, iter, CAT_COLUMN));

  iter = dee_model_get_iter_at_row(results, 2);
  EXPECT_EQ(string("uri+e+first.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat_shared, dee_model_get_uint32(results, iter, CAT_COLUMN));

  iter = dee_model_get_iter_at_row(results, 3);
  EXPECT_EQ(string("uri+a+second.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat0_second, dee_model_get_uint32(results, iter, CAT_COLUMN));

  iter = dee_model_get_iter_at_row(results, 4);
  EXPECT_EQ(string("uri+p+second.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat1_second, dee_model_get_uint32(results, iter, CAT_COLUMN));

  iter = dee_model_get_iter_at_row(results, 5);
  EXPECT_EQ(string("uri+e+second.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ(cat_shared, dee_model_get_uint32(results, iter, CAT_COLUMN));
}

TEST(TestHomeLens, TestOrderingAfterSearch)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  DeeModel* results = home_lens_.results()->model();
  DeeModel* cats = home_lens_.categories()->model();
  DeeModel* filters = home_lens_.filters()->model();
  DeeModelIter* iter;
  unsigned int lens1_cat = 0;
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;
  const unsigned int URI_COLUMN = 0;
  const unsigned int CAT_COLUMN = 2;

  home_lens_.AddLenses(lenses_);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(dee_model_get_n_rows(results), 9); // 3 hits from each lens
  EXPECT_EQ(dee_model_get_n_rows(cats), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(dee_model_get_n_rows(filters), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  /* The home lens includes applications lens which contains exact match, must
   * be first category */
  EXPECT_EQ(order.at(0), apps_lens_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);

  /* The model will not be sorted acording to the categories though. */
  iter = dee_model_get_iter_at_row(results, 0);
  EXPECT_EQ(string("uri+a+first.lens"), string(dee_model_get_string(results, iter, URI_COLUMN)));
  EXPECT_EQ( dee_model_get_uint32(results, iter, CAT_COLUMN), lens1_cat);
}

TEST(TestHomeLens, TestOrderingWithExactAppsMatch)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;

  home_lens_.AddLenses(lenses_);
  Lens::Ptr apps_lens = lenses_->GetLens("applications.lens");

  auto static_lens = dynamic_pointer_cast<MockTestLens>(apps_lens);
  static_lens->SetNumResults(1);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(home_lens_.results()->count(), 7); // 3+3+1 hits
  EXPECT_EQ(home_lens_.categories()->count(), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(home_lens_.filters()->count(), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  /* The home lens includes applications lens and it contains exact match,
   * so must be the first category, even though there are fewer results than
   * in the other categories */
  EXPECT_EQ(order.at(0), apps_lens_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);
}

TEST(TestHomeLens, TestOrderingWithoutExactAppsMatch)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;

  home_lens_.AddLenses(lenses_);
  Lens::Ptr apps_lens = lenses_->GetLens("applications.lens");

  auto static_lens = dynamic_pointer_cast<MockTestLens>(apps_lens);
  static_lens->SetResultsBaseName("noapes");
  static_lens->SetNumResults(1);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(home_lens_.results()->count(), 7); // 3+3+1 hits
  EXPECT_EQ(home_lens_.categories()->count(), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(home_lens_.filters()->count(), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  /* The home lens includes applications lens but it doesn't contain exact
   * match, so can't be the first category */
  EXPECT_NE(order.at(0), apps_lens_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);
}

TEST(TestHomeLens, TestOrderingByNumResults)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  unsigned int lens1_cat = 0;
  unsigned int lens2_cat = 1;
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;

  home_lens_.AddLenses(lenses_);

  Lens::Ptr lens = lenses_->GetLensAtIndex(2);
  auto static_lens = dynamic_pointer_cast<MockTestLens>(lens);
  static_lens->SetResultsBaseName("noapes"); // no exact match in apps lens
  static_lens->SetNumResults(2);

  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(0));
  static_lens->SetNumResults(1);
  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(1));
  static_lens->SetNumResults(3);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /*
   * lens1 -> 1 result
   * lens2 -> 3 results
   * lens3 -> 2 results (apps.lens)
   */

  /* Validate counts */
  EXPECT_EQ(home_lens_.results()->count(), 6); // 1+3+2 hits
  EXPECT_EQ(home_lens_.categories()->count(), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(home_lens_.filters()->count(), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  /* The home lens includes applications lens but it doesn't contain exact
   * match, so can't be the first category */
  EXPECT_EQ(order.at(0), lens2_cat);
  EXPECT_EQ(order.at(1), apps_lens_cat);
  EXPECT_EQ(order.at(2), lens1_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);
}

TEST(TestHomeLens, TestPersonalResultsFirst)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  unsigned int lens1_cat = 0;
  unsigned int lens2_cat = 1;
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;

  home_lens_.AddLenses(lenses_);

  /*
   * lens1 -> 1 result
   * lens2 -> 3 results (no personal content)
   * lens3 -> 2 results (apps.lens)
   */

  Lens::Ptr lens = lenses_->GetLensAtIndex(2);
  auto static_lens = dynamic_pointer_cast<MockTestLens>(lens);
  static_lens->SetResultsBaseName("noapes"); // no exact match in apps lens
  static_lens->SetNumResults(2);

  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(0));
  static_lens->SetNumResults(1);
  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(1));
  static_lens->SetNumResults(3);
  static_lens->SetProvidesPersonalResults(false);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(home_lens_.results()->count(), 6); // 1+3+2 hits
  EXPECT_EQ(home_lens_.categories()->count(), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(home_lens_.filters()->count(), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  /* The home lens includes applications lens but it doesn't contain exact
   * match, so can't be the first category */
  EXPECT_EQ(order.at(0), apps_lens_cat);
  EXPECT_EQ(order.at(1), lens1_cat);
  EXPECT_EQ(order.at(2), lens2_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);
}

TEST(TestHomeLens, TestNonPersonalCategoriesBeforeEmpty)
{
  HomeLens home_lens_("name", "description", "searchhint",
                      HomeLens::MergeMode::OWNER_LENS);
  std::shared_ptr<Lenses> lenses_ = std::make_shared<TwoMockTestLenses>();
  unsigned int lens1_cat = 0;
  unsigned int lens2_cat = 1;
  // the lens is added as third, so must have cat == 2
  unsigned int apps_lens_cat = 2;

  home_lens_.AddLenses(lenses_);

  /*
   * lens1 -> 1 result
   * lens2 -> 3 results (no personal content)
   * lens3 -> 0 results (apps.lens)
   */

  Lens::Ptr lens = lenses_->GetLensAtIndex(2);
  auto static_lens = dynamic_pointer_cast<MockTestLens>(lens);
  static_lens->SetNumResults(0);

  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(0));
  static_lens->SetNumResults(1);
  static_lens = dynamic_pointer_cast<MockTestLens>(lenses_->GetLensAtIndex(1));
  static_lens->SetNumResults(3);
  static_lens->SetProvidesPersonalResults(false);

  bool order_changed = false;
  home_lens_.categories_reordered.connect([&order_changed] ()
  {
    order_changed = true;
  });

  bool finished = false;
  home_lens_.Search("ape", [&finished] (Lens::Hints const&, glib::Error const&)
  {
    finished = true;
  });
  Utils::WaitUntil(finished);

  /* Validate counts */
  EXPECT_EQ(home_lens_.results()->count(), 4); // 1+3 hits
  EXPECT_EQ(home_lens_.categories()->count(), 3); // 3 cats since we are merging categories by lens
  EXPECT_EQ(home_lens_.filters()->count(), 0); // We ignore filters deliberately currently

  /* Validate the category order */
  auto order = home_lens_.GetCategoriesOrder();

  EXPECT_EQ(order.at(0), lens1_cat);
  EXPECT_EQ(order.at(1), lens2_cat);
  EXPECT_EQ(order.at(2), apps_lens_cat);

  /* Plus the categories reordered should have been emitted */
  EXPECT_EQ(order_changed, true);
}

}
