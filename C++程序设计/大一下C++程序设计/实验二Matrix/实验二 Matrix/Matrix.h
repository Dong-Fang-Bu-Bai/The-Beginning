
#pragma once

#include<iostream>

class Matrix
{
public:
	friend std::ostream& operator <<(std::ostream& outf, Matrix m);
	friend std::istream& operator >> (std::istream& inf, Matrix& m);
	friend Matrix operator *(int a, Matrix &m);

	Matrix();//

	Matrix(int, int, int, int);//
	
	void printnum() const
	{
		std::cout << m_a << " " << m_b << std::endl << m_c << " " << m_d << std::endl;
	}

	void getnum()
	{
		std::cin >> m_a  >> m_b >> m_c >> m_d ;
	}

	int outnuma() const
	{
		return m_a;
	}

	int outnumb() const
	{
		return m_b;
	}

	int outnumc() const
	{
		return m_c;
	}

	int outnumd() const
	{
		return m_d;
	}


	Matrix operator +(Matrix &);//

	Matrix operator -(Matrix &);//

	Matrix operator *(Matrix &);//

	Matrix operator +=(Matrix&);//

	Matrix operator -=(Matrix&);//

	Matrix operator *=(Matrix&);//

	bool operator ==(Matrix&);//

	bool operator !=(Matrix&);//

	

	

private:

	int m_a;
	int m_b;
	int m_c;
	int m_d;
};







