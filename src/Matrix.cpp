#include "../include/Matrix.hpp"
#include <string>
#include <vector>



Matrix::Matrix(int rows_, int cols_)
{
    this->rows = rows_;
    this->cols = cols_;
    arr = new double* [rows*cols];
    for (int i = 0; i < rows*cols; i++)
        arr[i] = new double[rows];
}

Matrix::Matrix(int rows_, int cols_, double* array)
{
    this->rows = rows_;
    this->cols = cols_;
    arr = new double* [rows*cols];
    for (int i = 0; i < rows*cols; i++)
        arr[i] = new double[rows];
    for (int i = 0; i < rows; i++)
        for(int j = 0; j < cols; ++j)
            arr[i][j] = array[rows*i+j];

}

Matrix::Matrix(const Matrix& m){
    Matrix ans(m.rows, m.cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            arr[i][j] = ans.arr[i][j];
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows*cols; i++)
        delete(arr[i]);

    delete[](arr);
}


double Matrix::get_elem(int i, int j){
    return arr[i][j];
}

string Matrix::mto_string(){
    std::string res = "";
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (j == cols - 1) {
                res += std::to_string(this->get_elem(i, j)) + "\n";
            }
            else {
                res += std::to_string(this->get_elem(i, j)) + " ";
            }
        }
    }
    res += "\n";
    return res;

}

void Matrix::show_matrix()
{
    for(int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}



bool is_equal(Matrix* m1, Matrix* m2){
    if(m1->rows == m2->rows && m1->cols == m2->cols)
        return true;
    else
        return false;
}

double Matrix::operator() (unsigned row, unsigned col)
{
    return arr[row][col];
}


Vector Matrix::delete_row(int ind){
    double* mass = new double[rows];
    for(int i = 0; i < rows; ++i){
        mass[i] = arr[i][ind];
    }
    Vector ans('r', rows, mass);
    return ans;
}

Vector Matrix::delete_line(int ind){
    double mass[cols];
    for(int i = 0; i < cols; ++i){
        mass[i] = arr[ind][i];
    }
    Vector ans('l', cols, mass);
    return ans;
}

Vector Matrix::delete_diag(int ind){
    double mass[cols];
    if(ind == 0){                       // основная
        for(int i = 0; i < cols; ++i){
            mass[i] = arr[i][i];
        }
    }
    else{                               // побочная
        for(int i = 0; i < cols; ++i){
            mass[i] = arr[cols-1-i][i];
        }
    }
    Vector ans('l', cols, mass);
    return ans;
}


Matrix operator + (const Matrix &A, const Matrix &B)
{
    if (A.rows != B.rows || A.cols != B.cols)
    {
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Matrix ans(A.rows, A.cols);
    for (size_t i = 0; i < A.rows; i++)
    {
        for (size_t j = 0; j < A.cols; j++)
        {
            ans.arr[i][j] = A.arr[i][j] + B.arr[i][j];
        }
    }
    return ans;
}

Matrix operator - (const Matrix &A, const Matrix &B)
{
    if (A.rows != B.rows || A.cols != B.cols){
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Matrix ans(A.rows, A.cols);
    for (size_t i = 0; i < A.rows; i++)
    {
        for (size_t j = 0; j < A.cols; j++)
        {
            ans.arr[i][j] = A.arr[i][j] - B.arr[i][j];
        }
    }
    return ans;
}

Matrix operator * (const Matrix &A, const Matrix &B)
{
    if (A.rows != B.cols || A.cols != B.rows) {
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Matrix ans = Matrix(A.rows, B.cols);

    for (size_t i = 0; i < ans.rows; i++)
    {
        for (size_t j = 0; j < ans.cols; j++)
        {
            ans.arr[i][j] = A.arr[i][j] * B.arr[i][j];
        }
    }
    return ans;
}


Matrix operator + (double A, const Matrix &B)
{
    Matrix ans(B.rows, B.cols);
    for (size_t i = 0; i < B.rows; i++)
    {
        for (size_t j = 0; j < B.cols; j++)
        {
            ans.arr[i][j] = A + B.arr[i][j];
        }
    }
    return ans;
}

Matrix operator - (double A, const Matrix &B)
{
    Matrix ans(B.rows, B.cols);
    for (size_t i = 0; i < B.rows; i++)
    {
        for (size_t j = 0; j < B.cols; j++)
        {
            ans.arr[i][j] = A - B.arr[i][j];
        }
    }
    return ans;
}

Matrix operator * (double A, const Matrix &B)
{
    Matrix ans(B.rows, B.cols);
    for (size_t i = 0; i < B.rows; i++)
    {
        for (size_t j = 0; j < B.cols; j++)
        {
            ans.arr[i][j] = A * B.arr[i][j];
        }
    }
    return ans;
}





Matrix Matrix::Transpose() const
{
    Matrix ans(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            ans.arr[j][i] = arr[i][j];
    return ans;
}

bool operator == (const Matrix &A, const Matrix &B)
{
    for (size_t i = 0; i < B.rows; i++)
    {
        for (size_t j = 0; j < B.cols; j++)
        {
            if(A.arr[i][j] != B.arr[i][j])
                return false;
        }
    }
    return true;
}