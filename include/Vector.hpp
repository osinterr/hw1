#include <string>
#include <iostream>

using namespace std;


class Vector{
private:
    char type;
    int size;
    double* arr;
public:
    Vector(char type_, int size_);
    Vector(char type_, int size_, double* arr_);
    Vector(const Vector& v);
    ~Vector();

    int get_size();
    string vec_to_str() const;
    double get_elem(int ind) const;
    Vector copy(const Vector &v);
    //int get_size();
    void show_vec();
    double operator [] (int ind);
    friend std::ostream& operator << (std::ostream &out, const Vector &v);
    Vector &operator = (const Vector &v);

    friend Vector operator + (const Vector &A, const Vector &B);
    friend Vector operator - (const Vector &A, const Vector &B);
    friend Vector operator * (const Vector &A, const Vector &B);

    friend Vector operator + (double A, const Vector &B);
    friend Vector operator - (double A, const Vector &B);
    friend Vector operator * (double A, const Vector &B);

    friend bool operator == (const Vector &A, const Vector &B);
};
