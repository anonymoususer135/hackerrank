# hackerrank

## Mock Test #1
Here is a prompt of a mock test and a quick solution I entered. It was to flip the matrix in the argument of the function, and then add the first two integers of the first row, then those of the second row.

```
int flippingMatrix(vector<vector<int>> matrix) {
    vector<vector<int>> flipped;
    for (int i = 0; i < matrix.size(); i++) {
        flipped.at(i) = matrix.at(matrix.size()-(i-1));
    }
    return (flipped.at(0)).at(0)+(flipped.at(0)).at(1)+(flipped.at(1)).at(0)+(flipped.at(1)).at(1);
}
```
