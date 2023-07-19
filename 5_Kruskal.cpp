
#include <bits/stdc++.h>
using namespace std;
 
class Edge {
    public:
        int src, dest, weight;
};

class Subset {
    public:
        int parent;
        int rank;
};

class Graph {
    public:
        int V, E;
        Edge* edge;
};
 
Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}
 
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
 
    return subsets[i].parent;
}
 
void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;

    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else 
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0; //for result[]
    int i = 0; //for sorted edges
 
    //1). Sort all the edges in non-decreasing order of their weight.
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    //Allocate memory for creating V subsets
    Subset* subsets = new Subset[(V * sizeof(Subset))];
 
    //Create V subsets with single elements
    for (int v = 0; v < V; ++v) 
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    //Number of edges to be taken is equal to V-1
    while(e<V-1 && i<graph->E) 
    {
        //2). Pick the smallest edge. And increment the index for next iteration
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        //If including this edge does't cause cycle, include it in result and increment the index of result for next edge
        if (x != y) 
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }

        //Else discard the next_edge
    }
 
    //Printing MST which is in result[]
    cout <<"\nFollowing are the edges in the constructed MST\n";
    cout<<"Edge\t\tWeight\n";
    int minimumCost = 0;
    for (i=0; i<e; i++) 
    {
        cout<<result[i].src<<" -- "<<result[i].dest<<"\t  == \t  "<<result[i].weight<<endl;
        minimumCost = minimumCost + result[i].weight;
    }

    cout<<"Minimum Cost Spanning Tree :- "<<minimumCost<<endl;
}
 
int main()
{
    int V = 4;
    int E = 5; 
    Graph* graph = createGraph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
 
    return 0;
}