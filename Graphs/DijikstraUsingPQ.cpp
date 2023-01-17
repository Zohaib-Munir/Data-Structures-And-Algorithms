#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstraAlgo(vector<vector<int>> graph , int source){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int size = graph.size();
    vector<int> distance(size,999);
    distance[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        int vertex= pq.top().second;
        int EdgeWeight = pq.top().first;
        pq.pop();
    
        for(int i=0; i < size; i++){
            if(graph[vertex][i] != 999){
                if(EdgeWeight + graph[vertex][i] < distance[i]){
                    distance[i] = EdgeWeight + graph[vertex][i];
                    pq.push({distance[i], i});
                }
            }
        } 
    }
    return distance;
}
int main(){
    vector<vector<int>> graph ={{999,8,999,2,999,999,999},
                                {8,999,9,999,999,999,999},
                                {999,9,999,999,5,4,1},
                                {2,999,999,999,999,999,3},
                                {999,999,5,999,999,999,999},
                                {999,999,4,999,999,999,6},
                                {999,999,999,3,999,6,999}
                                };
    vector<int> res = dijkstraAlgo(graph,0);

    for(int i=0; i<res.size(); i++){
        cout<<res.at(i)<<" ";
    }



    return 0;
}