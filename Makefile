DIR			:= lib
CXX			:= g++
ARCHIVE		:= ar
CHECK		:= clang-tidy

STD			:= -std=c++23
WARNINGS	:= -Wall -Wextra -Wpedantic -Wfatal-errors
OPTIMIZATION := -O3 -flto

CXXFLAGS	:= $(STD) $(WARNINGS)
ARFLAGS		:= rcs

SRC			:= $(wildcard src/*.cpp)
OBJS		:= $(SRC:.cpp=.o)

LIB			:= $(DIR)/lib_radix.a

SDL			:= -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer

.PHONY: build_debug build_optimized check clean

build_debug: CXXFLAGS += -g
build_debug: $(LIB)

build_optimized: CXXFLAGS += $(OPTIMIZATION)
build_optimized: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p $(DIR)
	$(ARCHIVE) $(ARFLAGS) $@ $^
	rm -f $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

check:
	$(CHECK) $(CXXFLAGS) $(SRC)

clean:
	rm -f $(OBJS)
	rm -rf $(DIR)
