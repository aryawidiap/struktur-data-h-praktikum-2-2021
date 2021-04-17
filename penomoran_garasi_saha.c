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
 * Queue structure
 */
/* Struktur Node */

typedef struct queueNode_t {
    BSTNode data;
    int depth;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, BSTNode value, int depth);
void queue_pop(Queue *queue);
BSTNode queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, BSTNode value, int depth)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->depth = depth;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

BSTNode queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    BSTNode *empty = (BSTNode*) malloc(sizeof(BSTNode));
    empty->key=-1;
    empty->left=empty->right=NULL;
    return *empty;
}

int queue_size(Queue *queue) {
    return queue->_size;
} 
//*****************************//

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

void __bst__inorder(BSTNode *root) { //berurutan
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) { //kiri-kanan-akar
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) { //akar-kiri-kanan
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

void printLevel(Queue *myQ, int level){
    int arr[level];
    arr[0] = myQ->_front->data.key; //root have only 1 member
    queue_pop(myQ);
    int depth = myQ->_front->depth;
    arr[1] = myQ->_front->data.key;
    queue_pop(myQ);
    QueueNode *p = myQ->_front;

    while (!queue_isEmpty(myQ))
    {
        p = myQ->_front;
        if(depth == p->depth){
            //MINIMUM
            if(depth%2 == level%2){
                if(arr[depth-1] > p->data.key){
                    arr[depth-1] = p->data.key;
                }
            }
            //MAXIMUM
            else {
                if(arr[depth-1] < p->data.key){
                    arr[depth-1] = p->data.key;
                }
            }
        } else {
            depth++;
            arr[depth-1] = p->data.key;
        }
        queue_pop(myQ);
    }


    for(int i=level-1; i>=0; i--){
        printf("%d ", arr[i]);
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

//breadth first traversal
void __bst__levelorder(BSTNode *root){
    Queue myQ, nuQ;
    queue_init(&myQ);
    queue_init(&nuQ);
    queue_push(&myQ, *root, 1);
    int level=0;

    while(!queue_isEmpty(&myQ)){
        BSTNode top = queue_front(&myQ);
        queue_push(&nuQ, top, myQ._front->depth);
        if(top.left != NULL){
            queue_push(&myQ, *(top.left), (myQ._front->depth)+1);
        }
        if(top.right != NULL){
            queue_push(&myQ, *(top.right), (myQ._front->depth)+1);
        }
        level=myQ._front->depth;
        queue_pop(&myQ);
    }

    printLevel(&nuQ, level);
}

void bst_levelorder(BST *myTree){
    __bst__levelorder(myTree->_root);
}

/*bst_levelorderreverse(){
    stackpush()
}*/
//path finding in graph!! -> pake bfs
int main()
{
    BST myTree;
    bst_init(&myTree);

    int n, temp;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        bst_insert(&myTree, temp);
    }

    bst_levelorder(&myTree);
    puts("");
    
    return 0;
}