# Makefile for to build a gcc/uClibc toolchain
#
# Copyright (C) 2002-2003 Erik Andersen <andersen@uclibc.org>
# Copyright (C) 2004 Manuel Novoa III <mjn3@uclibc.org>
# Copyright (C) 2005 Felix Fietkau <openwrt@nbd.name>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

include $(TOPDIR)/rules.mk

GCC_VERSION:=$(strip $(GCC_VERSION))

#GCC_SITE:=ftp://ftp.gnu.org/gnu/gcc/releases/gcc-$(GCC_VERSION)
GCC_SITE:=https://dl.meraki.net/

GCC_DIR:=$(TOOL_BUILD_DIR)/gcc-$(GCC_VERSION)
GCC_STRIP_HOST_BINARIES:=true
GCC_CAT:=bzcat

ifeq ($(GCC_VERSION),4.5.3)
	PKG_MD5:=8e0b5c12212e185f3e4383106bfa9cc6
else ifeq ($(GCC_VERSION),4.7.1)
	PKG_MD5:=933e6f15f51c031060af64a9e14149ff
else ifeq ($(GCC_VERSION),4.8.3)
	PKG_MD5:=7c60f24fab389f77af203d2516ee110f
else ifeq ($(GCC_VERSION),5.4.0)
	PKG_MD5:=4c626ac2a83ef30dfb9260e6f59c2b30
else ifeq ($(GCC_VERSION),6.3.0)
	PKG_MD5:=677a7623c7ef6ab99881bc4e048debb6
else ifeq ($(GCC_VERSION),6.4.0)
	PKG_MD5:=11ba51a0cfb8471927f387c8895fe232
	GCC_CAT:=xzcat
else ifeq ($(GCC_VERSION),7.3.0)
	PKG_MD5:=be2da21680f27624f3a87055c4ba5af2
	GCC_CAT:=xzcat
endif

ifeq ($(GCC_CAT),xzcat)
GCC_SOURCE:=gcc-$(GCC_VERSION).tar.xz
else
GCC_SOURCE:=gcc-$(GCC_VERSION).tar.bz2
endif


#############################################################
#
# Setup some initial stuff
#
#############################################################

ifeq ($(BR2_INSTALL_LIBGCJ),y)
TARGET_LANGUAGES:=c,c++,java
else
ifeq ($(BR2_INSTALL_LIBSTDCPP),y)
TARGET_LANGUAGES:=c,c++
else
TARGET_LANGUAGES:=c
endif
endif

ifeq ($(BR2_POWERPC_E500),y)
GCC_WITH_CPU := --with-cpu=8548
endif

#############################################################
#
# build the first pass gcc compiler
#
#############################################################

GCC_BUILD_DIR1:=$(TOOL_BUILD_DIR)/gcc-$(GCC_VERSION)-initial

$(DL_DIR)/$(GCC_SOURCE):
	mkdir -p $(DL_DIR)
	$(SCRIPT_DIR)/download.pl $(DL_DIR) $(GCC_SOURCE) $(PKG_MD5) $(GCC_SITE)

$(GCC_DIR)/.unpacked: $(DL_DIR)/$(GCC_SOURCE)
	mkdir -p $(TOOL_BUILD_DIR)
	$(GCC_CAT) $(DL_DIR)/$(GCC_SOURCE) | tar -C $(TOOL_BUILD_DIR) $(TAR_OPTIONS) -
	touch $(GCC_DIR)/.unpacked

$(GCC_DIR)/.patched: $(GCC_DIR)/.unpacked
	# Apply any files named gcc-*.patch from the source directory to gcc
	$(SCRIPT_DIR)/patch-kernel.sh $(GCC_DIR) ./$(GCC_VERSION) \*.patch
	# Note: The soft float situation has improved considerably with gcc 3.4.x.
	# We can dispense with the custom spec files, as well as libfloat for the arm case.
	# However, we still need a patch for arm.  There's a similar patch for gcc 3.3.x
	# which needs to be integrated so we can kill of libfloat for good.
