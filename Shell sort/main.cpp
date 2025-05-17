#include <iostream>

using namespace std;

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    //distance value
    //int d=(n+1)/2;
    //shell sort
    //first way (can be incorrect)
 /* while(d>=1)
    {
        int i=0;
        while((d+i)<=n)
        {
            if(arr[i]>arr[i+d])
            {
                int temp= arr[i];
                arr[i]=arr[i+d];
                arr[i+d]=temp;
            }
            i++;
        }
        d--;
    }*/
    //second way (original way)
    int j;
    int temp;
    for(int d=n/2;d>=1;d/=2)
    {
        for(int i=d;i<n;i++)
        {
            temp= arr[i];
            for(j=i;j>=d;j-=d)
            {
                if(temp<arr[j-d])
                {
                    arr[j]=arr[j-d];
                }
                else
                {
                    break;
                }
            }
            arr[j]=temp;
        }

    }
    //print array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
