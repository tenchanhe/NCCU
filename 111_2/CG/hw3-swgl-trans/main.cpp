//Computer Graphics HW-SWGL 2023
//simple modeling tool
//Transformation and Projection



#include <GL/glew.h>
//#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

//OpenGL Mathematics (GLM)  https://glm.g-truc.net/
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include<glm/vec3.hpp>
#include<glm/vec4.hpp>
#include<glm/mat4x4.hpp>
#include<math.h>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace glm;

const bool STEP2 = true;
const bool STEP3 = true;

float theta = 3.14159f / 4.0f;
float tho = 3.14159f / 4.0f;

int winWidth = 1280;
int winHeight = 720;

mat4x4 transformMat = mat4x4(1);

mat4x4 ViewMat = mat4x4(1);
mat4x4 ProjectionMat = mat4x4(1);

vec3 default_tetrahedron_vertices[4] = {
	vec3(1,0,0), vec3(0,1,0), vec3(0,0,1), vec3(0,0,0)
};
vec3 tetrahedron_verts[4];


//step1: implement Translate Matrix
mat4x4 swTranslate(float x, float y, float z)
{
	mat4x4 Translate = mat4x4(1);
	Translate[3][0] = x;
	//todo: y z
	Translate[3][1] = y;
	Translate[3][2] = z;

	return Translate;
}

//step1: implement Rotate Matrix
mat4x4 swRotateX(float angle)
{
	mat4x4 Rotate = mat4x4(1);
	float s = sinf(angle);
	float c = cosf(angle);
	Rotate = {
		{1.f, 0.f, 0.f, 0.f},
		{0.f,   c,   s, 0.f},
		{0.f,  -s,   c, 0.f},
		{0.f, 0.f, 0.f, 1.f}
	};

	return Rotate;
}

mat4x4 swRotateY(float angle)
{
	mat4x4 Rotate = mat4x4(1);
	float s = sinf(angle);
	float c = cosf(angle);
	Rotate = {
		{   c, 0.f,  -s, 0.f},
		{ 0.f, 1.f, 0.f, 0.f},
		{   s, 0.f,   c, 0.f},
		{ 0.f, 0.f, 0.f, 1.f}
	};

	return Rotate;
}

mat4x4 swRotateZ(float angle)
{
	mat4x4 Rotate = mat4x4(1);
	float s = sinf(angle);
	float c = cosf(angle);
	Rotate = {
		{   c,   s, 0.f, 0.f},
		{  -s,   c, 0.f, 0.f},
		{ 0.f, 0.f, 1.f, 0.f},
		{ 0.f, 0.f, 0.f, 1.f}
	};

	return Rotate;
}

//optinal
mat4x4 swRotate(float angle, float x, float y, float z)
{
	mat4x4 Rotate = mat4x4(1);

	return Rotate;
}

//step1: implement Scale(x, y, z)
mat4x4 swScale(float x, float y, float z)
{
	mat4x4 Scale = mat4x4(1);
	Scale = {
		{   x, 0.f, 0.f, 0.f},
		{ 0.f,   y, 0.f, 0.f},
		{ 0.f, 0.f,   z, 0.f},
		{ 0.f, 0.f, 0.f, 1.f}
	};

	return Scale;
}

//step2:
mat4x4 swLookAt(float eyeX, float eyeY, float eyeZ,
 	float centerX, float centerY, float centerZ,
 	float upX, float upY, float upZ)
{
	mat4x4 LookAt = mat4x4(1);
	
	vec3 eye = vec3(eyeX, eyeY, eyeZ);
	vec3 center = vec3(centerX, centerY, centerZ);
	vec3 up = vec3(upX, upY, upZ);
	vec3 f = normalize(center - eye);
	vec3 s = normalize(cross(f, up));
	vec3 u = cross(s, f);
	
	LookAt = {
		{ s.x, u.x, -f.x, 0.f},
		{ s.y, u.y, -f.y, 0.f},
		{ s.z, u.z, -f.z, 0.f},
		{ -dot(s, eye), -dot(u, eye), dot(f, eye), 1.f}
	};

	return LookAt;
}

