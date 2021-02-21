#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;
void PushBack(vector<int> *);


int main(int argc, char** argv) {
	vector<int> numbers(0);
	cout << "Vector size : "<< numbers.size()<<"\nVector capacity : " << numbers.capacity() <<"\n\n===\n"<< endl;
	
	// Initializing x
	int x = 0;
	
	auto startFull = chrono::high_resolution_clock::now();
	
	for(int i = 0; i < 100; i++){
		auto startOne = chrono::high_resolution_clock::now();
		PushBack(&numbers);
		auto stopOne = chrono::high_resolution_clock::now();
		
		auto durationOne = chrono::duration_cast<chrono::nanoseconds>(stopOne - startOne);	
		cout << "For iteration " << i << " : " << durationOne.count() << "ns" << endl; 
	}
	
	auto stopFull = chrono::high_resolution_clock::now();
	
	auto durationFull = chrono::duration_cast<chrono::nanoseconds>(stopFull - startFull);
	
	cout << "\n-----\n\nFull execution time \n\n\tNanoseconds : " << durationFull.count() << "ns\n\tSeconds: "<<durationFull.count() / 1000000000.0 << "s"<< endl;
	cout << "\n===\n\nVector size : "<< numbers.size()<<"\nVector capacity : " << numbers.capacity() << endl;
	return 0;
}

void PushBack(vector<int> * list){
	for(int i = 0; i<100; i++){
		srand(time(NULL));
		int x = rand() % 10 + 1;
		list->push_back(x);
	}
}
