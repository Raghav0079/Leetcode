/*Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
// Definition for a QuadTree node.
struct Node {
    bool val;
    bool isLeaf;
    struct Node* topLeft;
    struct Node* topRight;
    struct Node* bottomLeft;
    struct Node* bottomRight;
};
struct Node* construct(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || gridColSize[0] == 0) return NULL;

    // Helper function to check if all values in the sub-grid are the same
    bool isUniform(int** grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        int firstValue = grid[rowStart][colStart];
        for (int i = rowStart; i < rowEnd; i++) {
            for (int j = colStart; j < colEnd; j++) {
                if (grid[i][j] != firstValue) {
                    return false;
                }
            }
        }
        return true;
    }

    // Recursive function to construct the Quad-Tree
    struct Node* buildTree(int** grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (isUniform(grid, rowStart, rowEnd, colStart, colEnd)) {
            struct Node* leafNode = (struct Node*)malloc(sizeof(struct Node));
            leafNode->val = grid[rowStart][colStart] == 1;
            leafNode->isLeaf = true;
            leafNode->topLeft = NULL;
            leafNode->topRight = NULL;
            leafNode->bottomLeft = NULL;
            leafNode->bottomRight = NULL;
            return leafNode;
        }

        struct Node* internalNode = (struct Node*)malloc(sizeof(struct Node));
        internalNode->isLeaf = false;

        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;

        internalNode->topLeft = buildTree(grid, rowStart, midRow, colStart, midCol);
        internalNode->topRight = buildTree(grid, rowStart, midRow, midCol, colEnd);
        internalNode->bottomLeft = buildTree(grid, midRow, rowEnd, colStart, midCol);
        internalNode->bottomRight = buildTree(grid, midRow, rowEnd, midCol, colEnd);

        return internalNode;
    }

    return buildTree(grid, 0, gridSize, 0, gridColSize[0]);
}
