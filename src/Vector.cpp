#include <iostream>
#include "../include/Vector.hpp"
#include <sstream>

using namespace std;


Vector::Vector(char type_, int size_){
    size = size_;
    type = type_;
    arr = new double[size];
    for(int i = 0; i < size; ++i){
        arr[i] = 0;
    }
}


Vector::Vector(char type_, int size_, double* arr_){                       // конструктор по массиву
    size = size_;
    type = type_;
    arr = new double[size];
    for(int i = 0; i < size; ++i){
        arr[i] = arr_[i];
    }
}


int Vector::get_size(){
    return size;
}

void Vector::show_vec(){// принт вектора
    if(type == 'r'){
        for(int i = 0; i < size; ++i){
            cout << arr[i] << endl;
        }
    }
    else if(type == 'l'){
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
    }
    else{
        cout << "Incorrect  input" << endl;
    }
    cout << endl;
}

Vector Vector::copy(const Vector& v){
    size = v.size;
    arr = new double[size];
    for(int i = 0; i < size; ++i)
        arr[i] = v.arr[i];
    Vector ans(v.type, v.size, arr);
    return ans;
}

Vector::Vector(const Vector& v){                                                        // конструктор по вектору
    copy(v);
}


Vector::~Vector(){                                                                      // деструктор вектора
    delete[](arr);
}


double Vector::get_elem(int ind) const{                                                 // возвращает элемент
    return arr[ind];
}

double Vector::operator [] (int ind){                                            // перегрузка обращения по элементу
    return get_elem(ind);
}

string Vector::vec_to_str() const{                                                      // печатает вектор
    string str;
    ostringstream ss;
    for(int i = 0; i < size; ++i){
        ss << get_elem(i);
        ss << " ";
    }
    return ss.str();
}


ostream& operator << (ostream &out, const Vector &v){                                   // перегрузка вывода
    cout << "v.size =  " << v.size << endl;
    return out << v.vec_to_str();
}

Vector& Vector::operator = (const Vector &v) {
    if (this == &v)
        return *this;
    copy(v);
    return *this;
}




Vector operator + (const Vector &A, const Vector &B)
{
    if (A.size != B.size || A.type != B.type)
    {
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Vector ans(A.type, A.size);
    for (size_t i = 0; i < A.size; i++)
    {
        ans.arr[i] = A.arr[i] + B.arr[i];
    }
    return ans;
}

Vector operator - (const Vector &A, const Vector &B)
{
    if (A.size != B.size || A.type != B.type)
    {
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Vector ans(A.type, A.size);
    for (size_t i = 0; i < A.size; i++)
    {
        ans.arr[i] = A.arr[i] - B.arr[i];
    }
    return ans;
}

Vector operator * (const Vector &A, const Vector &B)
{
    if (A.size != B.size || A.type != B.type)
    {
        cout << "Incorrect input" << endl;
        exit(1);
    }

    Vector ans(A.type, A.size);
    for (size_t i = 0; i < A.size; i++)
    {
        ans.arr[i] = A.arr[i] * B.arr[i];
    }
    return ans;
}



Vector operator + (double A, const Vector &B)
{
    Vector ans(B.type, B.size);
    for (size_t i = 0; i < B.size; i++)
    {
        ans.arr[i] = A + B.arr[i];
    }
    return ans;
}

Vector operator - (double A, const Vector &B)
{
    Vector ans(B.type, B.size);
    for (size_t i = 0; i < B.size; i++)
    {
        ans.arr[i] = A - B.arr[i];
    }
    return ans;
}

Vector operator * (double A, const Vector &B)
{
    Vector ans(B.type, B.size);
    for (size_t i = 0; i < B.size; i++)
    {
        ans.arr[i] = A * B.arr[i];
    }
    return ans;
}

bool operator == (const Vector &A, const Vector &B){
    for (size_t i = 0; i < A.size; i++)
    {
        if(A.arr[i] != B.arr[i])
            return false;
    }
    return true;
}
