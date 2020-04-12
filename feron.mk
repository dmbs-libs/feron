#
#            DMBS Build System
#     Released into the public domain.
#
#  dean [at] fourwalledcubicle [dot] com
#        www.fourwalledcubicle.com
#

# Include Guard
ifeq ($(filter FERON, $(DMBS_BUILD_MODULES)),)

# Sanity check user supplied DMBS path
ifndef DMBS_PATH
$(error Makefile DMBS_PATH option cannot be blank)
endif

# Location of the current module
FERON_MODULE_PATH := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))

# Import the CORE module of DMBS
include $(DMBS_PATH)/core.mk

# This module needs to be included before gcc.mk
ifneq ($(findstring GCC, $(DMBS_BUILD_MODULES)),)
$(error Include this module before gcc.mk)
endif

# Include NEC module
include $(LIB_PATH)/nec/nec.mk

# Help settings
DMBS_BUILD_MODULES         += FERON
DMBS_BUILD_TARGETS         +=
DMBS_BUILD_MANDATORY_VARS  += DMBS_PATH
DMBS_BUILD_OPTIONAL_VARS   +=
DMBS_BUILD_PROVIDED_VARS   += FERON_SRC
DMBS_BUILD_PROVIDED_MACROS +=

# Sanity check user supplied values
$(foreach MANDATORY_VAR, $(DMBS_BUILD_MANDATORY_VARS), $(call ERROR_IF_UNSET, $(MANDATORY_VAR)))

# FERON Library
FERON_SRC := $(FERON_MODULE_PATH)/src/feron.c

# Compiler flags and sources
SRC      += $(FERON_SRC)
CC_FLAGS += -DDMBS_MODULE_FERON
CC_FLAGS += -I$(FERON_MODULE_PATH)/include/

# Phony build targets for this module
.PHONY: $(DMBS_BUILD_TARGETS)

endif
