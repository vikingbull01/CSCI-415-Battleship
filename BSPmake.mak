CC = g++
DIR = 
TAGS = -lcrypto++ -lpthread

# Build All
all: common.o sqltdb.o infoFromHub.o randStrHash.o update.cgi play.cgi

update.cgi: update.cpp sqltdb.o randStrHash.o common.o
	$(CC) -std=c++11 -o $(DIR)update.cgi update.cpp sqltdb.o randStrHash.o common.o -lsqlite3 $(TAGS)

play.cgi: update.cpp sqltdb.o infoFromHub.o randStrHash.o common.o
	$(CC) -std=c++11 -o $(DIR)play.cgi play.cpp sqltdb.o infoFromHub.o randStrHash.o common.o -lsqlite3 $(TAGS)
	
#	g++ -std=c++11 BSPHist.cpp -o BSPHist.cgi sqltdb.o infoFromHub.o  -lsqlite3

# Clean
clean:
	rm -f *.o
	
# Base modules
	
sqltdb.o: libs/sqltdb.cpp
	$(CC) -c libs/sqltdb.cpp -lsqlite3
	
infoFromHub.o: libs/infoFromHub.cpp
	$(CC) -c libs/infoFromHub.cpp
