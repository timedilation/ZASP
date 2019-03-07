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

bool findWay(int r, int c)
{
    bool find = false;
    if((r>4) || (c>4))
        return false;
    else if((r==4) && (c==4)) {
        way.push(pair<int,int>(r,c));
        return true;
    }
    else if((grid[r+1][c]==1) && findWay(r+1,c)) {
        way.push(pair<int,int>(r,c));
        return true;
    }
    else if((grid[r][c+1]==1) && findWay(r,c+1)) {
        way.push(pair<int,int>(r,c));
        return true;
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
