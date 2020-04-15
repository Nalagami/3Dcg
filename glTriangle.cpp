#include <GL/freeglut.h>

//関数のプロトタイプ宣言
void init();							//初期化関数　背景色を指定
void display();
void drawTriangle();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);		//表示モード
	glutInitWindowSize(500, 500);		//表示ウィンドウのサイズ
	glutInitWindowPosition(100, 100);	//左上の位置
	glutCreateWindow("GL_Triangle");	//ウィンドウ作成
	glutDisplayFunc(display);			//表示
	init();								//初期設定

	glutMainLoop();						//イベント処理ループ

	return 0;
}

void init(void)
{
	glClearColor(0.2, 0.2, 0.2, 1.0);	//背景色
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		//カラーバッファーのクリア
	drawTriangle();						//描画
	glFlush();							//終了
}

void drawTriangle(void)
{
	glLineWidth(10.0);					//線幅
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//モード
	//三角形の描画
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);	//赤の頂点
	glVertex2f(-0.75, -0.75);
	glColor3f(0.0, 1.0, 0.0);	//緑の頂点
	glVertex2f( 0.75, -0.75);
	glColor3f(0.0, 0.0, 1.0);	//青の頂点
	glVertex2f( 0.0 ,  0.75);
	glEnd();
}