DIR = lib
CXX = g++
LFLAGS = -L.
OBJS = ./*.o
ARCHIVE = ar
ARCHFLAGS = rcs
COMPILEFLAGS = -c
STD = -std=c++23
CHECK = cppcheck
SRC = ./src/*.cpp
LIB = lib_radix.a
OPTIMIZATION = -O3 -flto
LIBPATH = "./$(DIR)/$(LIB)"
SDL = -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer
WARNINGS = -w -Wall -Wextra -Wpedantic -Wfatal-errors
CHECKFLAGS = --quiet --enable=all --force --error-exitcode=1

build:
	mkdir -p $(DIR);
	$(CXX) $(STD) $(WARNINGS) $(OPTIMIZATION) $(SRC) $(COMPILEFLAGS) $(LFLAGS) $(SDL);
	$(ARCHIVE) $(ARCHFLAGS) $(LIBPATH) $(OBJS);
	rm -f $(OBJS);

clean:
	rm -f $(OBJS);
	rm -rf $(DIR);

check:
	$(CHECK) $(CHECKFLAGS) $(SRC);
