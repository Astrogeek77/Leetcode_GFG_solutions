If you think clearly, you will notice that all the pairs we have form a set.
if (a,b) , (b,c) are in pairs then it means (a,c) can also be swaped (you can notice this using example also).
Now this means that (a,b,c) are connected to each other and hence are in a set.
​
So first create union and find functions to create and use sets (Disjoint set method).
Union all the connected indices.
​
Now, think more, these same set characters can be sorted and
assigned to the values of the sorted indices which are connected
to each other, to solve the problem.
​
Hence create data structure to store the characters and the indices separately.
You can now sort the characters vector but don't need to sort indices vector
because iteraction will give you sorted indices only.
And after this you need to assign the sorted characters to the corresponding indices.