ifeq ($(BR2_SOFT_FLOAT),y)
ifeq ("$(strip $(ARCH))","arm")
	$(SCRIPT_DIR)/patch-kernel.sh $(GCC_DIR) ./$(GCC_VERSION) arm-softfloat.patch.conditional
endif
ifeq ("$(strip $(ARCH))","armeb")
	$(SCRIPT_DIR)/patch-kernel.sh $(GCC_DIR) ./$(GCC_VERSION) arm-softfloat.patch.conditional
endif
endif
	$(SED) 's,\(version_string.. = "[0-9\.]*\).*\(";\),\1 (OpenWrt-2.0)\2,' $(GCC_DIR)/gcc/version.c
	$(SED) 's,\(bug_report_url.. = "\).*\(";\),\1<URL:https://dev.openwrt.org/>\2,' $(GCC_DIR)/gcc/version.c
	touch $(GCC_DIR)/.patched

# The --without-headers option stopped working with gcc 3.0 and has never been
# # fixed, so we need to actually have working C library header files prior to
# # the step or libgcc will not build...

ifeq ($(GCC_VERSION),4.4.3)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --without-cloog
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.4.4)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --without-cloog
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.5.1)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.5.3)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.6.2)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --disable-libquadmath --disable-target-libiberty --disable-target-zlib --disable-decimal-float
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.6.3)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.7.0)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.7.1)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-tls --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR)  --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),4.8.3)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float --disable-libatomic --disable-libsanitizer
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR) --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),5.4.0)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float --disable-libatomic --disable-libsanitizer
# GNU hash style is incompatible with MIPS ABI
ifneq ("$(strip $(ARCH))","mips")
ifneq ("$(strip $(ARCH))","mipsel")
DISABLE_LIB_OPTS += --with-linker-hash-style=gnu
endif
endif
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR) --with-build-sysroot=$(STAGING_DIR)
GCC_CXXFLAGS=-std=gnu++03
endif

ifeq ($(GCC_VERSION),6.3.0)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float --disable-libatomic --disable-libsanitizer
# GNU hash style is incompatible with MIPS ABI
ifneq ("$(strip $(ARCH))","mips")
ifneq ("$(strip $(ARCH))","mipsel")
DISABLE_LIB_OPTS += --with-linker-hash-style=gnu
endif
endif
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR) --with-build-sysroot=$(STAGING_DIR)
endif

ifeq ($(GCC_VERSION),6.4.0)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float --disable-libatomic --disable-libsanitizer
# GNU hash style is incompatible with MIPS ABI
ifneq ("$(strip $(ARCH))","mips")
ifneq ("$(strip $(ARCH))","mipsel")
DISABLE_LIB_OPTS += --with-linker-hash-style=gnu
endif
endif
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR) --with-build-sysroot=$(STAGING_DIR)
endif

ifeq ($(GCC_VERSION),7.3.0)
DISABLE_LIB_OPTS:=--disable-libmudflap --disable-libssp --disable-libquadmath --disable-nls --disable-target-libiberty --disable-target-zlib --disable-decimal-float --disable-libatomic --disable-libsanitizer
# GNU hash style is incompatible with MIPS ABI
ifneq ("$(strip $(ARCH))","mips")
ifneq ("$(strip $(ARCH))","mipsel")
DISABLE_LIB_OPTS += --with-linker-hash-style=gnu
endif
endif
FIX_SYSROOT:=--with-sysroot=$(STAGING_DIR) --with-build-sysroot=$(STAGING_DIR)
endif

