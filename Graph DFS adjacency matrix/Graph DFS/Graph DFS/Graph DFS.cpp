 

#include <iostream>
using namespace std;


const int maxn = 20;
class graph
{
protected:
    int adj_matrix[maxn][maxn];
    int v;
public:

    void graph_initial(int num_vertex)
    {
        v = num_vertex;
        for (int i = 0; i < maxn; i++)
        {
            for (int j = 0; j < maxn; j++)
                adj_matrix[i][j] = NULL;
        }
    }

    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
    }


    void remove_edge(int u, int v)
    {
        adj_matrix[u][v] = NULL;
    }

    void add_vertx()
    {
        v++;
    }

    void print_graph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "vertex  " << i << " -> ";
            for (int j = 0; j < v; j++)
            {
                if (adj_matrix[i][j] == 1)
                    cout << j << " ";
            }
            cout << endl;
        }
    }

};


class DFS : public graph
{
 protected:
     bool visited[maxn] = {false};
 public:
     
     
     void print_DFS(int start)
     {
         visited[start] = true;
         cout << start << "  ";
         for (int i = 0; i < v; i++)
         {
             if (adj_matrix[start][i] == 1 && visited[i] == false)
             {
                 print_DFS(i);
             }
         }
     }
};




int main()
{
    DFS d;
    d.graph_initial(8);

    d.add_edge(0, 1);
    d.add_edge(0, 3);
    d.add_edge(0, 7);
    d.add_edge(1, 4);
    d.add_edge(1, 5);
    d.add_edge(2, 0);
    d.add_edge(3, 1);
    d.add_edge(3, 2);
    d.add_edge(3, 6);
    d.add_edge(5, 4);
    d.add_edge(7, 6);
     
    d.print_graph();

    cout << "\n =====================\n";

    d.print_DFS(2);
   
    return 0;
}

 












 