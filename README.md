# cpp_Learning
记录自己学习c++的经历</br>
此仓库为自己学习c++时所写的所有demo</br>
开发环境为：vs2015，遵循c++11及以上标准。</br>

## 1. 简单整理
### 1.1 多态
#### 1.1.1 c++多态的概念以及用法初步
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
  
  delete *p;
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
![1644484693(1)](https://user-images.githubusercontent.com/22597323/153376015-5b976acd-fe3f-4966-b3ea-4564a8d61bd4.png) </br>
&emsp;从图中可以清晰的看出，每个对象都有一个虚指针，虚指针一般位于类对象内存的开始，一般为4个字节（看机器字长），虚指针指向一个</br>
静态的虚函数表，静态的含义是指这个虚函数表是该类所有对象所共享的，即不管实例化了多少该类的对象，该虚函数表都只有一个。</br>
&emsp;在执行：
```cpp
  Base *p = new Derive1();
  p->testFunc();
```
的时候，p指针指向如下图所示位置，接着通过子类Derive1的vPtr即可访问到Derive1的testFunc()函数。</br>
![1644484723(1)](https://user-images.githubusercontent.com/22597323/153376111-b629fec7-145d-444c-b722-e90f66dce08e.png) </br>
执行：
```cpp
  p = new Derive2();
  p->testFunc();
```
的时候同理。</br>

#### 1.1.2 c++多态的注意事项
(1). 要想实现多态，必须有三个要素：</br>
&emsp;a. 必须有继承结构；</br>
&emsp;b. 子类中必须重写父类的虚函数；</br>
&emsp;c. 调用时必须是父类指针或者引用指向它的子类类型（即子类类型的父类指针）。</br>
(1). 在类的多态继承体系中，父类的析构函数必须是虚函数，否则在执行
```cpp
  delete *p;
```
的时候不会调用子类的虚构函数。</br>
(2). 如果父类中有需要重写的函数，则在父类中该函数必须加virtual关键字，在继承的子类中可加可不加，因为编译器会默认子类中与父类虚函数同名、</br>
同返回类型、同形参列表的函数为虚函数。</br>
(3). 注意虚函数的重写跟函数重载不一样。虚函数的重写需要保证函数的函数名、形参列表以及返回类型完全一致。</br>
(4). 类的静态成员函数是不能加virtual关键字的，即类的静态成员函数是不能实现多态的，因为静态成员函数是全局的，所有该类的对象所共享的全局函数。</br>
(5). 注意虚函数的默认形参是静态绑定的。例如：</br>
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
  
  // 这里testFunc函数有一个形参str, 其有默认参数"Base Class Str Parameter"
  virtual void testFunc(std::string str = "Base Class Str Parameter")
  {
    std::cout<<"Derive1 Class Test Function ..."<<std::endl;
    std::cout<<"str = "<<str<<std::endl;
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
  
  // 子类testFunc函数有一个形参str, 其有默认参数"Derive Class Str Parameter"
  virtual void testFunc(std::string str = "Derive Class Str Parameter")
  {
    std::cout<<"Derive Class Test Function ..."<<std::endl;
    std::cout<<"str = "<<str<<std::endl;
  }
}; 

int main()
{
  Base *p = new Derive();
  p->testFunc();

  return 0;
}
```
这里的执行结果如下:</br>
```cpp
Derive Class Test Function ...
str = Base Class Str Parameter
```
可见在这段执行代码：</br>
```cpp
  Base *p = new Derive();
  p->testFunc();
```
中确实实现了多态，因为父类类型的指针确实调用了子类中重写的函数，但是却没有使用子类的默认形参变量值，而是仍然使用了</br>
父类中的默认参数值，这是因为父类中该虚函数的默认形参值是静态绑定的，这个值相当于一个全局变量值，子类虽然重写了该方法</br>
但是在调用时使用的默认参数仍然是从这个全局变量值来取。</br>

### 1.1 多态--抽象类（接口的实现）

