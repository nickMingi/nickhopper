#include <iostream>
#include <fstream>
using namespace std;

int integersumfromfilemain()
{
    ifstream myfile("integersum.txt");
    int result = 0;
    int temp = 0;
    if(myfile.is_open())
    {
        myfile >> temp;
        result+=temp;
    }
    cout << result << endl;
    myfile.close();
    return 0;
}