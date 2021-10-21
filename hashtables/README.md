RUN INSTRUCTIONS:
Type "make" to run the basic hashtable without timing (creates an executable called "hash".
main.cpp is where the generic main function is located, feel free to alter what is considered the "main".

Type "make counting" to create an executable called "counting" which times the code as well as outputs
to an output stream of your choice. It times the code using Hash tables with 3 differents collision 
resolution methods: Linear probing, Quadratic probing and Double Hashing. It also times the code using
a map. Run using "counting <inputfile> <outputfile> <int i> <boolean b>  <int r>".
The int "i" represents the collision resolution method: 0 means linear probing, 1 means quadratic 
probing 2 means double hashing and 3 means using a map. When b = true the debug mode is enabled and the hashtable 
seeding becomes constant. The int "r" stands for the number of repeats the counting program goes through before 
averaging the times to allow for greater accuracy.


Example results of 3 input cases of sizes 250, 2,500 and 30,000 (Shakespear's Hamlet).

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


