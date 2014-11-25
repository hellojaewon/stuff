.DEFAULT:
all: HeapTest.o heap.o
	g++ -coverage -o HeapTest HeapTest.o heap.o

HeapTest.o: HeapTest.cpp
	g++ -coverage -c HeapTest.cpp

heap.o: ../src/heap.cpp
	g++ -coverage -c ../src/heap.cpp

clean:
	rm HeapTest
	rm *.o
	rm *.gcno
	rm *.gcda
