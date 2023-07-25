#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to search for a key in the binary search tree
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum value in the binary search tree
Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL) {
        return root;
    }

    return findMin(root->left);
}

// Function to delete a node from the binary search tree
Node* delete(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // Case 1: No child or one child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Function to traverse the binary search tree in-order (left-root-right)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    int key = 30;
    Node* searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Key %d found in the binary search tree.\n", key);
    } else {
        printf("Key %d not found in the binary search tree.\n", key);
    }

    key = 55;
    searchResult = search(root, key);
    if (searchResult != NULL) {
        printf("Key %d found in the binary search tree.\n", key);
    } else {
        printf("Key %d not found in the binary search tree.\n", key);
    }

    root = delete(root, 40);
    printf("In-order traversal after deleting 40: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
