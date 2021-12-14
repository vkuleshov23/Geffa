#ifndef _GEFFA_
#define _GEFFA_

#include "LFSR.h"
#include <cmath>

class Geffa {
private:
	LFSR lfsr1;	
	LFSR lfsr2;	
	LFSR lfsr3;
	unsigned int NUMBER = 0b000000001;

public:
	Geffa(unsigned int polynom1, unsigned int polynom2, unsigned int polynom3) {
		this->lfsr1.setPolynom(polynom1);
		this->lfsr2.setPolynom(polynom2);
		this->lfsr3.setPolynom(polynom3);
	}

	unsigned int shift() {
		unsigned int a1 = this->lfsr1.shift();
		unsigned int a2 = this->lfsr2.shift();
		unsigned int a3 = this->lfsr3.shift();
		this->NUMBER = ((a1 & a2) | (~a1 & a3));
		return this->NUMBER;
	}

	void printBin() {
		for(int i = 0; i < 18; i++) {
			std::cout << (this->NUMBER & (int(pow(2, 16))>>i)?'1':'0');
		}
		std::cout << '\n';
		
		// for(int i = 0; i < 9; i++) {
		// 	std::cout << (this->POLYNOM & (256>>i)?'1':'0');
		// } std::cout << '\n';
		// std::cout << " : " << this->POLYNOM << '\n';
	}
	void print() {
		std::cout << this->NUMBER << '\n';
	}
	~Geffa() {}
};

#endif