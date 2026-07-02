#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

struct node
{
    int key,height;
    struct node *left,*right;
};

// A utility function to get height of the tree
int height(struct node *N)
{
    if(N==NULL)
        return 0;
    else
        return N->height;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T2=x->right;

    // Perform rotation
    x->right=y;
    y->left=T2;

    // Update heights
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T2=y->left;

    // Perform rotation
    y->left=x;
    x->right=T2;

    //  Update heights
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct node *N)
{
    if(N==NULL)
        return 0;
    else
        return height(N->left)-height(N->right);
}

struct node *insert(struct node *node,int key)
{
    /* 1.  Perform the normal BST rotation */
    if(node==NULL)
    {
        node=(struct node*)malloc(sizeof(struct node));
        node->key=key;
        node->left=NULL;    /* initialize the children to null */
        node->right=NULL;   /* initialize the children to null */
        node->height=1;
        return node;
    }

    if(key<node->key)
        node->left=insert(node->left,key);
    else
        node->right=insert(node->right,key);

    /* 2. Update height of this ancestor node */
    node->height=max(height(node->left),height(node->right))+1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance=getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if(balance>1 && key<node->left->key)
        return rightRotate(node);

    // Right Right Case
    if(balance<-1 && key>node->right->key)
        return leftRotate(node);

    // Left Right Case
    if(balance>1 && key>node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if(balance<-1 && key<node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void inorder(struct node *leaf)
{
    if(leaf==NULL)
      return;

    inorder(leaf->left);                    // Printing left of root
    printf("%d ",leaf->key);          // Print root
    inorder(leaf->right);                   // Print right of root
}

void preorder(struct node *leaf)
{
    if(leaf==NULL)
      return;

    printf("%d ",leaf->key);
    preorder(leaf->left);
    preorder(leaf->right);
}

void postorder(struct node *leaf)
{
    if(leaf==NULL)
      return;

    postorder(leaf->left);
    postorder(leaf->right);
    printf("%d ",leaf->key);
}

int maxDepth(struct node *node)
{
   if(node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth=maxDepth(node->left);
       int rDepth=maxDepth(node->right);

       /* use the larger one */
       if(lDepth>rDepth)
           return(lDepth+1);
       else
           return(rDepth+1);
   }
}

unsigned int getLeafCount(struct node *node)
{
  if(node==NULL)
    return 0;
  if(node->left==NULL && node->right==NULL)
    return 1;
  else
    return getLeafCount(node->left)+getLeafCount(node->right);
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(struct node *root,struct node *&pre,struct node *&suc,int key)
{
    // Base case
    if(root==NULL)
        return;

    // If key is present at root
    if(root->key==key)
    {
        // the maximum value in left subtree is predecessor
        if(root->left!=NULL)
        {
            struct node *tmp=root->left;
            while(tmp->right)
                tmp=tmp->right;
            pre=tmp;
        }
        // the minimum value in right subtree is successor
        if(root->right!=NULL)
        {
            struct node *tmp=root->right;
            while(tmp->left)
                tmp=tmp->left;
            suc=tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if(root->key>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else // go to right subtree
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}

/* Drier program to test above function*/
int main()
{
  struct node *root = NULL;

  /* Constructing tree given in the above figure */
  root=insert(root,10);
  root=insert(root,20);
  root=insert(root,30);
  root=insert(root,40);
  root=insert(root,50);
  root=insert(root,25);

  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");

  printf("Leaf count of the tree is %d",getLeafCount(root));
  printf("\n");

  struct node *pre=NULL,*suc=NULL;

  int key=20;
  findPreSuc(root,pre,suc,key);

  if(pre!=NULL)
      printf("Predecessor is %d\n",pre->key);
  else
      printf("No Predecessor\n");

  if(suc!=NULL)
      printf("Successor is %d\n",suc->key);
  else
      printf("No Successor\n");

  printf("Hight of tree is %d", maxDepth(root));
  printf("\n");

  return 0;
}
