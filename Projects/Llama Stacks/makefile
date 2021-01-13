CXX = g++
CXXFLAGS = -Wall

Driver.out: LlamaNode.o Llama.o OvCoInt.o Driver.o
	$(CXX) $(CXXFLAGS) Llama.o LlamaNode.o OvCoInt.o Driver.cpp -o Driver.out

Llama.o: Llama.h Llama.cpp LlamaNode.o
	$(CXX) $(CXXFLAGS) -c Llama.cpp

LlamaNode.o: LlamaNode.h LlamaNode.cpp
	$(CXX) $(CXXFLAGS) -c LlamaNode.cpp

OvCoInt.o: OvCoInt.h OvCoInt.cpp
	$(CXX) $(CXXFLAGS) -c OvCoInt.cpp

Driver.o: Driver.cpp
	$(CXX) $(CXXFLAGS) -c Driver.cpp

driver1.o: driver1.cpp
	$(CXX) $(CXXFLAGS) -c driver1.cpp

driver2.o: driver2.cpp
	$(CXX) $(CXXFLAGS) -c driver2.cpp

driver3.o: driver3.cpp
	$(CXX) $(CXXFLAGS) -c driver3.cpp

run:
	./Driver.out

clean:
	rm *.o*
	rm *~

val:
	valgrind Driver.out
