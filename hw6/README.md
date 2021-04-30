I used 3 input cases of sizes 250, 2,500 and 30,000 (Shakespear's Hamlet).
Used the STL map because my AVL tree was not consistent with big input sizes

Test Case 250
Linear: .0003258s
Quadratic: .0003166s
Double Hash: .00366s
Map: .0000782

Test Case 2500
Linear: .002095s
Quadratic: .002277s
Double Hash: .002869s
Map: .0008802s

Test Case 30,000
Linear: .028904s
Quadratic: .02884s
Double Hash: .034975s
Map: .013243s

I was not suprised that the map outperformed the hashtable in this test because the hash
table needs to reallocate a new array multiple times to store large numbers of words, 
which take a lot of time.
I was however, suprised that the double hash function took slightly longer than linear and quadratic
probing. Looking back it makes sense because an additional funtion has to be called rather than just
+1 or +i^2.


RUN INSTRUCTIONS:
Type "make" to run the basic hashtable without timing (creates an executable called "hash".
main.cpp is where the test code is located, feel free to alter what is considered the "main".

Type "make counting" to create an executable called "counting" which times the code as well as outputs
to an output stream of your choice. Run using ./counting input output x d r
