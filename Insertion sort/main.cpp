#include <iostream>

using namespace std;

int main()
{
    int arr[2][2]={1,3,6,9};
    cout<<arr[5];
    //int arr[10]={10,9,8,7,6,5,4,3,2,1};
    //first way
/*    for (int i=0;i<10;i++)
    {
        if(i>0 && arr[i]<arr[i-1])
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1]=temp;
                }
                else
                {
                    break;
                }
            }
        }
    }*/
    //second way
    /*
    for(int i=0;i<10;i++)
    {
        int index = arr[i]; int j=i;
        while(j>0 && arr[j-1]> index)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = index;
    }
    //print result
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"  ";
    }*/

    return 0;
}
