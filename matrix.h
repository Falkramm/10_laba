//
// Created by user on 01.12.2021.
//

#ifndef INC_10_LABA_MATRIX_H
#define INC_10_LABA_MATRIX_H
#pragma once

#include <vector>

class matrix {
private:
    std::vector<std::vector<double> > array;
public:
    matrix() {
        array.clear();
    }

    matrix(matrix &matrix1) {
        this->array = matrix1.array;
    }

    matrix(int n, int m) {

        set_num_of_lines(n);
        set_num_of_columns(m);
    }

    ~matrix() {
        array.clear();
    }

    void setter_of_element(int i, int j, double definition) {
        array[i][j] = definition;
    }

    double getter_of_element(int i, int j) {
        return array[i][j];
    }

    int get_num_of_lines() {
        return array.size();
    }

    void set_num_of_lines(int n) {
        array.clear();
        array.resize(n);
    }

    int get_num_of_columns() {
        if (get_num_of_lines() == 0)
            return 0;
        return array[0].size();
    }

    void set_num_of_columns(int m) {
        for (int i = 0; i < array.size(); i++) {
            array[i].clear();
            array[i].resize(m, 0);
        }
    }

    bool operator==(matrix &matrix1) {
        if (matrix1.get_num_of_lines() != this->get_num_of_lines())
            return false;
        if (matrix1.get_num_of_columns() != this->get_num_of_columns())
            return false;
        for (int i = 0; i < matrix1.get_num_of_lines(); i++)
            for (int j = 0; j < matrix1.get_num_of_columns(); j++)
                if (matrix1.getter_of_element(i, j) != this->getter_of_element(i, j))
                    return false;
        return true;
    }

    bool operator!=(matrix &matrix1) {
        if (matrix1 == *this)
            return false;
        else
            return true;
    }

    matrix operator++(int) {
        matrix matrix1(*this);
        ++(*this);
        return matrix1;
    }

    matrix &operator++() {
        for (int i = 0; i < this->get_num_of_lines(); i++)
            for (int j = 0; j < this->get_num_of_columns(); j++)
                this->setter_of_element(i, j, this->getter_of_element(i, j) + 1);
        return *this;
    }

    friend matrix operator+(matrix &matrix1, double n);

    friend matrix &operator+=(matrix &matrix1, double n);

    friend matrix operator-(matrix &matrix1, double n);

    friend matrix &operator-=(matrix &matrix1, double n);

    friend matrix operator*(matrix &matrix1, double n);

    friend matrix &operator*=(matrix &matrix1, double n);

    friend matrix operator/(matrix &matrix1, double n);

    friend matrix &operator/=(matrix &matrix1, int n);

    matrix operator[](int index) {
        try {
            if (index >= this->get_num_of_lines())
                throw "going beyond the boundaries of the array\n";
            matrix new_matrix(1, this->get_num_of_columns());
            for (int i = 0; i < this->get_num_of_columns(); i++)
                new_matrix.setter_of_element(0, i, this->getter_of_element(index, i));
            return new_matrix;
        }
        catch (char *str) {
            std::cout << str;
        }
    }

    friend std::ostream &operator<<(std::ostream &output, matrix &matrix1);

    friend std::istream &operator>>(std::istream &input, matrix &matrix1);

};

#endif //INC_10_LABA_MATRIX_H
