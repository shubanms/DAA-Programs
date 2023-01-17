#include <iostream>
#include <climits>

using namespace std;

#define INF INT_MAX
#define Vertices 4

void printArray(int matrix[][Vertices]);

void shortestPath(int matrix[][Vertices]){
    for(int k = 0;k<Vertices;k++){
        for(int i = 0;i<Vertices;i++){
            for(int j = 0;j<Vertices;j++){
                if(matrix[i][j] > (matrix[i][k]+matrix[k][j]) && matrix[k][j] != INF && matrix[i][k] != INF){
                    matrix[i][j] = (matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
   
    printArray(matrix);
}

void printArray(int matrix[][Vertices]){
    for(int i=0;i<Vertices;i++){
        for(int j=0;j<Vertices;j++){
                cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
       
}

int main(){

    int graph[Vertices][Vertices] = { {0,3,INF,7},
                        {8,0,2,INF},
                        {5,INF,0,1},
                        {2,INF,INF,0} };
   
    shortestPath(graph);

    return 0;
}