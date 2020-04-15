//
// Created by user on 11.04.2020.
//

#include "Matrix.h"

int Matrix::m_size = 2;


Matrix::Matrix(double _11, double _12, double _21, double _22) {
    createArray();

    _arrMatrix[0][0] = _11;
    _arrMatrix[0][1] = _12;
    _arrMatrix[1][0] = _21;
    _arrMatrix[1][1] = _22;

#ifndef NDEBUG
    cout << "Created " << *this << endl;
#endif
}

void Matrix::createArray() {
    _arrMatrix = new double *[m_size];
    for (int i = 0; i < m_size; ++i) {
        _arrMatrix[i] = new double[m_size];
    }

    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            _arrMatrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &other) {
    createArray();


    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            _arrMatrix[i][j] = other._arrMatrix[i][j];
        }
    }

#ifndef NDEBUG
    cout << "Copied " << *this << endl;
#endif
}

Matrix::~Matrix() {
#ifndef NDEBUG
    cout << "Deleted " << *this << endl;
#endif

    for (int i = 0; i < m_size; ++i) {
        delete[] _arrMatrix[i];
    }
    delete[] _arrMatrix;


}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            _arrMatrix[i][j] = other._arrMatrix[i][j];
        }
    }
    return *this;
}


Matrix &Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            _arrMatrix[i][j] += other._arrMatrix[i][j];
        }
    }
    return *this;
}

Matrix operator+(const Matrix &first, const Matrix &second) {
    Matrix result(first);
    return (result += second);
}


Matrix &Matrix::operator-=(const Matrix &other) {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            _arrMatrix[i][j] -= other._arrMatrix[i][j];
        }
    }
    return *this;
}

Matrix operator-(const Matrix &first, const Matrix &second) {
    Matrix result(first);
    return (result -= second);
}

Matrix &Matrix::operator*=(const Matrix &other) {
    Matrix temp(0);
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            for (int k = 0; k < m_size; ++k) {
                temp._arrMatrix[i][j] += _arrMatrix[i][k] * other._arrMatrix[k][j];
            }
        }
    }
    return (*this = temp);
}

Matrix &Matrix::operator*=(const double number) {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            for (int k = 0; k < m_size; ++k) {
                _arrMatrix[i][j] *= number;
            }
        }
    }
    return *this;
}

const double &Matrix::operator()(const size_t i, const size_t j) const {
    return _arrMatrix[i][j];
}


Matrix operator*(const Matrix &first, const Matrix &second) {
    Matrix result(first);
    return (result *= second);
}

Matrix operator*(const Matrix &matrix, double number) {
    Matrix result(matrix);
    return (result *= number);
}

ostream &operator<<(ostream &os, const Matrix &matrix) {
    os << "matrix: " << endl;
    for (int i = 0; i < Matrix::m_size; ++i) {
        os << matrix(i, 0);
        for (int j = 1; j < Matrix::m_size; ++j) {
            os << " " << matrix(i, j);
        }
        os << endl;
    }
    return os;
}







