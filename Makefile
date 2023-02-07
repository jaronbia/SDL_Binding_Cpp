#OBJS specifies which files to compile as part of the project
OBJS = *.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

#This is the target that compiles our executable
all : $(OBJS)
	clang++ -std=c++17 $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
