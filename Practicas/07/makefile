SRC = $(filter-out $(wildcard server*.cc),$(wildcard *.cc))
EXE = $(basename $(SRC))

CXXFLAGS = -march=native -O3 -pthread -Wall

all:
	-find -mindepth 2 -maxdepth 2 -name makefile -execdir make \;

exe: $(EXE)

clean:
	-rm -fv $(EXE) *~
	-find -mindepth 2 -maxdepth 2 -name makefile -execdir make $@ \;

.PHONY: all clean exe

