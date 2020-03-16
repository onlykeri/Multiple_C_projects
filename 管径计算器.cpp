#include <iostream>
#include <cmath>
#include <cstdlib>
#define PI 3.1415926 //定义PI

using namespace std;
int remember1,remember2;
double x,u,Q,P,Result,deviation=0.001,l2;
char choice1,choice2,choice3,choice4;
double l=0.25;

void FirstChoice();	//判断是否更改管子长度
void SecondChoice();	//判断输出结果是管子直径还是半径
void ThirdChoice();	//判断输出结果的单位
void FourthChoice();	//判断程序是否继续
void FifthChoice();
void Import();		//输入相关数值
void OutputResult();

int main()
{
	system("color f0");	//修改程序输出窗口的背景颜色和前景颜色（默认为：亮白色背景f，和黑色字体0）
	cout << endl;
	cout << "*计算" << endl;	//方程为：x=[(128*u*l*Q)/(PI*P)]1/4
	FirstChoice();
	cout << endl;
	SecondChoice();
	cout << endl;
	ThirdChoice();
	cout << endl;
	FifthChoice();
	there:
	Import();
	Result = sqrt(sqrt((128*u*l*Q)/(PI*P)));	//计算结果
	cout << endl;
	OutputResult();
	cout << endl;
	FourthChoice();
	goto there;

	return 0;
}

void FirstChoice()	//判断是否更改管子长度
{
	cout << "#默认管子长度为25cm：请选择是否需要更改管子长度（y/n）:" << endl;
	cin >> choice1;
	switch(choice1)
	{
	case 'y': case 'Y':
		cout << "请输入更改后的长度（单位：cm，厘米）" << endl;
		cin >> l2;
		l = l2;
		break;
	case 'n': case 'N':
		break;
	default:
		cout << "*您输入的非法！默认管子长度为25cm*" << endl;
		break;
	}
}

void SecondChoice()	//判断输出结果是直径还是半径
{
	cout << "#默认输出结果为管内直径（不包含管子厚度）：请选择是否更改为半径（y/n）" << endl;	//请选择输出结果为半径（0）或者直径（1）：（如果选择结果为半径则输入0；否则输入1）
	cin >> choice2;	//判断输出结果为半径还是直径
	switch(choice2)
	{
		case 'y': case 'Y':
		remember1 = 0;
		cout << "*输出结果为管内半径*" << endl;
		break;
		case 'n': case 'N':
		remember1 = 1;
		cout << "*输出结果为管内直径*" << endl;
		break;
		default:
			cout << "*您输入的非法！默认输出结果为直径*" << endl;
		remember1 = 1;
		break;

	}
	//	cout << "请输入管子长度：（单位：m，米）" << endl;
//	cin >> l;
//	if(l<0)
//	{
//		cout << "@您输入的管子长度非法！管子长度应该为正数。" << endl;
//		cout << "@请重新输入！" << endl;
//		goto there;
////    		exit(0);
//	}
}

void ThirdChoice()	//判断输出结果的单位
{
	cout << "#默认输出结果的单位为毫米（mm）：请选择是否更改输出结果单位为米（m）（y/n）" << endl;	//请选择输出结果的单位米（0）或者毫米（1）：（如果选择单位是米则0；否则输入1）
	cin >> choice3;	//判断输出结果为
	switch(choice3)
	{
		case 'y': case 'Y':
			remember2 = 0;
			cout << "*之后输出结果的单位是米*" << endl;
		break;
		case 'n': case 'N':
			remember2 = 1;
			cout << "*之后输出结果的单位是毫米*" << endl;
		break;
		default:
			cout << "*您输入字符非法！默认输出结果的单位为毫米*" << endl;
		remember2 = 1;
		break;

	}
}

void FourthChoice()	//判断是否继续程序
{
	cout << "#请问是否继续计算：(y/n)" << endl;
	cin >> choice4;
	switch(choice4)	//判断是否继续计算
	{
		case 'y':case 'Y':
			break;
		case 'n':case 'N':
			exit(0);
		default:
			exit(0);
	}
}

void FifthChoice()
{
	cout << "请输入偏差值：（单位：毫米）" << endl;
	cout << "（例如：管子规格18F的标准要求（管内直径6毫米，不包含管壁），偏差值为0.1毫米，则所求得结果在5.9~6.1范围内都所符合要求）" << endl;
	cin >> deviation;
	deviation = deviation*0.001;	//偏差将毫米单位转化为米
}

void Import()	//输入相关数值
{


	cout << endl;
	cout << "****************************************************************" << endl;
	there2:
	cout << "请输入粘滞系数（例如：1.0*10^3，则用e代表10，写成1.0e3，输入下方。同理其它值得输入也可采用此方法）（单位：Pas，帕秒）：" << endl;
	cin >> u;
	if(u<0)
	{
		cout << "@您输入的粘滞系数非法！粘滞系数应该为正数。" << endl;
		cout << "@请重新输入！" << endl;
		goto there2;
	//    	exit(0);
	}
	cout << "请输入压强差：（单位：Pa，帕）" << endl;
	cin >> P;
	P=abs(P);
	there3:
	cout << "请输入体积流量：（单位：m^3/s,立方米/s）" << endl;
	cin >> Q;
	if(Q<0)
	{
		cout << "@您输入的体积流量非法！体积流量应该为正数。" << endl;
		cout << "@请重新输入！" << endl;
		goto there3;
//    		exit(0);
	}
}

void OutputResult()	//输出结果
{
	  if(Result >( 0.006-deviation) && Result < (0.006-deviation))
	    {
		cout << "*所求得的管内直径满足要求。" <<endl;
	    }else
	    {
		cout << "*所求得的管内直径不满足要求！" <<endl;
	    }
	    if(remember1 == 0 && remember2 == 0)	//半径，单位米
	   {
		Result = Result/2;
		cout << "结果为：" << endl;
		cout << "*管子的内半径是： "
		     << Result << "米" << endl;
	   }else if(remember1 == 0 && remember2 == 1)	//半径，单位毫米
	   {
		Result = Result/2;
		cout << "结果为：" << endl;
		cout << "*管子的内半径是： "
		     << Result*1000 << "毫米" << endl;
	   }else if(remember1 == 1 && remember2 == 0)	//直径，单位米
	   {
		Result = Result;
		cout << "结果为：" << endl;
		cout << "*管子的内直径是： "
		     << Result << "米" << endl;
	   }else if(remember1 == 1 && remember2 == 1 )	//直径，单位毫米
	   {
		Result = Result;
		cout << "结果为：" << endl;
		cout << "*管子的内直径是： "
		     << Result*1000 << "毫米" << endl;
	   }
}
