#include <iostream>
using namespace std;
void quick_sort(int arr[],int l,int r);
int main()
{
    int n=20;
    int arr[n]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    quick_sort(arr,0,n-1);
    // print array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
void quick_sort(int arr[],int l,int r)
{
    int pivot=arr[(l+r)/2];
    int i=l,j=r,temp;
    while(j>=i)
    {
       while(arr[i]<pivot)
       {
           i++;
       }
       while(arr[j]>pivot)
       {
           j--;
       }
       if(j>=i)
       {
           temp =arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
           i++;
           j--;
       }
    }
    //recursion
    if(i<r)
        quick_sort(arr,i,r);
    if(l<j)
        quick_sort(arr,l,j);
}
