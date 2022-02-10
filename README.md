# cpp_Learning
记录自己学习c++的经历</br>
此仓库为自己学习c++时所写的所有demo</br>
开发环境为：vs2015，遵循c++11及以上标准。</br>

## 1. 简单整理
### 1.1 多态的一些知识点
&emsp;以一个例子开头：
```cpp
class Base
{
public:
  Base()
  {
  
  }
  
  virtual ~Base()
  {
  
  }
  
  virtual void testFunc()
  {
    std::cout<<"Base Class Test Function ..."<<std::endl;
  }
};

class Derive : public Base
{
public:
  Derive()
  {
  
  }
  
  ~Derive()
  {
  
  }
  
  void testFunc()
  {
    std::cout<<"Derived Class Test Function ..."<<std::endl;
  }
};
```
