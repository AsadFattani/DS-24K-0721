#include <iostream>
using namespace std;

#define N 5

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int solution[N][N], int x, int y, int destX, int destY) {
    if (x == destX && y == destY && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y) && solution[x][y] == 0) {
        solution[x][y] = 1;

        // Move down
        if (solveMaze(maze, solution, x + 1, y, destX, destY))
            return true;
        // Move right
        if (solveMaze(maze, solution, x, y + 1, destX, destY))
            return true;
        // Move up
        if (solveMaze(maze, solution, x - 1, y, destX, destY))
            return true;
        // Move left
        if (solveMaze(maze, solution, x, y - 1, destX, destY))
            return true;

        solution[x][y] = 0;
    }
    return false;
}

void setSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;
}

void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int maze[N][N] = {
        {1,1,1,0,1},
        {0,1,0,1,1},
        {1,1,1,1,0},
        {0,1,0,1,1},
        {1,1,1,0,1}
    };

    int solutionR[N][N];
    setSolution(solutionR);
    int solutionC[N][N];
    setSolution(solutionC);

    cout << "Maze Path for Rabbit from (0,0) to (" << N/2 << "," << N/2 << "):" << endl;
    if(solveMaze(maze, solutionR, 0, 0, N/2, N/2)){
        printSolution(solutionR);
    } else {
        cout << "No path found." << endl;
    }

    cout << "Maze Path for Cat from (2,2) to (" << N-1 << "," << N-1 << "):" << endl;
    if(solveMaze(maze, solutionC, N/2, N/2, N-1, N-1)){
        printSolution(solutionC);
    } else {
        cout << "No path found." << endl;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (solutionR[i][j] == solutionC[i][j] && solutionR[i][j] == 1){
                cout << "Intersection at: (" << i << ", " << j << ")";
                break;
            }
        }
    }


    return 0;
}

