#                       #########################
#                       # DIRAC ENGINE MAKEFILE #
#                       #########################

CC        := g++                                                        # c compiler
SRC_ALL   := src/*.cpp                                                  # all dirac src files + main src file
SRC_MAIN  := src/main.cpp                                               #                       main src file
SRC_DIRAC := $(filter-out $(SRC_MAIN), $(SRC_ALL))                      # all dirac src files
DLL       := bin/dirac.dll                                              # dynimic link library file
EXE_MAIN  := bin/main                                                   # executable file
DONE      := DONE

dirac:
	$(CC) --shared -o $(DLL)      $(SRC_DIRAC)

exe:
	$(CC)          -o $(EXE_MAIN) $(SRC_MAIN)  $(DLL)

echo:
	echo $(DONE)

all: dirac exe echo