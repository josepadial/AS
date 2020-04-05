SHELL = bash
.ONESHELL:

SRC = $(sort $(wildcard *.cc))
EXE = $(basename $(SRC))
LTR = $(EXE:=.ltrace)
STR = $(EXE:=.strace)

DATA = $(EXE:=.data)
PERF = $(EXE:=.perf)

CXXFLAGS = -march=native -O3 -pthread -Wall

all: $(EXE)
	@for i in $^; do 
		rm -f *.dat
		echo -n "$$i: "
		perf stat -r 25 -- ./$$i |& grep 'elapsed' | tr -s ' '
	done

clean:
	-rm -fv $(DATA) $(EXE) $(LTR) $(STR) core.* *~

l: $(LTR)

s: $(STR)

$(EXE): work.h

%.data: %
	perf record --call-graph dwarf --freq=max -o $@ -- ./'$<'

%.ltrace: %
	ltrace -c -f ./$< |& c++filt | tee $@

%.perf: %.data
	perf report -i $<

%.strace: %
	strace -c -f -qq ./$< |& c++filt | tee $@

.PHONY: all clean l s
.PRECIOUS: $(DATA)

