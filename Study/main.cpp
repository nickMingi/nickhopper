#include <iostream>
#include <fstream>
#include <string>
#include "./csc482/BubbleSort.cpp"
#include "./csc461/interpreter.cpp"
#include "./csc482/mergesort.cpp"
#include "./csc482/assignment2.cpp"
#include "./datastructures/sort/bubbleSort.cpp"
#include "./datastructures/sort/selectionSort.cpp"
#include "./datastructures/sort/insertionSort.cpp"
#include "./datastructures/sort/mergeSort.cpp"
#include "./datastructures/list/linkedList.cpp"
#include "./datastructures/tree/binarysearchtree.cpp"
#include "./datastructures/tree/AVLtree.cpp"
#include "./datastructures/heap/heap.cpp"
#include "./datastructures/graph/vertex.cpp"
#include "./practice/removeDuplicates.cpp"
#include "./practice/stockProfit.cpp"
#include "./practice/rotatearray.cpp"
#include "./practice/iscontainduplicate.cpp"
#include "./practice/singlenumber.cpp"
#include "./practice/intersection.cpp"
#include "./practice/plusone.cpp"
#include "./practice/movezeros.cpp"
#include "./practice/twosum.cpp"
#include "./practice/validsudoku.cpp"
#include "./practice/rotateimage.cpp"
#include "./practice/reverseinteger.cpp"
#include "./practice/fibonacci.cpp"
#include "./practice/gradeschoolmultiplication.cpp"
#include "./practice/integersumfromfile.cpp"
//#include "./csc410/assignment2.c"
using namespace std;

int main() {
    int x = 0;
    int N = 0, names=0, prices=0, money=0;
    cout << "Hello World" << endl;
    ifstream inputfile("input.txt");
    if(inputfile.is_open())
    {
        inputfile >> N;
        for(int i = 0; i <N; i++)
        {
            inputfile >> money;
            inputfile >> names;
            string name[names];
            int price[names];
            for(int j = 0; j < names; j++)
            {
                inputfile >> name[j];
                inputfile >> price[j];
            }
            inputfile >> prices;
            string name2[prices];
            int price2[prices];
            for(int k = 0; k < prices; k++)
            {
                inputfile >> name2[k];
                inputfile >> name2[k];
            }
        }
    }
    else{

    }
    inputfile.close();

    ofstream myfile("output.txt");
    if(myfile.is_open())
    {
        
    
    /*--------------CSC410 Start---------------*/
    //mainInterpreter();
    //mainAssignment2();
    /*--------------CSC410 End-----------------*/

    /*--------------CSC461 Start---------------*/
    //mainInterpreter();
    /*--------------CSC461 End-----------------*/

    /*--------------CSC482 Start---------------*/
    //maincsc482assignment1();
    //Bubblemain();
    //assignment2main();
    /*--------------CSC482 End-----------------*/

    /*--------------Datastructures Start---------------*/
    //bubblesortMain();
    //selectionSortmain();
    //Linkedmain();
    //bstmain();
    //AVLmain();
    //heapMain();
    //   myfile << vertexmain();
    //    myfile <<  mergemain();
    /*--------------Datastructures End-----------------*/
        integersumfromfilemain();
        //gradeschoolmultiplicationmain();
        //fibonaccimain();
        //reverseintegermain();
        //rotateimagemain();
        //validsudokumain();
        //twosummain();
        //movezerosmain();
        //plusonemain();
        //intersectionmain();
        //singlenumbermain();
        //iscontainduplicatemain();
        //rotatearraymain();
        //stockprofitmain();
        //removeDuplicatesmain();
    }
    else
    {
        cout << "File is not opened."<<endl;
    }
    myfile.close();
    cout << "This is the end of program" << endl;
    return 0;
}
