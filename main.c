#include <stdio.h>
#include <stdlib.h>
//https://gyazo.com/fc825a42a16e35381c1e726263503ac8
// https://gyazo.com/e90b07ce9f55d3d6a81b246c3cf30705
// https://gyazo.com/83b46fefa95561c712f3c89624cf7a6d
// https://gyazo.com/7a15018e40bbf673e4b91c1738969362
// https://gyazo.com/ffd1e92e6738fa400e21bd6971718a5b

long long int totex = 0;

typedef struct Node Node;

struct Node {
  int bracket;
  int winner;
  Node * l, * r;
};

Node * createNode(int value) {
  Node * ret = calloc(1, sizeof(Node));
  ret->bracket = value;
  ret->winner = 0;
  ret->r = ret->l = NULL;
  return ret;
}

void printPostOrder(Node * root) {
    if (root == NULL)
        return; // move up a level

    // going down a level
    printPostOrder(root->l);
    // coming up a level

    // go down a level
    printPostOrder(root->r);
    // come up a level

    printf("Post order: %d ", root->bracket);

    // beginning the process of moving up
}

// Print root last post order traversal
void sim(Node *root, int arr[]) {
  if (root == NULL){
    return; // move up a level
  }

  // going down a level
  sim(root->l, arr);
  // coming up a level

  // go down a level
  sim(root->r, arr);
  // come up a level

  

  // beginning the process of moving up
}

// Return the root of the tree
Node * insert(Node * root, int value) {
  if (root == NULL){
    return createNode(value);
  }
  // Don't add duplicates (optional)
  if (root->bracket == value) {
    return root;
  }
  // root is smaller than our target
  if (root->bracket < value) {
    root->r = insert(root->r, value);
  } else {
    root->l = insert(root->l, value);
  }
  return root;
}

int main() {
  Node * root = NULL;
  int num;
  int temp;
  scanf("%d", &num);

  int arr[num];
  int players[num];

  if(num == 1){
    printf("%d", 0);
    exit(0);
  }
  for (int i = 0; i < num-1; i++) {
    scanf("%d", &temp);
    arr[i] = temp;
  }
  for(int k =0; k < num;k++){
    scanf("%d", &temp);
    players[k] = temp;
  } 
  for(int i = num-2; i >= 0; i--){
    root = insert(root, arr[i]);
  }

  sim(root, arr);

  // for(int j =0; j< num-1;j++){
  //   printf("Table order: %d ", arr[j]);
  // }
  // printf("\n");
  
  // for(int j =0; j< num;j++){
  //   printf("Players: %d ", players[j]);
  // }
  
  
  printf("\n");
  // Entering the root
  //printPostOrder(root);
    // leaving the root

    printf("\n");

    return 0;
}

