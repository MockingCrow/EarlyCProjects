Program based on the 4 color theorm, takes an input file in the format below.
The numbers at the top go, number of countries, rows, cols, respectively
Each letter is a country and each country must be contigous (diagonals don't count).

6 4 8 
FFFFFFFF                                       
FEEEDDDF                    
FAABBCCF                
FFFFFFFF                               

Color the map using "make" which produces an executable named coloring. Do "./coloring inputfile" to run the program. 
The program will assign colors from 1-4 to satisfy the four color theorm using backtracking.
