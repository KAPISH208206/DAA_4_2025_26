#include <bits/stdc++.h>
using namespace std;

int chess[10][10] = {0};
int n;

bool vertical(int row, int col){
    for(int i = 0; i < row; i++){
        if(chess[i][col] == 1)
            return false;
    }
    return true;
}

bool left_diagonal(int row, int col){
    while(row >= 0 && col >= 0){
        if(chess[row][col] == 1)
            return false;
        row--;
        col--;
    }
    return true;
}

bool right_diagonal(int row, int col){
    while(row >= 0 && col < n){
        if(chess[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool isSafe(int row, int col){
    return vertical(row, col) &&
           left_diagonal(row, col) &&
           right_diagonal(row, col);
}

void printBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << chess[i][j];
        }
        cout << endl;
    }
    cout << "----------\n";
}

void solve(int row){
    if(row == n){
        printBoard();
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(row, col)){
            chess[row][col] = 1;
            solve(row + 1);
            chess[row][col] = 0;
        }
    }
}

int main(){
    cin >> n;
    if(n > 10){
        return 0;
    }
    solve(0);

    return 0;
}
