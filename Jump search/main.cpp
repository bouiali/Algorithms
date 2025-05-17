#include <iostream>

using namespace std;

int main()
{
    int n=16;
    int arr[n]={1,2,3,4,6,7,8,10,11,13,14,15,16,18,19,20};
    int value =1;
    int l=0,r=n-1,jump=4;//jump value definition need modified
    for(int i=3;i<n;i+=jump)
    {
        if(arr[i]==value)
        {
            cout<<i<<endl;
            break;
        }
        if(arr[i]>value)
        {
            for(int j=(i-jump);j<=i;j++)
            {
                if(arr[j]==value)
                {
                   cout<<j<<endl;
                   break;
                }
            }
        }
    }
    return 0;
}
