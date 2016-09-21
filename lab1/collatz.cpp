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
bool isPerfectNum (int test_num);
bool isOrderRefer(int &a, int &b, int &c);
void fillArray(int *arr, int size);
void printArray(int *arr, int size);
void reverseArray(int *array, int size);
int minOfArray(int *array,int size);
int sumOfArray(int *array, int size);
int sortArray(int *array,int size);
int lowFilter(int *list, int winSize, int length);

int main() {
/*
 * Call/test each function and print out each problem
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
	cout << "Problem 2b: "<<endl;
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
		cout << isPerfectNum (test_num) << "\n"<<endl;  // test if 3-30 if perfect number
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
	int arr[k];  // initialize pointer with null
	fillArray(arr,k);
	cout << "Original Array"<< endl;
	printArray(arr,k);    // test case for 6b

	//Problem 7
	cout << "Problem 7: "<<endl;
	cout << "Reversed Array"<< endl;
	reverseArray(arr,k);
	printArray(arr,k);		// print out reversed array

	//Problem 8
	cout << "Problem 8: "<<endl;
	cout<<minOfArray(arr, k)<<endl; //print out the min of an array

	//Problem 9
	cout << "Problem 9: "<<endl;
	cout << sumOfArray(arr, k)<<endl; //find the sum of an array;

	//Problem 10
	cout << "Problem 10: "<<endl;
	cout << "Count: "<<endl;
	cout<<sortArray(arr,k)<<endl;	//find the sort an array;
	cout << "sorted array"<<endl;
	printArray(arr,k);			//print out sorted array

	//Problem 11
	cout << "Problem 11: "<<endl;
	int arraySize = rand() % 30 +20;  // random number 20-50
	int list[arraySize];
	fillArray(list,arraySize);		  // random array to be trucked
	cout << "Original Array"<<endl;
	printArray(list,arraySize);

	int windowSize = rand() % 4 +3;  // window size (randomly choose 3-7)
	cout << "Window Size: "<<windowSize<<endl;
	lowFilter(list, windowSize, arraySize);	 // truck with windowSize
	cout << "Trucked Array" << endl;
	printArray(list,arraySize);
/*
	//test case example from assignment
	int test[]={3,2,7,0,4,2,1,6,4,2,9,5,4,2,3};
	lowFilter(test, 5, 15);
	printArray(test,15);
*/

	//Problem 12
	cout << "Problem 12: "<<endl;

	return 0;
}  // main

//Problem 1
int helloword() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

//Problem 2
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
//Problem 2b
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

//Problem 3
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

//Problem 4
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

bool isPerfectNum (int test_num){
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

//Problem 5
bool isOrderRefer(int &a, int &b, int &c){
	/*
	 * check if a < b < c
	 */
	return (&a<&b) && (&b<&c);
}

//Problem 6
void fillArray(int *arr, int size){
	/*
	 * fill in array with input size w/ random numbers
	 */
	for (int i = 0; i < size; i++){
		int r = rand() % 100 - 50;  // random numbers -50 to 50.
		arr[i] = r;
	}
	return;
}

//Problem 6b
void printArray(int *arr, int size){
	/*
	 *print out each elements in an array
	 */
	for (int a=0; a<size;a++){
		cout<<arr[a]<<endl;
	}
	return;
}

//Problem 7
void reverseArray(int *array, int size){
	/*
	 * reverse the order of array
	 */
	int temp;
	for(int a = 0; a< size/2; a++){
		temp = array[a];
		array[a] = array[size-a-1];
		array[size-a-1]=temp; //replace last element with first element
	}//for
	return;
}

//Problem 8
int minOfArray(int *array,int size){
	/*
	 * find the minimum value of an array
	 */
	int min = array[0];
	for (int a = 1; a<size;a++){
		if (array[a]<min){
			min = array[a];
		}//if
	}//for
	return min;
}

//Problem 9
int sumOfArray(int *array, int size){
	/*
	 * sum the values in an array
	 */
	if (size == 0){	//base case
		return 0;
	}else{
		return array[size-1]+ sumOfArray(array, size-1); //recursive case (index from 0 to size-1)
	}//if
}

//Problem 10
int sortArray(int *array,int size){
	int temp;
	int count = 0;
	for(int a = 0; a<size; a++){
		for(int b = 0; b<(size-1);b++){
			if (array[a]<array[b]){
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			count +=1;
			}//if
		}//for
	}//for
	return count;
}

//Problem 11
int lowFilter(int *list, int winSize, int length){
	/*
	 * filter array to be more smooth

	    winSize 3, first/last ONE 0; winSize 4, fist/last TWO 0; winSize 5, fist/last TWO 0;
		winSize 6,first/last THREE 0; winSize 7, fist/last THREE 0;
	 */

	int copyList[length]={0};
	//make a copy of original array, so the truncated number wouldn't affect others
	for (int c=0 ; c<length; c++){
		copyList[c] =list [c];
	}

	 //Minimum surrounding numbers
	int s = 0 ;
	if (winSize % 2 == 1){
		s = (winSize - 1)/2;
	}else{
		s = winSize / 2;
	}

	//replacement for even window size
	if (winSize % 2 == 0){
	for (int a = s; a < (length-s-1); a++){
		// Initial sum for each truck
		int sum = 0;
		for (int b = 0 ; b < s; b++){	//base on winSizes
			sum = sum + copyList[a+b]+copyList[a-b]; // split truck in half and add them up
		}//for
		sum = sum - copyList[a] + copyList[a-s];   // subtract the duplicate one and add the first index of that truck.
		list[a] = sum/winSize;			   // compute avg. and replace
	}//for
	}//if

	//replacement for odd window size
	else{
	for (int a = s; a < (length-s-1); a++){
		int sum = 0;
		for (int b = 0 ; b <= s; b++){
			sum = sum + copyList[a+b]+copyList[a-b]; // split truck in half and add them up
		}//for
		sum = sum - copyList[a];
		list[a] = sum/winSize;			   // compute avg. and replace
	}//for
	}//else

	// Note: replace 0 for last step.
	for (int i = 0; i < s; i++){	// replace first and last s elements with 0
		list[i]=0;
		list[length-i-1]=0;
	}//for
	return 0;
}
