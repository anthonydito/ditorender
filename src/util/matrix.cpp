#include "matrix.hpp"

#include <initializer_list>
#include <iostream>
#include <cmath>

using namespace dito::util;

const double COMPARE_EPSILON = 0.00001;

Matrix Matrix::identity_matrix(int size)
{
    Matrix m(size, size);

    for (int i = 0; i < size; ++i)
    {
        m.set(i, i, 1);
    }
    return m;
}

Matrix Matrix::translation(double x, double y, double z)
{
    Matrix start = Matrix::identity_matrix(4);
    start.set(0, 3, x);
    start.set(1, 3, y);
    start.set(2, 3, z);
    return start;
}

Matrix Matrix::scaling(double x, double y, double z)
{
    Matrix start = Matrix::identity_matrix(4);
    start.set(0, 0, x);
    start.set(1, 1, y);
    start.set(2, 2, z);
    return start;
}

Matrix Matrix::rotation_x(double radians)
{
    Matrix start = Matrix::identity_matrix(4);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    start.set(1, 1, cos_r);
    start.set(2, 2, cos_r);
    start.set(2, 1, sin_r);
    start.set(1, 2, -sin_r);
    return start;
}

Matrix Matrix::rotation_y(double radians)
{
    Matrix start = Matrix::identity_matrix(4);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    start.set(0, 0, cos_r);
    start.set(0, 2, sin_r);
    start.set(2, 0, -sin_r);
    start.set(2, 2, cos_r);
    return start;
}

Matrix Matrix::rotation_z(double radians)
{
    Matrix start = Matrix::identity_matrix(4);
    double cos_r = cos(radians);
    double sin_r = sin(radians);
    start.set(0, 0, cos_r);
    start.set(0, 1, -sin_r);
    start.set(1, 0, sin_r);
    start.set(1, 1, cos_r);
    return start;
}

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
            std::cout << "testing sizes " << curr_col_count << " - " << row.size();
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

Tuple Matrix::mult(const Tuple &t) const
{
    Matrix new_matrix{
        {t.x()},
        {t.y()},
        {t.z()},
        {t.w()}};
    Matrix output = this->mult(new_matrix);
    return Tuple(output.get(0, 0), output.get(1, 0), output.get(2, 0), output.get(3, 0));
}

Matrix Matrix::transpose() const
{
    Matrix m(this->num_rows(), this->num_cols());
    for (int row = 0; row < this->num_rows(); ++row)
    {
        for (int col = 0; col < this->num_cols(); ++col)
        {
            m.set(col, row, this->get(row, col));
        }
    }
    return m;
}

double Matrix::determinant() const
{
    if (this->num_cols() == 2 && this->num_rows() == 2)
    {
        return (this->get(0, 0) * this->get(1, 1)) - (this->get(1, 0) * this->get(0, 1));
    }
    double sum = 0;
    for (int col = 0; col < this->num_cols(); ++col)
    {
        sum += (this->get(0, col) * this->cofactor(0, col));
    }
    return sum;
}

Matrix Matrix::submatrix(int row_to_remove, int col_to_remove) const
{
    Matrix new_matrix(this->num_rows() - 1, this->num_cols() - 1);
    for (int row = 0; row < this->num_rows(); ++row)
    {
        if (row == row_to_remove)
        {
            continue;
        }
        for (int col = 0; col < this->num_cols(); ++col)
        {
            if (col == col_to_remove)
            {
                continue;
            }
            int setting_row = row;
            int setting_col = col;
            if (row > row_to_remove)
            {
                --setting_row;
            }
            if (col > col_to_remove)
            {
                --setting_col;
            }
            new_matrix.set(setting_row, setting_col, this->get(row, col));
        }
    }
    return new_matrix;
}

double Matrix::minor(int row, int col) const
{
    return this->submatrix(row, col).determinant();
}

double Matrix::cofactor(int row, int col) const
{
    double minor = this->minor(row, col);
    if ((row + col) % 2 == 0)
    {
        return minor;
    }
    else
    {
        return -minor;
    }
}

bool Matrix::is_invertable() const
{
    return this->determinant() != 0;
}

Matrix Matrix::inverse() const
{
    if (!this->is_invertable())
    {
        throw std::invalid_argument("matrix is not invertable");
    }
    auto determinant = this->determinant();
    Matrix output(this->num_rows(), this->num_cols());
    for (int row = 0; row < this->num_rows(); ++row)
    {
        for (int col = 0; col < this->num_cols(); ++col)
        {
            auto c = this->cofactor(row, col);
            output.set(col, row, c / determinant);
        }
    }
    return output;
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

Tuple Matrix::operator*(const Tuple &t) const
{
    return this->mult(t);
}

std::ostream &dito::util::operator<<(std::ostream &os, const Matrix &m)
{
    os << std::endl;
    for (int row = 0; row < m.num_rows(); ++row)
    {
        os << "[";
        for (int col = 0; col < m.num_cols(); ++col)
        {
            if (col != 0)
            {
                os << ", ";
            }
            os << m.get(row, col);
        }
        os << "]" << std::endl;
    }
    return os;
}
