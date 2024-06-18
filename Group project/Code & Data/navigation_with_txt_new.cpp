//
// Created by Quan on 2024/4/28.
//
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int id;
    pair<double, double> coordinates;
};

struct Edge {
    int id;
    int startNodeId;
    int endNodeId;
    double length;
};

vector<Node> nodes;
vector<Edge> edges;

void readNodeData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int id;
        double lat, lon;
        if (iss >> id >> lat >> lon) {
            nodes.push_back({id, {lat, lon}});
        } else {
            cerr << "Invalid node data: " << line << endl;
        }
    }
    file.close();
}

void readEdgeData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (std::getline(file, line)) {
        istringstream iss(line);
        int id, startNodeId, endNodeId;
        double length;
        if (iss >> id >> startNodeId >> endNodeId >> length) {
            edges.push_back({id, startNodeId, endNodeId, length});
            edges.push_back({id, endNodeId, startNodeId, length});
        } else {
            cerr << "Invalid edge data: " << line << endl;
        }
    }
    file.close();
}

pair<vector<int>, double> findway(int startNodeId, int endNodeId) {
    map<int, int> nodeIndexMap;
    for (size_t i = 0; i < nodes.size(); ++i) {
        nodeIndexMap[nodes[i].id] = i;
    }

    vector<double> distance(nodes.size(), numeric_limits<double>::infinity());
    distance[nodeIndexMap[startNodeId]] = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, nodeIndexMap[startNodeId]});

    vector<int> predecessor(nodes.size(), -1);

    while (!pq.empty()) {
        auto [dist, curr] = pq.top();
        pq.pop();

        for (const Edge &edge : edges) {
            if (edge.startNodeId == nodes[curr].id) {
                int neighborIndex = nodeIndexMap[edge.endNodeId];
                double newDist = dist + edge.length;

                if (newDist < distance[neighborIndex]) {
                    distance[neighborIndex] = newDist;
                    predecessor[neighborIndex] = curr;
                    pq.push({newDist, neighborIndex});
                }
            }
        }
    }

    vector<int> path;
    int curr = nodeIndexMap[endNodeId];
    while (curr != -1) {
        path.push_back(nodes[curr].id);
        curr = predecessor[curr];
    }
    reverse(path.begin(), path.end());

    double totalLength = 0.0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        int startId = path[i];
        int endId = path[i + 1];
        for (const Edge &edge : edges) {
            if ((edge.startNodeId == startId && edge.endNodeId == endId) || (edge.startNodeId == endId && edge.endNodeId == startId)) {
                totalLength += edge.length;
                break;
            }
        }
    }

    return make_pair(path, totalLength);
}


void print_map() {
    cout << "____________________________________________________________________________________" << endl;
    cout << "|                     Welcome to Longgang City Navigation!                         |" << endl;
    cout << "|                                                                                  |" << endl;
    cout << "|                        Here is map of Longgang City                              |" << endl;
    cout << "|                                                                                  |" << endl;
    cout << "|                                      @------------------------(7)                |" << endl;
    cout << "|                                     /                          |                 |" << endl;
    cout << "|                                    /                           |                 |" << endl;
    cout << "|                       (5)--------(6)-----------(22)-----------(8)                |" << endl;
    cout << "|                       /|          |             |              |                 |" << endl;
    cout << "|                      / |          |             |              |                 |" << endl;
    cout << "|                     /  |          |            (23)-----------(9)                |" << endl;
    cout << "|                    /   |          |             |              |                 |" << endl;
    cout << "|                   /    |          |             |             (10)               |" << endl;
    cout << "|                  /    (20)-------(21)----------(24)           /|                 |" << endl;
    cout << "|           @-----(4)    |                        |            / |                 |" << endl;
    cout << "|          /       \\     |                        |           /  |                 |" << endl;
    cout << "|         /         \\    |                        |          /  (11)               |" << endl;
    cout << "|       (3)--------(19)-(34)                     (25)-------@    /\\                |" << endl;
    cout << "|       /           |    |                       /  \\           /  \\               |" << endl;
    cout << "|      |            |    |                     /      \\        /    \\              |" << endl;
    cout << "|     (2)----------(18)-(33)                 (27)     (26)----@     (12)           |" << endl;
    cout << "|      |            |     \\                 /  \\       /             /             |" << endl;
    cout << "|      |            |      \\              /     \\    /              /              |" << endl;
    cout << "|      |            |        \\        (29)       (28)             /                |" << endl;
    cout << "|      |            |         \\       /  \\       /               /                 |" << endl;
    cout << "|     (1)----------(17)        \\    /     \\    /               /                   |" << endl;
    cout << "|       \\             \\         (31)       (30)               /                    |" << endl;
    cout << "|        \\              \\      /    \\      /                /                      |" << endl;
    cout << "|         \\              \\    /      \\    /                /                       |" << endl;
    cout << "|          \\       @------(32)        \\  /               /                         |" << endl;
    cout << "|           \\      |         \\        (13)--------------@                          |" << endl;
    cout << "|            \\    /            \\      /                                            |" << endl;
    cout << "|             \\ /                (14)                                              |" << endl;
    cout << "|             (16)                /                                                |" << endl;
    cout << "|              /                 /                                                 |" << endl;
    cout << "|           (15)----------------@                                                  |" << endl;
    cout << "|                                                                                  |" << endl;
    cout << "|__________________________________________________________________________________|" << endl;

}

bool nodeExists(int nodeId) {
    for (const Node &node : nodes) {
        if (node.id == nodeId) {
            return true;
        }
    }
    return false;
}

int getValidInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Invalid input. Please enter a valid integer: ";
        } else if (!nodeExists(input)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Node " << input << " does not exist in the map. Please enter a valid node ID: ";
        } else {
            return input;
        }
    }
}

int main() {
    readNodeData("nodes_longgang.txt");
    readEdgeData("edges_longgang.txt");

    print_map();


    while (true) {
        int startNodeId, endNodeId;
        cout << endl;
        cout << "_____________________________________________________" << endl;
        cout << "Enter the ID of your starting point: ";
        startNodeId = getValidInput();
        cout << endl;

        cout << "Enter the ID of your destination: ";
        endNodeId = getValidInput();
        cout << endl;


        pair<vector<int>, double> pathAndEdges = findway(startNodeId, endNodeId);

        cout << "Suggested path: ";
        for (int nodeId : pathAndEdges.first) {
            if (nodeId == pathAndEdges.first[pathAndEdges.first.size() - 1]) {
                cout << nodeId << endl;
            } else {
                cout << nodeId << " --> ";
            }
        }
        cout << endl;
        cout << "Detailed information:" << endl;
        cout << endl;
        cout << "   Total distance: " << pathAndEdges.second / 3 << " kilometers" << endl;
        cout << endl;
        cout << "   Number of nodes traversed: " << pathAndEdges.first.size();
        cout << endl;
        cout << "_____________________________________________________" << endl;
        string state;
        cout << endl;
        cout << "Enter 'q' to quit or press any other key to continue: ";
        cin >> state;
        cout << endl;
        if (state == "Q" or state == "q") {
            cout << "Thank for using our system! Goodbye!" << endl;
            cout << endl;
            break;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
