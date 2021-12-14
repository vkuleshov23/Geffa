#include <iostream>
#include <vector>
#include "Geffa.h"
#include "frequency.h"
#include "series.h"
#include "poker.h"
#include "autocor.h"
#include <cmath>

using namespace std;

int main() {
	
	Geffa a(0b10000000000010000, 0b10000000000100000, 0b10000000000000100);
	// a.print();
	// int N = int(pow(2, 8) -1);
	int N = 300;
	vector<int> mass;

	for(int i = 0; i < N; i++) {
		mass.push_back(a.shift());
		// a.print();
		// a.printBin();
		// cout << ' ';
	}
	cout << '\n';
	int count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i != j){
				if(mass[i] == mass[j]){
					count++;
				}
			}
		}
	}
	cout << "--" << count/2 << "--" << '\n';

	Frequency::test(mass, 9);
	Series::test(mass, 9);
	Poker::test(mass,9, 3);
	Autocor::test(mass, 9, 10);
}