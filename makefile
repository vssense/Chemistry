CXXFLAGS = -Wall -Wextra -pedantic $(shell pkg-config --cflags sdl2)
LXXFLAGS = $(shell pkg-config --libs sdl2)

SrcDir = src
BinDir = bin

MathDir = $(SrcDir)/math
ShapesDir = $(SrcDir)/shapes
GraphicsDir = $(SrcDir)/graphics

CppSrc  = $(notdir $(wildcard $(SrcDir)/*.cpp))     \
		  $(notdir $(wildcard $(MathDir)/*.cpp))    \
		  $(notdir $(wildcard $(ShapesDir)/*.cpp))  \
		  $(notdir $(wildcard $(GraphicsDir)/*.cpp))

Headers = $(wildcard $(SrcDir)/*.h)     \
		  $(wildcard $(MathDir)/*.h)    \
		  $(wildcard $(ShapesDir)/*.h)  \
		  $(wildcard $(GraphicsDir)/*.h)

Intermediates = $(addprefix $(BinDir)/, $(CppSrc:.cpp=.o))

chemistry: $(Intermediates)
	g++ -o chemistry $(Intermediates) $(LXXFLAGS)

vpath %.cpp $(SrcDir) $(MathDir) $(ShapesDir) $(GraphicsDir)
$(BinDir)/%.o: %.cpp $(Headers)
	g++ -c $< $(CXXFLAGS) -o $@

.PHONY: init
init:
	mkdir -p $(BinDir)

.PHONY: clean
clean:
	rm -f $(BinDir)/*.o