/*auto maze solution / 
BUL ID:1944419*/
#include<stdio.h>
                       // 0   1   2   3   4   5   6   7   8   9     
int maze[10][10] =       {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1,  //0
                          1 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1,  //1
                          1 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1,  //2
                          1 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 1,  //3
                          1 , 0 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 1,  //4
                          1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1,  //5
                          1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1,  //6
                          1 , 0 , 1 , 1 , 1 , 0 , 1 , 1 , 0 , 1,  //7
                          1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1,  //8
                          1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1   //9
                        } ;
int vis[10][10]; //To judge whether the position has been visited
typedef struct position{
        int x;
        int y;
    }position;
    position pos[100];//To store the right positon
    int idx = 0;
int run(int a, int b)
{
    if (vis[a][b] == 1)//If the position has been visited
        return 0;
    if (maze[a][b] == 1)//If the position is a wall
        return 0;
	
    vis[a][b] = 1;//To mark this position "visited"


    if (a == 8 && b == 8)//destination (8,8)
    {
        pos[idx].x = a;
        pos[idx].y = b;
        idx++;  
        //prepare for printing the last position
        return 1;//logical mark for the right route 
    }

    //search from all directions
    int flag = 0;//initialize the flag

    flag = run(a+1, b);//right
    if (flag == 1)//if it is the right route
    {
        pos[idx].x = a;
        pos[idx].y = b;
        idx++;
        //To store the right position into pos[]
        return 1;
    }


    flag = run(a, b+1);//down
    if (flag == 1)
    {
        pos[idx].x = a;
        pos[idx].y = b;
        idx++;
        return 1;
    }


    flag = run(a-1, b);//left
    if (flag == 1)
    {
        pos[idx].x = a;
        pos[idx].y = b;
        idx++;
        return 1;
    }


    flag = run(a, b-1);//up
    if (flag == 1)
    {
        pos[idx].x = a;
        pos[idx].y = b;
        idx++;
        return 1;
    }
    return 0;
}

/*------------------main function-------------------*/

int main()
{
    run(1, 1);
	printf("The maze is :\n");
	//print the whole maze
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d  ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	printf("The route is :\n");
    for (int i=idx-1; i>=0; i--)
        printf("(%d, %d) \n", pos[i].x, pos[i].y);
    return 0;
}
