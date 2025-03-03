#include<iostream>
#include<graphics.h>//  包含被淘汰的函数
     // <easyx.h> 只包含最新的函数

void Draw()
{
	//画棋盘
	initgraph(400, 400);

	setbkcolor(LIGHTBLUE);//设置背景颜色
	cleardevice();  //刷新一下
	setlinecolor(BLACK);  //设置线条颜色
	
	for (int i = 0; i <= 400; i +=20)
	{
		line(0, i, 400, i);
		line(i, 0, i, 400);
	}

	system("pause");

	closegraph();
}


int main()
{
	
	////initgraph(800, 600, 1);  1 表示显示控制台
	////可以在控制台进行调试
	////std::cout << "x=100,y=100" << std::endl;
	//
	//initgraph(800, 600);//默认不显示控制台

	////设置背景颜色  2.RGB设置

	//// 1.颜色宏
	//setbkcolor(RED);//使用颜色宏  具体颜色可右键点击后转到定义查看
	//cleardevice();//记得刷新一下，否则不会显示颜色

	//line(0, 0, 800, 600);//使用划线函数，输入两点坐标即可
	//circle(100, 100, 50);//画圆函数，输入坐标和半径


	//rectangle(300, 300, 400, 400);//矩形函数，输入左上角和右下角的参数

	//setfillcolor(LIGHTBLUE);//设置填充颜色
	//fillcircle(200, 200, 50);//绘制带边框线的填充圆
	//solidcircle(300, 300, 50);//绘制不带边框线的填充圆

	//fillrectangle(400, 400, 500, 500);//绘制带边框线的矩形
	//solidrectangle(10, 10, 100, 100);//绘制不带边框线的矩形

	//system("pause");
	//closegraph();


	Draw();

	

	

	return 0;

	
}