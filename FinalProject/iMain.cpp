#include "iGraphics.h"

#define screenWidth 1366
#define screenHeight 768

void drawHomePage();
void drawMenuButtons();
void drawStoryPage();
void drawAboutPage();
void drawPlayPage();


int homePage = 1;
int playPage = 0;
int storyPage = 0;
int aboutPage = 0;


bool menuMusicOn = true;
bool playMusicOn = false;


struct buttonCoordinate {
	int x = 200;
	int y = 0;
};
buttonCoordinate bCoordinate[5];

//int play, story, controls, about, bexit;
int title, story, about, back_button;
int buttons[5];


char level[1][20] = { "bc\\level1.bmp" };
char arun[8][20] = { "bc\\arun1.bmp", "bc\\arun2.bmp", "bc\\arun3.bmp", "bc\\arun4.bmp", "bc\\arun5.bmp", "bc\\arun6.bmp", "bc\\arun7.bmp", "bc\\arun8.bmp" };
char arunl[8][20] = { "bc\\arun1l.bmp", "bc\\arun2l.bmp", "bc\\arun3l.bmp", "bc\\arun4l.bmp", "bc\\arun5l.bmp", "bc\\arun6l.bmp", "bc\\arun7l.bmp", "bc\\arun8l.bmp" };
char aatk[7][20] = { "bc\\aatk1.bmp", "bc\\aatk2.bmp", "bc\\aatk3.bmp", "bc\\aatk4.bmp", "bc\\aatk5.bmp", "bc\\aatk6.bmp", "bc\\aatk6.bmp" };
char aatkl[7][20] = { "bc\\aatk1l.bmp", "bc\\aatk2l.bmp", "bc\\aatk3l.bmp", "bc\\aatk4l.bmp", "bc\\aatk5l.bmp", "bc\\aatk6l.bmp", "bc\\aatk6l.bmp" };
char idle[20] = { "bc\\aidle.bmp" };
char idlel[20] = { "bc\\aidlel.bmp" };
int ax = 200;
int ay = 300;
int aindex = 0;

