#ifndef __DATA_TYPE_H_
#define __DATA_TYPE_H_


//--------- 服务器结构体 ----------//
struct Server {
	Server( int cpuA_, int cpuB_, int memoryA_, int memoryB_, int hardWareCost_, int operatingCost_ ):cpuA( cpuA_ ),
																									cpuB( cpuB_ ),
																									memoryA( memoryA_ ),
																									memoryB( memoryB_ ),
																									hardWareCost( hardWareCost_ ),																								
																									operatingCost(operatingCost_)
	{
		
	}

	Server(int cpu_, int memory_, int hardWareCost_, int operatingCost_):cpuA( cpu_/2 ),
																		cpuB( cpu_/2 ),
																		memoryA( memory_/2 ),
																		memoryB( memory_/2 ),
																		hardWareCost(hardWareCost_),
																		operatingCost(operatingCost_)
	{

	}

	Server():cpuA(0), cpuB(0), memoryA(0), memoryB(0), hardWareCost(0), operatingCost(0)
	{
	
	}
	~Server(){}


	int cpuA;
	int cpuB;
	int memoryA;
	int memoryB;

	int hardWareCost;
	int operatingCost;
};

//--------- 虚拟机结构体 ----------//
struct VirtualMachine {
	VirtualMachine():cpuNum(0),
					memeorySize(0),
					isDoubleNode(0)
	{
		
	}

	VirtualMachine( int cpuNum_, int memorySize_, unsigned char isDoubleNode_ ):cpuNum(cpuNum_),
																				memeorySize(memorySize_),
																				isDoubleNode(isDoubleNode_)
	{

	}

	int cpuNum;
	int memeorySize;
	unsigned char isDoubleNode;
};

#endif
