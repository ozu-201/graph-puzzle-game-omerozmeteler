//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "../DisjointSet.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"


namespace array{

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        edges = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }

    void Graph::connectedComponentDisjointSet() {
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (edges[fromNode][toNode] > 0){
                    if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                        sets.unionOfSets(fromNode, toNode);
                    }
                }
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

    Path *Graph::bellmanFord(int source) {
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                for (int toNode = 0; toNode < vertexCount; toNode++){
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert( HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }

    int **Graph::floydWarshall() {
        int** distances;
        distances = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            distances[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++){
                distances[i][j] = edges[i][j];
            }
        }
        for (int k = 0; k < vertexCount; k++){
            for (int i = 0; i < vertexCount; i++){
                for (int j = 0; j < vertexCount; j++){
                    int newDistance = distances[i][k] + distances[k][j];
                    if (newDistance < distances[i][j]){
                        distances[i][j] = newDistance;
                    }
                }
            }
        }
        return distances;
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (paths[toNode].getDistance() > edges[fromNode][toNode]){
                    int position = heap.search(toNode);
                    heap.update(position, edges[fromNode][toNode]);
                    paths[toNode].setDistance(edges[fromNode][toNode]);
                    paths[toNode].setPrevious(fromNode);
                }
            }
        }
    }
    void Graph::search(std::vector<std::string>& words, std::string& start, std::string& target){
        int start_index = -1;
        int target_index = -1;

        for(int i = 0; i < words.size() ; i++){
            if(words[i] == start){
                start_index = i;
            }
            if(words[i] == target){
                target_index = i;
            }
        }
        if(start_index == -1 && target_index == -1){
            std::cout << "Start word and Target word is not found in the dictionary.";
            return;
        }else if(start_index == -1){
            std::cout << "Start word not found in the dictionary";
        }else if(target_index == -1){
            std::cout << "Target word not found in the dictionary";
        }
        std::vector<bool> visited(vertexCount,false);
        std::vector<int> parent(vertexCount,-1);

        Queue queue = Queue(words.size());
        queue.enqueue(Element(start_index));
        visited[start_index] = true;

        while(!queue.isEmpty()){
            int current_node = queue.dequeue().getData();
            for(int to_node = 0; to_node < vertexCount ; to_node++){
                if(edges[current_node][to_node] > 0 && !visited[to_node]){
                    visited[to_node] = true;
                    parent[to_node] = current_node;
                    queue.enqueue(Element(to_node));

                    if(to_node == target_index){
                        std::cout << "Path from '" << start << "' to '" << target <<"' : ";
                        int node = target_index;
                        while(node != start_index){
                            std::cout << words[node] << " <-- ";
                            node = parent[node];
                        }
                        std::cout << words[start_index] << std::endl;
                        return;
                    }
                }
            }
        }
        std::cout << "No path found from" << start << "to" << target << std::endl;
    }

}
