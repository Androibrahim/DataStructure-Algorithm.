 

#include <iostream>
using namespace std;
const int maxn = 20;
class graph
{
private: 
    int adj_matrix[maxn][maxn];
    int v;
public:
    graph(int num_vertex)
    {      
        v = num_vertex;
        for (int i = 0; i <maxn; i++)
        {
            for (int j = 0; j <maxn; j++)
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
                    cout << j<<" ";
            }
            cout << endl;
        }
    }

};
int main()
{
    graph ob1(5);

    ob1.add_edge(0, 1);
    ob1.add_edge(0, 2);
    ob1.add_edge(1, 2);
    ob1.add_edge(1, 4);
    ob1.add_edge(2, 3);
    ob1.add_edge(3, 4);

    cout << "initial graph \n";

    ob1.print_graph();

    ob1.remove_edge(1, 4);
    ob1.add_vertx();
    ob1.add_edge(5, 2);
    cout << "\ngraph after removing \n";
    ob1.print_graph();

    return 0;
}

 