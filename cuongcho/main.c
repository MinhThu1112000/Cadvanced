/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "fileprocess.h"

//[i][j] tu [0][0] toi [row-1][col-1]
//tesst 1 [i][j+1], 2 [i+1][j], 3 [i][j-1], 4 [i-1][j]
// tra ve 1 neu co duong vaf 0 neu ko ton tai
int try(char **Graph, int row, int col, int currow, int curcol)
{
    if(currow==row-1 && curcol==col-1) { // diem cuoi cung
        Graph[currow][curcol]=3;
        return 1;
    }
    if(Graph[currow][curcol]==0 || Graph[currow][curcol]==3) return 0;
    Graph[currow][curcol]=3; // danh dau de ko quay lai
    if(currow==0) // hang dau
    {
        // dau hang, dau cot
        if(curcol==0) return try(Graph,row,col,currow, curcol+1) ||
                             try(Graph,row,col,currow+1, curcol);
        else if(curcol==col-1)  // dau hang, cot cuoi
            return try(Graph,row,col,currow+1, curcol) ||
                   try(Graph,row,col,currow, curcol-1);
        else // giua hang tren cung
            return try(Graph,row,col,currow, curcol+1) ||
                   try(Graph,row,col,currow+1, curcol) ||
                   try(Graph,row,col,currow, curcol-1);

    }
    else if(currow==row-1) // hang cuoi
    {
        // cuoi hang, dau cot
        if(curcol==0) return try(Graph,row,col,currow, curcol+1) ||
                             try(Graph,row,col,currow-1, curcol);
        else if(curcol==col-1)  // cuoi hang, cot cuoi  (bo qua)
            return try(Graph,row,col,currow-1, curcol) ||
                   try(Graph,row,col,currow, curcol-1);
        else // hang cuoi, giua cot
            return try(Graph,row,col,currow, curcol+1) ||
                   try(Graph,row,col,currow, curcol-1) ||
                   try(Graph,row,col,currow-1, curcol);
    }
    else // giua hang
    {
        if(curcol==0) return try(Graph,row,col,currow, curcol+1) ||
                             try(Graph,row,col,currow-1, curcol)||
                             try(Graph,row,col,currow+1, curcol);
        else if(curcol==col-1)  // giua hang, cot cuoi
            return try(Graph,row,col,currow+1, curcol) ||
                   try(Graph,row,col,currow, curcol-1)||
                   try(Graph,row,col,currow-1, curcol);
        else // hang cuoi, giua cot
            return try(Graph,row,col,currow, curcol+1) ||
                   try(Graph,row,col,currow+1, curcol) ||
                   try(Graph,row,col,currow, curcol-1) ||
                   try(Graph,row,col,currow-1, curcol);
    }
}
int checkPath(char **Graph, int row, int col)
{
    int retval = try(Graph,row,col,0,0);
    if(retval==1)
        printf("Ton tai duong di!\n");
    else
        printf("KHONG ton tai duong di!\n");
}
int main()
{
    char **Graph;
    int row, col;
    Graph = readFile("input1.txt", &row, &col);
    printGraph(Graph, row, col);
    checkPath(Graph, row, col);
    printGraph(Graph, row, col);
    return 0;
}
