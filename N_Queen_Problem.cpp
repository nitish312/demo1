#include<bits/stdc++.h>
using namespace std;

#define N 4

void printMatrix(char matrix[][N]){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(char matrix[][N], int r, int c){

    // check if two queens share the same column
    for(int i=0; i<r; i++){
        if(matrix[i][c] == 'Q'){
            return false;
        }
    }
 
    // check if two queens share the same left diagonal
    int row = r, col = c;
    while(row >=0 && col >= 0){
    	if(matrix[row][col] == 'Q'){
    		return false;
    	}
    	row--;
    	col--;
    }
 
    // check if two queens share the same right diagonal
    row = r, col = c;
    while(row >=0 && col < N){
    	if(matrix[row][col] == 'Q'){
    		return false;
    	}
    	row--;
    	col++;
    }
 
    return true;
}
 
void nQueen(char matrix[][N], int r){

    // base condition
    if(r == N){ 
        printMatrix(matrix);
        return;
    }
 
    // recursively calling function
    for(int i=0; i<N; i++){

        if(isSafe(matrix, r, i)){
            matrix[r][i] = 'Q'; // fill Q if isSafe returns true
            nQueen(matrix, r+1); // next row
            matrix[r][i] = 'x'; // backtracking
        }
    }
}

int main(){

	char matrix[N][N];
	memset(matrix, 'x', sizeof(matrix));
	nQueen(matrix, 0);

	return 0;
}