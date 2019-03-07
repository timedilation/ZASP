#include <iostream>
#include <stack>
using namespace::std;
#define N 5

int grid[N][N] = {
    {1,1,1,1,1},
    {1,1,0,1,0},
    {1,0,0,1,1},
    {0,0,0,0,1},
    {0,0,0,1,1}
};

stack<pair<int,int> > way;
int isVisited[N][N] = {};

bool findWay(int r, int c)
{
    isVisited[r][c] = 1;
    if((r>4) || (c>4))
        return false;
    if(grid[r][c] == 0)
        return false;
    if((r==4) && (c==4)) {
        way.push(pair<int,int>(r,c));
        return true;
    }
    if(isVisited[r+1][c] == 0) {
        if(findWay(r+1,c)) {
            way.push(pair<int,int>(r,c));
            return true;
        }
    }
    if(isVisited[r][c+1] == 0) {
        if(findWay(r,c+1)) {
            way.push(pair<int,int>(r,c));
            return true;
        }
    }
    return false;
}

int main()
{
    findWay(0,0);
    while(way.empty()==false) {
        cout << way.top().first << "," <<way.top().second << endl;
        way.pop();
    }
    return 0;
}
