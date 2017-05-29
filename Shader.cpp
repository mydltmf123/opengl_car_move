#include "Shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(std::string& vs, std::string& fs)
{
	Shader::LoadShader(vs, fs);
}
Shader::Shader(std::string& vs, std::string& fs, std::string& gs)
{
	Shader::LoadShader(vs, fs, gs);
}
Shader::Shader()
{

}

void Shader::Use()
{
	glUseProgram(program);
}

void Shader::AddUniformVar(const char* var)
{
	GLint loc = glGetUniformLocation(program, var);
	if (loc == -1)
		return;
	uniformVars[var] = loc;
}

GLint Shader::GetUniformVar(const char* var)
{
	return uniformVars[var];
}

void Shader::LoadShader(std::string& vs, std::string& fs)
{
	GLuint ShaderObj;
	program = glCreateProgram();

	// Vertex shader
	std::ifstream ifsVS(vs);
	std::string vshader((std::istreambuf_iterator<char>(ifsVS)), std::istreambuf_iterator<char>());

	ShaderObj = glCreateShader(GL_VERTEX_SHADER);
	const char* temp_vs = vshader.c_str();
	glShaderSource(ShaderObj, 1, &temp_vs, nullptr);
	glCompileShader(ShaderObj);
	GLint success;
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		std::cout <<"error"<<std::endl;
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);

		return;
	}
	std::cout << "success" << std::endl;
	glAttachShader(program, ShaderObj);

	ifsVS.close();

	// Fragment shader
	std::ifstream ifsFS(fs);
	std::string fshader((std::istreambuf_iterator<char>(ifsFS)), std::istreambuf_iterator<char>());

	ShaderObj = glCreateShader(GL_FRAGMENT_SHADER);
	const char* temp_fs = fshader.c_str();
	glShaderSource(ShaderObj, 1, &temp_fs, nullptr);
	glCompileShader(ShaderObj);
	if (!success) {
		std::cout << "errer" << std::endl;
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);

		return;
	}
	std::cout << "	success" << std::endl;
	glAttachShader(program, ShaderObj);

	ifsFS.close();

	glLinkProgram(program);
}
void Shader::LoadShader(std::string& vs, std::string& fs, std::string& gs)
{
	GLuint ShaderObj;
	program = glCreateProgram();

	// Vertex shader
	std::ifstream ifsVS(vs);
	std::string vshader((std::istreambuf_iterator<char>(ifsVS)), std::istreambuf_iterator<char>());

	ShaderObj = glCreateShader(GL_VERTEX_SHADER);
	const char* temp_vs = vshader.c_str();
	glShaderSource(ShaderObj, 1, &temp_vs, nullptr);
	glCompileShader(ShaderObj);
	GLint success;
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		std::cout << "error" << std::endl;
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);

		return;
	}
	std::cout << "success" << std::endl;
	glAttachShader(program, ShaderObj);

	ifsVS.close();
	//GS
	std::ifstream ifsGS(gs);
	std::string gshader((std::istreambuf_iterator<char>(ifsGS)), std::istreambuf_iterator<char>());

	ShaderObj = glCreateShader(GL_GEOMETRY_SHADER);
	const char* temp_gs = gshader.c_str();
	glShaderSource(ShaderObj, 1, &temp_gs, nullptr);
	glCompileShader(ShaderObj);

	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		std::cout << "	error" << std::endl;
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);

		return;
	}
	std::cout << "	success" << std::endl;
	glAttachShader(program, ShaderObj);

	ifsGS.close();

	// Fragment shader
	std::ifstream ifsFS(fs);
	std::string fshader((std::istreambuf_iterator<char>(ifsFS)), std::istreambuf_iterator<char>());

	ShaderObj = glCreateShader(GL_FRAGMENT_SHADER);
	const char* temp_fs = fshader.c_str();
	glShaderSource(ShaderObj, 1, &temp_fs, nullptr);
	glCompileShader(ShaderObj);
	if (!success) {
		std::cout << "		errer" << std::endl;
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, sizeof(InfoLog), NULL, InfoLog);

		return;
	}
	std::cout << "		success" << std::endl;
	glAttachShader(program, ShaderObj);

	ifsFS.close();

	

	glLinkProgram(program);
}

