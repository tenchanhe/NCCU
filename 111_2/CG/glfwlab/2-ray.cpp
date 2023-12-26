#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vec3.h"

GLFWwindow* window;
int width = 640;
int height = 480;
GLubyte* PixelBuffer = NULL;

float BLUE = 1.0f;

using namespace std;

class ray
{
public:
    ray() {}
    ray(const vec3& a, const vec3& b) { O = a; D = b; }
    vec3 origin() const { return O; }
    vec3 direction() const { return D; }
    vec3 point_at_parameter(float t) const { return O + t * D; }

    vec3 O;
    vec3 D;
};

bool hit_sphere(const vec3& center, float radius, const ray& r) {
    //todo


    return true;
}


vec3 color(const ray& r)
{
    //if (hit_sphere(vec3(0, 0, -1), 0.5, r)) {
    //    return vec3(1, 0, 0);
    //}

    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);

    vec3 skycolor(0.5, 0.7, 1.0);
    return (1.0 - t) * vec3(1, 1, 1) + t * skycolor * BLUE;
}



void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    BLUE = fmodf(BLUE + 0.01f, 1.0f);


    vec3 lower_left_corner(-2, -1, -1);
    vec3 origin(0, 0, 0);
    vec3 horizontal(4, 0, 0);
    vec3 vertical(0, 2, 0);
    //file << "P3\n" << width << " " << height << "\n255\n";
    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            float u = float(i) / float(width);
            float v = float(j) / float(height);
            vec3 uvcenter = lower_left_corner + u * horizontal + v * vertical;
            ray r(origin, uvcenter - origin);
            vec3 c = color(r);

            PixelBuffer[j * width * 3 + i * 3 + 0] = c[0] * 255;
            PixelBuffer[j * width * 3 + i * 3 + 1] = c[1] * 255;
            PixelBuffer[j * width * 3 + i * 3 + 2] = c[2] * 255;
            //file << int(c[0] * 255) << " " << int(c[1] * 255) << " " << int(c[2] * 255) << "\n";
        }
    }

    glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
    glfwSwapBuffers(window);
}

int main(void)
{
    

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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

    PixelBuffer = new GLubyte[width * height * 3];

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        draw();

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}