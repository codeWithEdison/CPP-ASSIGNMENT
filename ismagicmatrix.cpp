#include<iostream>
#include<vector>
using namespace std;

// creating a function to check if the matrix is magic or not
bool ismagic(vector<vector<int> > matrix) {
    int n = matrix.size();
    
    // check if the matrix is empty
    if (n == 0 || matrix[0].size() == 0) {
        return false;
    }
    
    // finding sum of the first row and using it as a sample 
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[0][i];
    }
    
    // finding sum of each row and each column
    // and check if it is equal to our sample
    for (int i = 0; i < n; ++i) {
        int row_sum = 0;
        int column_sum = 0;
        for (int j = 0; j < n; ++j) {
            row_sum += matrix[i][j];
            if (row_sum != sum) {
                return false;
            }
            column_sum += matrix[j][i];
            if (column_sum != sum) {
                return false;
            }
        }
    }
    
    // finding sum of both diagonals and checking if they are equal to our sample
    int diagonal1_sum = 0;
    int diagonal2_sum = 0;
    for (int i = 0; i < n; ++i) {
        diagonal1_sum += matrix[i][i];
        diagonal2_sum += matrix[i][n - 1 - i];
    }
    if (diagonal1_sum != sum || diagonal2_sum != sum) {
        return false;
    }

    return true;
}


 int main() {
    vector<vector<int> > A;
    A.push_back({0, 0});
    A.push_back({1, 1});
    A.push_back({2, 2});

    if (ismagic(A)) {
        cout << "This is a magic matrix!!\n";
    } else {
        cout << "This is not a magic matrix!!\n";
    }

    return 0;
}
  

