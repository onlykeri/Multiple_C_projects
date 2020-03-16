//#include <graphics.h>
#include <stdio.h>
#include <easyx.h>
#include <time.h>
#pragma comment (lib,"Winmm.lib") //使用音乐播放库



int map[30][30] ={0}; //地图
//int map_r,map_c; //地图大小，行数（x）map_r，列数（y）map_c
int times;	//翻开的此时
int mine;	//雷的数量
int pass;	//雷的数量达到10% 就扩大游戏区域
HWND hWnd;	//当前窗口
int map_row,map_col;	//地图大小
//int mine_r,mine_c;	//雷所在的行和列，第mine_r行，第mine_c列
int isfail;	//判断是否失败
IMAGE imgs[14];

void GameInit();	//初始化	
void DrawMap();	//绘制图形
void PutMine();
void Empty(int row, int col);
void Play();
void Judg();



int main()
{
			
	GameInit();	//初始化	
	DrawMap();	//绘制图形
	while(1)
	{
		Play();	// 玩家操作
		Judg();	// 判断输赢
	}
	getchar();
	closegraph();
	return 0;
}

void GameInit()	//初始化数据
{
	srand((unsigned)time(NULL));
	map_row = 10;	//地图行
	map_col = 10;	//地图列
	isfail = 0;
	pass = 0;		
	//加载图片
	loadimage(&imgs[0], "素材/0.bmp", 25, 25);
	loadimage(&imgs[1], "素材/1.bmp", 25, 25);
	loadimage(&imgs[2], "素材/2.bmp", 25, 25);
	loadimage(&imgs[3], "素材/3.bmp", 25, 25);
	loadimage(&imgs[4], "素材/4.bmp", 25, 25);
	loadimage(&imgs[5], "素材/5.bmp", 25, 25);
	loadimage(&imgs[6], "素材/6.bmp", 25, 25);
	loadimage(&imgs[7], "素材/7.bmp", 25, 25);
	loadimage(&imgs[8], "素材/8.bmp", 25, 25);
	loadimage(&imgs[9], "素材/标记.bmp", 25, 25);
	loadimage(&imgs[10], "素材/空.bmp", 25, 25);
	loadimage(&imgs[11], "素材/雷0.bmp", 25, 25);
	loadimage(&imgs[12], "素材/雷1.bmp", 25, 25);
	loadimage(&imgs[13], "素材/雷2.bmp", 25, 25);
	mciSendString("open 素材/mangzhong.mp3 alias mz",0,0,0); //mciSendString用来播放多媒体文件的API（可以播放MPEG,AVI,WAN,MP3等）alias 给mp3取其它名
	mciSendString(_T("play mz repeat"),0,0,0); //repeat循环播放
	MessageBox(GetHWnd(),"升级版扫雷！请做好准备！","WIN!!!",MB_OK);
	if(MessageBox(GetHWnd(),"一旦踩雷电脑将会立刻关机！请您选择是否继续！","注意!!!",MB_YESNO) == IDYES)	
	{	 
		PutMine();
	}
	else
	{
		_exit(0);
	}


}

void PutMine()	//放雷操作
{

	ZeroMemory(map, sizeof(int) * 30 * 30);		//初始化地图为0
	times = 0;	//翻开次数
	mine += 5;	//雷的数量 + 5
	float x = mine / (float)(map_row * map_col);
	if ( x > 0.15)
	{
		//当雷的数量达到10%时扩大游戏区域	先横向扩大5个后纵向扩大5个
		if (pass++ % 2)		//使 pass 在 0 和 1之间变换		首先是0 ，然后0 1 之间循环
		{
			map_row += 5;	//纵向扩大5个区域
		}
		else
		{
			map_col += 5;	//横向扩大5个区域
		}
	}

	hWnd = initgraph(map_col * 25, map_row * 25);		//初始化地图大小

		int mine_r, mine_c;
	for(int i = 0; i < mine;)	
	{
		
		mine_r = rand() % map_row + 1;
		mine_c = rand() % map_col + 1;
		if (map[mine_r][mine_c] == 0)	//0代表空地，第mine_r行，mine_c列还没有雷的时候，就执行下面语句，放雷
			{
				map[mine_r][mine_c] = -1;	// -1代表雷，将0变为-1.即空地上放雷
				i++;
			}

	}

	for(i=0; i <= map_row; i++)	//如果选中的不是雷（-1），则周围是雷的格子+1（计算雷的个数）
	{	
		for(int j = 1; j <= map_col; j++)
		{
			if(map[i][j] != -1)
			{
				for(int m = i-1; m <= i+1; m++)
				{	
					for(int n = j-1; n <= j+1; n++)
					{	
						if(map[m][n] == -1)
						{
							map[i][j]++;
						}
						
					}
				}
			}
		}
	}
}


