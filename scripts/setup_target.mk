ifndef TARGET
$(error TARGET variable is required)
endif

include scripts/targets/$(TARGET).mk

$(info Build configuration:)

$(info O = $(O))
$(info A = $(A))
$(info STATIC_LIB_FILE = $(STATIC_LIB_FILE))
$(info LIST_DEPS = $(LIST_DEPS))
$(info CXXFLAGS = $(CXXFLAGS))

$(info add_to_lib = $(call add_to_lib,lib.$(A),object.$(O)))
$(info build_cxx_obj = $(call build_cxx_obj,file.cpp,file.$(O)))
$(info build_cxx_exe = $(call build_cxx_exe,file.$(O),out))

$(info )
