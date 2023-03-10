
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

struct node *newNode(int key)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = key;
  temp->left = NULL;
  temp->right = NULL;

  if (root == NULL)
  {
    root = temp;
  }
  return temp;
}

struct node *insert(struct node *node, int key)
{
  if (node == NULL)
    return (newNode(key));
  else
  {
    if (key <= node->data)
      node->left = insert(node->left, key);
    else
      node->right = insert(node->right, key);
    return node;
  }
}

int parentOfmaxValue(struct node *root)
{
  struct node *prev = (struct node *)malloc(sizeof(struct node));
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp = root;

  int p_max = 0, s_max = 0;
  int p_min = 0, s_min = 0;

  while (root->right != NULL)
  {
    prev = root;
    root = root->right;
  }
  if (prev != NULL)
  {
    p_max = prev->data;
    printf("ata_max: %d\n", p_max);
    if (prev->left != NULL)
    {
      s_max = prev->left->data;
      printf("kardes_max: %d\n", s_max);
    }
  }
}

int parentOfminValue(struct node *root)
{
  struct node *prev = (struct node *)malloc(sizeof(struct node));
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp = root;
  int p_max = 0, s_max = 0;
  int p_min = 0, s_min = 0;

  while (root->left != NULL)
  {
    prev = root;
    root = root->left;
  }
  if (prev != NULL)
  {
    p_min = prev->data;
    printf("ata_min: %d\n", p_min);

    if (prev->right != NULL)
    {
      s_min = prev->right->data;
      printf("kardes_min: %d\n", s_min);
    }
  }
}

void printLevelOrder(struct node *root)
{
  int h = height_lv(root);
  int i;
  for (i = 1; i <= h; i++)
    printCurrentLevel(root, i);
}

void printCurrentLevel(struct node *root, int level)
{
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
  }
}

int height_lv(struct node *node)
{
  if (node == NULL)
    return 0;
  else
  {
    int lheight = height_lv(node->left);
    int rheight = height_lv(node->right);

    if (lheight > rheight)
    {
      return (lheight + 1);
    }

    else
    {
      return (rheight + 1);
    }
  }
}

int main()
{

  insert(root, 10);
  insert(root, 25);
  insert(root, 2);
  insert(root, 34);
  insert(root, 7);
  insert(root, 21);

  printf("\n Level Order traversal of binary tree is \n");
  printLevelOrder(root);
  printf("\n ListMinMax: \n");
  parentOfmaxValue(root);
  parentOfminValue(root);

  getchar();
  return 0;
}