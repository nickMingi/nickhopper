// #include <iostream>

// using namespace std;

// struct node 
// {
//     int data;
//     struct node* next; // just the pointer that holds the address
// };
// void insertNode(node*& head, int index, int d);
// void deleteNode(node*& head, int index);
// void printList(node* head);
// node* searchNode(node* head, int key);

// void insertNode(node*& head, int index, int d)
// {
//     node* newNode = new node;
//     newNode->data = d;
//     newNode->next = nullptr;
    
//     if(index == 0)
//     {
//         newNode->next = head;
//         head = newNode;
//         return;
//     }else
//     {
//         node* walker = head;
//         int wIndex = 0;
//         while(walker != NULL && wIndex < index-1)
//         {
//             walker = walker->next;
//             wIndex++;
//         }

//         if(walker == nullptr)
//         {
//             cout << "The index is too large, could not insert.\n";
//             delete newNode;
//             return;
//         }
//         else
//         {
//            newNode->next = walker->next;
//            walker->next = newNode; 
//         }
//     }
// }

// void deleteNode(node*& head, int index)
// {
//     if(head == nullptr)
//     {
//         cout << "The list is empty, there's nothing to delete.\n";
//         return;
//     }

//     if(index == 0)
//     {
//         node* dltTemp = head;
//         head = head->next;

//         delete dltTemp;
//         return;
//     }
//     else
//     {
//         node* walker = head;
//         int wIndex = 0;
//         while(walker != NULL && wIndex < index-1)
//         {
//             walker = walker->next;
//             wIndex++;
//         }

//         if(walker == nullptr)
//         {
//             cout << "The index is too large, could not delete.\n";
//             return;
//         }
//         else
//         {
//             node* dltTemp = walker->next;
//             walker->next = walker->next->next;
//             delete dltTemp;
//         }
//     }
// }

// void printList(node* head)
// {
//     node* walker = head;

//     while(walker != nullptr)
//     {
//         cout << walker->data << " ";
//         walker = walker->next;
//     }
//     cout << endl;
// }

// node* searchNode(node* head, int key)
// {
//     node* walker = head;

//     while(walker != nullptr && walker->data != key)
//     {
//         walker = walker->next;
//     }

//     if(walker == nullptr)
//     {
//         cout << key << " could not be found.\n";
//         return nullptr;
//     }
//     else
//     {
//         return walker;
//     }
// }

// int Linkedmain()
// {
//     node* head = nullptr;
//     node* myNode = nullptr;
//     cout << "hello world\n";
//     int choice, data, index, key;
//     do
//     {
//         cout << "0.) search a node\n";
//         cout << "1.) insert a new node\n";
//         cout << "2.) delete a node\n";
//         cout << "3.) Exit\n\n";

//         cin >> choice;
//         switch(choice)
//         {
//             case 1:
//                 cout << "Please enter the value to insert: ";
//                 cin >> data;
//                 cout << "Which index would you like to insert at: ";
//                 cin >> index;
//                 insertNode(head, index, data);
//                 break;
//             case 2:
//                 cout << "Please enter the index to delete: ";
//                 cin >> index;
//                 deleteNode(head, index);
//                 break;
//             case 3:
//                 cout << "Goodbye\n";
//                 break;
//             case 0:
//                 cout << "Please enter what to search:";
//                 cin >> key;
//                 myNode = searchNode(head, key);
//                 if(myNode != nullptr)
//                 {
//                     cout << myNode->data << " is founded at\n" << myNode;
//                 }
//                 break;
//             default:
//                 cout << choice << "is an invalid option. Please try again.";
//         }
//         printList(head);
//     }while(choice != 3);
//     return 0;
// }