#include <bits/stdc++.h>
using namespace std;

// Define an Edge structure
struct Edge {
    string destination;
    int distance;
};

// Define a Graph class
class Graph {
private:
    map<string, vector<Edge>> adjList;

public:
    // Constructor that adds all edges
Graph() {
    // Add edges to the graph
addEdge("Saddar", "Clifton", 6);
addEdge("Saddar", "Korangi", 15);
addEdge("Saddar", "Lyari", 9);
addEdge("Saddar", "Gulshan", 3);
addEdge("Clifton", "Korangi", 18);
addEdge("Clifton", "Saddar", 12);
addEdge("Korangi", "Stadium", 24);
addEdge("Korangi", "Gulshan", 30);
addEdge("Korangi", "Jinnah Bridge", 9);
addEdge("Lyari", "Gulshan", 6);
addEdge("Lyari", "Saddar", 12);
addEdge("Lyari", "Saddar", 21);
addEdge("Gulshan", "Saddar", 18);
addEdge("Gulshan", "Korangi", 9);
addEdge("Gulshan", "Saddar", 21);
addEdge("Gulshan", "Jinnah Bridge", 18);
addEdge("Gulshan", "Beach", 9);
addEdge("Korangi", "Gulshan", 12);
addEdge("Korangi", "Beach", 21);
addEdge("Jinnah Bridge", "Saddar", 12);
addEdge("Jinnah Bridge", "Korangi", 6);
addEdge("Beach", "Stadium", 18);
addEdge("Stadium", "Saddar", 9);
addEdge("Stadium", "Beach", 6);

}


    // Add edge to the graph
    void addEdge(const string& source, const string& destination, int distance) {
        adjList[source].push_back(Edge{destination, distance});
        // Since it's bidirectional
        adjList[destination].push_back(Edge{source, distance});
    }

    // Method to print all location points
    void printLocations() {
        cout << "Locations:" << endl;
        for (const auto& pair : adjList) {
            cout << "- " << pair.first << endl;
        }
    }

    // Dijkstra's algorithm to find the shortest path
    map<string, pair<int, string>> dijkstra(const string& source) {
        map<string, pair<int, string>> distances;
        set<pair<int, string>> queue;

        // Initialize distances to infinity and set predecessors to empty
        for (auto& vertex : adjList) {
            distances[vertex.first] = {numeric_limits<int>::max(), ""};
        }

        // Set the distance for the source
        distances[source].first = 0;
        queue.insert({0, source});

        while (!queue.empty()) {
            auto front = *queue.begin();
            queue.erase(queue.begin());

            int distance = front.first;
            string current = front.second;

            // Visit all neighbors
            for (auto& edge : adjList[current]) {
                int newDist = distance + edge.distance;
                if (newDist < distances[edge.destination].first) {
                    queue.erase({distances[edge.destination].first, edge.destination});
                    distances[edge.destination] = {newDist, current};
                    queue.insert({newDist, edge.destination});
                }
            }
        }

        return distances;
    }

    // Method to print the shortest path
    int printShortestPath(const string& source, const string& destination) {
        auto distances = dijkstra(source);
        vector<string> path;
        string current = destination;
        int totalDistance = 0;  // Initialize total distance

        while (current != source) {
            path.push_back(current);
            totalDistance += distances[current].first;  // Accumulate distance
            current = distances[current].second;
        }
        path.push_back(source);

        reverse(path.begin(), path.end());

        cout << "Shortest path from " << source << " to " << destination << ":" << endl;
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        // cout << "Total distance: " << totalDistance << " km" << endl;  // Print total distance
        return totalDistance; // Return total distance
    }

};

// int main() {
//     Graph g; // Graph is now initialized with all edges
//     g.printLocations(); // Print all locations

//     string source, destination;
//     cout << "Enter source location: ";
//     // cin >> source;
//     getline(cin, source);
//     cout << "Enter destination location: ";
//     // cin >> destination;
//     getline(cin, destination);

//     int distance = g.printShortestPath(source, destination); // Print the shortest path and total distance
//     cout<<distance<<" Km"<<endl;

//     return 0;
// }
