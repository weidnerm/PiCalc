#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = BigInt
CPPUTEST_HOME = /home/vagrant/cpputest-3.7.1

CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_USE_GCOV = Y
CPP_PLATFORM = Gcc

CPPUTEST_WARNINGFLAGS = -Wno-error=sign-conversion -Wno-write-strings

SRC_DIRS = /home/vagrant/workspace/BigInts \

TEST_SRC_DIRS = /home/vagrant/workspace/BigInts/unit_test \

INCLUDE_DIRS =\
  /home/vagrant/workspace/BigInts \
  /home/vagrant/workspace/BigInts/unit_test \
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

.PHONY: dox_all dox_clean
dox_all:
	doxygen ../doxygen.cfg
	
dox_clean:
	rm -rf ../doxygen/

