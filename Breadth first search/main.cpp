#include <iostream>
#define MAX 20
using namespace std;
                /* Queue implementation */
class Queue
{
    int arr[MAX]={0};
    int front ;
    int rear;

public:
    int size ;
    Queue();
    void insert(int value);
    int remove ();
    bool is_empty();
};
Queue::Queue()
{
   front = -1;
   rear = -1;
   size = -1;
}
void Queue::insert(int value)
{
    if(front==-1 && rear == -1)
    {
        front = rear = size =0;
        arr[rear]=value;
    }
    else
    {
        arr[++rear] = value;
        size++;
    }
}
int Queue::remove()
{
    if(size > -1)
    {
        size--;
        return arr[++front];
    }
    else
    {
        front = rear = size = -1;
    }
}
bool Queue::is_empty()
{
    if(front == rear && size == -1)
        return true;
    return false;
}
struct vertex
{
    char data;
    bool is_visited = false;
};
class graph
{
    vertex *arr[MAX] ;
    int eadg_matrix[MAX][MAX]= {0};
    int size;
public:
    graph();
    void add(char value);
    void display_vertex(int index);
    int unvisited_vertex(int index);
    void add_eadg(int start,int end);
    void breadth_first_();
};
graph::graph()
{
    size = -1;
}
void graph::add(char value)
{
    arr[++size] = new vertex;
    arr[size]->data = value;
    arr[size]->is_visited = false;
}
void graph::display_vertex(int index)
{
    cout<<arr[index]->data<<endl;
}
int graph::unvisited_vertex(int index)
{
    for(int i=0;i<=size;++i)
    {
        if(eadg_matrix[index][i]== 1 && arr[i]->is_visited == false)
        {
            cout << index << " --- "<<i<<"   ";
            return i;
        }

    }
    return -1;
}
void graph::add_eadg(int start,int end)
{
    eadg_matrix[start][end] = 1;
    eadg_matrix[start][end] = 1;
}
void graph::breadth_first_()
{
    Queue q;
    display_vertex(0);
    arr[0]->is_visited=true;
    q.insert(0);
    int i= 0;
    int j;
    while(!q.is_empty())
    {
        j=unvisited_vertex(i);
        while(j != -1)
        {
            display_vertex(j);
            arr[j]->is_visited= true;
            q.insert(j);
            j=unvisited_vertex(i);
        }
        i=q.remove();
    }
   /* int unvisitedVertex;
while(!q.is_empty())
{
    int tempVertex = q.remove();
    while((unvisitedVertex = unvisited_vertex(tempVertex)) != -1)
    {
        arr[unvisitedVertex]->is_visited = true;
        display_vertex(unvisitedVertex);
        q.insert(unvisitedVertex);
    }
}*/
    for(i=0;i<=size;i++)
        arr[i]->is_visited = false;

}
int main()
{
    cout << "Hello world!" << endl;
    graph g;
    g.add('s');
    g.add('a');
    g.add('b');
    g.add('c');
    g.add('d');
    g.add('e');
    g.add('f');
    g.add('g');
    g.add('h');
    g.add('i');
    g.add_eadg(0,1);
    g.add_eadg(0,2);
    g.add_eadg(0,3);
    g.add_eadg(2,4);
    g.add_eadg(1,4);
    g.add_eadg(3,4);
    g.add_eadg(4,5);
    g.add_eadg(4,6);
    g.add_eadg(6,7);
    g.add_eadg(6,8);
    g.add_eadg(6,9);
    g.breadth_first_();
    return 0;
}
