#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    int height;
};

int height(node* root)
{
    return (root ==nullptr ? -1 : root->height);
}

node* singleRightRotate(node*& root)
{
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = max(height(root->left),height(root->right)) + 1;
    temp->height = max(height(root->right),root->height) + 1;
    return temp;
}

node* singleLeftRotate(node*& root)
{
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = max(height(root->left),height(root->right)) + 1;
    temp->height = max(height(root->right),root->height) + 1;
    return temp;
}

node* doubleLeftRotate(node*& root)
{
    root->right = singleRightRotate(root->right);
    return singleLeftRotate(root);
}

node* doubleRightRotate(node*& root)
{
    root->left = singleLeftRotate(root->left);
    return singleRightRotate(root);
}



node* insert(node*& root,int data)
{
    if( root == nullptr)
    {
        root = new node;
        root->data = data;
        root->height = 0;
        root->left = root->right = nullptr;
    }else if(data < root->data)
    {
        root->left = insert(root->left,data);
        if(height(root->left)-height(root->right) == 2)
        {
            if(data < root->left->data)
                root = singleRightRotate(root);
            else
                root = doubleRightRotate(root);
        }
    }else if(data > root->data)
    {
        root->right = insert(root->right,data);
        if(height(root->right)-height(root->left) == 2)
        {
            if(data > root->right->data)
                root = singleLeftRotate(root);
            else
                root = doubleLeftRotate(root);
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

void printInorder(node* root)
{
    if(root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int AVLmain()
{
    node* root = nullptr;
    insert(root, 20);
    insert(root, 18);
    insert(root, 26);
    insert(root, 24);
    insert(root, 19);
    insert(root, 15);
    printInorder(root);
    return 0;
}