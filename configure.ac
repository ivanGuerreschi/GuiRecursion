#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([GuiRecursion], [1], [ivanGuerreschi86@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_SILENT_RULES([yes])
PKG_PROG_PKG_CONFIG

# Checks for programs.
AC_PROG_CPP
CFLAGS+=" -std=c11"

# Checks for libraries.
PKG_CHECK_MODULES([GUI_RECURSION], [
    glib-2.0
    gtk+-3.0
])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CONFIG_FILES([
    Makefile
    src/Makefile
])

AC_OUTPUT
