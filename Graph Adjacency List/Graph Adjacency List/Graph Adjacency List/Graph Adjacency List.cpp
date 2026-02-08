
#include <iostream>
#include<list>
using namespace std;


class graph
{
private:
    int max_size = 20;
    list<int>* adj_list  = new list<int>[max_size];
    int vertex;
public:
    graph(int num_vertex)
    {
        vertex = num_vertex;
        for (int i = 0; i < max_size; i++)
            adj_list[i].clear();
    }

    void add_edge(int u, int v)
    {
        adj_list[u].push_back(v);
    }



    void remove_edge(int u, int v)
    {
        list<int>::iterator it ;
        for (it = adj_list[u].begin();  it != adj_list[u].end(); it++)
        {
            if (*it == v)
            {
                adj_list[u].erase(it);
                break;
            }
        }
    }

    void add_vertex()
    {
        vertex++;
    }
    void print_graph()
    {
        list<int>::iterator it;
        for (int i = 0; i < vertex; i++)
        {
            cout << "vertex " << i << " -> ";
            for (it = adj_list[i].begin(); it != adj_list[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

};
int main()
{
    graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    cout << "initial graph \n";
    g.print_graph();

    cout << "\n after removing edge \n";
    g.remove_edge(1, 4);
    g.add_vertex();
    g.add_edge(5, 1);
    g.print_graph();
    return 0;
}

 