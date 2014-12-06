all: welcomeBSHP.cgi\


# ###########################################
# Linking to create .cgi file for each script
# ###########################################

welcomeBSHP.cgi: welcomeBSHP.o infoFromHub.o
	g++ -o welcomeBSHP.cgi welcomeBSHP.o infoFromHub.o 

# ###########################################
# Compilation of main file for each script
# ###########################################

welcomeBSHP.o: welcomeBSHP.cpp infoFromHub.hpp 
	g++ -c welcomeBSHP.cpp

# ###########################################
# Compilation of general module used by scripts
# ###########################################

infoFromHub.o: infoFromHub.cpp infoFromHub.hpp
	g++ -c infoFromHub.cpp
	

	

