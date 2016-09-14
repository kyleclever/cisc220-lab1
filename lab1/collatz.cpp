/*
 * collatz.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: kylewang
 */
/* Lab 1
 *
 * TA:
 * YuChen Tang
 * Kyle Wang
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int collatz (int num);

int main() {
	string number;
	cout << "Please enter a natural positive number:" << endl;
	cin >> number;
	int num = atoi(number.c_str()); 	// Convert the string to an int

	collatz(num);

	return 0;
}  // main

int collatz(int num){
	int times = 0;

	while (num / 2 != 1){
		if (num % 2 == 0 ){
			num = num / 2;
		}
		else {
			num = num *3 + 1;

		}
		times =+ 1;  //count how many loops
		cout << num << endl;
	}
	return times;
}




