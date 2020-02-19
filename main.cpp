#include <iostream>
using namespace std;
//int getSmallestPathToDestination
void setMatrixField(int * matrix , int row , int column)
{
    for (int i = 0 ; i < column ; i++)
    {
        for (int j = 0 ; j < row ; j++)
        {

        }
    }
}
//void printMatrix
void setSize(int & rowSet , int & columnSet)
{
    cout << "Enter How Many Row You Want? " << endl;
    cin >> rowSet;
    cout << "Enter How Many Column You Want? " << endl;
    cin >> columnSet;
}
int main() {
    int row , column;
    setSize(row , column);
    int matrixField [row][column];
    setMatrixField((int *)matrixField , row , column);
    return 0;
}
