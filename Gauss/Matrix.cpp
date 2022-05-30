#include <iostream>
#include "Vector.h"
#include "Matrix.h"
int Matrix::getStr() { return this->q; }
int Matrix::getStolb() { return this->p; }
//меняет местами строки в матрице
void Matrix::swap(int a, int b) {
	Vector v(p);
	v = mall[b];
	mall[b] = mall[a];
	mall[a] = v;
}

Matrix::Matrix() {
	mall = new Vector[0];
};
Matrix::Matrix(int q, int p) {
	this->q = q;
	this->p = p;
	mall = new Vector[q];
	for (int i = 0; i < q; i++) {
		mall[i] = Vector(p);
	}
}

Matrix::Matrix(const Matrix& v) {
	this->q = v.q;
	this->p = v.p;
	mall = new Vector[q];
	for (int i = 0; i < q; i++) {
		mall[i] = v.mall[i];
	}
}


Matrix::~Matrix() {
	delete[] mall;
}


void Matrix::resize(int q, int p) {
	delete[] mall;
	this->q = q;
	this->p = p;
	mall = new Vector[q];
	for (int i = 0; i < q; i++) {
		mall[i] = Vector(p);
	}
};

Matrix& Matrix::operator=(const Matrix& v) {
	if ((this->q != v.q) || (this->p != v.p))
		this->resize(v.q, v.p);
	for (int i = 0; i < q; i++) {
		mall[i] = v.mall[i];
	};
	return *this;
};



Matrix Matrix::operator+(const Matrix& v) const {
	if ((this->q != v.q) || (this->p != v.p)) {
		std::cout<< "ERROR"<< std::endl;
		return Matrix(0, 0);
	}
	Matrix r(q, p);
	for (int i = 0; i < q; i++) {
		r.mall[i] = mall[i] + v.mall[i];
	};
	return r;

};
Matrix Matrix::operator-(const Matrix& v) const {
	if ((this->q != v.q) || (this->p != v.p)) {
		std::cout << "ERROR" << std::endl;
		return Matrix(0, 0);
	}
	Matrix r(q, p);
	for (int i = 0; i < q; i++) {
		r.mall[i] = mall[i] - v.mall[i];
	};
	return r;

};


Matrix& Matrix::operator+=(const Matrix& v) {
	if ((this->q != v.q) || (this->p != v.p)) {
		std::cout <<"ERROR" << std::endl;
		return *this;
	}
	for (int i = 0; i < q; i++) {
		mall[i] += v.mall[i];
	}
	return*this;
};
Matrix& Matrix::operator-=(const Matrix& v) {
	if ((this->q != v.q) || (this->p != v.p)) {
		std::cout<< "ERROR" << std::endl;
		return *this;
	}
	for (int i = 0; i < q; i++) {
		mall[i] += v.mall[i];
	}
	return*this;
};


Matrix Matrix::operator*(double c) const {
	Matrix r(q, p);
	for (int i = 0; i < q; i++) {
		r.mall[i] = mall[i] * c;
	}
	return r;
};
Matrix& Matrix::operator*=(double c) {
	for (int i = 0; i < this->q; i++) {
		mall[i] *= c;
	}
	return *this;
};


Vector& Matrix::operator[](int i) {
	return mall[i];
};
Vector Matrix::operator[](int i) const {
	return mall[i];
};
void Matrix::print() const {
	for (int i = 0; i < this->q; i++) {
		mall[i].print();
		std::cout << ' ' << std::endl;
	}
};
Matrix Matrix::mult(const Matrix& v) const {
	if (this->p != v.q) {
		std::cout << "ERROR" << std::endl;
		return Matrix(0, 0);
	}
	Matrix New(this->q, v.p);
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < v.p; j++) {
			for (int k = 0; k < v.q; k++)
				(New.mall[i])[j] += (mall[i])[k] * (v.mall[k])[j];
		}
	}
	return New;
}