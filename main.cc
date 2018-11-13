#include"Engine.h"
#include"Sphere.h"
#include"Rectangle.h"
#include"Cylinder.h"
#include<iostream>
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS or action == GLFW_REPEAT)
	{
	}
}

#include<ctime>

int main()
{
	Engine E(640, 480, "world");

	Object *R = new Rectangle(0, 0, 0, 0, 0.1, 0, 1, 0, 0);
	//Object *S = new Sphere(x, 0, 0, 0.1);
	//S->setTexture("./resources/textures/a.png");
	
	//Object *C = new Cylinder(x, 0, 0, x, 0.5, 0, 0.1);
	//C->setTexture("./resources/textures/a.png");


	float x = -1;
	float d = 0.01;

	glfwSwapInterval(1);
	while (!E.isClosed())
	{
		std::clock_t t0 = clock();

		if (x>1 or x<-1)
			d = -d;
		x += d;


		E.clear();
		E.setCam(0, x, 2);
		E.setCenter(0, 0, 0);
		E.setUp(0,1,0);
		E.setPov(1.0);

		E.draw(R);
		//E.draw(S);
		//E.draw(C);
		E.swapBuffers();
		E.pollEvents();

		std::clock_t t1 = clock();
		std::cout<<"FPS : "<<static_cast<float>(CLOCKS_PER_SEC)/(t1-t0)<<std::endl;
		//glfwSetKeyCallback(E.getWindow(), key_callback);
		
	}

}
