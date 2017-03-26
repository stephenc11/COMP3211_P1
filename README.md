COMP3211 Fundamentals of Artificial Intelligence
==================================================

Compilation and Execution
--------------------------------------------------

g++ search.cpp -std=c++11 -o search

./search Graphx (where x = 1,2,3,4,5)


Output
--------------------------------------------------

Graph1:
Breadth First Tree Search: S A B B G 
Depth First Tree Search:   S A B C G 

Graph2:
Breadth First Tree Search: S B C A B G 
Depth First Tree Search:   S B A G 

Graph3:
Breadth First Tree Search: S B C A G 
Depth First Tree Search:   S B A G 

Graph4:
Breadth First Tree Search: S A B D D E C G1 
Depth First Tree Search:   S A D C A D C A D C . . . 
Uniform-cost Tree Search:  S A B D C E A F G2 
A* Tree Search:            S A D B G2 
A* Graph Search:           S A D B G2 

Graph5:
Breadth First Tree Search: S A B B C D D G 
Depth First Tree Search:   S A B D G 
Uniform-cost Tree Search:  S B A B D C D G 
A* Tree Search:            S B A D B C G 
A* Graph Search:           S B A D C G 

Implementation
--------------------------------------------------




