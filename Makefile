SRC_MAIN_FILES := $(wildcard src/*.cpp)						# all src files
SRC_FILES := $(filter-out src/main.cpp, $(SRC_MAIN_FILES))	# all dirac src files
DLL := bin/dirac.dll										# dynimic library file
MAIN := bin/main											# executable file

make:														# make a dynimic library file
	g++ -shared -o $(DLL) $(SRC_FILES)

exe:														# make an executable file
	g++ -o bin/main $(SRC_MAIN_FILES)