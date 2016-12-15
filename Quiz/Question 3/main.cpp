#include <cstdlib>
#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <vector>

bool find( vector<int> used, int j ){
	bool retval = false;
	for ( int i = 0; i < used.size(); i++ ){
		if (used[i] == j ) retval = true;
	}
	return retval;
}

int main( int argc, char **argv ){
	if (argc < 3){
		cout << "usage a <count> <max value>" << endl;
		return 1;
	}

	int M;
	istringstream convert( argv[1] );
	convert >> M;

	int N;
	istringstream convert2( argv[2] );
	convert2 >> N;

	if ( M > N ){
		cout << "The count cannot be greater than the max value." << endl;
	}

	vector<int> used;

	//I realized after beginning question 4, how this should 
	//actually be getting done. But I guess I leave this 
	//this way since it works, it's just brute force.
	for ( int i = 0; i < M; i++ ){
		int j = rand() % N;
		while ( find(used,j) ){
			j = rand() % N;
		}
		used.push_back(j);
		cout << j << endl;
	}

	return 0;
}