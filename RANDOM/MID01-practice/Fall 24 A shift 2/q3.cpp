#include <iostream>
using namespace std;

#define N 6

bool isSafe(char arr[N][N], int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N && (arr[x][y] == 'H' || arr[x][y] == 'D' || arr[x][y] == 'S'));
}

bool findPath(char arr[N][N], char sol[N][N], int x, int y, int &damage){
    if(x == N-1 && y == N-1){
        return true;
    }

    if (isSafe(arr, x, y) && sol[x][y] == ' '){
        sol[x][y] = 'S';

        if (findPath(arr, sol, x, y+1, damage)) return true;
        if (findPath(arr, sol, x+1, y, damage)) return true;
        if (findPath(arr, sol, x, y-1, damage)) return true;
        if (findPath(arr, sol, x-1, y, damage)) return true;

        sol[x][y] = ' ';
        if (arr[x][y] == 'R') damage ++;
    }
    return false;
}

int main(){
    char arr[N][N] = {
        {'H', 'S', 'S', 'X', 'R', 'R'},
        {'S', 'S', 'S', 'X', 'S', 'R'}, 
        {'S', 'R', 'S', 'S', 'S', 'X'},
        {'S', 'S', 'S', 'R', 'S', 'X'},
        {'S', 'X', 'S', 'S', 'S', 'D'}
    };

    char sol[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = ' ';

    int damage = 0;
    if (findPath(arr, sol, 0, 0, damage)){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (damage == 0){
        cout << "YOu on Safest path!" << endl;
    } else {
        cout << "You need " << damage + 1 << " minimum hp to survive the journey!" << endl;
    }
    

    return 0;
}



