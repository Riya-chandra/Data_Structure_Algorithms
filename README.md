﻿# Data_Structure_Algorithms

Its just a sample of love that I had for DSA
These are the important 15 patterns that would faster the process of youer learning


<h1>1. Prefix Sum</h1>
Prefix Sum involves preprocessing an array to create a new array where each element at index i represents the sum of the array from the start up to i. This allows for efficient sum queries on subarrays.

Use this pattern when you need to perform multiple sum queries on a subarray or need to calculate cumulative sums.

<h1>2. Two Pointers</h1>
The Two Pointers pattern involves using two pointers to iterate through an array or list, often used to find pairs or elements that meet specific criteria.

Use this pattern when dealing with sorted arrays or lists where you need to find pairs that satisfy a specific condition. 
 
2.1. Left & Right Pointer (Approaching from both ends of Array)

2.2. Slow & Fast Pointers
Using two pointers with different speed of movement. Typically they starts from the left end, then the first pointer advances fast and give some feedback to the slow pointer and do some calculation.

2.3. Merging 2 Arrays | Running from beginning of 2 Arrays
Given 2 arrays or lists, then you have to process them with individual pointers.

2.4. Divide & Conquer | Split & Merge of Array
Divide & conquer is similar to Split & Merge but there is one thing added. First, you need to split the given list into 2 separate lists and then do two pointers approach to merge or unify them. There aren’t many problems.


<h1>3. Sliding Window</h1>
Sliding Window pattern is used to find a sub-array or sub-string that satisfies a specific condition, optimizing the time complexity by maintaining a window of elements.

Use this pattern when dealing with problems involving contiguous sub-arrays or sub-strings.

<h1>4. Fast & Slow Pointers</h1>
The Fast & Slow Pointers (Tortoise and Hare) pattern is used to detect cycles in linked lists and other similar structures.

<h1>5. LinkedList In-place Reversal</h1>
In-place Reversal of a LinkedList pattern reverses parts of a linked list without using extra space.

Use this pattern when you need to reverse sections of a linked list.

<h1>6. Monotonic Stack</h1>
The Monotonic Stack pattern uses a stack to maintain a sequence of elements in a specific order (increasing or decreasing).

Use this pattern for problems that require finding the next greater or smaller element.

<h1>7. Top ‘K’ Elements</h1>
The Top ‘K’ Elements pattern finds the top k largest or smallest elements in an array or stream of data using heaps or sorting.

<h1>8. Overlapping Intervals</h1>
Overlapping Intervals pattern is used to merge or handle overlapping intervals in an array.

In an interval array sorted by start time, two intervals [a, b] and [c, d] overlap if b >= c (i.e., the end time of the first interval is greater than or equal to the start time of the second interval).


<h1>9. Modified Binary Search</h1>
Modified Binary Search pattern adapts binary search to solve a wider range of problems, such as finding elements in rotated sorted arrays.

Use this pattern for problems involving sorted or rotated arrays where you need to find a specific element.

<h1>10. Binary Tree Traversal</h1>
Binary Tree Traversal involves visiting all the nodes in a binary tree in a specific order.

PreOrder: root -> left -> right
InOrder: left -> root -> right
PostOrder: left -> right -> root

<h1>11. Depth-First Search (DFS)</h1>
Depth-First Search (DFS) is a traversal technique that explores as far down a branch as possible before backtracking.

Use this pattern for exploring all paths or branches in graphs or trees.

<h1>12. Breadth-First Search (BFS)</h1>
Breadth-First Search (BFS) is a traversal technique that explores nodes level by level in a tree or graph.

Use this pattern for finding the shortest paths in unweighted graphs or level-order traversal in trees.

<h1>13. Matrix Traversal</h1>
Matrix Traversal involves traversing elements in a matrix using different techniques (DFS, BFS, etc.).

Use this pattern for problems involving traversing 2D grids or matrices horizontally, vertically or diagonally.



<h1>14. Backtracking</h1>
Backtracking explores all possible solutions and backtracks when a solution path fails.

Use this pattern when you need to find all (or some) solutions to a problem that satisfies given constraints. For example: combinatorial problems, such as generating permutations, combinations, or subsets.

<h1>15. Dynamic Programming Patterns</h1>
Dynamic Programming (DP) involves breaking down problems into smaller subproblems and solving them using a bottom-up or top-down approach.

Use this pattern for problems with overlapping subproblems and optimal substructure.DP itself has multiple sub-patterns. Some of the most important ones are:

Fibonacci Numbers
0/1 Knapsack
Longest Common Subsequence (LCS)
Longest Increasing Subsequence (LIS)
Subset Sum
Matrix Chain Multiplication
