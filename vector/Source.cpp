#include"Vectorr.h"
#include"Matrix.h"
#include<iostream>
int main(void)
{
	//TMatrix<Type> result(_matrix.length, width, 0)!!!!!
	TMatrix<int> A(3, 3, 2);
	TVector<int> B(3);
	
	std::cin >> B;
	A* B;


	/*B.Show();
	std::cout << std::endl;
	C.Show();
	std::cout << std::endl;
	D = B * C;
	std::cout << D;*/
//	std::cout<<(B* C);

	






	return 0;
}
//TVector<int >A(5, 5);
//TVector<int> B(7, 5);
//TVector <int> C;
////std::cin >> A;
//C = B;
//int a = C.GetLength();
///*a = A.PopBack();
//a = A.PopBack();
//a = A.PopBack();
//a = A.PopBack();
//a = A.PopBack();*/
//
////std::cout << A[1] << std::endl;
//std::cin >> C;
//std::cout << C;
//A.~TVector();
//B.~TVector();