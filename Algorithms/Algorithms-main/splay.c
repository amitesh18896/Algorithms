/*******************************************************************************************
 Description: Implementation of "Splay Tree" in C.
 Version: 2.0
 Modifications: Shows each step during splaying.
 In this implementation the following notations have been used:
 x : The node where a given operation is to be performed. An operation is one of
     (i) left rotation, (ii) right rotation, (iii) zig, (iv) zag, (v) zig-zig,
     (vi) zag-zag, (vii) zag-zig, (viii) zig-zag, and (ix) splay.
 y : A child of x. It could be either the left child or the right child.
 p : The parent of x. x could be either the left child or the right child of p.
 g : The parent of p, i.e., the grandparent of x. p could be either the left child
     or the right child of g.
 Ti: This could be T1, T2, T3, and T4. They are binary search trees and are subtrees
     of x, y, p, and g.
 Therefore, the following relationships may hold:
      g       < level i
      |
      p       < level i + 1
      |
      x       < level i + 2
      |
      y       < level i + 3
  Here "|" indicates either "/" (left child) or "\" (right child).
  Moreover, in (i) zig-zig, (ii) zag-zag, (iii) zig-zag, and (iv) zag-zig steps of
  splaying we need to access the parent of g, if any.

  The functions drawTree() and drawTreeHelper() are not parts of splay trees. I have
  modified the code available at
  https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
  to write these two functions. I do not suggest you realize these two functions as
  of now. When you are done with the core concepts (functions) of splay trees,
  you should utilize your time to understand these two functions.

  For further clarification, please contact Kaustuv Nag (kaustuv.nag@gmail.com, 9232682253).
*******************************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <ctype.h>

# define VERBOSE // Comment out this or # undef VERBOSE if you do not want verbose output

typedef struct treenode_t *Tree;

struct treenode_t {
    int key;      // Keys are nonnegative and unique
    Tree left;    // Pointer to left subtree
    Tree right;   // Pointer to right subtree
    Tree parent;  // Pointer to parent
};

Tree newTree(int key, Tree parent) {
    Tree tree = (Tree) calloc(1, sizeof(struct treenode_t));
    tree->key = key;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = parent;
    return tree;
}

/** drawTree() and drawTreeHelper() begin here. */
/** Related to drawTree() and drawTreeHelper(). */
# define COMPACT    // # undef it to get a sparse draw of the trees
# define SIZE1 30   // Increase this value if you have a tree with higher depth
# define SIZE2 1000 // Do not change this value
# define WIDTH 5    // Do not change this value

