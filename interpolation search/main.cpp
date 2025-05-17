#include <iostream>
using namespace std;
int interpolation_search(int arr[],int l,int r,int value);
int main()
{
    int n=20;
    int arr[n]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //first way
    int value =10;
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid= l+((r-l)*(value-arr[l]))/(arr[r]-arr[l]);
        if(arr[mid]==value)
        {
            cout<<mid<<endl;
            break;
        }
        else
        {
            if(value<arr[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    //second way
    cout<<interpolation_search(arr,0,n-1,value);
    return 0;
}
int interpolation_search(int arr[],int l,int r,int value)
{
    if(l<=r)
    {
        int mid= l+((r-l)*(value-arr[l]))/(arr[r]-arr[l]);
        if(arr[mid]==value)
        {
            return mid;
        }
        else
        {
            if(value<arr[mid])
            {
                interpolation_search(arr,l,mid-1,value);
            }
            else
            {
                interpolation_search(arr,mid+1,r,value);
            }
        }
    }
    else
        return -1;
}
