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
        double get(int row, int col) const;
        int num_rows() const;
        int num_cols() const;
        bool eq(const Matrix &) const;
        bool neq(const Matrix &) const;
        Matrix mult(const Matrix &) const;
        void set(int row, int col, double value);

        bool operator==(Matrix const &m) const;
        bool operator!=(Matrix const &m) const;
        Matrix operator*(Matrix const &m) const;

    private:
        std::vector<std::vector<double>> _rows;
        int _num_rows;
        int _num_cols;
    };
};

#endif