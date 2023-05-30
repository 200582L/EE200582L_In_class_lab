#include <iostream>
#include <climits>

#define V 6 

int findMinDistance(int distances[], bool visited[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void runDijkstra(int graph[V][V], int source) {
    int distances[V]; 
    bool visited[V]; 

    
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    
    distances[source] = 0;

    
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(distances, visited);

        
        visited[u] = true;

        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    
    std::cout << "Shortest distances from the source city " << source << ":\n";
    for (int i = 0; i < V; i++) {
        std::cout << "City " << i << ": " << distances[i] << "\n";
    }

    
    int totalDistance = 0;
    int numCities = V - 1; // Excluding the source city itself
    for (int i = 0; i < V; i++) {
        if (i != source) {
            totalDistance += distances[i];
        }
    }
    double averageDistance = static_cast<double>(totalDistance) / numCities;
    std::cout << "Average distance from the source city " << source << ": " << averageDistance << "\n";
    std::cout << "------------------------\n";
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    
    for (int source = 0; source < V; source++) {
        runDijkstra(graph, source);
    }

    return 0;
}
