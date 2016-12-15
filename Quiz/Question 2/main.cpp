#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int main ( int argc, char **argv ){
	if (argc < 3 ){
		cout << "Usage a.exe <document> <testfile>" << endl;
		return 1;
	}
	
	ifstream handle;	
	string line, file; 

	//open the document
	handle.open(argv[1]);
	if ( handle.is_open() ){
		while(getline(handle, line)){
			file.append(line);
			file.append("\n");
		}
	}

	ifstream handle2;	
	string line2, file2; 

	//open and compress file to a single line space delimited.
	handle2.open(argv[2]);
	if ( handle2.is_open() ){
		while(getline(handle2, line2)){
			file2.append(line2);
			file2.append(" ");
		}
	}

	//split the array up into a usuable data structure.
	vector<string> words;
	int split = file2.find(" "); 
	while (split!=string::npos){
		string t = file2.substr(0,split);
		file2 = file2.substr( split+1 );
		words.push_back(t);
		split = file2.find(" "); 
	}
	
	//now check each word.
	for (int i = 0; i < words.size(); i++ ){
		string tempfile = file;
		int n = 0;
		int split = tempfile.find(words[i]);
		while ( split != string::npos){
			n++;
			tempfile = tempfile.substr( split + words[i].size() );
			split = tempfile.find(words[i]);
		}
		cout << words[i] << " has " << n << endl;
	}
	return 0;
}
