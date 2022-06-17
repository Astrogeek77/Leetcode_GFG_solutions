Time Complexity : O(n), Space Complexity : O(h) [n = number of nodes, h = height of the tree]
​
In this approach we are using recursion in which we are transferring the root of the tree and initial number of cameras (n) i.e. 0 to the function status.
​
The number of cameras are transferred into the status function by reference so it gets updated automatically when a new camera is added to any node. As no node is traversed more than once so the end number of cameras is the answer. So we can use thereturn value of status function for checking the status of the node on which it was performed.
​
In status function the meaning of the return values and functions of steps inside it are mentioned in the code.
​
The status function gets automatically executed when we check status of the root in the minCameraCover function. So we can directly return n.