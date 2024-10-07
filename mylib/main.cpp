#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "pizza.hpp"
#include "shaders.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 732;

unsigned int renderMode = GL_LINES;

ogl::vector moveRight(0.1f, 0.0f, 0.0f);
ogl::vector moveLeft(-0.1f, 0.0f, 0.0f);
ogl::vector moveUp(0.0f, 0.1f, 0.0f);
ogl::vector moveDown(0.0f, -0.1f, 0.0f);

ogl::pizza miEstrella;

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif

  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetKeyCallback(window, key_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

    // Compile vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShader1Source, NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

    // Compile white fragment shader
  unsigned int fragmentShaderWhite = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderWhite, 1, &fragmentShader1Source, NULL);
  glCompileShader(fragmentShaderWhite);

    // Compile black fragment shader
  unsigned int fragmentShaderBlack = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderBlack, 1, &fragmentShader2Source, NULL);
  glCompileShader(fragmentShaderBlack);

    // Compile red fragment shader
  unsigned int fragmentShaderRed = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderRed, 1, &fragmentShader3Source, NULL);
  glCompileShader(fragmentShaderRed);

  // Compile green fragment shader
  unsigned int fragmentShaderGreen = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderGreen, 1, &fragmentShader4Source, NULL);
  glCompileShader(fragmentShaderGreen);

  // Compile blue fragment shader
  unsigned int fragmentShaderBlue = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShaderBlue, 1, &fragmentShader5Source, NULL);
  glCompileShader(fragmentShaderBlue);

    // Link shader program for white
  unsigned int shaderProgramWhite = glCreateProgram();
  glAttachShader(shaderProgramWhite, vertexShader);
  glAttachShader(shaderProgramWhite, fragmentShaderWhite);
  glLinkProgram(shaderProgramWhite);

    // Link shader program for black
  unsigned int shaderProgramBlack = glCreateProgram();
  glAttachShader(shaderProgramBlack, vertexShader);
  glAttachShader(shaderProgramBlack, fragmentShaderBlack);
  glLinkProgram(shaderProgramBlack);

    // Link shader program for red
  unsigned int shaderProgramRed = glCreateProgram();
  glAttachShader(shaderProgramRed, vertexShader);
  glAttachShader(shaderProgramRed, fragmentShaderRed);
  glLinkProgram(shaderProgramRed);

  // Link shader program for green
  unsigned int shaderProgramGreen = glCreateProgram();
  glAttachShader(shaderProgramGreen, vertexShader);
  glAttachShader(shaderProgramGreen, fragmentShaderGreen);
  glLinkProgram(shaderProgramGreen);

  // Link shader program for blue
  unsigned int shaderProgramBlue = glCreateProgram();
  glAttachShader(shaderProgramBlue, vertexShader);
  glAttachShader(shaderProgramBlue, fragmentShaderBlue);
  glLinkProgram(shaderProgramBlue);

  float vertices[27];
  miEstrella.get_vertices(vertices);

  unsigned int indices[32];
  miEstrella.get_indices(indices);

  glGenVertexArrays(1, miEstrella.VAOs);
  glGenBuffers(1, miEstrella.VBOs);
  glGenBuffers(1, miEstrella.EBOs);

    // estrella setup
  glBindVertexArray(miEstrella.VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, miEstrella.VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, 27 * sizeof(float), vertices, GL_DYNAMIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, miEstrella.EBOs[0]);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 32 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

    // Render loop
  while (!glfwWindowShouldClose(window)) {
    miEstrella.get_vertices(vertices);

    glBindBuffer(GL_ARRAY_BUFFER, miEstrella.VBOs[0]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, 27 * sizeof(float), vertices);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (renderMode == GL_LINES) {
      glLineWidth(5.0f);
    } else {
      glLineWidth(1.0f);
    }

    if (renderMode == GL_POINTS) {
      glPointSize(10.0f);
    } else {
      glPointSize(1.0f);
    }

    if (renderMode == GL_TRIANGLES) {
      glUseProgram(shaderProgramWhite);
    } else if (renderMode == GL_LINES) {
      glUseProgram(shaderProgramGreen);
    } else if (renderMode == GL_POINTS) {
      glUseProgram(shaderProgramRed); 
    }
    glBindVertexArray(miEstrella.VAOs[0]);
    glDrawElements(renderMode, 36, GL_UNSIGNED_INT, 0);

    glDrawElements(renderMode, 36, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, miEstrella.VAOs);
  glDeleteBuffers(1, miEstrella.VBOs);
  glDeleteBuffers(1, miEstrella.EBOs);

  glDeleteShader(vertexShader);

  glDeleteProgram(shaderProgramWhite);
  glDeleteProgram(shaderProgramBlack);
  glDeleteProgram(shaderProgramRed);
  glDeleteProgram(shaderProgramGreen);
  glDeleteProgram(shaderProgramBlue);

  glDeleteShader(fragmentShaderRed);
  glDeleteShader(fragmentShaderGreen);
  glDeleteShader(fragmentShaderBlue);
  glDeleteShader(fragmentShaderWhite);
  glDeleteShader(fragmentShaderBlack);
   
  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (key == GLFW_KEY_D && action == GLFW_PRESS) {
    miEstrella.move(moveRight);
  }
  if (key == GLFW_KEY_A && action == GLFW_PRESS) {
    miEstrella.move(moveLeft);
  }
  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
    miEstrella.move(moveUp);
  }
  if (key == GLFW_KEY_S && action == GLFW_PRESS) {
    miEstrella.move(moveDown);
  }
  if (key == GLFW_KEY_1 && action == GLFW_PRESS) {
    renderMode = GL_TRIANGLES;
  }
  if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
    renderMode = GL_LINES;
  }
  if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
    renderMode = GL_POINTS;
  }
}
