#include "test_service_model.h"

namespace unity
{
namespace service
{

Model::Model()
  : model_(dee_shared_model_new("com.canonical.test.model"))
  , results_model_(dee_shared_model_new("com.canonical.test.resultsmodel"))
  , categories_model_(dee_shared_model_new("com.canonical.test.categoriesmodel"))
{
  PopulateTestModel();
  PopulateResultsModel();
  PopulateCategoriesModel();
}

void Model::PopulateTestModel()
{
  dee_model_set_schema(model_, "u", "s", nullptr);

  for (unsigned i = 0; i < 100; ++i)
    dee_model_append(model_, i, ("Test"+std::to_string(i)).c_str());
}

void Model::PopulateResultsModel()
{
  dee_model_set_schema(results_model_, "s", "s", "u", "u", "s", "s", "s", "s", "a{sv}", nullptr);

  GVariantBuilder b;
  g_variant_builder_init(&b, G_VARIANT_TYPE("a{sv}"));
  GVariant *hints = g_variant_builder_end(&b);

  for(unsigned i = 0; i < 200; ++i)
  {
    auto name = "Result"+std::to_string(i);
    dee_model_append(results_model_,
                     name.c_str(),
                     name.c_str(),
                     (guint)(i/50), // new category every 50 results
                     0,             // result type
                     name.c_str(),
                     name.c_str(),
                     name.c_str(),
                     name.c_str(),
                     hints);
  }
  g_variant_unref(hints);
  hints = NULL;
}

void Model::PopulateCategoriesModel()
{
  dee_model_set_schema(categories_model_, "s", "s", "s", "s", "a{sv}", nullptr);

  GVariantBuilder b;
  g_variant_builder_init(&b, G_VARIANT_TYPE("a{sv}"));
  GVariant *hints = g_variant_builder_end(&b);

  for(unsigned i = 0; i < 5; ++i)
  {
    dee_model_append(categories_model_,
                     ("cat"+std::to_string(i)).c_str(),
                     ("Category "+std::to_string(i)).c_str(),
                     "gtk-apply",
                     "grid",
                     hints);
  }
  g_variant_unref(hints);
}

}
}
