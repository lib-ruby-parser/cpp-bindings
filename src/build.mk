ifeq ($(DETECTED_OS), Windows)
	CXXFLAGS += /std:c++17 /nologo /bigobj /MT /Zi
	CXXOBJFLAGS += /c /Fo
	ifeq ($(BUILD_ENV), debug)
		CXXFLAGS += /Od /DEBUG
	else
		CXXFLAGS += /O2
	endif
	OBJ_FILE_EXT = obj
endif

ifeq ($(DETECTED_OS), Linux)
	CXXFLAGS += -Wall -Wextra -std=c++17
	CXXOBJFLAGS += -fPIC -c
	CXXEXECFLAGS = -lpthread -ldl
	ifeq ($(BUILD_ENV), debug)
		CXXFLAGS += -g -O0
	else
		CXXFLAGS += -O2
	endif
	OBJ_FILE_EXT = o
endif

ifeq ($(DETECTED_OS), Darwin)
	CXXFLAGS += -Wall -Wextra -std=c++17
	CXXOBJFLAGS += -fPIC -c
	CXXEXECFLAGS = -lpthread -ldl
	ifeq ($(BUILD_ENV), debug)
		CXXFLAGS += -g -O0
	else
		CXXFLAGS += -O2
	endif
	OBJ_FILE_EXT = o
endif

ALL_SRCS = $(wildcard src/*.cpp) $(wildcard src/gen/messages/*.cpp) $(wildcard src/gen/nodes/*.cpp)
ALL_HEADERS = $(wildcard src/*.h) $(wildcard src/gen/messages/*.h) $(wildcard src/gen/nodes/*.h)
OBJECTS = $(foreach src,$(ALL_SRCS), $(patsubst src/%.cpp,$(TARGET_DIR)/%.$(OBJ_FILE_EXT),$(src)))

include .depend
.depend: $(ALL_SRCS) $(ALL_HEADERS)
	rm -f "$@"
	touch "$@"
	$(foreach src,$(ALL_SRCS), $(CXX) -MT $(patsubst src/%.cpp,$(TARGET_DIR)/%.$(OBJ_FILE_EXT),$(src)) -MM $(src) >> $@; echo "" >> $@;)
depend: .depend

$(TARGET_DIR)/%.$(OBJ_FILE_EXT): filename = $(patsubst $(TARGET_DIR)/%.$(OBJ_FILE_EXT),%,$@)
$(TARGET_DIR)/%.$(OBJ_FILE_EXT): source = src/$(filename).cpp
$(TARGET_DIR)/%.$(OBJ_FILE_EXT): header = src/$(filename).h
$(TARGET_DIR)/%.$(OBJ_FILE_EXT):
	$(CXX) $(source) $(CXXFLAGS) $(CXXOBJFLAGS)
	mv $(notdir $(filename)).$(OBJ_FILE_EXT) $(TARGET_DIR)/$(filename).$(OBJ_FILE_EXT)
