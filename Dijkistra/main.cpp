#include <iostream>
#define MAX 20
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#define IN 99
#define N 7
int dijsktra(int cost[][N],int source,int target);
using namespace std;
struct node
{
    int value;
    int weigth=IN;
    bool pop = false;
};
class p_q
{
public:
    node *node[MAX];
    int head;
    int till;
    int size;
public:
    p_q();
    void push(int value,int weigth);
    int pop();
    bool is_empty();
};
p_q::p_q()
{
    head=till=size=-1;
}
void p_q::push(int value,int weigth)
{
    if(is_empty())
    {
        head=till=0;
        this->node[till]=new struct node;
        node[till]->value = value;
        node[till]->weigth = weigth;
        size=0;
    }
    else
    {
        this->node[++till]=new struct node;
        node[till]->value=value;
        node[till]->weigth =weigth;
        size++;
    }
}
int p_q::pop()
{
    //if(is_empty())
      //  return -1;
    struct node min;
    min.weigth = IN;
    min.value= -1;
    int index;
    for(int i=0;i<=size;++i)
    {
        if(node[i]->weigth<min.weigth && node[i]->pop==false)
        {
            min.weigth = node[i]->weigth;
            min.value =node[i]->value;
            index=i;
        }
    }
    if(min.value != -1)
        node[index]->pop=true;
    return min.value;

}
bool p_q::is_empty()
{
    if(head>=till && size==-1)
        return true;
    return false;
}
struct vertex
{
    char value;
    bool visited = false;
    int weigth = 1000;
};
class graph
{
    vertex *verteces[MAX];
  public:  int eadg_matrix[N][N] = {0};
    int size;
    p_q q;
public:
    graph();
    int nei_ver(int index);
    void add (char value);
    void add_eadge(int start , int end , int weigth);
    void shortest_path(int start , int target);
    void weigth_calc(int start);
    void display();
};
graph::graph()
{
    size = -1;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            eadg_matrix[i][j]=IN;

}
void graph::add(char value)
{
    verteces[++size] = new vertex;
    verteces[size]->value=value;
    verteces[size]->weigth=IN;
}
void graph::add_eadge(int start , int end , int weigth)
{
    eadg_matrix[start][end] = weigth;
}
int graph::nei_ver(int index)
{
    for(int i =0;i<MAX;++i)
    {
        if(eadg_matrix[index][i] > 0)
            return i;
    }
    return -1;
}
void graph::weigth_calc(int start)
{
    verteces[start]->visited =true;

    for(int i=0;i<=size;i++)
    {
        if(eadg_matrix[start][i] > 0)
        {
            if((verteces[start]->weigth+eadg_matrix[start][i]) < verteces[i]->weigth)
            {
                verteces[i]->weigth = (verteces[start]->weigth+eadg_matrix[start][i]);
            }
            if(verteces[i]->visited==false)
                q.push(i,verteces[i]->weigth);
        }
    }

}
void graph::shortest_path(int start , int target)
{
    verteces[start]->weigth=0;
    q.push(start,0);
    while(start!=-1)
    {
       start=q.pop();
       if(start!=target && start != -1)
       {
            weigth_calc(start);
       }
    }
    display();
    for(int i=0;i<=size;i++)
    {
        verteces[i]->weigth=IN;
        verteces[i]->visited=false;
    }
    q.head=-1;
    q.till=-1;
    q.size= -1;
}
void graph::display()
{
    cout<<endl<<"--------------=display=---------------"<<endl;
    for(int i =0;i<=size;i++)
        cout<<verteces[i]->value<<"="<<verteces[i]->weigth<<"\n";
}
int main()
{
    graph g;
    g.add('a');
    g.add('b');
    g.add('c');
    g.add('d');
    g.add('e');
    g.add('f');
    g.add('g');
    //a
    g.add_eadge(0,1,3);
    g.add_eadge(0,3,2);
    //b
    g.add_eadge(1,4,8);
    //c
    g.add_eadge(2,0,6);
    g.add_eadge(2,3,3);
    g.add_eadge(2,5,19);
    //d
    g.add_eadge(3,1,4);
    g.add_eadge(3,5,7);
    //e
    g.add_eadge(4,6,2);
    g.add_eadge(4,3,1);
    //f
    g.add_eadge(5,6,4);
    //g
    g.add_eadge(6,3,5);
    cout << "Hello world!" << endl;
    dijsktra(g.eadg_matrix,2,6);
   /* g.shortest_path(2,6);
    g.shortest_path(1,6);
    g.shortest_path(3,6);
    g.shortest_path(4,6);
    g.shortest_path(5,6);
    g.shortest_path(6,6);*/
    return 0;
}
                    /*! second method (book method) !*/
int dijsktra(int cost[][N],int source,int target)
{
    int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
    char path[N];
    for(i=0;i< N;i++)
    {
        dist[i] = IN;//infinity distance (initially 99)
        prev[i] = -1;//non previous (initially -1)
    }
    start = source;//start (c>>3 in our case)
    selected[start]=1;//start is visited
    dist[start] = 0;//weight
    while(selected[target] ==0)//while the target is don't visited
    {
        min = IN;//weight ( initially 99)
        m = -1;//index  (initially 0)
        for(i=0;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)//relaxation the weight
            {
                dist[i] = d;//relaxation
                prev[i] = start;//get previous
                                    //in our case >>>>>>>
                                    //#c#//a=6//d=3//f=19
                                    //#d#//b=7//f=10
                                    //#a#//
                                    //#b#//e=15
                                    //#f#//g=14
            }
            if(min>dist[i] && selected[i]==0)//!!!(important) get the smallest from #ALL# weighter elements (if don't visited before)
            {
                min = dist[i];//get the smallest weight
                m = i;//get the smallest weight index
            }
        }
        cout<<endl;
        start = m;//d 3=3>>//a  0=6//b  1=7>>//f  5=10>>//g  6=14 break;
        selected[start] = 1;//start is visited
    }

    start = target;//6
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65;//g>>e>>b>>d>>c;
        start = prev[start];
    }
    path[j]='\0';//last character
    strrev(path);//reverse the string
    cout<< path ;//print the result
    return dist[target];
}

