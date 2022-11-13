CC        = g++
LD        = g++

INC_DIR   = ./inc

DEPFLAGS  = -MP -MD

LIBS = 	-L"./arc/SDL2-devel-2.0.18-mingw/SDL2-2.0.18/x86_64-w64-mingw32/lib" \
		-L"./arc/SDL2_image-devel-2.0.5-mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/lib" \
		-L"./arc/SDL2_ttf-devel-2.0.15-mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib" -static-libgcc -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
		
INC_SDL = -I"./arc/SDL2-devel-2.0.18-mingw/SDL2-2.0.18/x86_64-w64-mingw32/include/SDL2" \
		  -I"./arc/SDL2_image-devel-2.0.5-mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2" \
		  -I"./arc/SDL2_ttf-devel-2.0.15-mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2" 

CXXFLAGS  = -ggdb -O0 -Wall -Wextra $(foreach D,$(INC_DIR), -I$(D)) $(DEPFLAGS) $(INC_SDL)# incluir headers
PROG_NAME = solid

LIB_DIR   = ./lib
SRC_DIR   = ./src
BUILD_DIR = ./build
BIN_DIR   = ./bin
ALL_SRC_LIST  = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(LIB_DIR)/*.cpp) 

SRC_LIST  = $(wildcard $(SRC_DIR)/*.cpp) 
LIB_LIST  = $(wildcard $(LIB_DIR)/*.cpp) 

SRC_OBJ =  $(addprefix $(BUILD_DIR)/,$(notdir $(SRC_LIST:.cpp=.o))) 
LIB_OBJ =  $(addprefix $(BUILD_DIR)/,$(notdir $(LIB_LIST:.cpp=.o))) 


DEP_LIST  = $(addprefix $(BUILD_DIR)/,$(notdir $(ALL_SRC_LIST:.cpp=.d))) 

.PHONY: all clean $(PROG_NAME)

all: $(PROG_NAME)

$(SRC_OBJ): $(SRC_LIST) #Main.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/Framework.o: $(LIB_DIR)/Framework.cpp 
	$(CC) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/Window.o: $(LIB_DIR)/Window.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Mesh.o: $(LIB_DIR)/Mesh.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Vector.o: $(LIB_DIR)/Vector.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Fonts.o: $(LIB_DIR)/Fonts.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

#....................................................

$(PROG_NAME): $(SRC_OBJ) $(LIB_OBJ)
	$(LD) $(SRC_OBJ) $(LIB_OBJ) -o $(BIN_DIR)/$@ $(LIBS)

clean:
	rm -f $(BIN_DIR)/$(PROG_NAME) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d

-include $(DEPFLAGS)


