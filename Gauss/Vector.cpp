#include <iostream>
#include "Vector.h"
#include <cmath>
//меняет элементы в векторе местами
void Vector::swap(int a, int b) {
	double t;
	t= data[a];
	data[a] = data[b];
	data[b] = t;
}
//для обнуления очень маленьких чисел
void Vector::check() {
	for (int i = 0; i < n; i++){
			if (abs(data[i]) < 0.0000000001) { data[i] = 0; }
	}
}
int Vector::getlen() const {
	return n;
}

Vector::Vector() {
	data = 0;
	n = 0;
}

Vector::Vector(int n) {
	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; i++) {
		data[i] = 0;
	}
}

Vector::Vector(const Vector& v) {
	this->n = v.n;
	data = new double[n];
	for (int i = 0; i < n; i++) {
		data[i] = v[i];
	}
}


Vector::~Vector() {
	delete[]data;
	data = 0;
	n = 0;
}

void Vector::print() const {
	for (int i = 0; i < n; i++) {
		std::cout << data[i] << ' ';
	}
}



Vector& Vector::operator+=(const Vector& v) {
	if (this->n != v.n) {
		std::cout << "ERROR" << std::endl;
		return *this;
	}

	for (int i = 0; i < n; i++) {
		data[i] += v.data[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v) {
	if (this->n != v.n) {
		std::cout << "ERROR" << std::endl;
		return *this;
	}

	for (int i = 0; i < n; i++) {
		data[i] -= v.data[i];
	}
	return *this;
};

double& Vector::operator[](int i) {
	return data[i];
}
double Vector::operator[](int i) const {
	return data[i];
}

void Vector::resize(int newSize) {
	delete[] data;
	data = new double[newSize];
	this->n = newSize;
	for (int i = 0; i < n; i++) {
		data[i] = 0.;
	}
}

Vector& Vector::operator=(const Vector& v) {
	if (this->n != v.n) {
		this->resize(v.n);
	}
	for (int i = 0; i < n; i++) {
		data[i] = v.data[i];
	}
	return *this;
}

Vector Vector::operator*(double c) const {
	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = data[i] * c;
	}
	return r;
}


Vector& Vector::operator*=(double c) {
	for (int i = 0; i < n; i++) {
		data[i] *= c;
	}
	return *this;
}

double Vector::dot(const Vector& v) const {

	if (this->n != v.n) {
		std::cout << "ERROR" << std::endl;
		return 0;
	}

	double s = 0;
	for (int i = 0; i < n; i++) {
		s += data[i] * v.data[i];
	}
	return s;
}



Vector Vector::operator-(const Vector& v) const {
	if (this->n != v.n) {
		std::cout <<"ERROR" << std::endl;
		return 0;
	}
	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = data[i] - v.data[i];
	}
	return r;
};


Vector Vector::operator+(const Vector& v) const {
	if (this->n != v.n) {
		std::cout << "ERROR" << std::endl;
		return 0;
	}
	Vector r(n);
	for (int i = 0; i < n; i++) {
		r[i] = data[i] + v.data[i];
	}
	return r;
};

Vector operator*(double c, const Vector& v) {
Vector r(v.n);
for (int i = 0; i < v.getlen(); i++) {
r[i] = v.data[i] * c;
}
return r;
};