//step3:
mat4x4 swPerspective(float fovy, float aspect, float zNear, float zFar)
{
	mat4x4 PP = mat4x4(1);
	float f = 1/(tan(fovy * 3.14/360));
	PP = {
		{ f/aspect, 0.f,                         0.f,                         0.f},
		{      0.f,   f,                         0.f,                         0.f},
		{      0.f, 0.f,   (zFar+zNear)/(zNear-zFar),                          -1},
		{      0.f, 0.f, (2*zFar*zNear)/(zNear-zFar),                         0.f}
	};

	return PP;
}

void swTriangle(vec3 color, vec3 in_v1, vec3 in_v2, vec3 in_v3, mat4x4 Modelmatrix)
{
	vec4 v1(in_v1.x, in_v1.y, in_v1.z, 1);
	vec4 v2(in_v2.x, in_v2.y, in_v2.z, 1);
	vec4 v3(in_v3.x, in_v3.y, in_v3.z, 1);

	v1 = Modelmatrix * v1;
	v2 = Modelmatrix * v2;
	v3 = Modelmatrix * v3;

	//step2: remove glLookAt, compute view matrix
	//v1 = View* Modelmatrix * v1;
	v1 = ViewMat * v1;
	v2 = ViewMat * v2;
	v3 = ViewMat * v3;


	//step3: remove glProjection, compute project matrix
	//v1 =  Projection * View * Modelmatrix * v1;
	v1 = ProjectionMat * v1;
	v2 = ProjectionMat * v2;
	v3 = ProjectionMat * v3;
	// prespective division
	v1 = v1/v1.w;
	v2 = v2/v2.w;
	v3 = v3/v3.w;


	glColor3f(color.r, color.g, color.b);
	glVertex3f(v1.x, v1.y, v1.z);
	glVertex3f(v2.x, v2.y, v2.z);
	glVertex3f(v3.x, v3.y, v3.z);
}



void Draw_Tetrahedron() {
	vec3 color(1, 1, 0);
	//glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLES);

		swTriangle(vec3(1, 0, 0), tetrahedron_verts[0], tetrahedron_verts[1], tetrahedron_verts[2], transformMat);

		swTriangle(vec3(0, 0, 1), tetrahedron_verts[3], tetrahedron_verts[0], tetrahedron_verts[1], transformMat);

		swTriangle(vec3(0, 1, 0), tetrahedron_verts[2], tetrahedron_verts[3], tetrahedron_verts[0], transformMat);

		swTriangle(vec3(1, 1, 0), tetrahedron_verts[1], tetrahedron_verts[2], tetrahedron_verts[3], transformMat);

	glEnd();
}

void DrawGrid(int size = 10)
{
	glBegin(GL_LINES);
	glColor3f(0.3, 0.3, 0.3);
	for (int i = 1; i < size; i++) {
		glVertex3f(i, -size, 0);
		glVertex3f(i, size, 0);
		glVertex3f(-i, -size, 0);
		glVertex3f(-i, size, 0);
		glVertex3f(-size, i, 0);
		glVertex3f(size, i, 0);
		glVertex3f(-size, -i, 0);
		glVertex3f(size, -i, 0);
	}
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(size, 0, 0);
		glColor3f(0.4, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(-size, 0, 0);

		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, size, 0);
		glColor3f(0, 0.4, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, -size, 0);

		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, size);
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 0.1, 50);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10 * cos(theta), -10 * sin(theta), 10, 0, 0, 0, 0, 0, 1);

	DrawGrid();

	//step 3 PROJECTION
	if (STEP3 == true) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glOrtho(0, winWidth, 0, winHeight, -2.0, 2.0);
		ProjectionMat = mat4x4(1);
		//todo 
		ProjectionMat = swPerspective(60, 1, 0.1, 50);

	} 

	//step 2 
	if (STEP2 == true) {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		ViewMat = mat4x4(1);
		//todo: 
		ViewMat = swLookAt(10 * cos(theta), -10 * sin(theta), 10, 0, 0, 0, 0, 0, 1);

	} 

	Draw_Tetrahedron();
}

