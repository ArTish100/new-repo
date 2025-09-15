#include<iostream>
using namespace std;
#define MAX 10
struct node{
    int vertex;
    struct node *next;
};
void addedge(struct node **, int, int);
void print(struct node **, int);
void BFS(struct node **, int *, int);
int main(){
    struct node **graph;
    int visited[MAX];
    int v, S;
    cout<<"Enter number of vertices : ";
    cin>>v;
    graph = new node*[v];
    for(int i = 0 ; i < v ; i++){
        graph[i]=NULL;
    }
    addedge(graph,1,2);
    addedge(graph,1,3);
    addedge(graph,1,4);
    addedge(graph,2,3);
    for(int i = 0 ; i < v ; i++){
        visited[i]=0;
    }
    cout<<"Enter the start node for BFS traversal : ";
    cin>>S;
    BFS(graph,visited,S);
}

