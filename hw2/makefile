# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
# -O2 option is for optimized version
OPTFLAGS = -O2


bin/main: 
	$(CC) $(OPTFLAGS) src/DataGenerate.cpp -o bin/DataGenerate
	$(CC) $(OPTFLAGS) src/main.cpp -o bin/Sorting


# clean all the .o and executable files
clean:
		rm -rf *.o bin/*

