#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "window.h"
#include "application.h"
#include "texture.h"
#include "shader.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "mesh.h"
#include "primitive.h"
