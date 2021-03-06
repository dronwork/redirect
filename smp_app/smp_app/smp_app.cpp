// smp_app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Main
{

   int main()
{
	   GLuint SimpleScene::compileShader(GLenum type, const std::string & source)
	   {
		   
		   GLuint shader = glCreateShader(type);

		  
		   const auto length = static_cast<int>(source.length());
		   const char* sourceLine = source.data();
		   glShaderSource(shader, 1, (const GLchar**)&sourceLine, &length);

		  
		   glCompileShader(shader);

		   GLint ok = 0;
		   glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
		   if (ok == GL_FALSE)
		   {
			   
			   GLint logLength = 0;
			   glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);

			  
			   std::string log(logLength, '\0');
			   GLsizei ignored = 0;
			   glGetShaderInfoLog(shader, log.size(), &ignored, (GLchar*)log.data());

			  
			   throw std::runtime_error("shader compilation failed: " + log);
		   }

		   return shader;
	   }
}

};

