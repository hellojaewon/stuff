.DEFAULT:
all: HeapTest.o
	g++ -coverage -o HeapTest HeapTest.o

HeapTest.o: HeapTest.cpp
	g++ -coverage -c HeapTest.cpp

#heap.o: ../src/heap.cpp
#	g++ -coverage -c ../src/heap.cpp

clean:
	rm HeapTest
	rm *.o
	rm *.gcno
	rm *.gcda
