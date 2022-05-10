#pragma once
#include<iostream>

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
	
	Type& operator[](int number);
	TVector<Type> operator + (const TVector<Type>& _vector);
	TVector<Type> operator - (const TVector<Type>& _vector);
	TVector<Type> operator / (const TVector<Type>& _vector);
	TVector<Type>& operator = (const TVector<Type>& _vector);
	bool operator == (const TVector<Type>& _vector);
};



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
inline Type& TVector<Type>::operator[](int number)
{
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
TVector<Type>& TVector<Type>::operator = (const TVector<Type>& _vector)
{
	if (_vector.data == 0 || _vector.length == 0) throw "empty vector was got";
	if (data == 0) data = new Type[_vector.length];
	else (data != 0)
	{
		data = 0;
		delete[] data;
		data = 0; 
		data = new Type[_vector.length];
	}
	
	length = _vector.length
	for (int q; q < length; q++)
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

/*
 доступ к защищенным пол€м;
  потоковый ввод и вывод;
*/
