#include <bits/stdc++.h>
using namespace std;
// Define the Node structure
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Class for BST creation from preorder traversal
class Solution
{
public:
    // Function that constructs BST from its preorder traversal.
    Node *create(int pre[], int left, int right)
    {
        if (left > right)
            return NULL;

        // Create a new root node with the current element
        Node *root = newNode(pre[left]);

        // Find the first element greater than the current root (to form the right subtree)
        int f1 = left + 1;
        while (f1 <= right && pre[f1] < pre[left])
        {
            f1++;
        }

        // Recursively create the left and right subtrees
        root->left = create(pre, left + 1, f1 - 1); // Left subtree: elements smaller than root
        root->right = create(pre, f1, right);       // Right subtree: elements greater than root

        return root;
    }

    // Main function to initiate BST creation
    Node *Bst(int pre[], int size)
    {
        return create(pre, 0, size - 1);
    }
};

// Inorder traversal for testing the BST
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function for testing
int main()
{
    Solution solution;

    int pre[] = {10, 5, 1, 7, 40, 50}; // Example preorder input
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = solution.Bst(pre, size);

    printf("Inorder traversal of the BST: ");
    inorder(root);

    return 0;
}
