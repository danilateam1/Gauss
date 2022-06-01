#pragma once
#include <iostream>
#include "vector"
#include "Matrix.h"
#include <cmath>
class GaussSolver {
public:
	GaussSolver() {};
	std::vector<Vector> solve(const Matrix& A, const Vector& b) {
		std::vector<Vector> l;
		int k = 0;
		Matrix B(A);
		Vector a(b);
		if (B.getStr() != a.getlen()) {
			std::cout << "nepravilnaya razmernost";
			return l;
		}
		double max = 0;
		int number = 0;
		int count = 0;
		int* massive = new int[B.getStr()];
		int* stolb = new int[B.getStolb()];
		for (int i = 0; i < B.getStolb(); i++) {
			stolb[i] = 0;
		}
		for (int i = 0; i < B.getStr(); i++) {
			massive[i] = 0;
		}
		//�������-������
		for (int i = 0; i < B.getStolb(); i++) {
			max = 0.0000000001;
			for (int j = 0; j < B.getStr(); j++) {
				if ((abs(max) < abs(B[j][i])) && (massive[j] == 0)) {
					//���� � ������� ������������ �������, ������� ��� �� ��������� � ������
					max = B[j][i];
					number = j;
				}
			}
			//std::cout << max << "\n";

			if (max != 0.0000000001) {
				a[number] *= (1 / B[number][i]);
				B[number] *= (1 / B[number][i]);


				for (int j = 0; j < B.getStr(); j++) {
					//���� max=0 �� ������� ������� ��� �� ��� ����� ������� � ���� ������
					if ((j != number)&&(abs(B[j][i])>0.0000000001)) {
						a[j] -= (a[number] * B[j][i]);
						B[j] -= (B[number] * B[j][i]);
					}
					
				}
				stolb[i] = 1;
				massive[number] = 1;
			}
			

			number = -1;
			k = 0;
			for (int q = 0; q < B.getStr(); q++) {
				if (massive[q] == 0) { k++; };
			}
			if (k == 0) { break; }
		}

	//		for (int i = 0; i < B.getStolb(); i++) {
		//		std::cout << stolb[i] << std::endl;
		//}

		//�������� ����� ��������� ��������
		for (int i = 0; i < B.getStr(); i++) {
			B[i].check();
		}
		a.check();

		//������ ������� ������, ����� ��� ��� ������ � ������������� ��� ��� ������������
		for (int i = 0; i < ((B.getStr() > B.getStolb()) ? B.getStolb() : B.getStr()); i++) {
			if (B[i][i] == 0) {
				for (int j = i + 1; j < B.getStr(); j++) {
					if (B[j][i] != 0) { B.swap(i, j); a.swap(i, j); }
				}
			}
		}


		//for (int i = 0; i < B.getStolb(); i++) {
		//	std::cout << massive[i];
		//}
		delete[] massive;

		//B.print();
		//std::cout << "\n";
		//a.print();

		//�������� �� ������������ �������(���� ������� ������ ����� ����� �� ��� �������)
		for (int i = 0; i < B.getStr(); i++) {
			k = 0;
			for (int j = 0; j < B.getStolb(); j++) {
				if (B[i][j] == 0) {
					k++;
				}
				if ((k == B.getStolb()) && (a[i] != 0)) {
					//std::cout << "net resheniy";
					return l;
				}
				//������� ������� ����� ��� ������ ����� �������
				if (k == B.getStolb()) { count++; }
			}
		}

		//	std::cout << count;
		Vector c(B.getStolb());
		//����� ���� �������
		if ((B.getStr() - count) == B.getStolb()) {
		//	std::cout << "odno reshenie" << '\n';
			l.push_back(c);
			for (int i = 0; i < B.getStolb(); i++) {
				l[0][i] = a[i];
			}
			return l;
		}

		//��������� ������ - �������� ������������ 
		int param = 0;
		param = (B.getStolb() - (B.getStr() - count)); // ���������� ���������� (���-�� ���������� ����� ����)
//�� �������� ���� �������,������� �� �� ����� ��� ������� � ���������� param; + ��� ������� ������



		for (int i = 0; i < param + 1; i++) {
			l.push_back(c);
		}

		//a.print();
		k = 0;
		//������ ������
		for (int i = 0; i < B.getStolb(); i++) {
			if (stolb[i] != 0){
				l[0][i] = a[k];
				k++;
			}
			if (k == B.getStr()) { break; }

		}
			//������ �������!
		
		int d = 1;
		for (int i = 0; i < B.getStolb(); i++) {
			if (stolb[i] == 0) {
				k = 0;
				for (int m= 0; m < B.getStolb(); m++) {
					if (stolb[m] ==0 ) {
						l[d][m] = 0;
					}
					if (i == m) {
						l[d][m] = 1;
					}
					if ((stolb[m]!=0)&&(k<B.getStr())) {
						l[d][m] -= B[k][i];
						k++;
					}
				}
				d++;
			}
			if (d == param + 1) { break; }
		}


		//	}
				delete[]stolb;
		return l;
	}
};