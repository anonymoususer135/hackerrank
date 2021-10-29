#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector<int> matrix = {1, 2, 3};
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    cout<<matrix.at(0) << endl; //returns 1
    cout << matrix2.at(1).at(2);

    return 0;
}