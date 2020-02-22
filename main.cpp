#include <iostream>
#include <vector>
using namespace std;


void setSize(int & rowSet , int & columnSet)
{
    cout << "Enter How Many Row You Want? " << endl;
    cin >> rowSet;
    cout << "Enter How Many Column You Want? " << endl;
    cin >> columnSet;
}
void printMatrix(vector< vector<int> > matrix , int column , int row)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}
void setMatrixField(vector< vector<int> > &matrix , int row , int column , int & plus , int & minus)
{
    for (int i = 0 ; i < row ; i++)
    {
        for (int j = 0 ; j < column ; j++)
        {
            cout << "This is Column: " << j << " and Row: " << i  << " and Enter \"" << 0 << "\" if You Want to Block This Place or Input Some Other Number for Keeping Open: ";
            int input;
            cin >> input;
            if (input == 0)
            {
                matrix[i][j] = 0;
                minus++;
            }
            else
            {
                matrix[i][j] = 1;
                plus++;
            }
            cout << endl;
        }
        printMatrix(matrix , column , i + 1);
    }
}
void setStartAndEnd(vector< vector<int> > matrix , int & startRow , int & startColumn , int & endRow , int & endColumn)
{
    /// Start
    while (matrix[startRow][startColumn] == 0)
    {
        cout << "What Row Do You Want to Start: " << endl;
        cin >> startRow;
        cout << endl;
        cout << "What Column Do You Want to Start: " << endl;
        cin >> startColumn;
        if (matrix[startRow][startColumn] == 1)
        {
            cout << "Well Done! You are Starting from ["<< startRow << "][" << startColumn << "] " << endl;
            break;
        }
        else
        {
            cout << "You Can't Start from Block Places!!!" << endl << "Enter Again" << endl;
        }
    }
    /// End
    while (matrix[endRow][endColumn] == 0)
    {
        cout << "What Row Do You Want to End: " << endl;
        cin >> endRow;
        cout << endl;
        cout << "What Column Do You Want to End: " << endl;
        cin >> endColumn;
        if (matrix[endRow][endColumn] == 1)
        {
            cout << "Well Done! You will Finish at ["<< endRow << "][" << endColumn << "] " << endl;
            break;
        }
        else
        {
            cout << "You Can't Start from Block Places!!!" << endl << "Enter Again" << endl;
        }
    }
}
int getSmallestPathToDestination(vector< vector<int> > matrix , int startRow , int startColumn , int endRow , int endColumn , int row , int column , int plus , int minus)
{
    cout << "Smallest Path to Destination is : " << endl;
    int tempRow , tempColumn;
    int path = 0 ;
    while (tempRow != endRow && tempColumn != endColumn)
    {
        tempRow = startRow;
        tempColumn = startColumn;
        if (tempRow < endRow && tempColumn < endColumn)
        {
            for (int i = 0; i < plus ; i++)
            {
                if(matrix[tempRow][tempColumn] != 0)
                {
                    
                }
            }
        }
        else if (tempRow > endRow && tempColumn < endColumn)
        {

        }
        else if (tempRow < endRow && tempColumn > endColumn)
        {

        }
        else
        {

        }
    }
}
int main() {
    int row , column;
    setSize(row , column);
    vector< vector<int> > matrixField (row, vector<int>  (column));
    int minus = 0 , plus = 0;
    setMatrixField(matrixField , row , column , plus , minus);
    int startRow = 0 , startColumn = 0 , endRow = 0 , endColumn = 0;
    setStartAndEnd(matrixField , startRow , startColumn , endRow , endColumn );
    getSmallestPathToDestination(matrixField , startRow , startColumn , endRow , endColumn , row , column , plus , minus);
    return 0;
}
