#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdexcept>
#include <errno.h>
using namespace std;


//void testException(int x)
//{
//	if (x == 0)
//		throw "Division by zero error!"; //抛出 const char* 类型的异常
//
//	cout << "x：" << x << endl;
//}
//
//void test1()
//{
//	try {
//		testException(0);
//	}
//	catch (const char* e)
//	{
//		cout << "(Inner catch) Caught an exception: " << e << endl;
//		//将捕获到的异常重新抛出
//		throw;
//	}
//}
//
//int main()
//{
//	try {
//		test1();
//	}
//	catch (const char* e)
//	{
//		cout << "(Outer catch) Caught an exception: " << e << endl;
//	}
//	catch (...)		//如果抛出的异常未经处理，程序会被terminate终止
//	{
//		cout << "Unkonwn exception!" << endl;
//	}
//	
//	return 0;
//}

//int main()
//{
//	try {
//		throw runtime_error("Runtime exception occurred!");
//	}
//	catch (...)
//	{
//		cout << "Unkonwn exception!" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	for (size_t i = 0; i <= 10; ++i)
//		cout << i << ":" << strerror(i) << endl;
//	return 0;
//}

double Divide(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这⾥可以看到如果发⽣除0错误抛出异常，另外下⾯的array没有得到释放。
	// 所以这⾥捕获异常后并不处理异常，异常还是交给外层处理，这⾥捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Divide(len, time) << endl;
	}
	catch (...)
	{
		// 捕获异常释放内存
		cout << "delete []" << array << endl;
		delete[] array;
		throw; // 异常重新抛出，捕获到什么抛出什么
	}
	cout << "delete []" << array << endl;
	delete[] array;
}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	return 0;
//}

void  testException(int x)
{
	int* array = new int[10];
	if (x == 0)
		throw "Division by zero error!"; //抛出 const char* 类型的异常

	cout << "x：" << x << endl;
	delete[] array;
}


int main()
{
	try
	{
		testException(0);
	}
	catch (const char* e)
	{
		cout << "Caught an exception: " << e << endl;
	}
	
	return 0;
}