bool left = false;
bool atk = false;
bool stand = true;
int standcounter = 0;


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if (homePage == 1)
	{
		drawHomePage();
		drawMenuButtons();

	} else if (storyPage == 1) {
		drawHomePage();
		drawStoryPage();
	}
	else if (aboutPage == 1) {
		drawHomePage();
		drawAboutPage();
	}
	else if (playPage == 1) {
		drawPlayPage();

	}

	
}


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//**********************ipassiveMouse************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (homePage == 1 && (mx >= 320 && mx <= 490) && (my >= 405 && my <= 490)) {//story button
			homePage = 0;
			storyPage = 1;
		}
		else if (homePage == 1 && (mx >= 260 && mx <= 550) && (my >= 510 && my <= 545)) {//play game button
			homePage = 0;
			playPage = 1;
			menuMusicOn = false;
			PlaySound(0, 0, 0);
			playMusicOn = true;
			PlaySound("music\\play.wav", NULL, SND_LOOP | SND_ASYNC);

		}
		else if (homePage == 1 && (mx >= 270 && mx <= 535) && (my >= 205 && my <= 245)) {//about button
			homePage = 0;
			aboutPage = 1;
		}
		else if ((storyPage == 1 || aboutPage == 1)  && (mx >= 355 && mx <= 475) && (my >= 100 && my <= 130)) {//back button
			homePage = 1;
			storyPage = 0;
			aboutPage = 0;
		}
		else if (homePage == 1 && (mx >= 345 && mx <= 460) && (my >= 105 && my <= 147)) {
			exit(0);
		}
		if (playPage == 1) {
			atk = true;
			stand = false;
			aindex = 0;
		}
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		if (ay + 10 < screenHeight)
		{
			ay += 10;
			aindex++;
			if (aindex >= 8)
				aindex = 0;
			stand = false;
		}
	}
	if (key == 's')
	{
		if (ay - 10 >= 0)
		{
			ay -= 10;
			aindex++;
			if (aindex >= 8)
				aindex = 0;
			stand = false;
		}
	}
	if (key == 'a')
	{
		left = true;
		if (ax - 10 >= 0)
		{
			ax -= 10;
			aindex++;
			if (aindex >= 8)
				aindex = 0;
			stand = false;
		}
	}
	if (key == 'd')
	{
		left = false;
		if (ax + 10 < screenWidth)
		{
			ax += 10;
			aindex++;
			if (aindex >= 8)
				aindex = 0;
			stand = false;
		}
	}
	if (key == '\r')
	{

	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}
	
	//F1 to stop music
	if (key == GLUT_KEY_F1) {
		if (menuMusicOn) {
			menuMusicOn = false;
			PlaySound(0, 0, 0);
		}
		else if (!menuMusicOn) {
			menuMusicOn = true;
			PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		if (playMusicOn && playPage == 1) {
			playMusicOn = false;
			PlaySound(0, 0, 0);
		}
		else if (!playMusicOn && playPage == 1) {
			playMusicOn = true;
			PlaySound("music\\play.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
}


void drawHomePage()
{
	//Background
	iShowBMP2(0, 0, "image\\menu\\bg.bmp", 0);
}
void drawMenuButtons() {
	//Menu buttons
	for (int i = 0; i < 5; i++) {
		iShowImage(bCoordinate[i].x, bCoordinate[i].y, 400, 90, buttons[i]);
	}
	//iShowImage(100, bCoordinate[0].y + 80, 600, 180, title);
}
void drawStoryPage() {
	iShowImage(100, 200, 650, 400, story);
	iShowImage(300, 80, 220, 70, back_button);
}
void drawAboutPage() {
	iShowImage(100, 250, 700, 300, about);
	iShowImage(300, 80, 220, 70, back_button);
}


void drawPlayPage() {
	iShowBMP(0, 0, level[0]);
	if (!left)
	{
		if (stand)
		{
			iShowBMP2(ax, ay, idle, 0);
		}
		else if (atk)
		{
			iShowBMP2(ax, ay, aatk[aindex], 0);
		}
		else
		{
			iShowBMP2(ax, ay, arun[aindex], 0);
			standcounter++;
			if (standcounter >= 15)
			{
				standcounter = 0;
				stand = true;
				aindex = 0;
			}
		}
	}
	else
	{
		if (stand)
		{
			iShowBMP2(ax, ay, idlel, 0);
		}
		else if (atk)
		{
			iShowBMP2(ax, ay, aatkl[aindex], 0);
		}
		else
		{
			iShowBMP2(ax, ay, arunl[aindex], 0);
			standcounter++;
			if (standcounter >= 15)
			{
				standcounter = 0;
				stand = true;
				aindex = 0;
			}
		}
	}

}

void change()
{
	if (atk)
	{
		aindex++;
		if (aindex >= 7)
		{
			atk = false;
			aindex = 0;
		}
	}
}


int main()
{
	iSetTimer(50, change);

	if (menuMusicOn) {
		PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (playMusicOn) {
		PlaySound("music\\play.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	int sum = 80;
	for (int i = 4; i >= 0; i--) {
		bCoordinate[i].y = sum;
		sum += 100;
	}
	
	iInitialize(screenWidth, screenHeight, "Jhol Saga");
	
	//title = iLoadImage("./image/menu/title.png");
	buttons[0] = iLoadImage("./image/menu/play.png");
	buttons[1] = iLoadImage("./image/menu/story.png");
	buttons[2] = iLoadImage("./image/menu/controls.png");
	buttons[3] = iLoadImage("./image/menu/about.png");
	buttons[4] = iLoadImage("./image/menu/exit.png");

	story = iLoadImage("./image/menu/story_page.png");
	about = iLoadImage("./image/menu/about_page.png");
	back_button = iLoadImage("./image/menu/back.png");

	iStart();

	return 0;
}