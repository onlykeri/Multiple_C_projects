/** 剪刀石头布游戏 */

#include <iostream>
//#include <cstdio>
#include <ctime>
//#include <cstdlib>
//#include <windows.h>

using namespace std;
string show1(string&);
string show2(string&);
string show3(string&);
//string show4(string&,string&);

int main()
{

	string show1(string&);
	string show2(string&);
	string show3(string&);
	//string show4(string&,string&);
	srand(time(NULL));
	int num,rival;
	string scissors,rock,paper,one,result;
	char chose;
	there:
	cout << "请猜拳：" << '\n' << "1.剪刀" << '\n' << "2.石头" << '\n' << "3.布"<<endl;
	cin >> num;
	rival = (rand() % 3) +1;
	if(num==1,rival==3||num==3,rival==2||num==2,rival==1)
	{
		result ="YOU WIN!";
	}else if(num==rival)
	{
		result = "平局！";
	}
	else
	{
		result= "YOU LOSE!";
	}


	switch(num)
	{
	case 1:
		one = show1(scissors);
		cout << one << endl;
		break;
	case 2:
		show2(rock);
	        break;
	case 3:
                show3(paper);
		break;
	default :
		cout << "你没猜拳！请再猜一遍。";
		goto there;//有bug，输入字母等会崩
	}
	cout <<endl;
	cout << "--------" << result << "--------" << endl;
	cout <<endl;

	switch(rival)
	{
	case 1:
		one = show1(scissors);
		cout << one << endl;
		break;
	case 2:
		show2(rock);
	        break;
	case 3:
                show3(paper);
		break;
	}

	cout << "你想再来一局吗？（Y/N）"<<endl;
	cin >> chose;
	if(chose == 'Y'||chose =='y')
	{
		system("cls");
		goto there;
	}
	return 0;


}

//剪刀
string show1 (string& scissors)
{

	string star ="  *******************\n*                    *\n*          **********\n*                    *\n*          **********\n*          *\n*         *\n *********\n";
	return star;


}

//石头
string show2(string& rock)
{
	cout  << "  ******"        << '\n'
	      << " *     *******"  << '\n'
	      << "*             *" << '\n'
	      << "*           **"  << '\n'
	      << "*             *" << '\n'
	      << "*           **"  << '\n'
	      << "*             *" << '\n'
	      << "*           **"  << '\n'
	      << "*             *" << '\n'
	      << " *************" << endl;

}

//布
string show3(string& paper)
{
	cout  << "   *******"             << '\n'
	//Sleep(100);
	      << " *        *"            << '\n'
	      << "*        ************"  << '\n'
	//Sleep(100);
	      << "*                    *" << '\n'
	      << "*        ************"  << '\n'
	      << "*                    *" << '\n'
	      << "*        ************"  << '\n'
	      << "*                    *" << '\n'
	      << "*        ************"  << '\n'
	      << "*                    *" << '\n'
              << "  ******************"   << endl;

}






