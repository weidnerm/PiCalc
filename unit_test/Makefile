
SOURCES = TestRunner.cpp \
          BigIntTest.cpp \
          ../BigIntBase.cpp \
          ../BigIntsBase10.cpp \
          ../BigInts32Bit.cpp \
          
TARGET:=runTests

CPPUTEST_HOME = /usr
CXXFLAGS += -Wno-write-strings -fpermissive
CXXFLAGS += -I/home/vagrant/workspace/BigInts
CPPFLAGS += -I(CPPUTEST_HOME)/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
    
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

all: ${TARGET}

$(SOURCES:.cpp=.o): $@
	@echo CXX $@
	@g++ -c -g ${CXXFLAGS} $(@:.o=.cpp) -o $@
	

${TARGET}: $(SOURCES:.cpp=.o)
	@g++ $(SOURCES:.cpp=.o) -o ${TARGET}   ${LD_LIBRARIES}
	@./${TARGET}

clean:
	rm -rf $(SOURCES:.cpp=.o)  ${TARGET}
	
.PHONY: dox_all dox_clean
dox_all:
	doxygen ../doxygen.cfg
	
dox_clean:
	rm -rf ../doxygen/
	