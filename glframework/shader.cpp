#include "shader.h"
#include "shader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../wrapper/checkerror.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cout << "ERROR:Shader File Error: " << e.what() << std::endl;
	}

	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();

	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertex, 1, &vertexShaderSource, NULL);
	glShaderSource(fragment, 1, &fragmentShaderSource, NULL);

	glCompileShader(vertex);
	checkShaderError(vertex, "COMPILE");
	glCompileShader(fragment);
	checkShaderError(fragment, "COMPILE");

	mProgram = glCreateProgram();

	glAttachShader(mProgram, vertex);
	glAttachShader(mProgram, fragment);

	glLinkProgram(mProgram);
	checkShaderError(mProgram, "LINK");


	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader()
{
}

void Shader::begin()
{
	glUseProgram(mProgram);
}

void Shader::end()
{
	glUseProgram(0);
}

void Shader::checkShaderError(GLuint target, std::string type)
{
	int success = 0;
	char infoLog[1024];
	if (type == "COMPILE") {
		glGetShaderiv(target, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(target, 1024, NULL, infoLog);
			std::cout << "Error: SHADER COMPILE ERROR" << "\n" << infoLog << std::endl;
		}
	}
	else if (type == "LINK") {
		glGetProgramiv(target, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(target, 1024, NULL, infoLog);
			std::cout << "Error: SHADER LINK ERROR " << "\n" << infoLog << std::endl;
		}
	}
	else {
		std::cout << "Error: Check shader errors Type is wrong" << std::endl;
	}
}

void Shader::setFloat(const std::string& name, float value)
{
	GLuint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	GL_CALL(glUniform1f(location, value));
}

void Shader::setVector3(const std::string& name, float x, float y, float z)
{
	GLint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	GL_CALL(glUniform3f(location,x,y,z ));
}

void Shader::setVector3(const std::string& name, const float* values)
{
	GLint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	GL_CALL(glUniform3fv(location, 1,values)); 
}

void Shader::setInt(const std::string& name, int value)
{
	GLint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	GL_CALL(glUniform1i(location,  value));
}

void Shader::setMatrix4x4(const std::string& name, glm::mat4 value)
{
	GLint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
