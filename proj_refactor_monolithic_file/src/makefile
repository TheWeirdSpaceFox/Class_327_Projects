CFLAGS = -Wall

#TODO link (-o) all object files into the executable myexe
all: fileio.o utils.o proj_refactor_file.o
	
	
#rebuild object file if fileio.cpp, or fileio.h or constants.h changes
#compile the .cpp file to an object file (-c)
fileio.o: ../fileio/fileio.cpp ../includes/fileio.h ../includes/constants.h
	g++ $(CFLAGS) -c ../fileio/fileio.cpp
	
#TODO 
utils.o: 
	
#TODO
proj_refactor_file.o: proj_refactor_file.cpp	
	

#TODO type 'make clean' to remove myexe and all .o files	
clean: