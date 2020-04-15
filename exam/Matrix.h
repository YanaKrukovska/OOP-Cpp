//
// Created by user on 11.04.2020.
//

#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <iostream>

#define NDEBUG

using namespace std;

class Matrix {
private:

    double **_arrMatrix;

public:
    //Can be changed to any number
    static int m_size;

    //For 2x2 matrix
    explicit Matrix(double _11 = 0, double _12 = 0, double _21 = 0, double _22 = 0);
    Matrix(const Matrix &);
    ~Matrix();

    Matrix &operator=(const Matrix &);


    Matrix &operator+=(const Matrix &);

    Matrix &operator-=(const Matrix &);

    Matrix &operator*=(const Matrix &);

    Matrix &operator*=(double);

    const double &operator()(size_t i, size_t j) const;

    void createArray();
};

Matrix operator+(const Matrix &, const Matrix &);

Matrix operator-(const Matrix &, const Matrix &);

Matrix operator*(const Matrix &, const Matrix &);

Matrix operator*(const Matrix &, double);

ostream &operator<<(ostream &, const Matrix &);

#endif //C_MATRIX_H
