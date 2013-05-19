all: go.cc UniversalArray.hpp
	c++ -o go go.cc

clean:
	rm -f go
