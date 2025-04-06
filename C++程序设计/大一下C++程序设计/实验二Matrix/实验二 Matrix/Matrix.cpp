
#include"Matrix.h"
#include<iostream>

Matrix::Matrix()
{
	m_a = 1;
	m_b = 0;
	m_c = 0;
	m_d = 1;
}

Matrix::Matrix(int a,int b,int c,int d )
{
	m_a = a;
	m_b = b;
	m_c = c;
	m_d = d;
}

Matrix Matrix::operator +(Matrix &m) 
{
	Matrix n { this->m_a + m.outnuma(),this->m_b + m.outnumb() ,
		this->m_c + m.outnumc(), this->m_d + m.outnumd() };

	return n;
}

Matrix Matrix::operator -(Matrix & m) 
{
	Matrix n{ this->m_a - m.outnuma(),this->m_b - m.outnumb() ,
	this->m_c - m.outnumc(), this->m_d - m.outnumd() };

	return n;

};


Matrix Matrix::operator *(Matrix & m)
{
	Matrix n
	{ 
		this->m_a * m.outnuma()+ this->m_b * m.outnumc(),
		this->m_a* m.outnumb() + this->m_b * m.outnumd() ,
	    this->m_c* m.outnuma() + this->m_d * m.outnumc(),
		this->m_c* m.outnumb() + this->m_d * m.outnumd()
	};
	
	return n;
};

Matrix Matrix::operator +=(Matrix& m)
{
	this->m_a += m.outnuma();
	this->m_b += m.outnumb();
	this->m_c += m.outnumc();
	this->m_d += m.outnumd();

	return *this;
}

Matrix Matrix::operator -=(Matrix& m)
{
	this->m_a -= m.outnuma();
	this->m_b -= m.outnumb();
	this->m_c -= m.outnumc();
	this->m_d -= m.outnumd();

	return *this;

}

Matrix Matrix::operator *=(Matrix& m)
{
	this->m_a = this->m_a * m.outnuma() + this->m_b * m.outnumc();
	this->m_b = this->m_a * m.outnumb() + this->m_b * m.outnumd();
	this->m_c = this->m_c * m.outnuma() + this->m_d * m.outnumc();
	this->m_d = this->m_c * m.outnumb() + this->m_d * m.outnumd();

	return *this;
}

std::ostream& operator <<(std::ostream& outf, Matrix  m)//重载插入运算符
{
	std::cout << "answer:" << std::endl;
	outf << m.m_a << " " << m.m_b
		<< std::endl << m.m_c << " " << m.m_d << std::endl;

	return outf;
}

std::istream& operator >> (std::istream& inf, Matrix & m)//重载提取运算符
{
	std::cout << "write 4 nums:" << std::endl;
	inf >> m.m_a  >> m.m_b
		 >> m.m_c  >> m.m_d;
	return inf;
}

Matrix operator *(int a, Matrix &m)
{
	Matrix n
	{
		m.m_a * a,
		m.m_b *  a,
		m.m_c *a ,
		m.m_d * a
	};

	return n;
}

bool Matrix::operator ==(Matrix& m)
{
	if (this->m_a == m.outnuma() && this->m_b == m.outnumb()
		&&this->m_c == m.outnumc() && this->m_d == m.outnumd())
	{
		return 1;
	}
	return 0;
}

bool Matrix::operator !=(Matrix& m)
{
	if (this->m_a == m.outnuma() && this->m_b == m.outnumb()
		&& this->m_c == m.outnumc() && this->m_d == m.outnumd())
	{
		return 0;
	}
	return 1;
}





