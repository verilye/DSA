# Mucking about with DSA

## Things to revise:

Notes: 

BFS vs DFS -
BFS uses QUEUE
DFS uses STACK

Depth First Seach of Binary tree preserves the structure!
O(n) runtime of trees are based on height, best case log(n) worst case n
Inserting into a binary tree is done at the bottom for binary (remember <= or >= the parent)

Deleting for binary search tree:
No children -> delete
1 child -> pass the reference to the parent of the deleted node
when deleting find child that is the largest on the right/smallest on the left and use that to replace deleted node

Max heap and min heap / Also known as priority queues-
All nodes below must be smaller or larger than the focus node and it runs down to the children
Is the parent maxier or minier? No? Swap up until it is
Delete node - swap bottom node with deleted one and swap it with children until appropriate
Children calculation 2i + 1 for left child, 2i +2 for right child
Parent calculation [(i-1)/ 2] with integers (DOES NOT WORK WITH FLOATING POINT NUMBERS BECAUSE NO ROUNDING)

Trie
A trie is basically an autocomplete tree with multiple children. CAR CARB CARBS is parent->child relationship that prints
out a string

Graphs
A graph has vertices and nodes
Acyclic (odd numbered or with dead ends)
Cyclic (can visit all nodes in a sequence) 
Adjacency lists and matricies can be used to represent verticies and edges
Breadth first and Depth first searches still apply on a graph??

Adjacency matrix - 
When finding value through a BFS, using a seen list can be used. Add the current amount of deque'd nodes to the index in the seen array which 
correlates to place where the the node was first seen. Chuck that bad boy in a while loop like this
while(curr!= -1 ){
    curr = prev[curr];
}
And the array will step back to the first node. For example prev[-1,0,0,2,1,1]


Maps - 
consistent hash such that modulo % hash points to the same spot in a list/array/blahblahblah. We store key with value to check hash correct 