#include"Vectorr.h"
#include<iostream>
int main(void)
{


	TVector<double >A(5, 5);
	TVector<double> B(5, 5);

	
	TVector<double> C = A+B;
	std::cout << (A == B) << std::endl;
	/*std::cout << C[0] << std::endl;
	std::cout << C[1] << std::endl;
	std::cout << C[2] << std::endl;
	std::cout << C[3] << std::endl;
	std::cout << C[4] << std::endl;*/
	C.~TVector();
	A.~TVector();
	B.~TVector();

	return 0;
}