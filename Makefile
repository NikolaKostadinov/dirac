#########################
# DIRAC ENGINE MAKEFILE #
#########################

SRC_MAIN_FILES := $(wildcard src/*.cpp)							# all src files + main.cpp
SRC_FILES := $(filter-out src/main.cpp, $(SRC_MAIN_FILES))		# all dirac src files
DLL := bin/dirac.dll											# dynimic link library file
MAIN := bin/main												# executable file

dirac:															# make a dynimic library file
	g++ --shared -o $(DLL) $(SRC_FILES)

exe:															# make an executable file
	g++ -o bin/main src/main.cpp $(DLL)

echo:
	echo DONE

all: dirac exe echo