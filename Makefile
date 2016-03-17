CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := 
CC_FLAGS := 

main.exe: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

obj/%.o: %.cpp
	g++ $(CC_FLAGS) -I. -c -o $@ $<

