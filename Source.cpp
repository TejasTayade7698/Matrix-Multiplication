#include<iostream>
using namespace std;

class Matrix { //class defining matrix operation functions
private:
    int** M;
    int num_rows, num_cols;
public:
    Matrix();
    Matrix(int, int);
    Matrix operator*(Matrix); // '*' operator overloading for matrix multiplication
    Matrix transpose();
    friend ostream& operator<<(ostream&, Matrix&); // '<<' overloading for printing matrix as output 
    friend istream& operator>>(istream&, Matrix&); // '>>' overloading for taking input as matrix
};

Matrix::Matrix() { // constructer initialisation 
    num_rows = 0;
    num_cols = 0;
}
Matrix::Matrix(int m, int n) { //constructer definition
    num_rows = m;
    num_cols = n;
    M = new int* [num_rows]; // dynamic memory allocation
    for (int i = 0; i < num_rows; i++) {
        M[i] = new int[num_cols];
    }
}
Matrix Matrix :: operator*(Matrix A) { //
    Matrix P;
    if (num_cols != A.num_rows) { //to check if matrix multiplication is possible or not
        cout << "Invalid\n";
        exit(0);
    }
    else {
        P = Matrix(num_rows, A.num_cols);
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < A.num_cols; j++) {
                P.M[i][j] = 0;
                for (int k = 0; k < A.num_rows; k++) {
                    P.M[i][j] = P.M[i][j] + M[i][k] * A.M[k][j]; //Matrix Multiplication

                }
            }
        }
    }
    return P;


}
Matrix Matrix::transpose() { //method to return transpose of the matrix
    Matrix P;
    int m = num_rows;
    int n = num_cols;
    P = Matrix(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            P.M[j][i] = M[i][j];
        }
    }
    return P;
}
istream& operator>>(istream& in, Matrix& A) { // '>>' operator overloading definition 
    for (int i = 0; i < A.num_rows; i++) {
        for (int j = 0; j < A.num_cols; j++) {
            cin >> A.M[i][j];
        }
    }
    return cin;
}
ostream& operator<<(ostream& out, Matrix& A) {// '<<' operator overloading definition 
    for (int i = 0; i < A.num_rows; i++) {
        for (int j = 0; j < A.num_cols; j++) {
            cout << A.M[i][j] << "\t";
        }
        cout << endl;
    }
    return cout;
}
int main() {
    int m, n;
    cout << "Enter number of rows and columns for the first matrix: \n" ;
    cin >> m >> n;
    Matrix m1(m, n);
    cout << "\n";
    cout << "Enter the elements of the first matrix serially (e.g: for a 2x2 matrix[A] enter - A11 A12 A21 A22) : \n" ;
    cin >> m1;
    cout << "\n";
    int a, b;
    cout << "Enter number of rows and columns for the second matrix: \n";
    cin >> a >> b;
    Matrix m2(a, b);
    cout << "\n";
    cout << "Enter the elements of the first matrix serially (e.g: for a 2x2 matrix[B] enter - B11 B12 B21 B22) : \n ";
    cin >> m2;
    cout << "\n";
    cout << "Matrix 1:" << endl;
    cout << m1;
    cout << "\n";
    cout << "Matrix 2:" << endl;
    cout << m2;
    cout << "\n";
    Matrix ans = m1 * m2;
    cout << "Matrix multiplication result: \n"  << ans << endl;
    Matrix ans_trans = ans.transpose();
    cout << "Transpose of the solution matrix: \n" << ans_trans << endl;
}