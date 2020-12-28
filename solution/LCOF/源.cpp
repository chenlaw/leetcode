#include<vector>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool DFS(int i, int j, int rows, int cols, char* matrix, char* str) {
    if (matrix[i * rows + cols] != str[0])
        return false;

}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (DFS(i, j,rows,cols, matrix, str))
                return true;
        }
    }
    return false;
}