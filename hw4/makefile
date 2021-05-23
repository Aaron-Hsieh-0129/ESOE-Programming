# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
# -O2 option is for optimized version
OPTFLAGS = -O2


all: bin/Permutation bin/Combination

bin/Permutation: 
	$(CC) $(OPTFLAGS) src/Permutation.cpp -o bin/Permutation

bin/Combination:
	$(CC) $(OPTFLAGS) src/Combination.cpp -o bin/Combination


# clean all the .o and executable files
clean:
		rm -rf *.o bin/*