void initGL() {
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		switch (key) {
			case GLFW_KEY_ESCAPE: //ESC
				glfwSetWindowShouldClose(window, GLFW_TRUE);
				break;

			//rotate world
			case '9':
				theta += 3.14159f / 90.0f;
				break;
			case '0':
				theta -= 3.14159f / 90.0f;
				break;
			case '-':
				transformMat = mat4x4(1);
				break;

			//translate +x
			case 'q': case 'Q':
				glfwSetWindowTitle(window, "translate +x");
				transformMat = swTranslate(1, 0, 0) * transformMat;

				break;

			//translate -x
			case 'a': case 'A':
				glfwSetWindowTitle(window, "translate -x");
				transformMat = swTranslate(-1, 0, 0) * transformMat;

				break;

			
			//translate +y
			case 'w': case 'W':
				glfwSetWindowTitle(window, "translate +y");
				transformMat = swTranslate(0, 1, 0) * transformMat;

				break;

			//translate -y
			case 's': case 'S':
				glfwSetWindowTitle(window, "translate -y");
				transformMat = swTranslate(0, -1, 0) * transformMat;

				break;
			

			//Todo: translate +z ...
			//translate +z
			case 'e': case 'E':
				glfwSetWindowTitle(window, "translate +z");
				transformMat = swTranslate(0, 0, 1) * transformMat;

				break;

			//translate -z
			case 'd': case 'D':
				glfwSetWindowTitle(window, "translate -z");
				transformMat = swTranslate(0, 0, -1) * transformMat;

				break;

			//Rotate X
			//rotate +x
			case 'r': case 'R':
				glfwSetWindowTitle(window, "rotate +x");
				transformMat = swRotateX(45) * transformMat;

				break;
			
			//rotate -x
			case 'f': case 'F':
				glfwSetWindowTitle(window, "rotate -x");
				transformMat = swRotateX(-45) * transformMat;

				break;

			//rotate +y
			case 't': case 'T':
				glfwSetWindowTitle(window, "rotate +y");
				transformMat = swRotateY(45) * transformMat;

				break;

			//rotate -y
			case 'g': case 'G':
				glfwSetWindowTitle(window, "rotate -y");
				transformMat = swRotateY(-45) * transformMat;

				break;

			//rotate +z
			case 'y': case 'Y':
				glfwSetWindowTitle(window, "rotate +z");
				transformMat = swRotateZ(45) * transformMat;

				break;
			//rotate -z
			case 'h': case 'H':
				glfwSetWindowTitle(window, "rotate -z");
				transformMat = swRotateZ(-45) * transformMat;

				break;
			
			//Scale X
			//scale +x
			case 'u': case 'U':
				glfwSetWindowTitle(window, "scale +x");
				transformMat = swScale(2, 1, 1) * transformMat;

				break;

			//scale -x
			case 'j': case 'J':
				glfwSetWindowTitle(window, "scale -x");
				transformMat = swScale(0.5, 1, 1) * transformMat;

				break;

			//scale +y
			case 'i': case 'I':
				glfwSetWindowTitle(window, "scale +y");
				transformMat = swScale(1, 2, 1) * transformMat;

				break;

			//scale -y
			case 'k': case 'K':
				glfwSetWindowTitle(window, "scale -y");
				transformMat = swScale(1, 0.5, 1) * transformMat;

				break;

			//scale +z
			case 'o': case 'O':
				glfwSetWindowTitle(window, "scale +z");
				transformMat = swScale(1, 1, 2) * transformMat;

				break;
			
			//scale -z
			case 'l': case 'L':
				glfwSetWindowTitle(window, "scale -z");
				transformMat = swScale(1, 1, 0.5) * transformMat;

				break;
			
			//Function Key for tool
			case GLFW_KEY_F1:
				//cout << "F1: add a tetrahedron." << endl;
				glfwSetWindowTitle(window, "F1: add a tetrahedron");
				for (int i = 0; i < 4; i++) {
					tetrahedron_verts[i] = default_tetrahedron_vertices[i];
				}
				break;

			case GLFW_KEY_F2:
				glfwSetWindowTitle(window, "F2: add a cube or somthing");

				break;

			case GLFW_KEY_F5:
				glfwSetWindowTitle(window, "F5: SAVE");

				break;

			case GLFW_KEY_F6:
				glfwSetWindowTitle(window, "F6: LOAD");

				break;

		}
	}

}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(winWidth, winHeight, "HW-SWGL-trans", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	initGL();
	glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		Display();

		glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
