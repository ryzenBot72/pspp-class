/*Write a program that does the following :
has one large array of size 1024 (or more)
reads a number n from end user, then allocates an array of n character pointers (pointed to by say, p)
then one by one, it reads n lines of input in the large array (upto its size) , but duplicates each string (with exact length) in a new malloced array every time,  and makes the pointer array elements point to it one by one
then the program finds the line with the maximum length and prints it. (you can use strlen())
The data when stored looks like this, and the output of the program will be : i love clang*/
