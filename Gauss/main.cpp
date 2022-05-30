#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Gauss.h"
int main() {
	/*
Vector a(3);
Vector b(3);
a[0] = 1.;
b[1] = 2.;
b += a;
b.print();
Vector c(3);
c[0] = 1.;
c[1] = 2.;
c[2] = 3.;
Vector d(3);
d[0] = 3.;
d[1] = 2.;
d[2] = 1.;
c.print();
d.print();
Vector r(3);
Vector m(3);


double s = 0;
s = c.dot(d);
std::cout << s << std::endl;


std::cout << c.norma() << std::endl;

double A = 5;
c *= A;
c.print();

r = c * A;
r.print();

r = c + d;
r.print();

	Matrix r(2, 2);
	r[0][0] = 1.;
	r[0][1] = 2.;
	r[1][0] = 3.;
	r[1][1] = 4.;
	
*/



	Matrix m(3, 5);
	m[0][0] = 1.; m[1][2] = 5.;
	m[0][1] = 2.; m[2][0] = 6.;
	m[0][2] = 1.; m[2][1] = 7.;
	m[1][0] = 4.; m[2][2] = 9.;
	m[1][1] = 5.; m[0][3] = 5.;
	m[0][4] = 7.; m[1][3] = 2;
	m[1][4] = 6; m[2][3] = 5;
	 m[2][4] = 4;

	
	 std::cout << "Matrix: " << '\n';
	m.print();
	std::cout << '\n';
	std::cout << "Vector: " << '\n';
	Vector l(3);
	l[0] = 1;
	l[1] = 2;
	l[2] = 10;

	l.print();
	std::cout << '\n';

	GaussSolver solver;
	std::vector<Vector> q=solver.solve(m,l);
	std::cout << '\n';
	if (q.size() == 1) {
		q[0].print();
	}
	if (q.size() > 1) {
		std::cout << "linear variety:  "<<'\n';
		std::cout << "shift vector: ";
			q[0].print();
		for (int i = 1; i < q.size(); i++) {
			std::cout <<'\n' << "vector[" << i << "]: ";
			q[i].print();
		}
	}

	//std::cout << q.size();
	//std::cout << " " << std::endl;

	 /*

	//m.print();
	//std::cout << " " << std::endl;


	//(m + r).print();
	std::cout << " " << std::endl;

	Matrix f(m.mult(r));
	//f.print();
	std::cout << " " << std::endl;
	m += r;
	//m.print();

	std::cout << " " << std::endl;
	//(r * 5).print();

	return 0;
	}
	*/
	return 0;
}