#ifndef CONFIG_H
#define CONFIG_H

#cmakedefine PREFIXDIR "@PREFIXDIR@"
#cmakedefine DATADIR "@DATADIR@"
#cmakedefine PKGDATADIR "@PKGDATADIR@"
#cmakedefine LOCALE_DIR "@LOCALE_DIR@"
#cmakedefine VERSION "@VERSION@"
#cmakedefine BUILDDIR "@BUILDDIR@"
#cmakedefine TESTVALADIR "@TESTVALADIR@"
#cmakedefine TESTDATADIR "@TESTDIRDIR@"
#cmakedefine GETTEXT_PACKAGE "@GETTEXT_PACKAGE@"
#cmakedefine LENSES_DIR "@LENSES_DIR@"
#ifndef INDICATORDIR
#cmakedefine INDICATORDIR "@INDICATORDIR@"
#endif
#ifndef INDICATORICONDIR
#cmakedefine INDICATORICONDIR "@INDICATORICONDIR@"
#endif

#endif // CONFIG_H
