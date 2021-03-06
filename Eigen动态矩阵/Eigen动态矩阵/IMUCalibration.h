#ifndef __IMU_CALIBRATION_H_
#define __IMU_CALIBRATION_H_

#include <Eigen/Dense>
#include <vector>

struct IMU
{
	float ax;// x 方向加速度
	float ay;// y 方向加速度
	float az;// z 方向加速度
	float gx;// x 方角速度
	float gy;// y 方角速度
	float gz;// z 方角速度
};
typedef struct IMU IMU;

namespace sensor {

class IMUCalibration
{
public:
	IMUCalibration();
	~IMUCalibration();

	void addDataOfAccelerometer( const IMU &imu );
	void addDataOfGyrometer( const IMU &imu );

	bool calibrateAccelerometer();
	bool calibrateGyrometer();

	Eigen::RowVector3f getAccelBias() const;
	Eigen::Vector3f getGyroBias() const;

	float getAccelBiasX() const;
	float getAccelBiasY() const;
	float getAccelBiasZ() const;

	float getGyroBiasX() const;
	float getGyroBiasY() const;
	float getGyroBiasZ() const;

private:
	template<typename T>
	T square(const T &num );

	bool caculateParametersA();

private:
	std::vector<Eigen::Matrix<float, 9, 1>> accelArray;
	std::vector<Eigen::Vector3f> gyroArray;

	Eigen::Matrix<float, 9, 1> parameters;
	Eigen::RowVector3f ellipsoidCenter;

	Eigen::Vector3f gyroBias;
};

}

#endif
