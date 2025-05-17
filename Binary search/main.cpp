#include <iostream>
using namespace std;
int Binary_search(int arr[],int l,int r,int value);
int main()
{
    int n=20;
    int arr[n]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int l=0,r=n-1,mid=(l+r)/2;
    //first way
    while(l<=r)
    {
       if(arr[mid]==14)
       {
           cout<< mid<<endl;
           break;
       }
       else
       {
           if(14>arr[mid])
           {
               l=mid+1;
               mid=(l+r)/2;
           }
           else
           {
               r=mid-1;
               mid=(l+r)/2;
           }
       }
    }

    //second way
    cout<<Binary_search(arr,0,n-1,14);
    return 0;
}
                /* Recursion*/

int Binary_search(int arr[],int l,int r,int value)
{
    if(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==value)
        {
            return mid;
        }
        else
        {
            if(value>arr[mid])
            {
                Binary_search(arr,mid+1,r,value);
            }
            else
            {
                Binary_search(arr,l,mid-1,value);
            }
        }
    }
    else
        return -1;
}