$(GCC_BUILD_DIR1)/.configured: $(GCC_DIR)/.patched
	mkdir -p $(GCC_BUILD_DIR1)
	(cd $(GCC_BUILD_DIR1); rm -f config.cache; PATH=$(TARGET_PATH) \
		CC="$(HOSTCC)" \
		CXX="$(HOSTCXX)" \
		CXXFLAGS="$(GCC_CXXFLAGS)" \
		$(GCC_DIR)/configure \
		--prefix=$(HOST_STAGING_DIR) \
		--build=$(GNU_HOST_NAME) \
		--host=$(GNU_HOST_NAME) \
		--target=$(REAL_GNU_TARGET_NAME) \
		--enable-obsolete \
		--enable-languages=c \
		--disable-shared \
		--disable-threads \
		--disable-libgomp \
		$(DISABLE_LIB_OPTS) \
		MAKEINFO=missing \
		--without-headers \
		--with-newlib \
		--disable-__cxa_atexit \
		--enable-target-optspace \
		--with-gnu-ld \
		$(SOFT_FLOAT_CONFIG_OPTION) \
		$(DISABLE_NLS) \
		$(MULTILIB) \
		$(GCC_WITH_CPU) $(GCC_WITH_ARCH) $(GCC_WITH_TUNE) \
		$(shell echo $(BR2_EXTRA_GCC_CONFIG_OPTIONS)));
	touch $(GCC_BUILD_DIR1)/.configured

$(GCC_BUILD_DIR1)/.compiled: $(GCC_BUILD_DIR1)/.configured
ifeq ($(GCC_VERSION),4.4.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.4.4)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.5.1)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.5.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.6.2)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.6.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.7.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.7.1)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),4.8.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),5.4.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),6.3.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),6.4.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else ifeq ($(GCC_VERSION),7.3.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc all-target-libgcc
else
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j4 -C $(GCC_BUILD_DIR1) all-gcc
endif
	touch $(GCC_BUILD_DIR1)/.compiled

$(HOST_STAGING_DIR)/bin/$(REAL_GNU_TARGET_NAME)-gcc: $(GCC_BUILD_DIR1)/.compiled
ifeq ($(GCC_VERSION),4.4.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.4.4)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.5.1)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.5.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.6.2)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.6.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.7.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.7.1)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),4.8.3)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),5.4.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install-gcc install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),6.3.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install-gcc install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),6.4.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install-gcc install-target-libgcc || (rm "$@" && false)
else ifeq ($(GCC_VERSION),7.3.0)
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install-gcc install-target-libgcc || (rm "$@" && false)
else
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR1) install-gcc
endif

#############################################################
#
# second pass compiler build.  Build the compiler targeting 
# the newly built shared uClibc library.
#
#############################################################
#
# Sigh... I had to rework things because using --with-gxx-include-dir
# causes issues with include dir search order for g++.  This seems to
# have something to do with "path translations" and possibly doesn't
# affect gcc-target.  However, I haven't tested gcc-target yet so no
# guarantees.  mjn3

GCC_BUILD_DIR2:=$(TOOL_BUILD_DIR)/gcc-$(GCC_VERSION)-final
$(GCC_BUILD_DIR2)/.configured: $(GCC_DIR)/.patched $(STAGING_DIR)/lib/libc.a
	mkdir -p $(GCC_BUILD_DIR2)
	# Important!  Required for limits.h to be fixed.
	rm -rf $(STAGING_DIR)/sys-include
	ln -sf include $(STAGING_DIR)/sys-include
ifeq ($(GCC_VERSION),4.4.3)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.4.4)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.5.1)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.5.3)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.6.2)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.6.3)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.7.0)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.7.1)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),4.8.3)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),5.4.0)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),6.3.0)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),6.4.0)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
ifeq ($(GCC_VERSION),7.3.0)
	rm -rf $(STAGING_DIR)/usr
	ln -sf ./ $(STAGING_DIR)/usr
