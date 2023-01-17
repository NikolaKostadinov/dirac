#                       #########################
#                       # DIRAC ENGINE MAKEFILE #
#                       #########################

CC        := g++                                                        # c compiler
SRC_ALL   := src/*.cpp                                                  # all dirac src files + main src file
SRC_MAIN  := src/main.cpp                                               #                       main src file
SRC_DIRAC := $(filter-out $(SRC_MAIN), $(SRC_ALL))                      # all dirac src files
DLL_DIRAC := bin/dirac.dll                                              # dynimic link library file
OBJ_DIRAC := bin/dirac.o                                                # object file
LIB_DIRAC := bin/dirac.a                                                # static link library file
EXE_MAIN  := bin/main                                                   # executable file

dirac-dynamic:
	$(CC) --shared -o $(DLL_DIRAC) $(SRC_DIRAC)

dirac-static:
	$(CC) -o $(OBJ_DIRAC) $(SRC_DIRAC)
	ar rcs $(LIB_DIRAC) $(OBJ_DIRAC)

exe-dynamic:
	$(CC) -o $(EXE_MAIN) $(SRC_MAIN) $(DLL_DIRAC)

exe-static:
	$(CC) -o $(EXE_MAIN) $(SRC_MAIN) $(LIB_DIRAC)

exe:
	$(CC) -o $(EXE_MAIN) $(SRC_MAIN) $(DIRAC_LIB_PATH)