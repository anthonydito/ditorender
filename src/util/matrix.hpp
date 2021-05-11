#ifndef DITO_UTIL_MATRIX
#define DITO_UTIL_MATRIX

#include "tuple.hpp"

#include <initializer_list>
#include <vector>

namespace dito::util
{
    class Matrix
    {
    public:
        Matrix(std::initializer_list<std::initializer_list<double>>);
        Matrix(int rows, int cols);

        static Matrix identity_matrix(int);

        double get(int row, int col) const;
        int num_rows() const;
        int num_cols() const;
        bool eq(const Matrix &) const;
        bool neq(const Matrix &) const;
        Matrix mult(const Matrix &) const;
        Tuple mult(const Tuple &) const;
        Matrix transpose() const;
        Matrix submatrix(int row, int col) const;
        double minor(int row, int col) const;
        double determinant() const;
        double cofactor(int row, int col) const;
        void set(int row, int col, double value);
        bool is_invertable() const;
        Matrix inverse() const;

        bool operator==(Matrix const &m) const;
        bool operator!=(Matrix const &m) const;
        Matrix operator*(Matrix const &m) const;
        Tuple operator*(const Tuple &m) const;
        friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

    private:
        std::vector<std::vector<double>> _rows;
        int _num_rows;
        int _num_cols;
    };
};

#endif