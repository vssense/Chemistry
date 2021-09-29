CXXFLAGS = -Wall -Wextra -pedantic $(shell pkg-config --cflags sdl2) -O2
LXXFLAGS = $(shell pkg-config --libs sdl2)

SrcDir = src
BinDir = bin

MathDir = $(SrcDir)/math
ShapesDir = $(SrcDir)/shapes
GraphicsDir = $(SrcDir)/graphics
ManagerDir = $(SrcDir)/manager
ListDir = $(SrcDir)/list

CppSrc  = $(notdir $(wildcard $(SrcDir)/*.cpp))     \
		  $(notdir $(wildcard $(MathDir)/*.cpp))    \
		  $(notdir $(wildcard $(ShapesDir)/*.cpp))  \
		  $(notdir $(wildcard $(GraphicsDir)/*.cpp))\
		  $(notdir $(wildcard $(ManagerDir)/*.cpp)) \
		  $(notdir $(wildcard $(ListDir)/*.cpp))

Headers = $(wildcard $(SrcDir)/*.hpp)     \
		  $(wildcard $(MathDir)/*.hpp)    \
		  $(wildcard $(ShapesDir)/*.hpp)  \
		  $(wildcard $(GraphicsDir)/*.hpp)\
		  $(wildcard $(ManagerDir)/*.hpp) \
		  $(wildcard $(ListDir)/*.hpp)

Intermediates = $(addprefix $(BinDir)/, $(CppSrc:.cpp=.o))

chemistry: $(Intermediates)
	g++ -o chemistry $(Intermediates) $(LXXFLAGS)

vpath %.cpp $(SrcDir) $(MathDir) $(ShapesDir) $(GraphicsDir) $(ManagerDir) $(ListDir)
$(BinDir)/%.o: %.cpp $(Headers) makefile
	g++ -c $< $(CXXFLAGS) -o $@

.PHONY: init
init:
	mkdir -p $(BinDir)

.PHONY: clean
clean:
	rm -f $(BinDir)/*.o
