// #include <iostream>
// using namespace std;

// struct node
// {
//     int data;
//     node* next;
// };

// struct queue
// {
//     node* front;
//     int count;
//     node* rear;
// };
// void initQueue(queue& q)
// {
//     q.front = nullptr;
//     q.rear = nullptr;
//     q.count = 0;
// }
// bool Enqueue(queue& q,int data);
// void Dequeue(queue*& q,int data);
// void printQueue(queue* q);

// bool Enqueue(queue& q,int data)
// {
//     node* newNode;

//     if(!(newNode = new node))
//         return false;
    
//     newNode->data = data;
//     newNode->next = nullptr;

//     if(q.count == 0)
//         q.front = newNode;
//     else
//         q.rear->next = newNode;
// }

// int queuemain()
// {
//     queue* head = nullptr;
//     cout << "Welcome\n";
//     int choice, data;
//     do
//     {
//         cout << "1.)Enqueue\n";
//         cout << "2.)Dequeue\n";
//         cout << "0.)End Program\n";
//         switch(choice)
//         {
//             case 1:
//                 cout << "Pls enter data\n";
//                 cin >> data;
//                 Enqueue(head,data);
//                 break;
//             case 2:
//                 cout << "Pls enter data\n";
//                 cin >> data;
//                 Dequeue(head,data);
//                 break;
//             case 0:
//                 cout <<"Ending the program";
//                 break;
//             default :
//                 break;
//         }
//         printQueue(head);
//     }while(choice!=0);
//     return 0;
// }