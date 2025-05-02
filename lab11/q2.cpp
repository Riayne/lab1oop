#include <iostream>
#include <vector>
#include <stdexcept>

class DimensionMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match!";
    }
};

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c, const T& value = T()) : rows(r), cols(c), data(r, std::vector<T>(c, value)) {}

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) throw std::out_of_range("Index out of bounds");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw std::out_of_range("Index out of bounds");
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) throw DimensionMismatchException();
        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }
};
