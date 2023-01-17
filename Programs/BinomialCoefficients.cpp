#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int min(int a, int b){
    return (a < b) ? a : b;
}

int binomialCoeff(int n, int k){
	int C[n + 1][k + 1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= min(i, k); j++){
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	return C[n][k];
}

int main(){
	int n , k;
    
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "Enter the value of k: " << endl;
    cin >> k;

	cout << "Value of nCk is " << binomialCoeff(n , k) << endl;
}
