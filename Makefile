#							#########################
#							# DIRAC ENGINE MAKEFILE #
#							#########################

CC        := g++														# c compiler
SRC_MAIN  := src/*.cpp													# all src files + main.cpp
SRC_DIRAC := $(filter-out src/main.cpp, $(SRC_MAIN_FILES))				# all dirac src files
DLL       := bin/dirac.dll												# dynimic link library file
MAIN      := bin/main													# executable file
DONE      := DONE

dirac:
	$(CC) --shared -o $(DLL) $(SRC_FILES)

exe:
	$(CC) -o bin/main src/main.cpp $(DLL)

echo:
	echo $(DONE)

all: dirac exe echo