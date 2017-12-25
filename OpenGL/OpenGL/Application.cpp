#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1080, 1080, "Hello Alam", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		cout << "Failed to initialize GLEW!" << endl;

	cout << "Printing the version number of the current opengl" << endl;
	cout << glGetString(GL_VERSION) << endl;

	// Modern code for OpenGL
	float vertices_cpu[6] = {
		0.0f,   .5f,
		-.5f,   -.5f,
		.5f,   -.5f
	};

	unsigned int buffer_id;
	glGenBuffers(1, &buffer_id);
	glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices_cpu, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(2), 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// Legacy code for OpenGL
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(1.4f, 0.0f);
		glVertex2f(1.4f, 1.4f);
		glEnd();

		// Modern code for OpenGL
		glDrawArrays(GL_TRIANGLES, 0, 3);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}