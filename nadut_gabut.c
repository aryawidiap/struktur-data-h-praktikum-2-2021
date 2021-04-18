/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

int sumParent (BSTNode *root){
    int sum = root->key;
    if(root->left != NULL){
        sum += root->left->key;
    }
    if(root->right != NULL){
        sum += root->right->key;
    }
    return sum;
}

int sumBranchRight (BSTNode *root, BSTNode *branch){
    return root->key + branch->key + branch->right->key;
}

int sumBranchLeft (BSTNode *root, BSTNode *branch){
    return root->key + branch->key + branch->left->key;
}

bool __findSum (BSTNode *root, int query){

    bool check = false;

    if(root->left != NULL && root->right != NULL){
        if (sumParent(root) == query){
            return true;
        }
    }

    if(root->right != NULL){

        if(root->right->right != NULL){
            if (sumBranchRight(root, root->right) == query){
                return true;
            }
        }

        if(root->right->left != NULL){
            if (sumBranchLeft(root, root->right) == query){
                return true;
            }
        }  
        
    } 
    
    if(root->left != NULL){
        
        if(root->left->right != NULL){
            if (sumBranchRight(root, root->left) == query){
                return true;
            }
        }

        if(root->left->left != NULL){
            if (sumBranchLeft(root, root->left) == query){
                return true;
            }
        }
   
    }

    
    //sum = root->key + root->left->key + root->right->key;

    if(root->left != NULL){
        check = __findSum (root->left, query);
        if(check) 
            return true;
    }

    if(root->right != NULL){
        check = __findSum (root->right, query);
        if(check) 
            return true;
    }
    
    return false;
}

bool findSum (BST *tree, int query){
    return __findSum(tree->_root, query);
}
 
int main()
{
    BST set;
    bst_init(&set);
    int P, N;

    scanf("%d", &P);
    for(int i=0; i<P; i++){
        int Q;
        scanf("%d", &Q);
        bst_insert(&set, Q);
    }
    scanf("%d", &N);
    bool check = findSum(&set, N);
    if (check){
        printf("Penjumlahan angka di tree yang menghasilkan %d ditemukan", N);
    } else {
        printf("Tidak ditemukan penjumlahan angka di tree yang menghasilkan %d", N);
    }
    
    return 0;
}