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

private:
  int a;
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

private:
  int b; 
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

private:
  int c;
};
```
&emsp;上述代码是一个简单的c++多态例程，最直观的感受是在父类的派生类中重写了父类中的带virtual 关键字的函数。</br>
这样做的目的是为了实现以下这种应用场景：</br>
&emsp;有时候在派生类中需要重写父类提供的某种方法，这种方法名称相同，实现了相同的作用，但是实现机制完全不一样，</br>
需要在程序运行过程中根据实际情况确定到底需要用哪个方法。</br>
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
&emsp;从main函数中可以看出，实现多态的条件有以下两个；</br>
&emsp;(1).必须通过基类的指针或者引用调用虚函数；</br>
&emsp;(2).被调用的函数是虚函数，且必须完成对基类虚函数的重写；</br>
&emsp;c++多态的原理就是--虚函数表；</br>
&emsp;当一个类中出现virtual关键字（不管是哪个函数前面有都一样），在实例化的时候编译器会为这个类对象自动分配一个虚指针(vPtr).</br>
该指针指向一个静态的虚函数表(vTable)。以上面的程序为例：Base类对象和继承类对象的内存模型如下：
![1644481704(1)](https://user-images.githubusercontent.com/22597323/153367608-377ad629-5bfc-4eb7-bae7-ca40a1e007a3.png) </br>
&emsp;从图中可以清晰的看出，每个对象都有一个虚指针，虚指针一般位于类对象内存的开始，一般为4个字节（看机器字长），虚指针指向一个</br>
静态的虚函数表，静态的含义是指这个虚函数表是该类所有对象所共享的，即不管实例化了多少该类的对象，该虚函数表都只有一个。</br>
&emsp;在执行：
```cpp
Base *p = new Derive1();
p->testFunc();
```
的时候，p指针指向如下图所示位置，接着通过子类Derive1的vPtr即可访问到Derive1的testFunc()函数。</br>
![1644483408(1)](https://user-images.githubusercontent.com/22597323/153372383-7f601527-21f9-460e-bc67-7d624ed3593e.png) </br>


