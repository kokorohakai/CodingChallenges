/*
	Let's first understand prime numbers and make a few assessments here:
	- Prime numbers, except for 2, are all odd.
	- Odd numbers, can only ever have odd products. e.g. 9 = 3x3, all numbers are odd numbers.
	- Prime numbers are only divisible by 1 and itself.
	The first thing we need to do is calculate the prime numbers.
	I honestly couldn't think of a quick way to do this other than trying each number. 
	The honest quickest way, would be to have a precalculated look up array:

	int primes[10] = {2,3,5,7,11,13,17,19,23,29};

	But I figured for this example, you want me to calculate them. So I have written 
	a method below that generates those for me.
*/
var PrimeTable = function(){
	/****************************************************************************
		Public:
			This is how I do private variables and methods in Javascript.<3
	****************************************************************************/
	this.unitTests = function(){
		console.log("Unit Tests:");
		//let's calculate 20 for the unit test.
		var primes = getPrimes(20);
		/*
			Let me explain as to why I'm assigning this.
			If you assign it now to a single variable, it prevents it from calling size
			and then calculating the size of the vector, each time it's called.
			So for the sake of effeciency, it's better to just assign it to an int.
		*/
		size = primes.length;

		//Now for some unit testing, to see if we got the correct results.
		console.log("Is this vector correct? (" + size + ")");
		
		outText = " : ";					
		for ( var i = 0; i < size; i++ ){
			outText += primes[i] + " : ";
		}
		console.log(outText);
		console.log("\n\n");
		/*
			But now let's unit test our Integer count method.
		*/
		var prod = primes[size-1]*primes[size-1];
		mwidth = CountIntegersInNumber(prod);
		console.log("Did it detect the right width? " + prod + " = " + mwidth );
		/* 
			and voila, the unit test should show that the prime calculator works. XD
			Now let's do the actual value needed.
		*/
		console.log("\n\n");
	}
	this.draw = function(){
		//get our calculations:
		primes = getPrimes(nop);
		size = primes.length;//come to think of it, this should always be the same as nop.
		mwidth = CountIntegersInNumber(primes[size-1]*primes[size-1]);

		//print our table:
		console.log("Our Multiplication Table:");
		drawSpacer();//draw a spacer to start with
		drawHeader();//Then draw the header
		for ( var i = 0; i < size; i++){
			drawSpacer();//put a spacer between each row
			drawRow(primes[i]);//then draw out each row
		}
		drawSpacer();//and finally one last spacer to make it look pretty.
		console.log("\n\n");
	}
	/****************************************************************************
		Private:
			This is how I do private variables and methods in Javascript.<3
	****************************************************************************/
	var primes = new Array(); //the vector in which our primes will be stored.
	var mwidth; //the largest width of an integer visually.
	var size; //the number of prime numbers we are working with.
	var nop; //The number of prime numbers we want to work with.
	var outText; //a general string used for outputing text in bulk, so console.log doesn't split it apart.

	function getPrimes( n ){
		var output = new Array();
		var c = 1; //c for cursor.
		var p = 3; //p for the current integer to be tested as prime.
		if (n<1){
			return output;
		}
		//we assign 2, because it's the only even number of the bunch.
		output.push(2);
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
			var isprime = true;
			for (var i = 3; i < p; i+=2 ){
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
				output.push(p);
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

	function CountIntegersInNumber( n ){
		/*
			Let's determine how many physical integers are in a number, so we can determine how it's
			going to draw on the screen. :3

			Javascript note: Javascript is a bit different than C++ since a string has a way to
			pull length, and it's very easy to convert to a string. So this may not be necessary.

			It is especially not necessary, if we were to use an HTML table, or divs.
			But then it would also be possible to get the width of the generated text, which is a whole
			other issue in rendering.
		*/
		return String(n).length;
	}


	/*
		Drawing Methods for the table:
	*/
	function drawSpacer(){
		/*
			The spacer.
			This is of course the thing that makes it a table. lol.
			You'll notice it's "size+1" so it can draw the row header.
		*/
		outText = "";
		for (var i = 0; i < size + 1; i++ ){
			outText += "|";
			for (var j = 0; j < mwidth; j++){
				outText += "-";
			}
		}
		outText += "|";
		console.log(outText);
	}
	function drawHeader(){
		/*
			This draws the prime numbers in the first row of the table.
		*/
		outText = "|";
		for ( var i = 0; i < mwidth; i++){
			outText += " ";
		}
		outText += "|";
		for ( var i = 0; i < size; i++ ){
			outText += drawNumber(primes[i]);
			outText += "|";
		}
		console.log(outText);
	}
	function drawRow(p){
		/*
			For drawing each row of the table, we take the current rows prime integer in.
			Then we do the calculations and output.
		*/
		//Then draw the row header:
		outText = "|";
		outText += drawNumber(p);
		outText += "|";
		//and now we draw each calculation:
		for ( var i = 0; i < size; i++ ){
			var product = primes[i]*p;
			outText += drawNumber(product);
			outText += "|";
		}
		//end
		console.log(outText);
	}
	function drawNumber(n){
		/*
			Calculate and draw the number of spaces required to fill the gap
			between the length of an integer and mwidth and then
			the number.
		*/
		var output = "";
		var s = CountIntegersInNumber(n);
		for (var i = 0; i < mwidth - s; i++ ){
			output+= " ";
		}
		output+= n;
		return output;
	}
	/****************************************************************************
		Constructor:
			Here to keep it clean, I call an annonymouse function.
			A method that is run on the creation of the "class". 
			Which... of course is not really a class.
	****************************************************************************/
	(function (){
		/*
			nop = number of primes, the number of primes you want to generate
			feel free to adjust this to play around with scalability of the table.
		*/
		nop = 10;
		//The following of course, should not be changed, they are just making
		//sure our data is initialized.
		mwidth = 0;
		size = 0;
		outText = "";
	})();
}

var pt = new PrimeTable();
pt.unitTests();
pt.draw();
