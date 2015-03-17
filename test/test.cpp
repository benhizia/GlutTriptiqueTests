// test.cpp : définit le point d'entrée pour l'application console.
//

#include "GlutTester.h"


int _tmain(int argc, _TCHAR* argv[])
{
	float left_fov = -0.296705;
    float right_fov = 0.296705;
	float top_fov =left_fov;
	float bottom_fov = right_fov;
	float azimuth_offset = 0.593411;
	glutInit(&argc, (char **)argv);
	GlutTester* myGlutTester1 = new GlutTester(800, 600,0,0,left_fov, right_fov, top_fov, bottom_fov, -azimuth_offset);	
	myGlutTester1->setupGlutCallbacks(myGlutTester1, 1);
	
	GlutTester* myGlutTester2 = new GlutTester(800, 600,800,0,left_fov, right_fov, top_fov, bottom_fov, 0.);	
	myGlutTester2->setupGlutCallbacks(myGlutTester2, 2);
	
	GlutTester* myGlutTester3 = new GlutTester(800, 600,1600,0,left_fov, right_fov, top_fov, bottom_fov, azimuth_offset);	
	myGlutTester3->setupGlutCallbacks(myGlutTester3, 3);
    //Main loop function
    ::glutMainLoop();
	printf("salut");	
	system("pause");
	return 0;
}

