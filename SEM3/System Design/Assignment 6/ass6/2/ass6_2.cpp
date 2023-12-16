#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//reference: geeksforgeeks
class Graph {
    private:
        struct Node {   //to hold information of each node
            int index;
            vector<int> connections;
            Node(int num) : index(num){}
        };

        int N;
        vector<Node> nodes;
    
    public:
        //constructor
        Graph(int NumOfNodes) 
        : N(NumOfNodes)
        , nodes(NumOfNodes + 1, 0){}

        void AddConnection(int X, int Y);
        int FindShortestRoute();
};

//adding a connection between node X and node Y (bidrectional)
void Graph::AddConnection(int X, int Y){
    nodes[X].connections.push_back(Y);
    nodes[Y].connections.push_back(X);
}

//BFS algorithm reference: geeksforgeeks 
int Graph::FindShortestRoute(){
    vector<bool> visited(N + 1, false);     //all nodes are unvisited.
    vector<int> shortestRoute(N + 1, 0);   
    
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (int neighbour : nodes[node].connections){
            if (!visited[neighbour]){
                visited[neighbour] = true;
                shortestRoute[neighbour] = shortestRoute[node] + 1;
                q.push(neighbour);
            }
        }
    }
    return shortestRoute[N];
}


int main(){
    int T, N, M;
    int route_count=0;
    
    cin >> T ;  //test cases
    for(int i = 0; i < T; i++)
    {
        cin >> N >> M;  //nodes + connections
        
        Graph graph(N);
        for (int j = 0; j < M; j++){
            int X, Y;   //neighbours
            cin >> X >> Y;
            graph.AddConnection(X, Y);
        }

        route_count = graph.FindShortestRoute();
        cout << route_count << endl;
    }
    return 0;
}
