CXX = g++
CXXFLAGS = -Wall

driver.out: HashedSplays.o SplayTree.h Util.o Node.o driver.o
	$(CXX) $(CXXFLAGS) Node.o HashedSplays.o Util.o driver.o -o driver.out

Node.o: Node.h Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

Util.o: Util.h Util.cpp
	$(CXX) $(CXXFLAGS) -c Util.cpp

HashedSplays.o: HashedSplays.h HashedSplays.cpp SplayTree.h Util.o Exceptions.h
	$(CXX) $(CXXFLAGS) -c HashedSplays.cpp

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

run:
	./driver.out $(DATA)

# Comment: an overly simplistic, but quick way to check overall runtime 
runtime:
	/usr/bin/time -p ./driver.out $(DATA)

clean:
	rm -rf *.o
	rm -f driver.out
	rm -f *~ *#
	rm -f vgcor*

val:
	valgrind --leak-check=full ./driver.out $(DATA)