endif
	(cd $(GCC_BUILD_DIR2); rm -f config.cache; PATH=$(TARGET_PATH) \
		CC="$(HOSTCC)" \
		CXX="$(HOSTCXX)" \
		CXXFLAGS="$(GCC_CXXFLAGS)" \
		$(GCC_DIR)/configure \
		--prefix=$(HOST_STAGING_DIR) \
		--build=$(GNU_HOST_NAME) \
		--host=$(GNU_HOST_NAME) \
		--target=$(REAL_GNU_TARGET_NAME) \
		--enable-obsolete \
		--enable-languages=$(TARGET_LANGUAGES) \
		$(FIX_SYSROOT) \
		--enable-shared \
		--disable-libgomp \
		$(DISABLE_LIB_OPTS) \
		MAKEINFO=missing \
		--disable-__cxa_atexit \
		--enable-target-optspace \
		--with-gnu-ld \
		$(SOFT_FLOAT_CONFIG_OPTION) \
		$(DISABLE_NLS) \
		$(MULTILIB) \
		$(GCC_WITH_CPU) $(GCC_WITH_ARCH) $(GCC_WITH_TUNE) \
		$(GCC_USE_SJLJ_EXCEPTIONS) \
		$(shell echo $(BR2_EXTRA_GCC_CONFIG_OPTIONS)));
	touch $(GCC_BUILD_DIR2)/.configured

$(GCC_BUILD_DIR2)/.compiled: $(GCC_BUILD_DIR2)/.configured
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -j8 -C $(GCC_BUILD_DIR2) all
	touch $(GCC_BUILD_DIR2)/.compiled

gcc-install: $(GCC_BUILD_DIR2)/.compiled
	PATH=$(TARGET_PATH) $(MAKE) CC="$(HOSTCC)" CXX="$(HOSTCXX)" -C $(GCC_BUILD_DIR2) install
	echo $(GCC_VERSION) > $(STAGING_DIR)/gcc_version
	# Set up the symlinks to enable lying about target name.
	set -e; \
	(cd $(HOST_STAGING_DIR); \
		ln -sf $(REAL_GNU_TARGET_NAME) $(GNU_TARGET_NAME); \
		cd bin; \
		for app in $(REAL_GNU_TARGET_NAME)-* ; do \
			ln -sf $${app} \
		   	$(GNU_TARGET_NAME)$${app##$(REAL_GNU_TARGET_NAME)}; \
		done; \
	);
	#
	# Now for the ugly 3.3.x soft float hack...
	#
ifeq ($(BR2_SOFT_FLOAT),y)
ifeq ($(findstring 3.3.,$(GCC_VERSION)),3.3.)
	# Make sure we have a soft float specs file for this arch
	if [ ! -f ./$(GCC_VERSION)/specs-$(ARCH)-soft-float ] ; then \
		echo soft float configured but no specs file for this arch ; \
		/bin/false ; \
	fi;
	# Replace specs file with one that defaults to soft float mode.
	if [ ! -f $(HOST_STAGING_DIR)/lib/gcc-lib/$(REAL_GNU_TARGET_NAME)/$(GCC_VERSION)/specs ] ; then \
		echo staging dir specs file is missing ; \
		/bin/false ; \
	fi;
	$(CP) ./$(GCC_VERSION)/specs-$(ARCH)-soft-float $(STAGING_DIR)/lib/gcc-lib/$(REAL_GNU_TARGET_NAME)/$(GCC_VERSION)/specs
endif
endif
# We do another ugly hack here because the standard behaviour is
# to include a reference to libgcc.so.1 in all binaries. For flash space
# saving, we change the specs file to link in a static libgcc here. 
	if [ -f $(HOST_STAGING_DIR)/lib/gcc/$(REAL_GNU_TARGET_NAME)/$(GCC_VERSION)/specs ] ; then \
		patch -d $(HOST_STAGING_DIR)/lib/gcc/$(REAL_GNU_TARGET_NAME)/$(GCC_VERSION)/ -p0 < ./$(GCC_VERSION)/static-libgcc.patch.conditional ; \
	fi;

source: $(DL_DIR)/$(GCC_SOURCE)
prepare: $(HOST_STAGING_DIR)/bin/$(REAL_GNU_TARGET_NAME)-gcc
compile: gcc-install
install:
clean: gcc-clean
	rm -rf $(GCC_DIR)
	rm -rf $(GCC_BUILD_DIR1)
	rm -rf $(GCC_BUILD_DIR2)
	rm -f $(HOST_STAGING_DIR)/bin/$(REAL_GNU_TARGET_NAME)-gc*
	rm -f $(HOST_STAGING_DIR)/bin/$(REAL_GNU_TARGET_NAME)-c*
