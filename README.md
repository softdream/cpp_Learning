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

class Derive1 : public Base
{
public:
  Derive1()
  {
  
  }
  
  ~Derive1()
  {
  
  }
  
  virtual void testFunc()
  {
    std::cout<<"Derive1 Class Test Function ..."<<std::endl;
  }
};

class Derive2 : public Base
{
public:
  Derive2()
  {
  
  }
  
  ~Derive2()
  {
  
  }
  
  virtual void testFunc()
  {
    std::cout<<"Derive2 Class Test Function ..."<<std::endl;
  }
};
```</br>
&emsp;上述代码是一个简单的c++多态例程，最直观的感受是在父类的派生类中重写了父类中的带virtual 关键字的函数。</br>
这样做的目的是为了实现以下这种应用场景：</br>
有时候在派生类中需要重写父类提供的某种方法，这种方法名称相同，实现了相同的作用，但是实现机制完全不一样，需要在程序运行过程中根据实际情况确定</br>
到底需要用哪个方法。</br>
&emsp;在实际调用时，如下：</br>
```cpp
int main()
{
  Base *p = new Derive1();
  p->testFunc();
  
  p = new Derive2();
  p->testFunc();
  
  return 0;
}
```
&emsp;此时打印出的结果分别为：</br>
```cpp
"Derive1 Class Test Function ...
Derive2 Class Test Function ...
```

