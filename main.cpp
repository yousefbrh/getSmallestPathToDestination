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
void setStartAndEnd(vector< vector<int> > matrix , int & startRow , int & startColumn , int & endRow , int & endColumn , int plus)
{
    /// Start
    while (plus > 0)
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
    while (plus > 0)
    {
        cout << "What Row Do You Want to End: " << endl;
        cin >> endRow;
        cout << endl;
        cout << "What Column Do You Want to End: " << endl;
        cin >> endColumn;
        if (matrix[endRow][endColumn] == 1 && startRow >= endRow && startColumn <= endColumn)
        {
            cout << "Well Done! You will Finish at ["<< endRow << "][" << endColumn << "] " << endl;
            break;
        }
        else
        {
            cout << "There might be two problems" << endl << "1.You Can't Start from Block Places!" << "or" << "2. We can't move to left or down!" << endl;
        }
    }
    if (plus = 0)
    {
        cout << "There is no free way in the matrix!" << endl;
    }
}
void getSmallestPathToDestination(vector< vector<int> > matrix , int startRow , int startColumn , int endRow , int endColumn , int row , int column , int plus , int minus)
{
    int finalPath = row + column;
    for (int i = startRow; i >= endRow ; i--)
    {
        for (int j = startColumn; j <= endColumn ; j++)
        {
            if (matrix[i][j] == 0)
            {
                continue;
            }
            int tempRow = i , tempColumn = j;
            int path;
            path = (startRow - i) + (j - startColumn);
            bool setCondition = true;
            bool permissionPath = true;
            while (setCondition)
            {
                if (tempRow == endRow && tempColumn == endColumn)
                {
                    setCondition = false;
                    continue;
                }
                if (tempRow != endRow)
                {
                    if(matrix[tempRow - 1][tempColumn] == 1)
                    {
                        tempRow--;
                        path++;
                    }
                    else if (matrix[tempRow][tempColumn + 1] == 1)
                    {
                        tempColumn++;
                        path++;
                    }
                    else
                    {
                        permissionPath = false;
                        setCondition = false;
                    }
                    continue;
                }
                if (tempColumn != endColumn)
                {
                    if (matrix[tempRow][tempColumn + 1] == 1)
                    {
                        tempColumn++;
                        path++;
                    }
                    else
                    {
                        permissionPath = false;
                        setCondition = false;
                    }
                }
            }
            if ((i == startRow && j == startColumn && permissionPath) || (path < finalPath && permissionPath))
            {
                finalPath = path;
            }
        }
    }
    cout << "Smallest Path to destination is: " << finalPath << endl;
}
int main() {
    int row , column;
    setSize(row , column);
    vector< vector<int> > matrixField (row, vector<int>  (column));
    int minus = 0 , plus = 0;
    setMatrixField(matrixField , row , column , plus , minus);
    int startRow = 0 , startColumn = 0 , endRow = 0 , endColumn = 0;
    setStartAndEnd(matrixField , startRow , startColumn , endRow , endColumn , plus );
    getSmallestPathToDestination(matrixField , startRow , startColumn , endRow , endColumn , row , column , plus , minus);
    return 0;
}
