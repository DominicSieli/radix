CXX = g++
OBJECTS = ./*.o
HEADERS = ./src/*.h
SOURCE = ./src/*.cpp
BUILD_DIRECTORY = radix
LIB_DIRECTORY = radix/lib
BINARY = ./radix/lib/lib_radix.a
HEADERS_DIRECTORY = radix/headers
CXXFLAGS = -w -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
CHECK_FLAGS = --quiet --enable=all --force --error-exitcode=1

LDFLAGS = -L.
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

build:
	mkdir -p $(BUILD_DIRECTORY);
	mkdir -p $(LIB_DIRECTORY);
	mkdir -p $(HEADERS_DIRECTORY);
	cp $(HEADERS) $(HEADERS_DIRECTORY);
	$(CXX) $(CXXFLAGS) $(SOURCE) -c $(LDFLAGS) $(LDLIBS);
	ar cr $(BINARY) $(OBJECTS);
	rm -f $(OBJECTS);

clean:
	rm -f $(OBJECTS);
	rm -rf $(BUILD_DIRECTORY);

check:
	cppcheck $(CHECK_FLAGS) $(SOURCE);
