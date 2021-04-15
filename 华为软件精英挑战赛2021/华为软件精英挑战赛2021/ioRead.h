#ifndef __IOREAD_H_
#define __IOREAD_H_

#include <iostream>
#include <string>
#include "dataType.h"

namespace competition {

class ReadInput {
public: 
	ReadInput()
	{

	}
	~ReadInput()
	{

	}



	void readTrainingFile()
	{
		std::freopen("training-1.txt", "rb", stdin);

		int serverNum;
		scanf("%d", &serverNum);

		std::string serverType, cpuCores, memorySize, serverCost, powerCost;
		for (int i = 0; i < serverNum; i++) {
			std::cin >> serverType >> cpuCores >> memorySize >> serverCost >> powerCost;
			generateServer(serverType, cpuCores, memorySize, serverCost, powerCost);
		}

		int vmNumber = 0;
		scanf("%d", &vmNumber);

		std::string vmType, vmCpuCores, vmMemory, vmTwoNodes;
		for (int i = 0; i<vmNumber; i++) {
			std::cin >> vmType >> vmCpuCores >> vmMemory >> vmTwoNodes;
			generateVm(vmType, vmCpuCores, vmMemory, vmTwoNodes);
		}
	}
private:
	void generateServer(std::string &serverType, std::string &cpuCores, std::string &memorySize, std::string &serverCost, std::string &powerCost) 
	{
		std::string _serverType = "";
		for (int i = 1; i<serverType.size() - 1; i++) {
			_serverType += serverType[i];
		}
		int _cpuCores = 0, _memorySize = 0, _serverCost = 0, _powerCost = 0;

		for (int i = 0; i<cpuCores.size() - 1; i++) {
			_cpuCores = 10 * _cpuCores + cpuCores[i] - '0';
		}
		for (int i = 0; i<memorySize.size() - 1; i++) {
			_memorySize = 10 * _memorySize + memorySize[i] - '0';
		}
		for (int i = 0; i<serverCost.size() - 1; i++) {
			_serverCost = 10 * _serverCost + serverCost[i] - '0';
		}
		for (int i = 0; i<powerCost.size() - 1; i++) {
			_powerCost = 10 * _powerCost + powerCost[i] - '0';
		}
	}

	void generateVm(std::string &vmType, std::string &vmCpuCores, std::string &vmMemory, std::string &vmTwoNodes) 
	{
		std::string _vmType;

		for (int i = 1; i<vmType.size() - 1; i++) {
			_vmType += vmType[i];
		}

		int _vmCpuCores = 0, _vmMemory = 0, _vmTwoNodes = 0;
		for (int i = 0; i<vmCpuCores.size() - 1; i++) {
			_vmCpuCores = _vmCpuCores * 10 + vmCpuCores[i] - '0';
		}
		for (int i = 0; i<vmMemory.size() - 1; i++) {
			_vmMemory = _vmMemory * 10 + vmMemory[i] - '0';
		}
		if (vmTwoNodes[0] == '1') {
			_vmTwoNodes = 1;
		}
		else {
			_vmTwoNodes = 0;
		}
	}

private:
	
};

}

#endif
