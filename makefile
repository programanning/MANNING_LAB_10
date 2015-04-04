all: project8

project8:	main.cpp classes.o strfunc.o
			g++ -g main.cpp classes.o strfunc.o -o project8

classes.o:	classes.cpp
			g++ -c -g classes.cpp

strfunc.o:	strfunc.cpp
			g++ -c -g strfunc.cpp

clean:
			rm -rf *.o project8
