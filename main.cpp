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
	
	Geffa a(0b10000000000010000, 0b1000000000010110, 0b100000000000010011);
	// a.print();
	// int N = int(pow(2, 9) -1);
	int N = 30;
	vector<int> mass;

	for(int i = 0; i < 5000; i++){
		a.shift();
	}

	for(int i = 0; i < N; i++) {
		mass.push_back(a.shift());
		// a.print();
		// a.printBin();
		// cout << ' ';
	}
	// cout << '\n';
	// int count = 0;
	// for(int i = 0; i < N; i++) {
	// 	for(int j = 0; j < N; j++) {
	// 		if(i != j){
	// 			if(mass[i] == mass[j]){
	// 				count++;
	// 			}
	// 		}
	// 	}
	// }
	// cout << "--" << count/2 << "--" << '\n';

	Frequency::test(mass, 17);
	Series::test(mass, 17);
	Poker::test(mass,17, 3);
	Autocor::test(mass, 17);
}