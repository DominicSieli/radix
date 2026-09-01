build:
	mkdir -p lib;
	cp ./src/*.h lib;
	g++ -w -std=c++23 -Wall -Wextra -Wpedantic -Wfatal-errors ./src/*.cpp -c -L. -lSDL3 -lSDL3_image -lSDL3_ttf -lSDL3_mixer;
	ar cr ./lib/lib_radix.a ./*.o;
	rm -f ./*.o;

clean:
	rm -f ./*.o;
	rm -rf lib;

check:
	cppcheck --quiet --enable=all --force --error-exitcode=1 ./src/*.cpp;
