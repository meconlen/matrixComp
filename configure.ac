AC_PREREQ(2.61)
AC_INIT([matrixComp], [0.1], [mike@conlen.org])
AC_CONFIG_SRCDIR([src/test.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_HOST
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_PROG_CXX([g++])
AC_PROG_CC([gcc])
AC_HEADER_STDC

case $host_os in
	darwin* )
		CFLAGS="$CFLAGS -I/opt/local/include"
		CXXFLAGS="$CXXFLAGS -I/opt/local/include"
		LDFLAGS="$LDFLAGS -L/opt/local/lib"
		;;
	linux*)
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
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])
AC_CONFIG_FILES([Makefile
	src/Makefile])
AC_OUTPUT
