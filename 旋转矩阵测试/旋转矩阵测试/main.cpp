#include <iostream>
#include <Eigen\Dense>
#include <math.h>

Eigen::Matrix<float, 3, 3> v2t(Eigen::Vector3f &v)
{
	float c = cos( v(2) );
	float s = sin( v(2) );

	Eigen::Matrix<float, 3, 3> A;
	A << c, -s, v(0),
		 s,  c, v(1),
		 0,  0,  1;

	return A;
}

Eigen::Vector3f t2v(Eigen::Matrix<float, 3, 3> &A)
{
	Eigen::Vector3f v;
	v(0) = A(0, 2);
	v(1) = A(1, 2);
	v(2) = ::atan2( A( 1, 0 ), A(0, 0) );

	return v;
}

int main()
{
	Eigen::Vector3f vertex1(18.5023, -4.61849, 3.04538);
	Eigen::Matrix<float, 3, 3> T1 = v2t( vertex1 );
	std::cout << "T1 = " << std::endl << T1 << std::endl << std::endl;

	/*Eigen::Vector3f poseDiff( 0.285345, -0.323944, -0.323711 );
	Eigen::Matrix<float, 3, 3> T2 = v2t(poseDiff);
	std::cout << "T2 = " << std::endl << T2 << std::endl << std::endl;*/
	 
	Eigen::Vector3f vertex2(17.5988, -4.62163, -0.23455);
	Eigen::Matrix<float, 3, 3> T2 = v2t(vertex2);
	std::cout << "T2 = " << std::endl << T2 << std::endl << std::endl;

	Eigen::Vector3f T2V = t2v( T2 );
	std::cout << "T2V = " << std::endl << T2V << std::endl << std::endl;

	Eigen::Matrix<float, 3, 3> T = T1.inverse() * T2;
	std::cout << "T = " << std::endl << T << std::endl << std::endl;

	Eigen::Vector3f V = t2v( T );
	std::cout << "V = " << std::endl << V << std::endl << std::endl;

	Eigen::Matrix<float, 3, 3> ret = T1 * v2t(V);
	std::cout << "ret = " << std::endl << ret << std::endl << std::endl;
	Eigen::Vector3f retV = t2v(ret);
	std::cout << "retV = " << std::endl << retV << std::endl << std::endl;


	return 0;

}