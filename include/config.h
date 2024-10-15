#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "defs.h"

static void glfw_error_callback(int error, const char *description)
{
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

inline update_fn_t upd;
inline GLFWwindow* glfw_window;
inline size_t glfw_width = 1280;
inline size_t glfw_height = 720;
inline ImVec4 clear_color;

void begin__() {
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) exit(1);
  glfw_window = glfwCreateWindow(glfw_width, glfw_height, "Dear ImGui GLFW+OpenGL2 example", nullptr, nullptr);
  if (glfw_window == nullptr) exit(1);
  glfwMakeContextCurrent(glfw_window);
  glfwSwapInterval(1);
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
  
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(glfw_window, true);
  ImGui_ImplOpenGL3_Init();

  clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

bool window_open() {
  return !glfwWindowShouldClose(glfw_window);
}

int frame() {
  glfwPollEvents();
  if (glfwGetWindowAttrib(glfw_window, GLFW_ICONIFIED) != 0) {
    ImGui_ImplGlfw_Sleep(10);
    return EV_ERR;
  }
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
  return EV_OK;
}

int render() {
  ImGui::Render();
  int display_w, display_h;
  ImVec2 size = ImGui::GetWindowSize();
  glfw_width  = size.x;
  glfw_height = size.y;
  glfwGetFramebufferSize(glfw_window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwMakeContextCurrent(glfw_window);
  glfwSwapBuffers(glfw_window);
}

int end__() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(glfw_window);
  glfwTerminate();
}

#define OK_OR_CONTINUE(n) if ((n) == EV_ERR) { continue; }
#define pre_render() OK_OR_CONTINUE(frame());