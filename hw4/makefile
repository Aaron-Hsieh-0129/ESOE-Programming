# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
# -O2 option is for optimized version
OPTFLAGS = -O2

all	: bin/Sorting bin/DataGenerate
	@echo -n ""

bin/Sorting	: Sorting_tool.o main.o
			$(CC) $(OPTFLAGS) Sorting_tool.o main.o -o bin/Sorting
main.o 	   	: src/main.cpp
			$(CC) $(CFLAGS) $< -o $@
Sorting_tool.o	: src/Sorting_tool.cpp src/Sorting_tool.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@


bin/DataGenerate : DataGenerate.o	
				   $(CC) $(OPTFLAGS) DataGenerate.o -o bin/DataGenerate		
DataGenerate.o	: src/DataGenerate.cpp
				  $(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# clean all the .o and executable files
clean:
		rm -rf *.o bin/*

