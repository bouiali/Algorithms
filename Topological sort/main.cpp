#include <iostream>

using namespace std;
class graph
{
    int arr[20];
    int adj_matrix[20][20];
    bool visited[20];
    int size;
public:
    graph();
    void add_vertex(int value);
    void add_eadg(int start,int end,int weight);
    void DFS(int node);
    void dispaly();
    void topological();
    void topological1(int node);
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
void graph::dispaly()
{
    char c;
    for(int i=0;i<=size;++i)
    {
        for(int j=0;j<=size;++j)
        {
            c=i+97;
            //cout<<c<<"==="<<s_p[i][j]<<"===";
            c=j+97;
            cout<<c<<"  ,  ";
        }
        cout<<endl;
    }

}
void graph::topological()
{
    int indegree[size+1]={0};
    for(int i=0;i<=size;++i)
    {
        for(int j=0;j<=size;++j)
        {
            if(adj_matrix[i][j]!=100)
                indegree[j]++;
        }
    }


}
int main()
{
    cout << "Hello world!" << endl;
    graph g1;
    g1.add_vertex(97);
    g1.add_vertex(98);
    g1.add_vertex(99);
    g1.add_vertex(100);
    g1.add_vertex(101);
    g1.add_vertex(102);
    g1.add_eadg(0,2,0);
    g1.add_eadg(1,2,0);
    g1.add_eadg(1,3,0);
    g1.add_eadg(2,3,0);
    g1.add_eadg(2,4,0);
    g1.add_eadg(2,5,0);
    g1.add_eadg(3,4,0);
    g1.add_eadg(3,5,0);
    g1.add_eadg(4,5,0);
    g1.DFS(0);
    return 0;
}
