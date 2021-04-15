#ifndef __MAPBASE_H_
#define __MAPBASE_H_

#include <Eigen/Core>
#include <Eigen/LU>

namespace slam {

template <typename MapCell>
class MapBase {
	MapBase():scale(1), size(10000)
	{
	
	}

	void allocateArray(const Eigen::Vector2i &mapPoint)
	{
		int sizeX = mapPoint.x();
		int sizeY = mapPoint.y();

		mapArray = new MapCell[sizeX * sizeY];

	}

	void deleteArray()
	{
		if (mapArray != nullptr) {
			delete[] mapArray;
			mapArray = nullptr;
		}
	}

	MapCell &getCell(const int x, const int y)
	{
		return mapArray[y * sizeX + x];
	}
	
	MapCell &getCell(const int index)
	{
		return mapArray[index];
	}

	const MapCell &getCell(const int index) const
	{
		return mapArray[index];
	}

	float getScaleToMap() const
	{
		return scaleToMap;
	}


protected:
	MapCell *mapArray;
	float scaleToMap;
	int size;

	Eigen::MatrixXf

private:

};

}

#endif

