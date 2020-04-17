#pragma once
#include <iostream>
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

GLuint vertexshader, fragmentshader;

//shader file��ǂݍ��݃R���p�C������
void readShaderCompile(GLuint shader, const char* file)	
{
	FILE* fp;
	char* buf;
	GLsizei size, len;
	GLint compiled;

	//�t�@�C�����J��
	fp = fopen(file, "rb");
	if (!fp) std::cout << "�t�@�C�����J�����Ƃ��ł��܂���" << file << std::endl;

	//�t�@�C���̖����Ɉړ����A���݈ʒu�𓾂�
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	//�t�@�C���T�C�Y�̃��������m��
	buf = (GLchar*)malloc(size);
	if (buf == NULL) std::cout << "���������m�ۂł��܂���ł���" << std::endl;

	//�t�@�C����擪����ǂݍ���
	fseek(fp, 0, SEEK_SET);
	fread(buf, 1, size, fp);

	//�V�F�[�_�E�I�u�W�F�N�g�Ƀv���O�������Z�b�g
	glShaderSource(shader, 1, (const GLchar**)&buf, &size);
	
	//�V�F�[�_�̓ǂݍ��ݗ̈�̊J��
	free(buf);
	fclose(fp);

	//�V�F�[�_�̃R���p�C��
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE)
	{
		std::cout << "�R���p�C���ł��܂���ł���!!:" << file << std::endl;
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			buf = (char*)malloc(size);
			glGetShaderInfoLog(shader, size, &len, buf);
			std::cout << buf << std::endl;
			free(buf);
		}
	}
}

//�����N����
void link(GLuint prog)
{
	GLsizei size, len;
	GLint	linked;
	char* infoLog;

	glLinkProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE)
	{
		std::cout << "�����N�ł��܂���ł���!" << std::endl;
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
	//glew�̏�����
	GLenum err = glewInit();
	if(err != GLEW_OK) std::cout<<Error:
}