#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graphs{

    public:


    vector<vector<int>> constructGraph(){
        int vertex, edges;
        cout<<"Enter Graph Vertex : ";
        cin>>vertex;
        cout<<"Enter Edges : ";
        cin>>edges;

        vector<vector<int>> matrix (vertex, vector<int>(vertex,0));

        int firstVertex , secondVertex;

        for(int i=0; i<matrix.size(); i++){
            cout<<"First Vertex : ";
            cin>>firstVertex;
            cout<<"Second Vertex : ";
            cin>>secondVertex;


            matrix[firstVertex][secondVertex] =1;
            matrix[secondVertex][firstVertex] = 1;

        }
        return matrix;
    }

    void depthFirstSearch(vector<vector<int>> matrix, int source , vector<bool> & visited){
        cout<<source<<"->";
        visited[source] = true;

        for(int i=0; i<matrix.size(); i++){
            if(matrix[source][i] == 1 && visited[i]== false){
                depthFirstSearch(matrix, i,visited);
            }
        }
    }
    void breathFirstSearch(vector<vector<int>> matrix, int start){
        vector<bool> visited (matrix.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while( !q.empty()){
            int front = q.front();
            q.pop();
            cout<<front<<" ";
            for(int i=0; i<matrix.size(); i++){
                if(matrix[front][i] == 1 && visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
int main(){
    Graphs g;
    vector<vector<int>> matrix = g.constructGraph();
    vector<bool> visited (matrix.size(), false);
    cout<<"DFS Print"<<endl;
    g.depthFirstSearch(matrix,0,visited);
    cout<<"\nBFS Print"<<endl;
    g.breathFirstSearch(matrix,0);
    return 0;
}