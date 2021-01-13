CXX = g++
CXXFLAGS = -Wall

Driver.out: BinarySearchTree.h Word.o dsexceptions.h Exceptions.h Indexer.o Driver.cpp
	$(CXX) $(CXXFLAGS) BinarySearchTree.h Word.o dsexceptions.h Exceptions.h
		Indexer.o Driver.cpp -o Driver.out

Word.o: Word.h Word.cpp 
	$(CXX) $(CXXFLAGS) -c Word.cpp

Indexer.o: Indexer.h Indexer.cpp Word.o BinarySearchTree.h
	$(CXX) $(CXXFLAGS) -c Indexer.cpp

Driver.o: Driver.cpp Indexer.o Word.o Exceptions.h
	$(CXX) $(CXXFLAGS) -c Driver.cpp

run:
	./Driver.out

clean:
	rm *.o*
	rm *~

val:
	valgrind Driver.out

