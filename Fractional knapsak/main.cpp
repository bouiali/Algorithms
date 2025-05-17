#include <iostream>
using namespace std;
struct item
{
    float profit;
    float weight;
    float ratioo;
};
int main()
{
    int n=0;
    item arr[3];
    arr[0]={500,40,12.5};
    arr[1]={330,30,11};
    arr[2]={225,25,9};
    int capacity=55;
    while(capacity > 0)
    {
        if(capacity-arr[n].weight >=0)
        {
            capacity-=arr[n].weight;
            cout<<arr[n].profit<<endl;
            ++n;
        }
        else
        {
            cout<<capacity*arr[n].profit/arr[n].weight<<endl;
            capacity=0;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
