#include <iostream>
using namespace std;
//int getSmallestPathToDestination
void printMatrix(const int * matrix , int row , int column)
{
    for (int i = 0 ; i < column ; i++)
    {
        for (int j = 0 ; j < row ; j++)
        {
            cout << *((matrix + i * row) + j) << "   ";
        }
        cout << endl;
    }
}
void setMatrixField(int * matrix , int row , int column)
{
    for (int i = 0 ; i < column ; i++)
    {
        for (int j = 0 ; j < row ; j++)
        {
            cout << "This is Column: " << i << " and Row: " << j << " and Enter \"" << 0 << "\" if You Want to Block This Place or Input Some Other Number for Keeping Open: ";
            int input;
            cin >> input;
            if (input == 0)
            {
                *((matrix + i * row) + j) = 0;
            }
            else
            {
                *((matrix + i * row) + j) = 1;
            }
            cout << endl;
        }
        printMatrix((int *)matrix , row , i+1);
    }
}
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
