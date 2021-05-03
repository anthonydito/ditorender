#include "matrix.hpp"

#include <initializer_list>
#include <iostream>

using namespace dito::util;

const double COMPARE_EPSILON = 0.000001;

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> rows)
{
    int curr_col_count = -1;
    for (auto row : rows)
    {
        if (curr_col_count == -1)
        {
            curr_col_count = row.size();
        }
        else if (curr_col_count != row.size())
        {
            throw std::invalid_argument("all cols are not the same size");
        }
        std::vector<double> row_vec;
        for (auto col : row)
        {
            row_vec.push_back(col);
        }
        _rows.push_back(row);
    }
    _num_rows = _rows.size();
    _num_cols = curr_col_count;
}

Matrix::Matrix(int rows, int cols)
{
    _num_rows = rows;
    _num_cols = cols;
    for (int row = 0; row < rows; ++row)
    {
        std::vector<double> v;
        for (int col = 0; col < cols; ++col)
        {
            v.push_back(0);
        }
        this->_rows.push_back(v);
    }
}

double Matrix::get(int row, int col) const
{
    return this->_rows[row][col];
}

int Matrix::num_cols() const
{
    return this->_num_cols;
}

int Matrix::num_rows() const
{
    return this->_num_rows;
}

bool Matrix::eq(const Matrix &m) const
{
    if (this->num_rows() != m.num_rows() || this->num_cols() != m.num_cols())
    {
        return false;
    }
    for (int row = 0; row < this->num_rows(); ++row)
    {
        for (int col = 0; col < this->num_cols(); ++col)
        {
            if (abs(m.get(row, col) - this->get(row, col)) > COMPARE_EPSILON)
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::neq(const Matrix &m) const
{
    return !this->eq(m);
}

Matrix Matrix::mult(const Matrix &m) const
{
    Matrix new_matrix(this->num_rows(), m.num_cols());
    for (int row = 0; row < this->num_rows(); ++row)
    {
        for (int col = 0; col < m.num_cols(); ++col)
        {
            // got through the rows and cols, multiplying each
            double curr_sum = 0;
            for (int idx = 0; idx < this->num_cols(); ++idx)
            {
                double row_value = this->get(row, idx);
                double col_value = m.get(idx, col);
                curr_sum += row_value * col_value;
            }
            new_matrix.set(row, col, curr_sum);
        }
    }
    return new_matrix;
}

bool Matrix::operator==(const Matrix &m) const
{
    return this->eq(m);
}

bool Matrix::operator!=(const Matrix &m) const
{
    return this->neq(m);
}

void Matrix::set(int row, int col, double value)
{
    this->_rows[row][col] = value;
}

Matrix Matrix::operator*(const Matrix &m) const
{
    return this->mult(m);
}
