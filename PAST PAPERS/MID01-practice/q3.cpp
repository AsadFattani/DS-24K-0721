// question3
// you are given a matrix with letters a, d, t, e, and r.
// a means artifact (+2 points), d means document (+1 point), 
// t means trap (-2 points), e means empty space, and r means the destination.
// start from the first cell and reach r using backtracking.
// you can move up, down, left, or right.
// avoid traps, collect a and d, and print the path, intersections,
//  matrix with path, and total points.
// be careful with backtracking when going backward so the values
//  passed by reference don’t cause errors.
// path ki movement O's sy represent ka bhi bola tha ajeeb or woh matrix bhi chahiye tha..
// A E E T D  
// D E A T T  
// E A D T E  
// D D E T R
// like that last q matrix

#include <iostream>
using namespace std;

#define M 4
#define N 5

bool isSafe(char arr[M][N], int x, int y, char sol[M][N]) {
    return (x >= 0 && x < M && y >= 0 && y < N &&
        (arr[x][y] == 'A' || arr[x][y] == 'D' || arr[x][y] == 'E' || arr[x][y] == 'R' || arr[x][y] == 'T') &&
        sol[x][y] != 'O');
}

bool findPath(char arr[M][N], char sol[M][N], int x, int y, int &points){
    if (x < 0 || x >= M || y < 0 || y >= N) return false;
    if (sol[x][y] == 'O') return false;
    if (arr[x][y] == 'R') {
        sol[x][y] = 'O';
        return true;
    }

    if (isSafe(arr, x, y, sol)){
        sol[x][y] = 'O';
        if (arr[x][y] == 'A') points += 2;
        else if (arr[x][y] == 'D') points += 1;
        else if (arr[x][y] == 'T') points -= 2;
    } else {
        return false;
    }

    if (findPath(arr, sol, x + 1, y, points)) return true; //Move down    
    if (findPath(arr, sol, x, y + 1, points)) return true; //Move Right    
    if (findPath(arr, sol, x, y - 1, points)) return true; //Move left    
    if (findPath(arr, sol, x - 1, y, points)) return true; //Move up    

    sol[x][y] = ' ';
    if (arr[x][y] == 'A') points -= 2;
    else if (arr[x][y] == 'D') points -= 1;
    else if (arr[x][y] == 'T') points += 2;
    
    return false;
};

int main(){
    char arr[M][N] = {
        {'A','E','E','T','D'},
        {'D','E','A','T','T'}, 
        {'E','A','D','T','E'},
        {'D','D','E','T','R'}
    };

    char sol[M][N];
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            sol[i][j] = ' ';
    int points = 0;

    
    if(findPath(arr, sol, 0, 0, points)){
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Total points: " << points << endl;
    } else {
        cout << "No path found!" << endl;
    }

    return 0;
}
