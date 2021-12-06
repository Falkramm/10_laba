//
// Created by user on 01.12.2021.
//
#pragma once

#include <iostream>
#include "matrix.h"
#include <exception>

matrix operator+(matrix &matrix1, double n) {
    matrix matrix2(matrix1);
    for (int i = 0; i < matrix2.get_num_of_lines(); i++)
        for (int j = 0; j < matrix2.get_num_of_columns(); j++)
            matrix2.setter_of_element(i, j, matrix1.getter_of_element(i, j) + n);
    return matrix2;
}

matrix &operator+=(matrix &matrix1, double n) {
    for (int i = 0; i < matrix1.get_num_of_lines(); i++)
        for (int j = 0; j < matrix1.get_num_of_columns(); j++)
            matrix1.setter_of_element(i, j, matrix1.getter_of_element(i, j) + n);
    return matrix1;
}

matrix operator-(matrix &matrix1, double n) {
    matrix matrix2(matrix1);
    for (int i = 0; i < matrix2.get_num_of_lines(); i++)
        for (int j = 0; j < matrix2.get_num_of_columns(); j++)
            matrix2.setter_of_element(i, j, matrix1.getter_of_element(i, j) - n);
    return matrix2;
}

matrix &operator-=(matrix &matrix1, double n) {
    for (int i = 0; i < matrix1.get_num_of_lines(); i++)
        for (int j = 0; j < matrix1.get_num_of_columns(); j++)
            matrix1.setter_of_element(i, j, matrix1.getter_of_element(i, j) - n);
    return matrix1;
}

matrix operator*(matrix &matrix1, double n) {
    matrix matrix2(matrix1);
    for (int i = 0; i < matrix2.get_num_of_lines(); i++)
        for (int j = 0; j < matrix2.get_num_of_columns(); j++)
            matrix2.setter_of_element(i, j, matrix1.getter_of_element(i, j) * n);
    return matrix2;
}

matrix &operator*=(matrix &matrix1, double n) {
    for (int i = 0; i < matrix1.get_num_of_lines(); i++)
        for (int j = 0; j < matrix1.get_num_of_columns(); j++)
            matrix1.setter_of_element(i, j, matrix1.getter_of_element(i, j) * n);
    return matrix1;
}

matrix operator/(matrix &matrix1, double n) {
    matrix matrix2(matrix1);
    try {
        if (n == 0)
            throw "division by zero\n";
        for (int i = 0; i < matrix2.get_num_of_lines(); i++)
            for (int j = 0; j < matrix2.get_num_of_columns(); j++)
                matrix2.setter_of_element(i, j, matrix1.getter_of_element(i, j) / n);
    }
    catch (char *str) {
        std::cout << str;
    }
    return matrix2;
}

matrix &operator/=(matrix &matrix1, double n) {
    try {
        if (n == 0)
            throw "division by zero\n";
        for (int i = 0; i < matrix1.get_num_of_lines(); i++)
            for (int j = 0; j < matrix1.get_num_of_columns(); j++)
                matrix1.setter_of_element(i, j, matrix1.getter_of_element(i, j) / n);
    }
    catch (std::string str) {
        std::cout << str;
    }
    return matrix1;
}

std::ostream &operator<<(std::ostream &output, matrix &matrix1) {
    for (int i = 0; i < matrix1.get_num_of_lines(); i++) {
        for (int j = 0; j < matrix1.get_num_of_columns(); j++)
            output << matrix1.getter_of_element(i, j) << ' ';
        output << std::endl;
    }
    return output;
}

std::istream &operator>>(std::istream &input, matrix &matrix1) {
    int n, m;
    input >> n >> m;
    matrix1 = matrix(n, m);
    for (int i = 0; i < matrix1.get_num_of_lines(); i++) {
        for (int j = 0; j < matrix1.get_num_of_columns(); j++) {
            int element;
            input >> element;
            matrix1.setter_of_element(i, j, element);
        }
    }
    return input;
}