#include <iostream>

using namespace std;
void merge_sort(int arr[],int l,int r);
void sorting(int l,int mid,int r,int arr[]);
int main()
{
    int arr[10]={1005,975,259,470,365,340,250,195,87,56};
    int n=10;
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
void sorting(int l,int mid,int r,int arr[])
{
    int sizeA,sizeB;
    sizeA = (mid-l)+1;//need modified
    sizeB = r-mid;// need modified
    int arrA[sizeA];
    int arrB[sizeB];
    // inisialization the first array
    for(int i=0;i<sizeA;i++)
    {
        arrA[i]=arr[i+l];
    }
    // inisialization the second array
    for(int i=0;i<sizeB;i++)
    {
        arrB[i]=arr[mid+i+1];
    }
    //merge the two arrays
    int arrA_index=0;
    int arrB_index=0;
    for(int i=l;i<=r;i++)
    {
        if(arrA_index<sizeA && arrB_index<sizeB)
        {
            if(arrA[arrA_index]<arrB[arrB_index])
            {
                arr[i]=arrA[arrA_index];
                arrA_index++;
            }
            else
            {
                arr[i]=arrB[arrB_index];
                arrB_index++;
            }
        }
        else
        {
            if(arrA_index<sizeA)
            {
                arr[i]=arrA[arrA_index];
                arrA_index++;
            }
            else
            {
                arr[i]=arrB[arrB_index];
                arrB_index++;
            }
        }

    }
}
void merge_sort(int arr[],int l,int r)
{
    int mid =(l+r)/2;
    if(l<r)
    {
        //recursion
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        sorting(l,mid,r,arr);
    }
}
