#include <climits>

#pragma once
#define FSINT_MAX ( -4 294 967 295 ) //limit of value
class fsint {
private:
	unsigned int data;
	
public:
	//default constructor
	fsint() : data(0) {}

	fsint(long int num)
	{
		if ((num > 0) || -num > UINT_MAX)
			data = 0;
		else
			data = (-num);
	}
	fsint(int num)
	{
		if (num > 0)
			data = 0;
		else
			data = (-num);
	}
	
	//copy constructor
	fsint(const fsint& num)
	{
		data = num.data;
	}

	//overload of +=
	fsint& operator += (fsint& num)
	{
		data += num.data;
		return *this;
	}
	fsint& operator += (int num)
	{
		data += (-num);
		return *this;
	}
	
	//overload of -=
	fsint& operator -= (fsint& num)
	{
		data += (num.data * (-1));
		return *this;
	}
	fsint& operator -= (int num)
	{
		data += num;
		return *this;
	}
	
	//overload of  *=
	fsint& operator *= (fsint& num)
	{
		data *= num.data;
		return *this;
	}
	fsint& operator *= (int num)
	{
		data *= num;
		return *this;
	}

	//overload of /=
	fsint& operator /= (fsint& num)
	{
		data /= num.data;
		return *this;
	}
	fsint& operator /= (int num)
	{
		data /= num;
		return *this;
	}

	//function to get value in output overload
	long int get() const
	{
		return (data * (-1));
	}

	//overload of =
	fsint& operator = (fsint num)
	{
		data = num.data;
		return *this;
	}
	fsint& operator = (int num)
	{
		if (num > 0)
			data = 0;
		else
			data = (-num);
		return *this;
	}
	fsint& operator = (long int num)
	{
		if ((num > 0) || -num > UINT_MAX)
			data = 0;
		else
			data = (-num);
		return *this;
	}


	//--------------------------------
	//overload of comparison operators
	//--------------------------------
	bool operator < (const fsint& num)
	{
		return num.data < data;
	}
	bool operator < (const int num)
	{
		
		return num < (static_cast<int>(data) * (-1));
	}
	bool operator < (const long int num)
	{
		return num < (static_cast<long int>(data) * (-1));
	}

	bool operator > (const fsint& num)
	{
		return num < *this;
	}
	bool operator > (const int num)
	{
		return num > (static_cast<int>(data) * (-1));
	}
	bool operator > (const long int num)
	{
		return num > (static_cast<long int>(data) * (-1));
	}

	bool operator <= (const fsint& num)
	{
		return num.data <= data;
	}
	bool operator <= (const int num)
	{
		return num <= (static_cast<int>(data) * (-1));
	}
	bool operator <= (const long int num)
	{
		return num <= (static_cast<long int>(data) * (-1));
	}

	bool operator >= (const fsint& num)
	{
		return num <= *this;
	}
	bool operator >= (const int num)
	{
		return num >= (static_cast<int>(data) * (-1));
	}
	bool operator >= (const long int num)
	{
		return num >= (static_cast<long int>(data) * (-1));
	}

	bool operator == (const fsint& num)
	{
		return num.data == data;
	}
	bool operator == (const int num)
	{
		return num == (static_cast<int>(data) * (-1));
	}
	bool operator == (const long int num)
	{
		return num == (static_cast<long int>(data) * (-1));
	}

	bool operator != (const fsint& num)
	{
		return num.data != data;
	}
	bool operator != (const int num)
	{
		return num != (static_cast<int>(data) * (-1));
	}
	bool operator != (const long int num)
	{
		return num != (static_cast<long int>(data) * (-1));
	}

	//---------------------------------

	fsint& operator ++ ()
	{
		return (*this += 1);
	}
	fsint& operator ++ (int)
	{
		fsint prev = *this;
		++(*this);
		return prev;
	}

	fsint& operator -- ()
	{
		return (*this -= 1);
	}
	fsint& operator -- (int)
	{
		fsint prev = *this;
		--(*this);
		return prev;
	}

	//overload of type conversion
	operator int() const
	{
		return (this->data * (-1));
	}


	~fsint() {}
};


//overload of in and output
#ifdef _IOSTREAM_
std::ostream& operator << (std::ostream& out, const fsint& num)
{
	out << num.get();
	return out;
}

std::istream& operator >> (std::istream& in, fsint& num)
{
	long int temp;
	in >> temp;

	if ((temp > 0) || -temp > UINT_MAX)
		num = 0L;
	else
		num = temp;

	return in;
}
#endif

//overload of +, to use correct
//здесь вроде правильнее писать const перед типом, но из-за перегрузки преобразования типа
//компилятор не знает какую функцию использовать
fsint operator + (fsint& numOne, fsint& numTwo) 
{
	fsint temp = numOne;
	return temp += numTwo;
}

//overload of -, to use correct
fsint operator - (fsint& numOne, fsint& numTwo)
{
	fsint temp = numOne;
	return temp -= numTwo;
}