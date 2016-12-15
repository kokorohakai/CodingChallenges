#include <iostream>
using namespace std;
#include <vector>

struct node;

struct node{
	int value;
	void addChild( node &t ){
		if ( t.check( this ) ){//make sure this hasn't already been added to the graph.
			cout << "ERROR: cannot insert, cycle detected." << endl;
			return;
		}
		children.push_back( &t );
	};
	bool check( node *t ){
		if (t == this){
			return true;
		}
		for ( int i = 0; i < children.size(); i++ ){
			if ( children[i]->check(t) ){
				return true;
			}
		}
		return false;
	}
	void print(){
		cout << value << "->";
		for (int i = 0; i < children.size(); i++ ){
			cout << children[i]->value << ", ";
		}
		cout << endl;
	}
	vector <node *> children;
};

int main(int argc, char **argv) {
	node n[6];
	for ( int i = 0; i < 6; i++ ){
		n[i].value = i;
	}

	n[0].addChild(n[0]);//should fail
	n[0].addChild(n[1]);
	n[0].addChild(n[2]);
	n[0].addChild(n[3]);

	n[1].addChild(n[4]);

	n[2].addChild(n[5]);

	n[3].addChild(n[2]);
	n[3].addChild(n[5]);
	n[3].addChild(n[0]);//should also fail.

	n[4].addChild(n[5]);
	
	for (int i = 0; i < 6; i ++ ){
		n[i].print();
	}
	return 0;
}
