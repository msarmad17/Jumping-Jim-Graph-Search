#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

/*
bfs
{
    load start to q
    mark start as disc

    while q not empty
        de-q v
        en-q undisc Nbors of v, check if any of them is G
        if q size equals 1 and no Nbors in prev step, give up
        mark v exp
        mark v's Nbors as disc
}
*/

int N[2][4];


struct node
{
    int x;
    int y;
    int val;
    int disc;
    int exp;
};

stack<struct node> trav;
stack<struct node> path;

int dfs(struct node * v)
{
    (*v).disc = 1;

    N[0][0] = (*v).x - (*v).val;
    N[0][1] = (*v).x + (*v).val;
    N[0][2] = (*v).x;
    N[0][3] = (*v).x;

    N[0][0] = (*v).y;
    N[1][0] = (*v).y;
    N[2][0] = (*v).y - (*v).val;
    N[3][0] = (*v).y + (*v).val;

    trav.push(*v);

    for(int i = 0; i < 4; i++)
    {
        if(N[i][0] >= 0 && N[i][1] >= 0 && N[i][0] <= r && N[i][1] <= c)
        {
            if( !((maze[(N[i][0])][(N[i][1])]).exp) )
                if( (maze[(N[i][0])][(N[i][1])]).val != 0)
                    dfs( &(maze[(N[i][0])][(N[i][1])]) );
                else
                {
                    trav.push((maze[(N[i][0])][(N[i][1])]));
                    return 0;
                }
        }
    (*v).exp = 1;
    }
}


int main(int argc, char * argv[])
{
    public int r, c;

    ifstream in;

    in.open("in.txt");

    in >> r >> c;

    cout << r << " " << c << endl;

    public struct node maze[r][c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            (maze[i][j]).x = i;
            (maze[i][j]).y = j;
            in >> (maze[i][j]).val;
            (maze[i][j]).disc = 0;
            (maze[i][j]).exp = 0;
        }
    }

    int ch = 0;
    struct node * temp;
    dfs(&(maze[0][0]));


}
