#include <cstdlib>
#include <iostream>
using namespace std;
#include <vector>

void randPrint( vector<int> arr, int N ){
	cout << "Some random values" << endl;
	if ( N > arr.size() ){
		cout << "N must equal or less than the size of the array";
	}
	for ( int i = 0; i < N; i++ ){
		int j = rand() % arr.size();
		cout << arr[j] << endl;
		arr.erase(arr.begin()+j);
	}
	cout << endl;
}

int main( int argc, char **argv ){
	vector<int> arr;
	for ( int i = 0; i < 100; i++ ){
		arr.push_back(i);
	}

	randPrint( arr, 10 );
	randPrint( arr, 20 );
	randPrint( arr, 100 );
}
