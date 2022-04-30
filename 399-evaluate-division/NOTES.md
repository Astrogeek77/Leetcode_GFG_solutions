Intuition for DFS:
Realizing that the question doesn't ask us to explicitly calculate the value of each variable, it becomes apparent that we have to perform some sort of chained multiplication.
​
When performing a chained multplication, it is a noticeable fact that the denominator of the previous term be equal to the numerator of the next term to be multiplied.
​
This provides an idea that only the terms/fractions which have the condition (stated in the previous point) can be multiplied, and hence they must be connected in some fashion to each other, and not connected to terms which can't be reached.
​
Drawing such a graph makes it even clearer that only such terms which have a path between them will yield a result. The result cannot be calculated in other situations.
​
Approach
Construct a directed weighted graph between the terms which have been provided. That is, if the terms A[0] and A[1] are given in the initial list, then add the nodes labelled A[0] and A[1] into the graph. There will be two edges between them, one with weight value[i] and the other with the weight 1/value[i]. Why?
​
Because we are defining weight of the path A --> B representing the fraction A/B. Therefore, to calculate B/A, the weight of the path B-->A must be reciprocal of the former path.
​
Note:
Now, a few things regarding the implementation:
​
Some queries involve variables which our system/graph doesn't store. So it makes sense to directly return -1 in such a case.
​
If both the A[i] and the B[i] term exist, then for calculating their ratio in the case when they are equal, two approaches can be used:
​
a. check for their equality before starting the DFS, and return 1 if they indeed are equal and already present in our graph.
​
b. insert a self loop at each node which is present in the graph with a weight equal to 1.
​
See the following image. Here:
​
x1/x2 = 3
x2/x3 = 5
x4/x1 = 0.25
and so on.