#include <iostream>

using namespace std;
struct eadg
{
    int from= -1;
    int to=-1;
    int weight =0;
};
class heap
{
private:
    eadg *arr[100];
    int size;
    int parent(int index);
    int rightchild(int index);
    int leftchild(int index);
    void heapifyup(int index);
    void heapifydown(int index);
public:
    bool is_empty();
    heap();
    void push(int from ,int to ,int weight);
    eadg pop();
    eadg get_root();
    void display();
};
heap::heap()
{
    size=-1;
}
int heap::parent(int index)
{
    return size<=0 || index<=0 ? -1 : (index-1)/2;
}
int heap::rightchild(int index)
{
    return 2+index*2 <=size ? 2+index*2 :-1 ;
}
int heap::leftchild(int index)
{
    return 1+(index*2) <=size ? 1+(index*2) :-1 ;
}
bool heap::is_empty()
{
    if(size<0)
        return true;
    return false;
}
void heap::heapifyup(int index)
{
    if (index <= 0 || arr[index]->weight > arr[parent(index)]->weight|| is_empty())
        return;
    swap(arr[index],arr[parent(index)]);
    heapifyup(parent(index));
}
void heap::heapifydown(int index)
{
    int selchild;
                    //first//
    /*
    if( rightchild(index) <= size && leftchild(index) <= size )
    {
        if(arr[rightchild(index)]<arr[leftchild(index)])
            selchild = rightchild(index);
        else
            selchild = leftchild(index);
    }
    else if(rightchild(index) <= size)
         selchild = rightchild(index);
    else if(leftchild(index)<= size)
         selchild = leftchild(index);

    cout<<arr[selchild]<<"==>"<<arr[index]<<"  ";
    if(arr[index] > arr[selchild] && arr[selchild]!=0)
    {
        swap(arr[index],arr[selchild]);
        heapifydown(selchild);
    }
    else
        return;*/
                 //second//
    selchild =leftchild(index);
    if(selchild ==-1)
    {
        return;
    }
    if(rightchild(index) != -1 && arr[rightchild(index)]->weight != 0 && arr[rightchild(index)]->weight < arr[selchild]->weight )
    {
        selchild = rightchild(index);
    }
    if (arr[index]->weight > arr[selchild]->weight)
    {
        swap(arr[index],arr[selchild]);
        heapifydown(selchild);
    }
}
void heap::push(int from ,int to ,int weight)
{
    arr[++size] = new eadg;
    arr[size]->from = from;
    arr[size]->to = to;
    arr[size]->weight = weight;
    heapifyup(size);
}
eadg heap::pop()
{
    if(is_empty())
        return {-1,-1,0};
    eadg value = *arr[0];
    arr[0] = arr[size];
    --size;
    if(is_empty())
        return {-1,-1,0};
    heapifydown(0);
    return value;
}
eadg heap::get_root()
{
    if(is_empty())
        return {-1,-1,0};
    return *arr[0];
}
void heap::display()
{
    cout<<endl;
    for (int i=0 ;i<=size;++i)
    {
        cout<<arr[i]->from<<"=="<<arr[i]->weight<<" , ";
    }
    cout<<endl;
}
///////////////////////////////////////////////////////////////////////////////
class graph
{
    char vertex[20];
    int size;
    int adj_matrix[20][20];
    bool visit[20];
    heap h;
public:
    graph();
    void add_vertex(char name);
    void add_eadg(int start , int end , int weight);
    void MST (int root);
};
graph::graph()
{
    size=-1;
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
            adj_matrix[i][j]= -1;
    for(int i=0;i<20;i++)
        visit[i]=false;
}
void graph::add_vertex(char name)
{
    vertex[++size]=name;
}
void graph::add_eadg(int start,int end,int weight)
{
    adj_matrix[start][end]=weight;
    adj_matrix[end][start]=weight;
}
void graph::MST(int root)
{
    do
    {
        visit[root] = true;
        for(int i=0;i<20;++i)
        {
            if(adj_matrix[root][i]>-1)
                h.push(root,i,adj_matrix[root][i]);
        }
        if(!h.is_empty())
        {
            while(visit[h.get_root().to] && !h.is_empty())
                h.pop();
            if(!h.is_empty())
            {
                cout<<vertex[h.get_root().from]
                    <<"=="<<h.get_root().weight<<"=="
                    <<vertex[h.get_root().to]<<" , ";
                root=h.pop().to;
            }

        }

    }while(!h.is_empty());

}
int main()
{
    cout << "Hello world!" << endl;
    graph g;
    /*g.add_vertex('a');
    g.add_vertex('b');
    g.add_vertex('c');
    g.add_vertex('d');
    g.add_vertex('e');
    g.add_vertex('f');
    g.add_vertex('g');
    g.add_eadg(0,1,2);
    g.add_eadg(0,2,4);
    g.add_eadg(0,3,1);
    g.add_eadg(1,3,3);
    g.add_eadg(1,4,10);
    g.add_eadg(2,3,2);
    g.add_eadg(2,5,5);
    g.add_eadg(3,4,7);
    g.add_eadg(3,5,8);
    g.add_eadg(3,6,4);
    g.add_eadg(4,6,6);
    g.add_eadg(5,6,1);*/
    g.add_vertex('a');
    g.add_vertex('b');
    g.add_vertex('c');
    g.add_vertex('d');
    g.add_vertex('e');
    g.add_vertex('f');
    g.add_vertex('g');
    g.add_vertex('h');
    g.add_vertex('i');
    g.add_vertex('j');
    g.add_vertex('k');
    g.add_eadg(0,1,3);
    g.add_eadg(0,3,15);
    g.add_eadg(0,4,24);
    g.add_eadg(1,2,5);
    g.add_eadg(1,3,9);
    g.add_eadg(3,4,13);
    g.add_eadg(3,2,14);
    g.add_eadg(3,5,12);
    g.add_eadg(2,5,18);
    g.add_eadg(2,6,4);
    g.add_eadg(4,5,20);
    g.add_eadg(4,9,9);
    g.add_eadg(5,6,7);
    g.add_eadg(5,7,21);
    g.add_eadg(5,8,8);
    g.add_eadg(6,7,2);
    g.add_eadg(7,8,6);
    g.add_eadg(8,9,19);
    g.add_eadg(9,10,11);
    g.add_eadg(9,5,10);
    g.add_eadg(10,4,17);
    g.MST(0);
    return 0;
}
