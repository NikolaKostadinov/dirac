#########################
# DIRAC ENGINE MAKEFILE #
#########################

SRC_MAIN_FILES := $(wildcard src/*.cpp)							# all src files + main.cpp
SRC_FILES := $(filter-out src/main.cpp, $(SRC_MAIN_FILES))		# all dirac src files
DLL := bin/dirac.dll											# dynimic link library file
MAIN := bin/main												# executable file

make:															# make a dynimic library file
	g++ -I include -shared -o $(DLL) $(SRC_FILES)

exe:															# make an executable file
	g++ -I include -o bin/main src/main.cpp $(DLL)