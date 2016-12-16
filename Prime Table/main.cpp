#include <iostream>
using namespace std;
#include <vector>
/*
	Let's first understand prime numbers and make a few assessments here:
	- Prime numbers, except for 2, are all odd.
	- Odd numbers, can only ever have odd products. e.g. 9 = 3x3, all numbers are odd numbers.
	- Prim numbers are only divisible by 1 and itself.
	The first thing we need to do is calculate the prime numbers.
	I honestly couldn't think of a quick way to do this other than trying each number. 
	The honest quickest way, would be to have a precalculated look up array:

	int primes[10] = {2,3,5,7,11,13,17,19,23,29};

	But I figured for this example, you want me to calculate them. So I have written 
	a method above that generates those for me.
*/
class PrimeTable {
	public:
		/****************
			vars:
		****************/
		vector <int>primes; //the vector in which our primes will be stored.
		int mwidth; //the largest width of an integer visually.
		int size; //the number of prime numbers we are working with.
		int nop; //The number of prime numbers we want to work with.

		/****************
			methods:
		****************/
		PrimeTable(){
			/*
				nop = number of primes, the number of primes you want to generate
				feel free to adjust this to play around with scalability of the table.
			*/
			nop = 10;
			//The following of course, should not be changed, they are just making
			//sure our data is initialized.
			mwidth = 0;
			size = 0;
		}
	private:
		/*
		The vector data structure is used here. Simply because we need a dynamic array.
		Since the prime numbers can vary. If we weren't using a dynamic array, a standard
		array would work best. We can assume with a vector array, that the look up shall 
		be almost as efficiant as an array look up, just with the added method call, but
		that the assignment to the array will be slow. Due to the class having to create
		a new array and copy the old array.
		*/
		vector <int> getPrimes(int n){
			vector <int>output;
			int c = 1; //c for cursor.
			int p = 3; //p for the current integer to be tested as prime.
			if (n<1){
				return output;
			}
			//we assign 2, because it's the only even number of the bunch.
			output.push_back(2);
			if (n==1){
				return output;
			}
			while( c < n ){
				/*
					since we know the only two numbers a prime should be divisible by
					are 1 and itself, we can skip those two numbers entirely.
					Since we also know that only odd numbers can be divisible by odd numbers
					we can skip even numbers here too.
				*/
				bool isprime = true;
				for (int i = 3; i < p; i+=2 ){
					/*
						good old operand. If there's ever no remainder, then the number
						is clearly not prime.
					*/
					if ( p % i == 0 ){ 
						isprime = false;
						break;//why continue to loop, if we failed? Might as well stop here.
					}
				}
				/*
					And then if it's prime, push our number to the vector (or stack, 
					if you would) and increment the count by 1.
				*/
				if (isprime){
					output.push_back(p);
					c++;
				}
				/*
					Since we know no even numbers are ever prime, we can skip by 
					two here. to speed the process up by n/2.
					Or I guess, it's T/2.
				*/
				p+=2;
			}
			return output;
		}

		int CountIntegersInNumber(int n){
			/*
				Let's determine how many physical integers are in a number, so we can determine how it's
				going to draw on the screen. :3
			*/
			int i = 0;
			while (n != 0){
				i++;
				n = n/10;
			}
			return i;
		}

		//The Table Drawing Methods:
		void drawSpacer(){
			/*
				The spacer.
				This is of course the thing that makes it a table. lol.
				You'll notice it's "size+1" so it can draw the row header.
			*/
			for (int i = 0; i < size + 1; i++ ){
				cout << "|";
				for (int j = 0; j < mwidth; j++){
					cout << "-";
				}
			}
			cout << "|" << endl;
		}
		void drawHeader(){
			/*
				This draws the prime numbers in the first row of the table.
			*/
			cout << "|";
			for ( int i = 0; i < mwidth; i++){
				cout << " ";
			}
			cout << "|";
			for ( int i = 0; i < size; i++ ){
				drawNumber(primes[i]);
				cout << "|";
			}
			cout << endl;
		}
		void drawRow(int p){
			/*
				For drawing each row of the table, we take the current rows prime integer in.
				Then we do the calculations and output.
			*/
			//Then draw the row header:
			cout << "|";
			drawNumber(p);
			cout << "|";
			//and now we draw each calculation:
			for ( int i = 0; i < size; i++ ){
				int product = primes[i]*p;
				drawNumber(product);
				cout << "|";
			}
			//end
			cout << endl;
		}
		void drawNumber(int n){
			/*
				Calculate and draw the number of spaces required to fill the gap
				between the length of an integer and mwidth and then
				the number.
			*/
			int s = CountIntegersInNumber(n);
			for (int i = 0; i < mwidth - s; i++ ){
				cout << " ";
			}
			cout << n;
		}
	public:
		void unitTests(){
			cout << "Unit Tests:" << endl;
			//let's calculate 20 for the unit test.
			vector <int>primes = getPrimes(20);
			/*
				Let me explain as to why I'm assigning this.
				If you assign it now to a single variable, it prevents it from calling size
				and then calculating the size of the vector, each time it's called.
				So for the sake of effeciency, it's better to just assign it to an int.
			*/
			size = primes.size();

			//Now for some unit testing, to see if we got the correct results.
			cout << "Is this vector correct? (" << size << ") " << endl << " : ";
			for ( int i = 0; i < size; i++ ){
				cout << primes[i] << " : ";
			}
			cout << endl << endl;
			/*
				But now let's unit test our Integer count method.
			*/
			int prod = primes[size-1]*primes[size-1];
			mwidth = CountIntegersInNumber(prod);
			cout << "Did it detect the right width? " << prod << " = " << mwidth << endl;
			/* 
				and voila, the unit test should show that the prime calculator works. XD
				Now let's do the actual value needed.
			*/
			cout << endl << endl;
		}
		/*
			Draw our prime table!
		*/
		void draw(){
			//get our calculations:
			primes = getPrimes(nop);
			size = primes.size();//come to think of it, this should always be the same as nop.
			mwidth = CountIntegersInNumber(primes[size-1]*primes[size-1]);

			//print our table:
			cout << "Our Multiplication Table:" << endl;
			drawSpacer();//draw a spacer to start with
			drawHeader();//Then draw the header
			for ( int i = 0; i < size; i++){
				drawSpacer();//put a spacer between each row
				drawRow(primes[i]);//then draw out each row
			}
			drawSpacer();//and finally one last spacer to make it look pretty.
			cout << endl << endl;
		}
};

int main( int argc, char *argv[] ){
	PrimeTable pt;

	//calling my unit tests just to make sure data we calculated is correct. XD
	pt.unitTests();
	//and then drawing my table. XD
	pt.draw();
}
