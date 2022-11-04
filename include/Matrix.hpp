#include "Vector.hpp"
#include <iostream>
#include <vector>


using namespace std;

class Matrix
{
protected:
    int rows, cols;
    double **arr;
public:
    Matrix(int rows_, int cols_);                           // конструктор без значений
    Matrix(int rows_, int cols_, double* array);            // конструктор по числам
    Matrix(const Matrix& m);
    //Matrix(int rows_, vector<Vector> v);                      // конструктор по векторам
    ~Matrix();

    double get_elem(int i, int j);
    string mto_string();

    double operator() (unsigned row, unsigned col);

    void show_matrix();
    Vector delete_row(int ind);
    Vector delete_line(int ind);
    Vector delete_diag(int ind);                                  // 0 - основная; 1 - побочная



    friend bool is_equal(Matrix* m1, Matrix* m2);
    friend Matrix operator + (const Matrix &A, const Matrix &B);
    friend Matrix operator - (const Matrix &A, const Matrix &B);
    friend Matrix operator * (const Matrix &A, const Matrix &B);

    friend Matrix operator - (double A, const Matrix &B);
    friend Matrix operator + (double A, const Matrix &B);
    friend Matrix operator * (double A, const Matrix &B);
    Matrix Transpose() const;

    friend bool operator == (const Matrix &A, const Matrix &B);
};
