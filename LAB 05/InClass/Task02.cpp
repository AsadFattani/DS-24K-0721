#include <iostream>
using namespace std;

#define N 5

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int solution[N][N], int x, int y) {
    // Base case: destination reached
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }
    // Check if current cell is safe and not already part of the solution path
    if (isSafe(maze, x, y) && solution[x][y] == 0) {
        solution[x][y] = 1; // Mark cell as part of solution path

        // Move down
        if (solveMaze(maze, solution, x + 1, y))
            return true;
        // Move right
        if (solveMaze(maze, solution, x, y + 1))
            return true;
        // Move up
        if (solveMaze(maze, solution, x - 1, y))
            return true;
        // Move left
        if (solveMaze(maze, solution, x, y - 1))
            return true;

        solution[x][y] = 0; // Unmark cell (backtrack)
    }
    return false;
}


int main(){
    int maze[N][N] = {
        {1,1,1,0,1},
        {0,1,1,1,1},
        {1,1,1,1,1},
        {1,0,0,0,0},
        {1,1,1,1,1}
    };

    int solution[N][N] = {0};

    if(solveMaze(maze, solution, 0,0)){
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    }
        
    return 0;
}

