#pragma once
#include<iostream>
#include<fstream>
template<class Type>
class TVector
{
protected:
	Type* data;
	int length;

public:
	TVector(int _lenght = 1, Type p = 0);
	TVector(const TVector<Type>& _vector);
	~TVector();
	Type GetLength();
	Type PopBack();
	void PushBack(Type variable);
	Type& operator[](int number);
	TVector<Type> operator + (const TVector<Type>& _vector);
	TVector<Type> operator - (const TVector<Type>& _vector);
	TVector<Type> operator / (const TVector<Type>& _vector);
	TVector<Type>& operator = (const TVector<Type>& _vector);
	
	bool operator == (const TVector<Type>& _vector);
}; 

template<class Type>
std::istream& operator>>(std::istream& stream, TVector<Type>& _vector)
{

	int count = 0;
	stream >> count;
	Type variable = 0;
	int length = _vector.GetLength();
	if (count > length) throw "the length of vector is less than count of number that you want to write ";
	for (int q = 0; q < length; q++)
	{
		variable = _vector.PopBack();
	}
	std::cout << "len = " << i << std::endl;
	variable = 0;
	for (int q = 0; q < count; q++)
	{
		stream >> variable;
		_vector.PushBack(variable);
	}
	return stream;
}

template<class Type>
std::ostream& operator<<(std::ostream& stream, TVector<Type>& _vector)
{
	for (int q = 0; q < _vector.GetLength(); q++)
	{
		stream << _vector[q] << ' ';
	}
	return stream;
}


template<class Type>
inline TVector<Type>::TVector(int _lenght, Type p)
{
	length = _lenght;
  data = new Type[_lenght];

	for (int i = 0; i < _lenght; i++)
	{
		data[i] = p;
	}

}

template <class Type>
inline TVector<Type>::TVector(const TVector<Type>& _vector)
{
	if (_vector.data == 0) throw "varriable of vector is empty!";
	else
	{		
		if (data != 0)
		{
			data = 0;
			delete[] data;
			data = 0;
			data = new Type[_vector.length];
		}
		else		
			data = new Type[_vector.length];
		length = _vector.length;
		for (int q = 0; q < length; q++)
		{
			data[q] = _vector.data[q];
		}
	}

}

template<class Type>
inline TVector<Type>::~TVector()
{
	if (data != 0) delete[] data;
	data = 0;
}

template<class Type>
inline Type TVector<Type>::GetLength()
{
	return length;
}

template<class Type>
inline Type TVector<Type>::PopBack()
{
	if (length <= 0) { throw"vector is empty"; }
	else
	{
		Type* temporary = new Type[length];
		for (int i = 0; i < length; i++)
		{
			temporary[i] = data[i];
		}
		Type variable = data[length - 1];

		data = 0;
		delete[] data;
		data = 0;
		data = new Type[length - 1];
		length--;
		for (int q = 0; q < length ; q++)
		{
			data[q] = temporary[q];
		}
		temporary = 0;
		delete[] temporary;
		temporary = 0;

		return variable;
	}
}

template<class Type>
inline void TVector<Type>::PushBack(Type variable)
{
	Type* temporary = new Type[length];
	for (int i = 0; i < length; i++)
	{
		temporary[i] = data[i];
	}
	data = 0;
	delete[] data;
	data = 0;
	data = new Type[length + 1];
	for (int i = 0; i < length; i++)
	{
		data[i] = temporary[i];
	}
	data[length] = variable;
	length++;
}

template<class Type>
inline Type& TVector<Type>::operator[](int number)
{
	if (number < 0 || number >= length) throw "trying to get unexist element of vector (array of values in vector) !";	
	return data[number];
}



template<class Type> 
TVector<Type> TVector<Type>::operator+ (const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.length < 0) throw "empty variable";
	if (_vector.length != this->length) throw "length of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < length; q++)
		{
			result.data[q] = (this->data[q]) + _vector.data[q];
		}

		return result;
	}
}

template<class Type>
TVector<Type> TVector<Type>::operator-(const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.length < 0) throw "empty variable";
	if (_vector.length != this->length) throw "length of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < length; q++)
		{
			result.data[q] = (this->data[q]) - _vector.data[q];
		}

		return result;
	}
}

template<class Type>
TVector<Type> TVector<Type>::operator/(const TVector<Type>& _vector)
{
	if (_vector.data == 0 && _vector.length < 0) throw "empty variable";
	if (_vector.length != this->length) throw "length of 1-st vector isn't equals to the 2-d vector";
	else
	{
		TVector<Type> result(*this);
		for (int q = 0; q < length; q++)
		{
			if (_vector.data[q] != 0)
				result.data[q] = (this->data[q]) / _vector.data[q];
			else throw "division by zero";
		}

		return result;
	}
}

template<class Type>
inline TVector<Type>& TVector<Type>::operator=(const TVector<Type>& _vector)
{
	
	if (_vector.data == 0 || _vector.length == 0) throw "empty vector was got";
	if(data == 0 ) data  = new Type[_vector.length];
	else if (data != 0)
	{
		data = 0;
		delete[] data;
		data = 0;
		data = new Type[_vector.length];
	}

	length = _vector.length;
	for (int q=0; q < length; q++)
	{
		data[q] = _vector.data[q];
	}
	return *this;
}

template<class Type>
inline bool TVector<Type>::operator==(const TVector<Type>& _vector)
{
	if (length != _vector.length) return false;
	for (int q = 0; q < length; q++)
	{
		if (data[q] != _vector.data[q]) return false;
	}
	return true;
}



