 
#include <iostream>
#include<queue>
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


class BFS : public graph
{
private:
    bool visited[maxn] = { false };
    queue<int>q;
public:
    void BFS_print(int start)
    {
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << "  ";
            for (int i = 0; i < v; i++)
            {
                if (adj_matrix[u][i] == 1 && visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    BFS d;

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
    
     
    cout << "\nafter adding vertex";
    d.add_vertx();
    d.add_edge(0 , 8);
    cout << "\n";
    d.print_graph();
    cout << "\n==================\n";
    cout << "breadth first search \n";
    d.BFS_print(2);

    return 0;
}

 