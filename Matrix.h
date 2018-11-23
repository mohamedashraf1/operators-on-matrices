#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;


class Matrix
{
    public:
        Matrix(int a,int b,int num[]);
        Matrix();
        Matrix(const Matrix& mat);
        Matrix operator=(const Matrix& mat);
        ~Matrix();
       // int setdata(int num[]);
        int  getData();
        int getrow();
        int getcol();
        Matrix operator+(const Matrix&  mat);
        Matrix operator-(const Matrix&  mat);
        Matrix operator*(const Matrix&  mat);
        Matrix operator+(const int &scaler);
        Matrix operator-(const int& scaler);
        Matrix operator*(const int& scaler);
        Matrix& operator+=(const Matrix& mat);
        Matrix& operator-= (const Matrix& mat);
        Matrix operator+= (int scalar);
        Matrix operator-= (int scalar);
        void  operator++ ();
        void  operator--();
        friend istream& operator>> (istream& in, Matrix& mat);
        friend ostream& operator<< (ostream& out, Matrix& mat);
        bool   operator== (Matrix mat);
        bool   operator!= (Matrix mat );
        bool   isSquare   ();
        bool   isSymetric ();
        bool   isIdentity ();
        Matrix transpose();

    private:
        int row,col;
        int *data;
};

#endif // MATRIX_H
