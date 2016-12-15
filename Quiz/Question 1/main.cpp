#include <iostream>
using namespace std;
void reverseArray( int arr[], int size ){
	for ( int a = 0; a < size / 2; a++ ){
		int temp = arr[a];
		arr[a] = arr[size-a-1];
		arr[size-a-1] = temp;
	}	
}

int main (int argc, char **argv ){
	//a first test.
	int test[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(test) / sizeof(int);
	reverseArray( test, n );
	for ( int i = 0; i < n; i++ ){
		cout << test[i] << ",";
	}
	cout << endl;

	//a second test.

	int test2[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110 };
	n = sizeof(test2) / sizeof(int);
	reverseArray(test2,n);
	for ( int i = 0; i < n; i++ ){
		cout << test2[i] << ",";
	}
	cout << endl;
	return 0;
}
