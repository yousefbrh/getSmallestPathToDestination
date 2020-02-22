#include <iostream>
using namespace std;
//int getSmallestPathToDestination
// ye tabe votodi dorost konam ke column mide on sotono chap kone bad bege kodomo mikhad

void setSize(int & rowSet , int & columnSet)
{
    cout << "Enter How Many Row You Want? " << endl;
    cin >> rowSet;
    cout << "Enter How Many Column You Want? " << endl;
    cin >> columnSet;
}
void printMatrix(const int * matrix , int column , int row)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << *((matrix + i) + j) << "   ";
        }
        cout << endl;
    }
}
void setMatrixField(int * matrix , int row , int column)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << "This is Column: " << j << " and Row: " << i << " and Enter \"" << 0 << "\" if You Want to Block This Place or Input Some Other Number for Keeping Open: ";
            int input;
            cin >> input;
            cout << *((matrix + 0) + 4) << endl;
            if (input == 0)
            {
                *((matrix + i) + j) = 0;
            }
            else
            {
                *((matrix + i) + j) = 1;
            }
            cout << endl;
        }
        printMatrix((int *)matrix , column , i + 1);
    }
}
void setStartAndEnd(const int * matrix , int & startRow , int & startColumn , int & endRow , int & endColumn , int row , int column)
{
    cout << *((matrix + 0) + 4) << endl;
    /// Start
    while (*((matrix + startColumn) + startRow) == 0)
    {
        cout << "What Row Do You Want to Start: " << endl;
        cin >> startColumn;
        for (int i = 0 ; i < row ; i++)
        {
            cout <<  *((matrix + startColumn) + i) << "  ";
        }
        cout << endl;
        cout << "What Column Do You Want to Start: " << endl;
        cin >> startRow;
        if (*((matrix + startColumn) + startRow))
        {
            cout << "Well Done! You are Starting from ["<< startColumn << "][" << startRow << "] " << endl;
            break;
        }
        else
        {
            cout << "You Can't Start from Block Places!!!" << endl << "Enter Again" << endl;
        }
    }
    /// End
    while (*((matrix + endColumn) + endRow) == 0)
    {
        cout << "What Row Do You Want to End: " << endl;
        cin >> endColumn;
        for (int i = 0 ; i < row ; i++)
        {
            cout <<  *((matrix + endColumn) + i) << "  ";
        }
        cout << endl;
        cout << "What Column Do You Want to End: " << endl;
        cin >> endRow;
        if (*((matrix + endColumn) + endRow))
        {
            cout << "Well Done! You are Starting from ["<< endColumn << "][" << endRow << "] " << endl;
            break;
        }
        else
        {
            cout << "You Can't Start from Block Places!!!" << endl << "Enter Again" << endl;
        }
    }
}
int main() {
    int row , column;
    setSize(row , column);
    int matrixField [row][column];
    setMatrixField((int *)matrixField , row , column);
    int startRow = 0 , startColumn = 0 , endRow = 0 , endColumn = 0;
    setStartAndEnd((int *) matrixField , startRow , startColumn , endRow , endColumn , row , column);
    return 0;
}
