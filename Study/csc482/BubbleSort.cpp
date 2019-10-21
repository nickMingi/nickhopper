#include <stdio.h>
#include <iostream>

using namespace std;

int Bubblemain()
{
    int a[20], N, temp, i, j;
    cout<<"Enter an N value: \n";
    cin>>N;
    cout<<"Input: \n";

    for(i=0;i<N;++i)
        cin>>a[i];
        for (i=0; i<N-1; i++){
            for(j=i+1; j<N;){

                if (a[i]==a[j]){
                    a[j] = a [ N-1];
                    N--;

                } else{
                    if(a[i]>a[j]){
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                    j++;
                }
            }
        }

    cout<<"Output:";
    for(i=0; i<N; ++i)
        cout<<" "<<a[i];
        cout<<"\nGood Bye I'm Exiting...\n";
      
    return 0;
    
}