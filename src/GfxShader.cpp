#include "GfxShader.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <iostream>

#define check() assert(glGetError() == 0)

// printShaderInfoLog
// From OpenGL Shading Language 3rd Edition, p215-216
// Display (hopefully) useful error messages if shader fails to compile

void printShaderInfoLog(GLint shader) {
  int infoLogLen = 0;
  int charsWritten = 0;
  GLchar *infoLog;

  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

  if (infoLogLen > 0) {
    infoLog = new GLchar[infoLogLen];
    // error check for fail to allocate memory omitted
    glGetShaderInfoLog(shader, infoLogLen, &charsWritten, infoLog);
    std::cout << "InfoLog : " << std::endl << infoLog << std::endl;
    delete [] infoLog;
  }
}

bool GfxShader::LoadVertexShader(const char* filename) {
  //cheeky bit of code to read the whole file into memory
  assert(!Src);
  FILE* f = fopen(filename, "rb");
  assert(f);
  fseek(f, 0, SEEK_END);
  int sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  Src = new GLchar[sz + 1];
  fread(Src, 1, sz, f);
  Src[sz] = 0; //null terminate it!
  fclose(f);

  //now create and compile the shader
  GlShaderType = GL_VERTEX_SHADER;
  Id = glCreateShader(GlShaderType);
  glShaderSource(Id, 1, (const GLchar**) &Src, 0);
  glCompileShader(Id);
  check();

  //compilation check
  GLint compiled;
  glGetShaderiv(Id, GL_COMPILE_STATUS, &compiled);
  if (compiled == 0) {
    printf("Failed to compile vertex shader %s:\n%s\n", filename, Src);
    printShaderInfoLog(Id);
    glDeleteShader(Id);
    return false;
  } else {
    printf("Compiled vertex shader %s:\n%s\n", filename, Src);
  }

  return true;
}

bool GfxShader::LoadFragmentShader(const char* filename) {
  //cheeky bit of code to read the whole file into memory
  assert(!Src);
  FILE* f = fopen(filename, "rb");
  assert(f);
  fseek(f, 0, SEEK_END);
  int sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  Src = new GLchar[sz + 1];
  fread(Src, 1, sz, f);
  Src[sz] = 0; //null terminate it!
  fclose(f);

  //now create and compile the shader
  GlShaderType = GL_FRAGMENT_SHADER;
  Id = glCreateShader(GlShaderType);
  glShaderSource(Id, 1, (const GLchar**) &Src, 0);
  glCompileShader(Id);
  check();

  //compilation check
  GLint compiled;
  glGetShaderiv(Id, GL_COMPILE_STATUS, &compiled);
  if (compiled == 0) {
    printf("Failed to compile fragment shader %s:\n%s\n", filename, Src);
    printShaderInfoLog(Id);
    glDeleteShader(Id);
    return false;
  } else {
    printf("Compiled fragment shader %s\n", filename);
  }

  return true;
}