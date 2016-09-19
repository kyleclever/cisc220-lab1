/*
 * collatz.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: kylewang
 */
/* Lab 1   09/15/16
 *
 * YuChen Tang
 * Kyle Wang
 *
 * TA: Leighanne Hsu  lhsu@udel.edu
 *
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// function declarations
int helloword();
int collatz (int num);
int collatzloop();
bool isOrder(int *a, int *b, int *c);
void swap(int &num1, int &num2);
bool is_perfect_num (int test_num);
bool isOrderRefer(int &a, int &b, int &c);
void fillArray(int array[], int size);
void printArray(int array[], int size);
void reverseArray(int array[], int size);
int minOfArray(int *array,int size);
int sumOfArray(int *array, int size, int x);
int sortArray(int *array,int size);

int main() {
/*
 * Call each function and print out each problem
 */
	// Problem 1
	cout << "Problem 1: "<<endl;
	helloword();

	// Problem 2
	cout << "Problem 2: "<<endl;
	string number;
	cout << "Please enter a natural positive number:" << endl;  // asking user input
	cin >> number;
	int num = atoi(number.c_str()); 	// Convert the string to an int
	cout<<"loop time: "<<endl;
	cout<<collatz(num)<<endl;

	// Problem 2b
	collatzloop();

	//Problem 3
	cout << "Problem 3: "<<endl;
	srand(time(NULL)); 	// create seed based on current time
	int x = rand();
	int y = rand();		// random number x, y, z
	int z = rand();
	cout<<x<<" "<<y<<" "<<z<<endl;
	cout<<isOrder(&x, &y, &z)<<endl;

	// sort x, y, z in order
	if (isOrder(&x, &y, &z)==0){
		if(x>y){
			swap(x,y);
		}
		if(x>z){
			swap(x,z);
		}
		if(y>z){
			swap(y,z);
		}
		cout<<x<<" "<<y<<" "<<z<<endl;
	}

	//Problem 4
	cout << "Problem 4: "<<endl;
	for (int test_num =3; test_num<30; test_num++){
		cout << "Test number: " << test_num << endl;
		cout << is_perfect_num (test_num) << "\n"<<endl;  // test if 3-30 if perfect number
	}  // if return 0, false; 1, true.

	//Problem 5
	cout << "Problem 5: "<<endl;
	int x1 = rand();
	int y2 = rand();		// random number x, y, z
	int z3 = rand();
	cout<<x1<<" "<<y2<<" "<<z3<<endl;
	cout<<isOrderRefer(x1, y2, z3)<<endl;
	// put numbers in order
	if (isOrderRefer(x1, y2, z3)==0){
			if(x1>y2){
				swap(x1,y2);
			}
			if(x1>z3){
				swap(x1,z3);
			}
			if(y2>z3){
				swap(y2,z3);
			}
			cout<<x1<<" "<<y2<<" "<<z3<<endl;
		}

	//Problem 6
	cout << "Problem 6: "<<endl;
	int k = rand() % 30 +20;   // random number 20-50
	int array[k];  // initialize pointer with null
	fillArray(&array,k);
	cout << array <<endl;

	//int array[3]={1,2,3};
	//printArray(array, 3);   //Problem 6b testcase

	//Problem 7
	cout << "Problem 7: "<<endl;
	//reverseArray(&x,k);

	//Problem 8
	cout << "Problem 8: "<<endl;
	//find the min value of an array;

	//Problem 9
	cout << "Problem 9: "<<endl;
	//find the sum of an array;

	//Problem 10
	cout << "Problem 10: "<<endl;
	//find the sort an array;
	int X[3]={1,3,2};
	//cout << sortArray(*X[],3)<<endl;

	return 0;
}  // main


int helloword() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

int collatz(int num){
	 int times = 0;

	 // collatz formula
	while (num != 1){
		if (num % 2 == 0 ){
			num = num / 2;
		}
		else{
			num = (3 * num) + 1;}
		times += 1;  //count how many loops
	}return times;
}

int collatzloop(){
	/*
	 * check collatz conjecture between 2 ints
	 *
	 */

	//asking inputs
	int num1;
	cout << "Please enter a first natural positive number:" << endl;
	cin >> num1;

	int num2;
	cout << "Please enter a second natural positive number:" << endl;
	cin >> num2;

	// switch if first int is bigger than second int
	if (num1 > num2) {
		swap(num1,num2);
	}

	// loop over & print result
	for(int a=num1; a<=num2;a++){
		collatz(a);
		cout<<"Value put in:"<<a<<endl;
		cout<<"Count time:"<<collatz(a)<<endl;
		cout<<"Collatz Conjecture is still working\n"<<endl;
	}
	return 0;
}

bool isOrder(int *a, int *b, int *c){
	/*
	 * check if a < b < c
	 */
	return (*a<*b) && (*b<*c);
}
void swap(int &num1, int &num2){
	/*
	 * sort 2 numbers
	 */
		int temp = num1;
		num1 = num2;
		num2 = temp;
	return;
}

int sum_divisors (int test_num, int sum, int divisor){
	/*
	 * check and sum all divisors for a integer
	 */
	// base case
	if (divisor == test_num){
		return sum;
	}

	// recursive case (test_num times)
	if (test_num % divisor){
		return sum_divisors(test_num, sum, (divisor+1));
	}else{
		return sum_divisors(test_num, (sum + divisor), (divisor + 1));  // add divisor
	}
}

bool is_perfect_num (int test_num){
	/*
	 * check if an integer is a perfect number
	 *
	 * initial sum = 0, divisor = 1
	 *
	 */
	if (sum_divisors(test_num, 0 , 1) == test_num){
		return true;
	}
	else{
		return false;
	}
}


bool isOrderRefer(int &a, int &b, int &c){
	/*
	 * check if a < b < c
	 */
	return (&a<&b) && (&b<&c);
}

void fillArray(int *array[], int size){
	/*
	 * fill in array with input size w/ random numbers
	 */

	for (int i = 0; i < size; i++){
		int *array[i] = rand() % 100 - 50;  // random numbers -50 to 50.
	}
	return;
}

void printArray(int array[], int size){
	for (int a=0; a<size;a++){
		cout<<array[a]<<endl;
	}
	return;
}

void reverseArray(int array[], int size){
	int temp;
	for(int a = 0; a< size/2; a++){
		array[a]= temp;
		temp = array[size-a-1];
		array[size-a-1]=array[a];
		array[a]=temp;

	}
	return;
}

int minOfArray(int *array,int size){
	int min = array[0];
	for (int a = 1; a<size;a++){
		if (array[a]<min){
			min = array[a];
		}
	}

	return min;

}

int sumOfArray(int *array, int size, int x){
	int sum = 0;
	if (array[size-1]<x){
		sum = array[size-1];
		}
	return sum + sumOfArray( array, size-1, x);
	}

int sortArray(int *array,int size){
	int temp;
	int count = 0;
	for(int a = 0; a<size; a++){
		for(int b = 1; b<(size-1);b++){
			if (array[a]>array[b]){
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			count +=1;
			}
		}
	}
	return count;
}


int lowFilter(int list, int winSize){






}
