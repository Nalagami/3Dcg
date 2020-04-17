#include "myGlsl.h"

//�֐��̃v���g�^�C�v�錾
void init();							//�������֐��@�w�i�F���w��
void display();
void drawTriangle();
//�V�F�[�_�E�v���O������
GLuint shaderProg;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);		//�\�����[�h
	glutInitWindowSize(500, 500);		//�\���E�B���h�E�̃T�C�Y
	glutInitWindowPosition(100, 100);	//����̈ʒu
	glutCreateWindow("GL_Triangle");	//�E�B���h�E�쐬
	glutDisplayFunc(display);			//�\��
	init();								//�����ݒ�
	initGlsl(&shaderProg, "triangle.vert");	//���_�V�F�[�_

	glutMainLoop();						//�C�x���g�������[�v
	glDeleteProgram(shaderProg);		//���\�[�X�̊J��
	return 0;
}

void init(void)
{
	glClearColor(0.2, 0.2, 0.2, 1.0);	//�w�i�F
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);		//�J���[�o�b�t�@�[�̃N���A
	//�`��
	glUseProgram(shaderProg);			//�V�F�[�_�E�v���O�����̓K�p
	drawTriangle();						//�}�`�̕`��
	glUseProgram(0);					//�V�F�[�_�E�v���O�����̓K�p������
	glFlush();							//�I��
}

void drawTriangle(void)
{
	glLineWidth(10.0);					//����
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	//���[�h
	//�O�p�`�̕`��
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);	//�Ԃ̒��_
	glVertex2f(-0.75, -0.75);
	glColor3f(0.0, 1.0, 0.0);	//�΂̒��_
	glVertex2f( 0.75, -0.75);
	glColor3f(0.0, 0.0, 1.0);	//�̒��_
	glVertex2f( 0.0 ,  0.75);
	glEnd();
}