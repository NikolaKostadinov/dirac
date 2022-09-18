SRC_FILES := $(wildcard src/*.cpp)
SRC_FILES := $(filter-out src/main.cpp, $(SRC_FILES))

DLL := $(bin/dirac.dll)

make:
	g++ -shared -o $(DLL) src/*.cpp

exe:
	g++ -o bin/main $(SRC_FILES)