#pragma once
#include <iostream>
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

GLuint vertexshader, fragmentshader;

//shader fileを読み込みコンパイルする
void readShaderCompile(GLuint shader, const char* file)	
{
	FILE* fp;
	char* buf;
	GLsizei size, len;
	GLint compiled;

	//ファイルを開く
	fp = fopen(file, "rb");
	if (!fp) std::cout << "ファイルを開くことができません" << file << std::endl;

	//ファイルの末尾に移動し、現在位置を得る
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	//ファイルサイズのメモリを確保
	buf = (GLchar*)malloc(size);
	if (buf == NULL) std::cout << "メモリが確保できませんでした" << std::endl;

	//ファイルを先頭から読み込む
	fseek(fp, 0, SEEK_SET);
	fread(buf, 1, size, fp);

	//シェーダ・オブジェクトにプログラムをセット
	glShaderSource(shader, 1, (const GLchar**)&buf, &size);
	
	//シェーダの読み込み領域の開放
	free(buf);
	fclose(fp);

	//シェーダのコンパイル
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE)
	{
		std::cout << "コンパイルできませんでした!!:" << file << std::endl;
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			buf = (char*)malloc(size);
			glGetShaderInfoLog(shader, size, &len, buf);
			std::cout << buf << std::endl;
			free(buf);
		}
	}
}

//リンクする
void link(GLuint prog)
{
	GLsizei size, len;
	GLint	linked;
	char* infoLog;

	glLinkProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE)
	{
		std::cout << "リンクできませんでした!" << std::endl;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
		if (size > 0)
		{
			infoLog = (char*)malloc(size);
			glGetProgramInfoLog(prog, size, &len, infoLog);
			std::cout << infoLog << std::endl;
			free(infoLog);
		}
	}
}

void initGlsl(GLuint* program, const char* vertexFile)
{
	//glewの初期化
	GLenum err = glewInit();
	if(err != GLEW_OK) std::cout<<Error:
}