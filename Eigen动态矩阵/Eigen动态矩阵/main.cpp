#include <iostream>

#include <Eigen/Dense>
#include <vector>

#include <map>

int main()
{
	/*Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mat( 100, 9 );
	//Eigen::Matrix<double, 3, 3> mat;
	Eigen::VectorXf parameters;

	parameters.resize(9);

	parameters << 1, 2, 3, 4, 5, 6, 7, 8, 9;


	std::cout << parameters << std::endl;
	std::cout << parameters.transpose() << std::endl;

	int rows = 9;
	Eigen::Matrix<float, 9, 1> Y = Eigen::Matrix<float, 9, 1>::Identity();

	std::cout<<"Y = "<<std::endl<<Y<<std::endl;

	std::cout << "Y[0] = " << Y[0] << std::endl;
	std::cout << "Y(0) = " << Y(0) << std::endl;
	*/

	/*std::vector<Eigen::Matrix<double, 9, 1>> vecArray;

	Eigen::Matrix<double, 9, 1> tmp;
	tmp << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	std::cout << "tmp = " << std::endl;
	std::cout << tmp << std::endl;

	vecArray.push_back( tmp );

	for (auto it : vecArray) {
		std::cout << "vector = " << std::endl;
		std::cout << it << std::endl;
	}*/

/*	Eigen::VectorXd vec;

	vec << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	std::cout << "vec = " << std::endl;
	std::cout << vec << std::endl;*/

//	mat << 1, 2, 3,
//		4, 5, 6,
//		5, 6, 7;
	/*mat.row(0) << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	mat.row(1) << 10, 11, 12, 13, 14, 15, 16, 17, 18;
	mat.row(2) << 19, 20, 21, 22, 23, 24, 25, 26, 27;

	mat.row(3) = vec;

	std::cout << std::endl;
	std::cout << mat << std::endl;*/

	/*Eigen::Matrix<float, 2, 2> mat = Eigen::Matrix<float, 2, 2>::Zero();

	mat << 4, 8,
		12, 16;
	std::cout << "mat = " << std::endl << mat << std::endl << std::endl;

	Eigen::Matrix<float, 2, 2> mat2 = Eigen::Matrix<float, 2, 2>::Zero();
	mat2 << 0.5, 0.5,
		0.5, (float)1/2;
	std::cout << "mat2 = " << std::endl << mat2 << std::endl << std::endl;

	Eigen::Matrix<float, 2, 2> mat3 = Eigen::Matrix<float, 2, 2>::Zero();

	mat3 = mat.cwiseProduct( mat2 );

	std::cout << "mat3 = " << std::endl << mat3 << std::endl << std::endl;*/


		Eigen::Matrix<float, 4, 4> mat;
		std::cout << mat.rows() << " " << mat.cols() << std::endl;

	return 0;
}