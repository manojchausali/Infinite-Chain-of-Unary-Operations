# Infinite-Chain-of-Unary-Operations
Solution for a problem given in an assignment for subject Operating Systems Principles by IIT Kanpur emaster's degree
 In this question, you need to write three c programs defined in Part1/square.c, Part1/double.c
 and Part1/root.c which perform square, double and square root operations respectively on
 a non-negative integer such that generated executables with these programs can be chained in
 any pattern.
 The order of the operations in the chained pattern would be from left to right. The program
 also takes operation offset as an argument; a non-negative integer offset decides which oper
ation to perform first in left to right order, then completes the chain of operations.
 In the left to right order, the first operation is at offset 0, second operation is at offset 1, third
 operation is at offset 2, and so on. The value of offset is always less than the total operations
 specified.
 Synopsis
 $ ./double root double root square integer_number operation_offset
 Example 1
 $ ./root square double 4 0
 8
 Since, the order of the operations in the chained pattern is from left to right and offset is 0.
 Hence, the chained pattern should be viewed as, starting with square:
 double(square(root(4))) = 8
 Example 2
 $ ./square root double root 8 2
 4
 The order of the operations in the chained pattern is from left to right and offset is 2. Hence,
 the chained pattern should be viewed as, starting with double:
 root(square(root(double(8)))) = 4
 Example 3
 $ ./square root double 4 1
 16
 The order of the operations in the chained pattern is from left to right and offset is 1. Hence,
 the chained pattern should be viewed as, starting with root:
 square(double(root(4))) = 16
 Output
 Print the final result only (as shown in the example).
 Note
 • At least 1 unary operation and utmost 100 unary operations will be specified during
 testing.
 • If your implementation results in parent-child relationship between processes, then parent
 process must wait for its child process to exit.
 • You can assume that the result of operations will always fit in unsigned long long data
 type.
 • If square root of number is a fraction then round off the result to the nearest integer, e.g.
 2.5 should be rounded to 3 and 2.4 should be rounded to 2. This needs to be done every
 time square root is performed. For example: Answer for chain of operations done below
 will be 8.
 ./root square root square root square double 3 0
 Error handling
 In case of any error print “UNABLE TO EXECUTE” as output.
 System calls and library functions
 You must only use the below mentioned APIs to implement this question.- fork- exec* family- str* family- ato* family- printf, sprintf- round
 Testing
 Run the script Part1/run- malloc- free- exit- wait/ waitpid- sqrt
 tests.sh for running the provided sample test cases which contains
 3 test cases. A sample output after running the script would be:
 Test 1 is Passed
 Test 2 is Passed
 Test 3 is Passed
