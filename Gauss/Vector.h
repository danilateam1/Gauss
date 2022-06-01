#pragma once
//vector (n length)
class Vector {
protected:
	double* data = 0;
	int n = 0;
public:
	void swap(int a, int b);
	void check();
	int getlen() const;
	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();
	void resize(int newSize);
	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	Vector& operator*=(double c);
	double dot(const Vector& v) const;
	double norma() const {
		return sqrt(this->dot(*this));
	}

	double& operator[](int i);
	double operator[](int i) const;
	void print() const;
	inline friend Vector operator*(double c,const Vector& v);
};
