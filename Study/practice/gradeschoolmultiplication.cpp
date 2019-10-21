#include <iostream>
#include <vector>
using namespace std;

int gradeschoolmultiplicationmain()
{
    vector< vector<int> > mynum;
    int i = 0, j = 0;
    for(i = 0; i <12; i++)
    {
        for(j = 0; j <12; j++)
        {
            if(i==0)
            {
                mynum[i][j] = j;
            }else if(j==0)
            {
                mynum[i][j] = i;
            }else
            {
                mynum[i][j] = i*j;
            }
            cout << mynum[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}