#include"Vectorr.h"
#include<iostream>
int main(void)
{


	TVector<int >A(5, 5);
	TVector<int> B(7, 5);
	TVector <int> C;
	//std::cin >> A;
	C = B;
	int a = C.GetLength();
	/*a = A.PopBack();
	a = A.PopBack();
	a = A.PopBack();
	a = A.PopBack();
	a = A.PopBack();*/
	
	//std::cout << A[1] << std::endl;
	std::cin >> C;
	std::cout << C;
	A.~TVector();
	B.~TVector();

	return 0;
}