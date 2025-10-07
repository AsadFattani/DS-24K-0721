#include <iostream>
using namespace std;

#define N 6

bool isSafe(char maze[N][N], int x, int y){
    return(x >= 0 && x < N && y >= 0 && y < N && (maze[x][y] == 'P' || maze[x][y] == 'S' || maze[x][y] == 'T'));
}

bool findPath(char maze[N][N], char sol[N][N], int x, int y){
    if(x == N-1 && y == N-1){
        sol[x][y] = 'P';
        return true;
    }

    if(isSafe(maze, x, y) && sol[x][y] == ' ' ){
        if(x == 0 && y == 0)
            sol[x][y] = 'S';
        else
            sol[x][y] = 'P';

        if(findPath(maze, sol, x, y+1)) return true; //Move Right
        if(findPath(maze, sol, x+1, y)) return true; //Move Down
        if(findPath(maze, sol, x, y-1)) return true; //Move Left
        if(findPath(maze, sol, x-1, y)) return true; //Move Up

        sol[x][y] = ' ';
    }
    return false;
}

int main(){
    char maze[N][N] = {
        {'S', 'P', 'P', 'D', 'H', 'H'},
        {'P', 'P', 'P', 'D', 'P', 'H'},
        {'P', 'H', 'P', 'P', 'P', 'D'},
        {'P', 'D', 'P', 'D', 'P', 'P'},
        {'P', 'P', 'P', 'H', 'P', 'D'},
        {'P', 'D', 'P', 'P', 'P', 'T'}
        // {'S', 'P', 'P', 'D', 'H', 'H'},
        // {'P', 'P', 'P', 'D', 'P', 'H'},
        // {'P', 'H', 'P', 'P', 'P', 'D'},
        // {'P', 'D', 'P', 'D', 'P', 'P'},
        // {'P', 'P', 'P', 'H', 'P', 'D'},
        // {'P', 'D', 'P', 'P', 'P', 'T'}
    };

    char sol[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sol[i][j] = ' ';

    if(findPath(maze, sol, 0, 0)){
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No path exists" << endl;
    }

    return 0;

}