int drawTreeHelper(Tree tree, int isLeft, int offset, int depth, char s[SIZE1][SIZE2]) {
    char b[SIZE1];
    int width = WIDTH;
    if (!tree) {
        return 0;
    }

    sprintf(b, "(%3d)", tree->key);

    int left  = drawTreeHelper(tree->left,  1, offset,                depth + 1, s);
    int right = drawTreeHelper(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++) {
        s[depth][offset + left + i] = b[i];
    }

    if (depth && isLeft) {
        for (int i = 0; i < width + right; i++) {
            s[depth - 1][offset + left + width/2 + i] = '-';
        }
        s[depth - 1][offset + left + width/2] = '.';
    } else if (depth && !isLeft) {
        for (int i = 0; i < left + width; i++) {
            s[depth - 1][offset - width/2 + i] = '-';
        }
        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++) {
        s[2 * depth][offset + left + i] = b[i];
    }
    if (depth && isLeft) {
        for (int i = 0; i < width + right; i++) {
            s[2 * depth - 1][offset + left + width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';
    } else if (depth && !isLeft) {
        for (int i = 0; i < left + width; i++) {
            s[2 * depth - 1][offset - width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void drawTree(Tree tree) {
    char s[SIZE1][SIZE2];
    for (int i = 0; i < SIZE1; i++) {
        sprintf(s[i], "%80s", " ");
    }
    drawTreeHelper(tree, 0, 0, 0, s);
    int flag = 1;
    for (int i = 0; flag && i < SIZE1; i++) {
        printf("%s\n", s[i]);
        flag = 0;
        for (int j = 0; s[i][j] != '\0'; j++) {
            if (s[i][j] != ' ') {
                flag = 1;
                //printf("d = %c %d\n", s[i], i);
                break;
            }
        }
    }
}
/** drawTree() and drawTreeHelper() end here.*/


/******************************************
        x                        y
       / \     rotateRight(x)   / \
      /   \                    /   \
     y    T3        ===>      T1    x
    / \                            / \
   /   \                          /   \
  T1   T2                        T2   T3
******************************************/
Tree rotateRight(Tree tree) {
    printf("rotateRight(%d)\n", tree->key);
    Tree x = tree;
    Tree y = x->left;
    Tree T2 = y->right;
    // Now rotate right
    y->right = x;
    x->left = T2;
    // Now fix the parents
    Tree t = x->parent;
    x->parent = y;
    y->parent = t;
    if (T2) {
        T2->parent = x;
    }
    return y;
}

/*******************************************
        x                             y
       / \         rotateLeft(x)     / \
      /   \                         /   \
     T1    y           ===>        x    T3
          / \                     / \
         /   \                   /   \
        T2   T3                 T1   T2
*******************************************/
Tree rotateLeft(Tree tree) {
    printf("rotateLeft(%d)\n", tree->key);
    Tree x = tree;
    Tree y = x->right;
    Tree T2 = y->left;
    // Now rotate left
    x->right = T2;
    y->left = x;
    //Now fix the parents
    Tree t = x->parent;
    x->parent = y;
    y->parent = t;
    if (T2) {
        T2->parent = x;
    }
    return y;
}

/** This function inserts a given node in a given binary search tree. */
Tree insertNodeIntoBST(Tree tree, Tree newNode) {
    if (tree == NULL) {
        return newNode;
    } else if (newNode->key < tree->key) { // go left
        printf("BST~insert>> Going left at %d to insert %d\n", tree->key, newNode->key);
        tree->left = insertNodeIntoBST(tree->left, newNode);
        tree->left->parent = tree;
    } else if (newNode->key > tree->key) { // go right
        printf("BST~insert>> Going right at %d to insert %d\n", tree->key, newNode->key);
        tree->right = insertNodeIntoBST(tree->right, newNode);
        tree->right->parent = tree;
    } else { // tree-> == key
        printf("BST~insert>> Duplicate key %d\n", tree->key);
        return tree;
    }
    return tree;
}

/** This function inserts a new node with a given key in a given binary search tree.
    Duplicate keys are ignored. */
Tree insertIntoBST(Tree tree, int key) {
    Tree newNode = newTree(key, NULL);
    if (tree == NULL) {
        return newNode;
    }
    tree = insertNodeIntoBST(tree, newNode);
    if (newNode-> parent == NULL) {
        free(newNode);
    }
    return tree;
}

/** This function returns the key of a given node and returns 0 if the node is NULL. */
static inline int getKey(Tree tree) {
    return tree == NULL ? -1 : tree->key; // assuming keys are nonnegative
}

/** I used this function to VERBOSE the code. Though it is useless now,
    some of you may find it interesting.*/
void _inorder(Tree tree) {
    if (tree == NULL) {
        printf("NIL");
        return;
    }
    printf("{");
    _inorder(tree->left);
    printf(", (%d, p = %d, l = %d, r = %d), ", getKey(tree), getKey(tree->parent),
        getKey(tree->left), getKey(tree->right)
    );
    _inorder(tree->right);
    printf("}");
}

/** Prints the inorder traversal of a given tree. */
void inorder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("%d ", getKey(tree));
    inorder(tree->right);
}

/** Prints the preorder traversal of a given tree. */
void preorder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->key);
    preorder(tree->left);
    preorder(tree->right);
}

/** Prints the postorder traversal of a given tree. */
void postorder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->key);
}


/** given a node of a tree returns the root node of the tree */
Tree getRoot(Tree tree) {
    for (; tree && tree->parent; tree = tree->parent)
        ;
    return tree;
}

/***************************************************************************************/
/** This function implements splaying. This is the most important part of splay trees. */
/***************************************************************************************/
Tree splay(Tree tree) {
    printf("splay(%d)\n", getKey(tree));
    /** The base case, when either tree is NULL or it is the root (the parent is NULL). */
    if (tree == NULL || tree->parent == NULL) {
        return tree;
    }

    Tree x = tree;
    Tree p = x->parent; // parent of x
    Tree g = p->parent; // grandparent of x

    /** Zig:
          p                          x
         / \                        / \
        x   T3   rotateRight(p)    T1  p
       / \       ============>        / \
      T1 T2                          T2 T3
    */
    if (p->left == x && g == NULL) { // Zig begins
        printf("Zig(%d)\n", x->key);
        tree = rotateRight(p);
# ifdef VERBOSE
        drawTree(getRoot(x));
# endif // VERBOSE
        return tree;
    } // Zig ends

    /** Zag:
          p                          x
         / \                        / \
        T1  x      rotateLeft(p)   p  T3
           / \     ============>  / \
          T2 T3                  T1 T2
    */
    else if (p->right == x && g == NULL) { // Zag begins
        printf("Zag(%d)\n", x->key);
        tree = rotateLeft(p);
# ifdef VERBOSE
        drawTree(getRoot(x));
# endif // VERBOSE
        return tree;
    } // Zag ends

    /** Zig-Zig:
           g                        p                           x
          / \                     /   \                        / \
         p  T4   rotateRight(g)  x     g     rotateRight(p)   T1  p
        / \      ============>  / \   / \    ============>       / \
       x  T3                   T1 T2 T3 T4                      T2  g
      / \                                                          / \
     T1 T2                                                        T3 T4
    */
    else if (p->left == x && g->left == p) { // Zig-Zig begins
        printf("Zig-Zig(%d)\n", x->key);
        tree = rotateRight(rotateRight(g));
    } // Zig-Zig ends

    /** Zag-Zag:
       g                          p                           x
      / \                       /   \                        / \
     T1  p     rotateLeft(g)   g     x     rotateLeft(p)    p   T4
        / \    ============>  / \   / \    ============>   / \
       T2  x                 T1 T2 T3 T4                  g   T3
          / \                                            / \
         T3 T4                                          T1 T2
    */
    else if (p->right == x && g->right == p) { // Zag-Zag begins
        printf("Zag-Zag(%d)\n", x->key);
        tree = rotateLeft(rotateLeft(g));
    } // Zag-Zag ends

    /** Zig-Zag:
           g                         g                           x
          / \                       / \                        /   \
         p   T4  rotateLeft(p)     x   T4    rotateRight(g)   p     g
        / \      ============>    / \        ============>   / \   / \
       T1  x                     p  T3                      T1 T2 T3 T4
          / \                   / \
         T2 T3                 T1 T2
    */
    else if (p->right == x && g->left == p) { // Zig-Zag begins
        printf("Zig-Zag(%d)\n", x->key);
        g->left = rotateLeft(p);
        tree = rotateRight(g);
    } //Zig-Zag ends

    /** Zag-Zig:
       g                         g                           x
      / \                       / \                        /   \
     T1  p    rotateRight(p)   T1  x     rotateLeft(g)    g     p
        / \   =============>      / \    ============>   / \   / \
       x  T4                    T2   p                  T1 T2 T3 T4
      / \                           / \
     T2 T3                         T3 T4
    */
    else if (p->left == x && g->right == p) { // Zag-Zig begins
        printf("Zag-Zig(%d)\n", x->key);
        g->right = rotateRight(p);
        tree = rotateLeft(g);
    } // Zag-Zig ends

    /** Connect this subtree with its root, if there is one */
    if (tree->parent) {
        if (tree->parent->left == g) { // if this is the left subtree
            tree->parent->left = tree;
        } else { // if (tree->parent->right == g) // if this is the right subtree
            tree->parent->right = tree;
        }
    }
# ifdef VERBOSE
    drawTree(getRoot(x));
# endif // VERBOSE
    /** Return the modified tree */
    return splay(tree);
}

/** Function to insert a new node in a splay tree. */
# ifdef VERBOSE
Tree insertIntoSplayTree(Tree tree, int key) {
    Tree newNode = newTree(key, NULL);
    if (tree == NULL) {
        tree = insertNodeIntoBST(tree, newNode);
        printf("After inserting %d in binary search tree:\n", key);
        drawTree(tree);
    } else {
        tree = insertNodeIntoBST(tree, newNode);
        printf("After inserting %d in binary search tree (before splaying):\n", key);
        drawTree(tree);
        if (newNode->parent == NULL) {
            free(newNode);
        } else {
            printf("Going for splaying...\n");
            tree = splay(newNode);
        }
        printf("After splaying %d:\n", key);
        drawTree(tree);
    }
    return tree;
}
# else
Tree insertIntoSplayTree(Tree tree, int key) {
    Tree newNode = newTree(key, NULL);
    if (tree == NULL) {
        tree = insertNodeIntoBST(tree, newNode);
    } else {
        tree = insertNodeIntoBST(tree, newNode);
        if (newNode->parent == NULL) {
            free(newNode);
        } else {
            tree = splay(newNode);
        }
    }
    return tree;
}
#endif // VERBOSE


Tree searchInBST(Tree tree, int key) {
    if (tree == NULL) {
        printf("BST~search>> %d is not found\n", key);
        return NULL;
    } else if (tree->key == key) {
        printf("BST~search>> %d is found\n", key);
        return tree;
    }

    if (tree->key > key) {
        printf("BST~search>> Going left at %d to search %d\n", tree->key, key);
        return searchInBST(tree->left, key);
    } else {
        printf("BST~search>> Going right at %d to search %d\n", tree->key, key);
        return searchInBST(tree->right, key);
    }
}

/** This implementation assumes that if a key is found it would be paced at the root
    of the modified tree. If the key is not found, the tree remains unchanged. There
    is another implementation that moves the last accessed node to the root by splaying
    if the key is not found. We, however, do not conceive that concept in this
    implementation. This can be modified and we expect you do the modification by yourself. */
# ifdef VERBOSE
Tree searchInSplayTree(Tree tree, int key) {
    Tree foundTree = searchInBST(tree, key);
    printf("Before Splaying the following tree is found:\n");
    drawTree(foundTree);
    if (foundTree && foundTree->key == key) {
        printf("Going for splaying...\n");
        tree = splay(foundTree);
        printf("After splaying:\n");
        drawTree(tree);
    }
    return tree;
}
# else
Tree searchInSplayTree(Tree tree, int key) {
    Tree foundTree = searchInBST(tree, key);
    if (foundTree && foundTree->key == key) {
        return splay(foundTree);
    }
    return tree;
}
# endif //VERBOSE

/** This function returns the node with the minimum key in a binary search tree. */
Tree findMinTreeInBST(Tree tree) {
    for (; tree && tree->left; tree = tree->left)
        ;
    return tree;
}

/** This function deletes a node with a given key from a given binary search tree. */
Tree deleteFromBST(Tree tree, int key, Tree *pParent) {
    if (tree == NULL) {
        printf("BST~delete>> Key %d is not found\n", key);
        return NULL;
    }
    if (tree->key > key) {
        printf("BST~delete>> Going left at %d to delete %d\n", tree->key, key);
        tree->left = deleteFromBST(tree->left, key, pParent);
    } else if (tree->key < key){
        printf("BST~delete>> Going right at %d to delete %d\n", tree->key, key);
        tree->right = deleteFromBST(tree->right, key, pParent);
    } else { // tree->key == key
        if (tree->left == NULL && tree->right == NULL) {
            printf("BST~delete>> Both the subtrees are NULL at %d\n", tree->key);
            if (pParent != NULL) {
                *pParent = tree->parent;
            }
            free(tree);
            return NULL;
        } else if (tree->left && tree->right == NULL) {
            printf("BST~delete>> The right subtree is NULL at %d\n", tree->key);
            Tree leftTree = tree->left;
            leftTree->parent = tree->parent;
            if (pParent != NULL) {
                *pParent = tree->parent;
            }
            free(tree);
            return leftTree;
        } else if (tree->left == NULL && tree->right) {
            printf("BST~delete>> The left subtree is NULL at %d\n", tree->key);
            Tree rightTree = tree->right;
            rightTree->parent = tree->parent;
            if (pParent != NULL) {
                *pParent = tree->parent;
            }
            free(tree);
            return rightTree;
        } else {
            Tree smallest = findMinTreeInBST(tree->right);
            tree->key = smallest->key;
            if (pParent != NULL) {
                *pParent = tree->parent;
            }
            printf("BST~delete>> Need to delete %d to delete %d\n", smallest->key, key);
            tree->right = deleteFromBST(tree->right, smallest->key, NULL);
            return tree;
        }
    }
}



/** This function deletes a node with a given key from a given splay tree. */
# ifdef VERBOSE
Tree deleteFromSplayTree(Tree tree, int key) {
    Tree parent = NULL;
    printf("Before deletion:\n");
    drawTree(tree);
    tree = deleteFromBST(tree, key, &parent);
    printf("After deletion from binary search tree (before splaying):\n");
    drawTree(tree);
    if (parent) {
        printf("Going for splaying...\n");
        tree = splay(parent);
        printf("After splaying:\n");
        drawTree(tree);
    }
    return tree;
}
# else
Tree deleteFromSplayTree(Tree tree, int key) {
    Tree parent = NULL;
    tree = deleteFromBST(tree, key, &parent);
    if (parent) {
        return splay(parent);
    }
    return tree;
}
# endif


/** The remaining code contains driver and main() and exactly not related to splay trees.
    However, you may get something new to learn here. */
void help() {
    printf("INSERT ABC         Inserts the 3 digit number ABC in a binary search tree and\n"
           "                   a splay tree.\n"
           "DELETE ABC         Deletes the 3 digit number ABC from the binary search tree\n"
           "                   and the splay tree.\n"
           "DRAW BST           Draws the binary search tree.\n"
           "DRAW SPLAY         Draws the splay tree.\n"
           "SEARCH BST ABC     Searches for the 3 digit number ABC in the binary search tree.\n"
           "SEARCH SPLAY ABC   Searches for the 3 digit number ABC in the binary search tree.\n"
           "PREORDER BST       Prints the preorder traversal of the binary search tree.\n"
           "PREORDER SPLAY     Prints the preorder traversal of the splay tree.\n"
           "INORDER BST        Prints the inorder traversal of the binary search tree.\n"
           "INORDER SPLAY      Prints the inorder traversal of the splay tree.\n"
           "POSTORDER BST      Prints the postorder traversal of the binary search tree.\n"
           "POSTORDER SPLAY    Prints the postorder traversal of the splay tree.\n"
           "TEST N             Randomly generates N numbers in the range [0, 2N - 1] and inserts\n"
           "                   them in a splay tree. Then, it randomly generates N numbers in\n"
           "                   the range [0, 2N - 1] and finds them in the splay tree.\n"
           "                   Next, it randomly generates N numbers in the range [0, 2N - 1]\n"
           "                   and attempts to delete them from the splay tree.\n"
           "HELP               Shows this help.\n"
           "EXIT               Exits the program.\n"
    );
}

int compareIgnoreCase(char *pa, char *pb) {
    for (;; pa++, pb++) {
        int difference = toupper((unsigned char)*pa) - toupper((unsigned char)*pb);
        if (difference != 0 || !*pa) {
            return difference;
        }
    }
}

/** This function randomly generates N numbers in the range [0, 2N - 1] and inserts
    them in a splay tree. Then, it randomly generates N numbers in the range [0, 2N - 1]
    and finds them in the splay tree. Next, it randomly generates N numbers in the range
    [0, 2N - 1] and attempts to delete them from the splay tree. */
void test(int n) {
    srand(time(0));
    Tree tree = NULL;
    for (int i = 0; i < n; i++) {
        /** After each insertion, the inserted key becomes the root of the tree.
        This is confirmed as the first element of the preorder traversal is
        always the new (inserted) key. The modified tree is a binary search
        tree as the inorder traversal of the tree is sorted. */
        int key = rand() % (n * 2);
        printf("%d. Inserting %d\n", i + 1, key);
        tree = insertIntoSplayTree(tree, key);
        printf("Preorder: ");
        preorder(tree);
        printf("\n");
        printf("Inorder: ");
        inorder(tree);
        printf("\n\n");
    }
    for (int i = 0; i < n; i++) {
        /** After each search operation, the searched key becomes the root of the tree.
        This is confirmed as the first element of the preorder traversal is always
        the searched key. The modified tree is a binary search tree as the inorder
        traversal of the tree is sorted. */
        int key = rand() % (n * 2);
        printf("%d. Searching for %d\n", i + 1, key);
        tree = searchInSplayTree(tree, key);
        printf("Preorder: ");
        preorder(tree);
        printf("\n");
        printf("Inorder: ");
        inorder(tree);
        printf("\n\n");
    }
    for (int i = 0; i < n; i++) {
        /** After each search operation, the searched key becomes the root of the tree.
        This is confirmed as the first element of the preorder traversal is always
        the searched key. he modified tree is a binary search tree as the inorder
        traversal of the tree is sorted. */
        int key = rand() % (n * 2);
        printf("%d. Attempting to delete %d\n", i + 1, key);
        tree = deleteFromSplayTree(tree, key);
        printf("Preorder: ");
        preorder(tree);
        printf("\n");
        printf("Inorder: ");
        inorder(tree);
        printf("\n\n");
    }
}

void driver() {
    help();
    fflush(stdout);
    Tree bst = NULL;
    Tree splayTree = NULL;
    char command[80];
    while (1) {
        printf("[bs-splay@tree ~]$ ");
        scanf("%s", command);
        if (compareIgnoreCase(command, "exit") == 0) {
            break;
        } else if (compareIgnoreCase(command, "insert") == 0) {
            int key = 0;
            scanf("%d", &key);
            printf("Inserting %d in BST...\n", key);
            bst = insertIntoBST(bst, key);
            printf("Inserting %d in splay tree...\n", key);
            splayTree = insertIntoSplayTree(splayTree, key);
        } else if (compareIgnoreCase(command, "delete") == 0) {
            int key = 0;
            scanf("%d", &key);
            printf("Deleting %d from BST...\n", key);
            bst = deleteFromBST(bst, key, NULL);
            printf("Deleting %d from splay  tree...\n", key);
            splayTree = deleteFromSplayTree(splayTree, key);
        } else if (compareIgnoreCase(command, "draw") == 0) {
            scanf("%s", command);
            if (compareIgnoreCase(command, "bst") == 0) {
                drawTree(bst);
            } else if (compareIgnoreCase(command, "splay") == 0) {
                drawTree(splayTree);
            }
        } else if (compareIgnoreCase(command, "search") == 0) {
            int key = 0;
            scanf("%s%d", command, &key);
            if (compareIgnoreCase(command, "bst") == 0) {
                Tree t = searchInBST(bst, key);
                drawTree(t);
            } else if (compareIgnoreCase(command, "splay") == 0) {
                splayTree = searchInSplayTree(splayTree, key);
#ifndef VERBOSE
                drawTree(splayTree);
#endif
            }
        } else if (compareIgnoreCase(command, "help") == 0) {
            help();
        } else if (compareIgnoreCase(command, "preorder") == 0) {
            scanf("%s", command);
            if (compareIgnoreCase(command, "bst") == 0) {
                preorder(bst);
                printf("\n");
            } else if (compareIgnoreCase(command, "splay") == 0) {
                preorder(splayTree);
                printf("\n");
            }
        } else if (compareIgnoreCase(command, "inorder") == 0) {
            scanf("%s", command);
            if (compareIgnoreCase(command, "bst") == 0) {
                inorder(bst);
                printf("\n");
            } else if (compareIgnoreCase(command, "splay") == 0) {
                inorder(splayTree);
                printf("\n");
            }
        } else if (compareIgnoreCase(command, "postorder") == 0) {
            scanf("%s", command);
            if (compareIgnoreCase(command, "bst") == 0) {
                postorder(bst);
                printf("\n");
            } else if (compareIgnoreCase(command, "splay") == 0) {
                postorder(splayTree);
                printf("\n");
            }
        } else if (compareIgnoreCase(command, "test") == 0) {
            int n = 0;
            scanf("%d", &n);
            test(n);
        }
    }
}

int main(int argc, char *argv[]) {
    driver();
}
