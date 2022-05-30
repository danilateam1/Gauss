#pragma once
#include <iostream>
#include "Vector.h"
class Matrix {
	Vector* mall;
	int q = 0;
	int p = 0;

public:
	void swap(int a, int b);
	int getStr();
	int getStolb();
	Matrix();
	Matrix(int q, int p);
	Matrix(const Matrix& v);
	~Matrix();
	void resize(int q, int p);
	Matrix& operator=(const Matrix& v);
	Matrix operator+(const Matrix& v) const;
	Matrix operator-(const Matrix& v) const;
	Matrix& operator+=(const Matrix& v);
	Matrix& operator-=(const Matrix& v);
	Matrix operator*(double c) const;
	Matrix& operator*=(double c);
	Vector& operator[](int i);
	Vector operator[](int i) const;
	void print() const;
	Matrix mult(const Matrix& v) const;
};