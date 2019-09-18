#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct node
{
    int x;
    int y;
    int val;
    int disc;
    int exp;
    string route;
};

string north = "N\0";
string south = "S\0";
string east = "E\0";
string west = "W\0";


int main(int argc, char * argv[])
{
    int r, c;

    ifstream in;

    in.open("input.txt");

    in >> r >> c;

    struct node maze[r][c];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            (maze[i][j]).x = i;
            (maze[i][j]).y = j;
            in >> (maze[i][j]).val;
            (maze[i][j]).disc = 0;
            (maze[i][j]).exp = 0;
            (maze[i][j]).route = "\0";
        }
    }

    in.close();

    struct node *temp;
    queue<struct node> trav;

    trav.push((maze[0][0]));
    (maze[0][0]).disc = 1;


    while(!trav.empty())
    {
        temp = &(trav.front());

        string str = temp->route + '\0';

        trav.pop();


        if( (*temp).x == r-1 && (*temp).y == c-1 )
        {
            ofstream out;

            out.open("output.txt");

            out << str;

            out.close();

            break;
        }


        if((*temp).x - (*temp).val >= 0) //up
            if( !((maze[(*temp).x - (*temp).val][(*temp).y]).disc) )
            {
                (maze[(*temp).x - (*temp).val][(*temp).y]).disc = 1;
                (maze[(*temp).x - (*temp).val][(*temp).y]).route = str + north + '\0';
                trav.push( (maze[(*temp).x - (*temp).val][(*temp).y]) );
            }

        if((*temp).x + (*temp).val <= r-1) //down
            if( !((maze[(*temp).x + (*temp).val][(*temp).y]).disc) )
            {
                (maze[(*temp).x + (*temp).val][(*temp).y]).disc = 1;
                (maze[(*temp).x + (*temp).val][(*temp).y]).route = str + south + '\0';
                trav.push( (maze[(*temp).x + (*temp).val][(*temp).y]) );
            }

        if((*temp).y - (*temp).val >= 0) //left
            if( !((maze[(*temp).x][(*temp).y - (*temp).val]).disc) )
            {
                 (maze[(*temp).x][(*temp).y - (*temp).val]).disc = 1;
                 (maze[(*temp).x][(*temp).y - (*temp).val]).route = str + west + '\0';
                 trav.push( (maze[(*temp).x][(*temp).y - (*temp).val]) );
            }

        if((*temp).y + (*temp).val <= c-1) //right
            if( !((maze[(*temp).x][(*temp).y + (*temp).val]).disc) )
            {
                (maze[(*temp).x][(*temp).y + (*temp).val]).disc = 1;
                (maze[(*temp).x][(*temp).y + (*temp).val]).route = str + east + '\0';
                trav.push( (maze[(*temp).x][(*temp).y + (*temp).val]) );
            }

        (*temp).exp = 1;

    }


}

