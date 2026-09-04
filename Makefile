DIR = lib
CXX = g++
CFLAGS = -c
LFLAGS = -L.
OBJS = ./*.o
ARCHIVE = ar
AFLAGS = rcs
STD = -std=c++23
CHECK = cppcheck
SRC = ./src/*.cpp
LIB = lib_radix.a
CHECKSTD = --std=c++23
OPTIMIZATION = -O3 -flto
LIBPATH = "./$(DIR)/$(LIB)"
SDL = -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer
WARNINGS = -w -Wall -Wextra -Wpedantic -Wfatal-errors
CHECKFLAGS = --quiet --enable=all --force --error-exitcode=1

build:
	mkdir -p $(DIR);
	$(CXX) $(STD) $(WARNINGS) $(OPTIMIZATION) $(SRC) $(CFLAGS) $(LFLAGS) $(SDL);
	$(ARCHIVE) $(AFLAGS) $(LIBPATH) $(OBJS);
	rm -f $(OBJS);

clean:
	rm -f $(OBJS);
	rm -rf $(DIR);

check:
	$(CHECK) $(CHECKSTD) $(CHECKFLAGS) $(SRC);
