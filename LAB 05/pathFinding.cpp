#include <iostream>
using namespace std;

#define N 5

bool isSafe(int maze[N][N],int x,int y){
    return( x >= 0 && x <= N && y >= 0 && y<= N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int solution[N][N],int x, int y){
    if(x == N-1 && y == N-1){
    return true;
    }

    if (isSafe(maze, x, y)){
        solution[x][y] = 1;
    }

    //Move right
    if (solveMaze(maze, solution, x, y+1))
        return true;

    //Move left
    if (solveMaze(maze, solution, x, y-1))
        return true;

    //Move down
    if (solveMaze(maze, solution, x+1, y))
        return true;

    //Move up
    if (solveMaze(maze, solution, x-1, y))
        return true;

    solution[x][y] = 0;

    return false;

}


int main(){
    int maze[N][N] = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,1,0,1,1},
        {1,0,0,1,1},
        {1,1,1,0,1}
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