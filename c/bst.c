#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode
{
    int key;
    struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode *newNodeCreate(int value)
{
    struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search for a node with a specific key in the tree
struct BinaryTreeNode *searchNode(struct BinaryTreeNode *root, int target)
{
    if (root == NULL || root->key == target)
    {
        return root;
    }
    if (root->key < target)
    {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the tree
struct BinaryTreeNode *insertNode(struct BinaryTreeNode *node, int value)
{
    if (node == NULL)
    {
        return newNodeCreate(value);
    }
    if (value < node->key)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->key)
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to find the minimum value
struct BinaryTreeNode *findMin(struct BinaryTreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    return root;
}

// Function to delete a node from the tree
struct BinaryTreeNode *deleteNode(struct BinaryTreeNode *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x > root->key)
    {
        root->right = deleteNode(root->right, x);
    }
    else if (x < root->key)
    {
        root->left = deleteNode(root->left, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            struct BinaryTreeNode *temp;
            if (root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else
        {
            struct BinaryTreeNode *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main()
{
    struct BinaryTreeNode *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (searchNode(root, value) != NULL)
            {
                printf("%d found\n", value);
            }
            else
            {
                printf("%d not found\n", value);
            }
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 4:
            printf("In-order Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Pre-order Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 6:
            printf("Post-order Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}