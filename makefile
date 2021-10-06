CXXFLAGS = -Wall -Wextra -pedantic $(shell pkg-config --cflags sdl2) -O2
LXXFLAGS = $(shell pkg-config --libs sdl2)

SrcDir = src
BinDir = bin

MathDir          = $(SrcDir)/math
ShapesDir        = $(SrcDir)/shapes
GraphicsDir      = $(SrcDir)/graphics
ShapeManagerDir  = $(SrcDir)/shape_manager
ListDir          = $(SrcDir)/list
EventDir         = $(SrcDir)/event
ButtonManagerDir = $(SrcDir)/button_manager
AppDir           = $(SrcDir)/app

CppSrc  = $(notdir $(wildcard $(SrcDir)/*.cpp))          \
		  $(notdir $(wildcard $(MathDir)/*.cpp))         \
		  $(notdir $(wildcard $(ShapesDir)/*.cpp))       \
		  $(notdir $(wildcard $(GraphicsDir)/*.cpp))     \
		  $(notdir $(wildcard $(ShapeManagerDir)/*.cpp)) \
		  $(notdir $(wildcard $(ListDir)/*.cpp))         \
		  $(notdir $(wildcard $(EventDir)/*.cpp))        \
		  $(notdir $(wildcard $(ButtonManagerDir)/*.cpp))\
		  $(notdir $(wildcard $(AppDir)/*.cpp))

Headers = $(wildcard $(SrcDir)/*.hpp)          \
		  $(wildcard $(MathDir)/*.hpp)         \
		  $(wildcard $(ShapesDir)/*.hpp)       \
		  $(wildcard $(GraphicsDir)/*.hpp)     \
		  $(wildcard $(ShapeManagerDir)/*.hpp) \
		  $(wildcard $(ListDir)/*.hpp)         \
		  $(wildcard $(EventDir)/*.hpp)        \
		  $(wildcard $(ButtonManagerDir)/*.hpp)\
		  $(wildcard $(AppDir)/*.hpp)

Intermediates = $(addprefix $(BinDir)/, $(CppSrc:.cpp=.o))

chemistry: $(Intermediates)
	g++ -o chemistry $(Intermediates) $(LXXFLAGS)

vpath %.cpp $(SrcDir) $(MathDir) $(ShapesDir) $(GraphicsDir) $(ShapeManagerDir) $(ListDir) $(EventDir) $(ButtonManagerDir) $(AppDir)
$(BinDir)/%.o: %.cpp $(Headers) makefile
	g++ -c $< $(CXXFLAGS) -o $@

.PHONY: init
init:
	mkdir -p $(BinDir)

.PHONY: clean
clean:
	rm -f $(BinDir)/*.o
