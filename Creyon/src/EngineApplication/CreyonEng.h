#pragma once

//All includes and aliases for Creyon engine are stored here

#include "MathEngine/matrix2x2.h"
#include "MathEngine/matrix3x3.h"
#include "MathEngine/matrix4x4.h"
#include "MathEngine/vector4d.h"
#include "MathEngine/vector3d.h"
#include "MathEngine/vector2d.h"
#include "MathEngine/transforms.h"
#include "MathEngine/Constants/constants.h"
#include "MathEngine/Miscellaneous/Misc.h"
#include "Render/CreyonWindow.h"
#include "Render/Shaderprogram.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

using mat44 = Creyon::matrix_4x4;
using mat33 = Creyon::matrix_3x3;
using mat22 = Creyon::matrix_2x2;
using std::cout;
using std::cin;
using Creyon::CreyonWindow;
using Creyon::vector3d;
using Creyon::vector4d;
using Creyon::Shaderprogram;