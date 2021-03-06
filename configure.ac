AC_PREREQ(2.61)
AC_INIT([matrixComp], [0.1], [mike@conlen.org])
AC_CONFIG_SRCDIR([src/test.c])
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_HOST
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CXX([g++-mp-4.8 g++])
AC_PROG_CC([gcc-mp-4.8 gcc])
AC_HEADER_STDC

CFLAGS="-std=c99 -O3 -funroll-loops -mfpmath=sse -mbmi2"
CPPFLAGS="$CPPFLAGS"
case $host_os in
	darwin* )
		CFLAGS="$CFLAGS -I/opt/local/include"
		CXXFLAGS="$CXXFLAGS -I/opt/local/include"
		LDFLAGS="$LDFLAGS -L/opt/local/lib"
		;;
	linux*)
		CFLAGS="-march=native $CFLAGS"
		# Do something specific for linux
		;;
	*BSD*)
		# Do something specific for BSD
		;;
	*)
		#Default Case
		AC_MSG_ERROR([Your platform is not currently supported])
		;;
esac

CXXFLAGS="$CXXFLAGS --std=c++0x"
LDFLAGS="$LDFLAGS"
AC_SEARCH_LIBS([CU_initialize_registry], [cunit], [
	AC_CHECK_HEADERS([CUnit/CUnit.h], [], [
		echo "CUnit.h not found"; exit -1;
	])

], [
	echo "libcunit not found"; exit -1
])

AC_SEARCH_LIBS([clock_getres clock_gettime clock_settime], [rt])
AC_SEARCH_LIBS([log2], [m])
AC_HEADER_TIME
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])
AC_CHECK_HEADERS([time.h])
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])
AC_CHECK_FUNCS([clock_getres clock_gettime clock_settime])
AC_CONFIG_FILES([Makefile
	src/Makefile
	src/C/Makefile])
AC_OUTPUT
