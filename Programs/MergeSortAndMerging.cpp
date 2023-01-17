#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void printArray(int array[] , int n){
    for(int i=0;i<n;i++){
        cout << array[i] << endl;
    }
   
    cout << endl;
}

void mergeArray(int array[] , int low , int high , int mid){
    int B[high+1];
    int i = low;
    int j = mid+1;
    int k = 0;
   
    while(i <= mid && j <= high){
        if(array[i] <= array[j]){
            B[k] = array[i];
            k++;
            i++;
        }
        else{
            B[k] = array[j];
            k++;
            j++;
        }
    }
   
    for(int n=i;n<=mid;n++){
        B[k] = array[n];
        k++;
    }
   
    for(int n=j;n<=high;n++){
        B[k] = array[n];
        k++;
    }
   
    printArray(B , high+1);
}

void mergeArrays(int A[] , int B[] , int lowA , int highA , int lowB , int highB){
    int C[highA + highB + 2];
    int i = lowA;
    int j = lowB;
    int k = 0;
   
    while(i <= highA && j <= highB){
        if(A[i] <= B[j]){
            C[k] = A[i];
            k++;
            i++;
        }
        else{
            C[k] = B[j];
            k++;
            j++;
        }
    }
   
    for(int n=i;n<=highA;n++){
        C[k] = A[n];
        k++;
    }
   
    for(int n=j;n<=highB;n++){
        C[k] = B[n];
        k++;
    }
   
    printArray(C , highA+highB+2);
}

void merge(int array[] , int low , int mid , int high){
    int B[high+1];
    int i = low;
    int j = mid+1;
    int k = 0;
   
    while(i <= mid && j <= high){
        if(array[i] <= array[j]){
            B[k] = array[i];
            k++;
            i++;
        }
        else{
            B[k] = array[j];
            k++;
            j++;
        }
    }
   
    for(int n=i;n<=mid;n++){
        B[k] = array[n];
        k++;
    }
   
    for(int n=j;n<=high;n++){
        B[k] = array[n];
        k++;
    }
   
    for(int i = low;i<=high;i++){
        array[i] = B[i];
    }
   
}

void mergeSort(int array[] , int low , int high){
    if(low < high){
        int mid = floor((low+high)/2);
        mergeSort(array , low , mid);
        mergeSort(array , mid+1 , high);
        merge(array , low , mid , high);
    }
}

int main(){
   
    int a[5] = {1,2,3,4,5};
    int b[7] = {6,7,8,9,10,11,12};
   
    int A[8] = {2,5,8,12,3,6,7,10};
   
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
   
    int lenOfA = sizeof(a) / sizeof(a[0]);
    int lenOfB = sizeof(b) / sizeof(b[0]);
    int lenOfANew = sizeof(A) / sizeof(A[0]);
    int lenOfArray = sizeof(array) / sizeof(array[0]);
   
    // mergeArrays(a , b , 0 , lenOfA-1 , 0 , lenOfB-1);

    mergeArray(A , 0 , lenOfANew-1 , floor((0+lenOfANew-1)/2));
   
    // mergeSort(array , 0 , lenOfArray-1);
    // printArray(array , lenOfArray);
   
    return 0;
}