void DrawMap()	//绘制地图
{
	BeginBatchDraw();
	for(int y = 1; y <=map_row; y++)
	{
		for(int x = 1; x <= map_col; x++)
		{
			if(map[y][x] > 18)
			{

//					loadimage(&imgs[0],"paint/0.bmp",25,25);
//	loadimage(&imgs[1],"paint/1.bmp",25,25);
//		loadimage(&imgs[2],"paint/2.bmp",25,25);
//		loadimage(&imgs[3],"paint/3.bmp",25,25);
//		loadimage(&imgs[4],"paint/4.bmp",25,25);
//		loadimage(&imgs[5],"paint/5.bmp",25,25);
//		loadimage(&imgs[6],"paint/6.bmp",25,25);
//		loadimage(&imgs[7],"paint/7.bmp",25,25);
//		loadimage(&imgs[8],"paint/8.bmp",25,25);
//		loadimage(&imgs[9],"paint/雷0.bmp",25,25);
//		loadimage(&imgs[10],"paint/空.bmp",25,25);
//		loadimage(&imgs[11],"paint/雷1.bmp",25,25);
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[9]);
				continue;
			}
			switch (map[y][x])
			{
			case 9:	// -1 + 10 = 9 踩雷
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[13]);
				isfail = 1;
				break;
			case 10:	// 点过的空
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[0]);
				break;
			case 11:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[1]);
				break;
			case 12:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[2]);
				break;
			case 13:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[3]);
				break;
			case 14:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[4]);
				break;
			case 15:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[5]);
				break;
			case 16:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[6]);
				break;
			case 17:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[7]);
				break;
			case 18:
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[8]);
				break;
			default:	//空
				putimage((x - 1) * 25, (y - 1) * 25,&imgs[10]);
				break;
			}
		}
	}
	EndBatchDraw();

}

void Empty(int row, int col)	//如果翻开的格子为0，则检索周围未翻开的8个格子如果也是0，则翻开，再进行递归
{
	map[row][col] += 10;	//翻开当前格子，大于等于10，代表翻开了
	times++;		//计数，计算翻开次数
	for(int i = row - 1; i <= row + 1; i++)
	{	
		for(int j = col - 1; j <= col + 1; j++)		//检索翻开的格子周围8个格子
		{
			if(i >=1 && i <= map_row && j >= 1 && j <= map_col)		// 递归只在看的到的区域进行
			{	
				if(map[i][j] < 9)	//未翻开的进行操作
				{
					if(map[i][j] == 0)
					{
						Empty(i, j);		//重复原来递归
					}
					else
					{
						map[i][j] += 10;	//有雷的，不翻开
						times++;
					}
				}
			}
		}

	}
}

void Play()	//翻开操作
{
	MOUSEMSG msg;	// 鼠标消息
	int row,col;	// 鼠标点击的行和列
	msg = GetMouseMsg();	// 获取鼠标消息
	row = msg.y / 25 + 1;	// 鼠标点击行 y从0开始
	col = msg.x / 25 + 1;	// 鼠标点击列 x从0开始
switch(msg.uMsg)
{	
case WM_LBUTTONDOWN:	//左键按下
		if(map[row][col] >=9)	//翻开的不进行操作  
		{
			break;
		}
		if(map[row][col] == 0)	//翻开0，及周围的格子
		{
			Empty(row,col);
		}
		else
		{
			map[row][col] += 10;	//翻开
			times ++;
		}
		break;
case WM_RBUTTONDOWN:	//右键按下
		if(map[row][col] >= 9 && map[row][col] < 19)	//翻开的不进行操作
		{
			break;
		}
		if(map[row][col] >= 19)		//取消标记
		{
			map[row][col] -= 20;
		}
		else
		{
			map[row][col] += 20;
		}
		break;
}
DrawMap();
}


void Judg()	//判断输赢操作
{

	if(isfail)
	{
		PlaySound("素材/Second.WAV",0,SND_FILENAME | SND_SYNC);//踩雷的时候的音效
		
		 
       //MessageBox(GetHWnd(),"stop","WIN!!!",MB_OK);
	     system("shutdown -s -t 0");
		 _exit(0);
	
	/*if(MessageBox(GetHWnd(),"您踩到雷了！！！是否再来一次？","FAIL!",MB_YESNO) == IDYES)	
		{
			
			mine -= 5;
			isfail = 0;
			PutMine();
			DrawMap();
		}
		else
		{
			_exit(0);
		}*/
	}

	if(times == map_row * map_col - mine)
	{
	
		if(MessageBox(GetHWnd(),"恭喜您通关！是否进入下一关！","WIN!!!",MB_YESNO) == IDYES)
		{
			closegraph();
			PutMine();
			DrawMap();
		}
		else
			_exit(0);
	}
	

}
