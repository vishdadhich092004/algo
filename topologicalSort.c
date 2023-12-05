#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node* array[MAX];
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}
void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node** stack) {
    visited[v] = 1;
    struct Node* temp = graph->array[v];
    while (temp) {
        if (!visited[temp->data])
            topologicalSortUtil(graph, temp->data, visited, stack);
        temp = temp->next;
    }
    struct Node* newNode = createNode(v);
    newNode->next = *stack;
    *stack = newNode;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};
    struct Node* stack = NULL;

    for (int i = 0; i < graph->V; ++i)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);

    while (stack) {
        printf("%d ", stack->data);
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
}
int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological Sort: ");
    topologicalSort(graph);
    return 0;
}
