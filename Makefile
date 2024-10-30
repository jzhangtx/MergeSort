MergeSort: MergeSort.o
	g++ -g -o MergeSort.exe MergeSort.o -pthread    

MergeSort.o: MergeSort/MergeSort.cpp
	g++ -g  -c -pthread MergeSort/MergeSort.cpp
