#include <iostream>

using namespace std;
struct eadg
{
    int from=-1;
    int to=-1;
    int weight=0;
};
class heap
{
    eadg *arr[30];
    int size;
    void heapifyup(int index);
    void heapifydown(int index);
    int parent(int index);
    int left_child(int index);
    int right_child(int index);
public:
    heap();
    void push(int from ,int to ,int weight);
    eadg pop();
    eadg get_root();
    bool is_empty();
    void display();
};
heap::heap()
{
    size = -1;
}
void heap::push(int from ,int to ,int weight)
{
    if(size < 30)
    {
        arr[++size]= new eadg;
        arr[size]->from = from;
        arr[size]->to = to;
        arr[size]->weight = weight;
        if(!is_empty())
            heapifyup(size);
    }

}
eadg heap::pop()
{
    eadg root = {-1,-1,0};
    if(!is_empty())
    {
        root = *arr[0];
        arr[0]=arr[size--];
        if(!is_empty())
            heapifydown(0);
    }
    return root;
}
bool heap::is_empty()
{
    return size == -1 ? true : false;
}
int heap::parent(int index)
{
    return (index-1)/2 >= 0 ? (index-1)/2 : -1;
}
int heap::left_child(int index)
{
    return (index*2)+1 <= size ? (index*2)+1 : -1;
}
int heap::right_child(int index)
{
    return (index*2)+2 <= size ? (index*2)+2 : -1;
}
void heap::heapifyup(int index)
{
    if(arr[index]->weight < arr[parent(index)]->weight)
    {
        swap(arr[index], arr[parent(index)]);
        heapifyup(parent(index));
    }
    return;
}
void heap::heapifydown(int index)
{
    int selchild = left_child(index);
    if(selchild == -1)
        return;
    if(right_child(index) != -1 && arr[right_child(index)]->weight < arr[selchild]->weight)
    {
        selchild = right_child(index);
    }
    if(arr[index]->weight > arr[selchild]->weight)
    {
        swap(arr[index], arr[selchild]);
        heapifydown(selchild);
    }

}
eadg heap::get_root()
{
    if(!is_empty())
        return *arr[0];
}
void heap::display()
{
    cout<<endl;
    for(int i=0;i<=size;++i)
        cout<<arr[i]->from
            <<"=="<<arr[i]->weight
            <<"=="<<arr[i]->to
            <<" , ";
    cout<<endl;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class union_find
{
    int parent[50];
    int rank[50];
    int forests;
public:
    union_find();
    int parentt(int index);
    void link(int in1,int in2);
    bool union_forest(int in1,int in2);
};
union_find::union_find()
{
    for(int i=0;i<50;++i)
    {
        parent[i]=i;
        rank[i]=1;
    }
    forests = 50;
}
int union_find::parentt(int index)
{
    if(parent[index] != index)
        return parent[index]=parentt(parent[index]);
    return index;
}
void union_find::link(int in1,int in2)
{
    forests--;
    if(rank[in1]<rank[in2])
        swap(in1,in2);
    parent[parent[in2]]=in1;
    if(rank[in1]==rank[in2])
        rank[in1]++;
}
bool union_find::union_forest(int in1,int in2)
{
    //cout<<parentt(in1)<<" "<<parentt(in2)<<endl;
    if(parentt(in1) != parentt(in2))
    {
        link(in1,in2);
        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class graph
{
    char vertex[20];
    int adj_matrix[20][20];
    int size;
    union_find uf;
    heap h;
    bool is_empty();
public:
    graph();
    void add_vertex(char value);
    void add_eadg(int start, int end, int weight);
    void eadg_sorting();
    void MST();
};
graph::graph()
{
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            adj_matrix[i][j]=-1;
    size=-1;
}
void graph::add_vertex(char value)
{
    if(size<20)
        vertex[++size] = value;
}
void graph::add_eadg(int start, int end, int weight)
{
    if(start <20 && end <20)
    {
        adj_matrix[start][end] = weight;
        adj_matrix[end][start] = weight;
    }

}
void graph::eadg_sorting()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(adj_matrix[i][j] != -1)
                h.push(i,j,adj_matrix[i][j]);
        }

    }
}
void graph::MST()
{
    eadg_sorting();
    int total=0;
    int total1=0;
    while(!h.is_empty())
    {
        if(uf.union_forest(h.get_root().from , h.get_root().to))
        {
            cout<<vertex[h.get_root().from]
                <<"=="
                <<h.get_root().weight
                <<"=="
                <<vertex[h.get_root().to]
                <<" , ";
            total+=h.get_root().weight;
        }
        total1+=h.pop().weight;
        //cout<<"\n"<<h.get_root().weight<<endl;
    }
    cout<<"\n\n\nweight of graph :"<<total1/2<<"  MST weight:"<<total;
}
bool graph::is_empty()
{
    return size != -1 ?true:false;
}
int main()
{
    cout << "Hello world!" << endl;
    graph g;
    g.add_vertex('o');
    g.add_vertex('a');
    g.add_vertex('b');
    g.add_vertex('c');
    g.add_vertex('d');
    g.add_vertex('e');
    g.add_vertex('f');
    g.add_vertex('g');
    g.add_vertex('h');
    g.add_eadg(1,2,9);
    g.add_eadg(1,6,14);
    g.add_eadg(1,7,14);
    g.add_eadg(2,3,23);
    g.add_eadg(6,3,18);
    g.add_eadg(6,5,30);
    g.add_eadg(6,7,5);
    g.add_eadg(7,5,20);
    g.add_eadg(7,8,44);
    g.add_eadg(8,3,19);
    g.add_eadg(8,4,6);
    g.add_eadg(5,4,11);
    g.add_eadg(5,3,2);
    g.add_eadg(5,8,16);
    g.add_eadg(4,3,6);
    g.add_eadg(4,8,6);
    g.MST();
    /*
    heap h;
    h.push(1,2,9);
    h.push(1,6,14);
    h.push(1,7,14);
    h.push(2,3,23);
    h.push(6,3,18);
    h.push(6,5,30);
    h.push(6,7,5);
    h.push(7,5,20);
    h.push(7,8,44);
    h.push(8,3,19);
    h.push(8,4,6);
    h.push(5,4,11);
    h.push(5,3,2);
    h.push(5,8,16);
    h.push(4,3,6);
    h.push(4,8,6);
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();
    cout<<"\n\n\n\n\n\n";
    h.pop();
    h.display();*/
    return 0;
}

