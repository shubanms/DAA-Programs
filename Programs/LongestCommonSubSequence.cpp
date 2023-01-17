#include <iostream>

using namespace std;

int longestCommonSequence(int lengthX , int lengthY , char X[] , char Y[]){
    int matrix[lengthX + 1][lengthY + 1];
   
    for(int i=0;i<=lengthX;i++){
        for(int j=0;j<=lengthY;j++){
            if(i == 0 || j == 0){
                matrix[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                matrix[i][j] = matrix[i-1][j-1] + 1;
            }
            else{
                matrix[i][j] = max(matrix[i-1][j] , matrix[i][j-1]);
            }
        }
    }
   
    return matrix[lengthX][lengthY];
}

int main(){
   
    char X[7] = {'A' , 'B' , 'C' , 'B' , 'D' , 'A' , 'B'};
    char Y[6] = {'B' , 'D' , 'C' , 'A' , 'B' , 'A'};
   
    int lengthX = sizeof(X) / sizeof(X[0]);
    int lengthY = sizeof(Y) / sizeof(Y[0]);
   
    cout << "Length of longest common sub-sequence is " << longestCommonSequence(lengthX , lengthY , X , Y) << "." << endl;
   
    return 0;
}