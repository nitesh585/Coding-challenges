/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by 0.

Note:

    The given board contain only digits 0-9.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.

*/


#include<iostream>
using namespace std;

#define N 9

bool checkRow(int ar[][N], int row, int num){
    for(int i=0; i<N; i++){
        if(ar[row][i]==num) return true;
    }
    return false;
    
}

bool checkCol(int ar[][N], int col,int num){
    for(int i=0; i<N; i++){
        if(ar[i][col]==num) return true;
    }
    return false;
}

bool checkBlock(int ar[][N], int rs, int cs,int num){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(ar[row+rs][col+cs]==num) return true;
        }
    }
    return false;
}

bool isSafe(int ar[][N],int row, int col, int num){
    return !checkRow(ar,row,num) && !checkCol(ar,col,num) && !checkBlock(ar,(row/3)*3, (col/3)*3, num) && ar[row][col]==0;
}

bool findUnassigned(int ar[][N], int &row, int &col){
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(ar[row][col]==0) return true;
        }
    }
    return false;
}

bool solver(int ar[][N]){
    int row, col;
    
    if(!findUnassigned(ar,row,col)) return true;
    
    for(int i=1; i<=9; i++){
        if(isSafe(ar, row, col, i)){
            ar[row][col]=i;
         
            if(solver(ar)) return true;
         
            ar[row][col] = 0;        
        }
    }
    return false;
}


void printGrid(int ar[][N]){
    // Print solution
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            cout<<ar[i][j]<<" ";
	        }
	    }
}


int main(){
	int t;
	cin>>t;
	while(t--){
	    int ar[N][N];
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            cin>>ar[i][j];
	        }
	    }
	    
	    if(solver(ar)) printGrid(ar);
	    else cout<<-1;
	    
	    cout<<"\n";
	}
	
	return 0;
}
