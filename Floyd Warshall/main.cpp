#include <iostream>

using namespace std;
class graph
{
    int arr[20];
    int adj_matrix[20][20];
    bool visited[20];
    int s_p[20][20];
    int size;
public:
    graph();
    void add_vertex(int value);
    void add_eadg(int start,int end,int weight);
    void DFS(int node);
    void BFS(int node);
    void dispaly();
    void floyd();
    void to_sort(int node);
};
graph::graph()
{
    size=-1;
    for(int i=0;i<20;++i)
        visited[i]=false;
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
            adj_matrix[i][j]=100;
}
void graph::add_vertex(int value)
{
    arr[++size]=value;
}
void graph::add_eadg(int start,int end,int weight)
{
    adj_matrix[start][end]=weight;
}
void graph::DFS(int node)
{
    char c;
    if(visited[node])
        return;
    visited[node]=true;

    for(int i=0;i<=size;++i)
    {
        if(adj_matrix[node][i] != 100)
            DFS(i);
    }
    c=arr[node];
    cout<<c<<" == ";
}
void graph::floyd()
{
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
            s_p[i][j]=adj_matrix[i][j];
    for(int k=0;k<=size;++k)
    {
        for(int i=0;i<=size;++i)
        {
             for(int j=0;j<=size;++j)
            {
                if(i==j)
                    s_p[i][j]=0;
                else if(s_p[i][k]!=100 && s_p[k][j]!=100)
                    s_p[i][j]=min(s_p[i][j],s_p[i][k]+s_p[k][j]);
            }
        }
    }
}
void graph::dispaly()
{
    char c;
    for(int i=0;i<=size;++i)
    {
        for(int j=0;j<=size;++j)
        {
            c=i+97;
            cout<<c<<"==="<<s_p[i][j]<<"===";
            c=j+97;
            cout<<c<<"  ,  ";
        }
        cout<<endl;
    }

}
int main()
{
    cout << "Hello world!" << endl;
    graph g;
    g.add_vertex(97);
    g.add_vertex(98);
    g.add_vertex(99);
    g.add_vertex(100);
    g.add_eadg(0,2,-3);
    g.add_eadg(0,1,5);
    g.add_eadg(1,0,9);
    g.add_eadg(1,3,3);
    g.add_eadg(2,1,5);
    g.add_eadg(2,0,4);
    g.add_eadg(3,2,1);
    g.floyd();
    g.dispaly();
    graph g1;
    g1.add_vertex(97);
    g1.add_vertex(98);
    g1.add_vertex(99);
    g1.add_vertex(100);
    g1.add_vertex(101);
    g1.add_vertex(102);
    g1.add_eadg(0,3,0);
    g1.add_eadg(0,2,0);
    g1.add_eadg(1,2,0);
    g1.add_eadg(1,4,0);
    g1.add_eadg(3,5,0);
    g1.add_eadg(5,4,0);
    g1.DFS(0);
    return 0;
}
