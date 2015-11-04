#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define DEFAULTWIDTH  800
#define DEFAULTHEIGHT 600

int main(int argc, char ** argv) {
    int width, height;

    if(argc < 3) {
        width  = DEFAULTWIDTH;
        height = DEFAULTHEIGHT;
    }
    else {
        width  = atoi(argv[1]);
        height = atoi(argv[2]);
    }

    /* Initialize GLFW */
    if(!glfwInit()) {
        fprintf(stderr, ">>> Error! Failed to initialize GLFW.\n");
        return (EXIT_FAILURE);
    }

    GLFWwindow* window;
    window = glfwCreateWindow(width, height, "Sample Window", NULL, NULL);
    if(window == NULL) {
        fprintf(stderr, ">>> Error! Failed to open GLFW window.\n");
        return (EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window); //-- Initialize GLEW
    if(glewInit() != GLEW_OK) {
        fprintf(stderr, ">>> Error! Failed to initialize GLEW.\n");
        return (EXIT_FAILURE);
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        /* GLFW swap buffers */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Check if the ESC key was pressed or the window was closed */
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);

    return 0;
}
