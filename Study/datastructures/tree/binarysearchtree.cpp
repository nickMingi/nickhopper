// #include <iostream>
// using namespace std;

// struct node
// {
//     int data;
//     struct node* left;
//     struct node* right;
// };

// void insertNode(node*& root, int key);
// void deleteNode(node*& root, int key);
// void printAscending(node* root);
// void printParenthetical(node* root);
// int findSmallest(node* root);
// int findLargest(node* root);
// node* searchNode(node* root, int key);

// void insertNode(node*& root, int key)
// {
//     if(root == nullptr)
//     {
//         cout << "Inserting " << key;
//         root = new node;
//         root->data = key;
//         root->right = nullptr;
//         root->left = nullptr;
//         cout << " Secceded!" << endl;
//     }
//     else
//     {
//         if(root->data > key)
//         {
//             insertNode(root->left, key);
//         }
//         else
//         {
//             insertNode(root->right, key);
//         }
//     }
// }

// void deleteNode(node*& root, int key)
// {
//     if(root == nullptr)
//     {
//         cout << key << " was not found in the tree.\n\n";
//         return;
//     }
//     else
//     {
//         if(key < root->data)
//         {
//             deleteNode(root->left, key);
//         }
//         else if ( key > root->data)
//         {
//             deleteNode(root->right, key);
//         }
//         else
//         {
//             if(root->left == nullptr)
//             {
//                 if(root->right == nullptr)
//                 {
//                     cout << "Deleting " << root->data << endl;
//                     delete root;
//                     root = nullptr;
//                 }
//                 else
//                 {
//                     cout << "Deleting " << root->data << endl;
//                     node* dltTemp = root;
//                     root = root->right;
//                     delete dltTemp;
//                 }
//             }
//             else // Here if left pointer is not null
//             {
//                 if(root->right == nullptr)
//                 {
//                     cout << "Deleting " << root->data << endl;
//                     node* dltTemp = root;
//                     root = root->left;
//                     delete dltTemp;
//                 }
//                 else // Node has two children.
//                 // Find largest child in left subtree.
//                 {
//                     node* largestLeft = root->left;
//                     while(largestLeft->right != nullptr)
//                     {
//                         largestLeft = largestLeft->right;
//                     }
//                     root->data = largestLeft->data;
//                     deleteNode(root->left, largestLeft->data);
//                 }
//             }
//         }
//     }
// }

// void printAscending(node* root)
// {
//     if(root != nullptr)
//     {
//         printAscending(root->left);
//         cout << root->data << " ";
//         printAscending(root->right);
//     }
// }

// void printParenthetical(node* root)
// {
//     // output should be 50(25(10 40)75(60 100))
//     // This is Preorder traverse
//     if(root != nullptr)
//     {
//         cout << root->data << " ";
//         if(root->left !=nullptr || root->right != nullptr)
//             cout << "( ";
//         printParenthetical(root->left);
//         printParenthetical(root->right);
//         if(root->left != nullptr || root->right != nullptr)
//             cout << ") ";
//     }
// }

// int findSmallest(node* root)
// {
//     if(root->left == nullptr)
//     {
//         cout << "Smallest -> " << root->data << endl;
//         return root->data;
//     }
//     else
//     {
//         return findSmallest(root->left);
//     }
// }

// int findLargest(node* root)
// {
//     if(root->right == nullptr)
//     {
//         cout << "Largest -> " << root->data << endl;
//         return root->data;
//     }
//     else
//     {
//         return findLargest(root->right);
//     }
// }

// node* searchNode(node* root, int key)
// {
//     if(root == nullptr)
//     {
//         cout << "Not Found" << endl;
//         return nullptr;
//     }
//     else
//     {
//         if(root->data < key)
//         {
//             return searchNode(root->right, key);
//         }else if(root->data > key)
//         {
//             return searchNode(root->left, key);
//         }else
//         {
//             cout << "Congrat! " << root->data << " is found\n";
//             return root;
//         }
//     }
// }

// int bstmain()
// {
//     node* head = nullptr;
//     int choice, key, check;
//     do
//     {
//         cout << "Welcome\n";
//         cout << "1.)Insert the node\n";
//         cout << "2.)Delete the node\n";
//         cout << "3.)Find smallest node\n";
//         cout << "4.)Find biggest node\n";
//         cout << "5.)Search node\n";
//         cout << "0.)End program\n";
//         cin >> choice;
//         switch(choice)
//         {
//             case 1:
//                 cout << "Pls enter key\n";
//                 cin >> key;
//                 insertNode(head,key);
//                 break;
//             case 2:
//                 cout << "Pls enter key\n";
//                 cin >> key;
//                 deleteNode(head,key);
//                 break;
//             case 3:
//                 check = findSmallest(head);
//                 if(check)
//                     cout << "found: " << check << endl;
//                 else
//                     cout << "not found\n";
//                 break;
//             case 4: 
//                 check = findLargest(head);
//                 if(check)
//                     cout << "found: " << check << endl;
//                 else
//                     cout << "not found\n";
//                 break;
//             case 5:
//                 cout << "Pls enter key\n";
//                 cin >> key;
//                 searchNode(head,key);
//                 break;
//             case 0:
//                 cout << "Ending the program\n";
//                 break;
//             default:
//                 cout << "Ending the program\n";
//                 break;
//         }
//         printParenthetical(head);
//     }while(choice!=0);
//     return 0;
// }