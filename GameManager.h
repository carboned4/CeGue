#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <stdio.h>
#include <vector>
#include <cmath>
#include "glut.h"
#include "GameObject.h"
#include "Frog.h"
#include "Roadside.h"
#include "Road.h"
#include "Riverside.h"
#include "River.h"
#include "Timberlog.h"
#include "Bus.h"
#include "Camera.h"
#include "Car.h"
#include "LightSource.h"

#define DRAWRIGHT -5.5
#define DRAWLEFT 5.5
#define DRAWBOTTOM -1.5
#define DRAWTOP 11.5
#define DRAWFAR -11.5
#define DRAWNEAR 11.5

int frame=0; //para fazer contagem dos frames na consola
int total_time = 0;
int delta_time;

class GameManager {

	protected:

	std::vector <GameObject*> _game_objects;

	std::vector <Camera *> _cameras;

	std::vector <LightSource> _light_sources;

	public:

	Frog* frog;		//relacionado com o movimento do sapo

	int rotate_y; //usado para rodar a c�mara e assim ver se os modelos est�o em ordem

	int rotate_x;

	double movex;

	double movey;

	double tens_of_seconds_passed;

	int _activeCamera;

	std::vector <Car *> _cars;

	GameManager(){
		rotate_x = 0;
		rotate_y = 0;
		movex = 0;
		movey = 0;
		_activeCamera = 0;
		tens_of_seconds_passed=0.0;
	}

	~GameManager();

	/* addGameObejct(obj) - adds a new Game object to the list.*/
	void addGameObject(GameObject* obj){ _game_objects.push_back(obj); }

	/* addCamera(cam) - Adds a new camera to the cameras list.*/
	void addCamera(Camera* cam){ _cameras.push_back(cam); }

	/* addlightSource(source) - Adds a new LightSource to the gameManager. */
	void addLightSource(LightSource source){ _light_sources.push_back(source);}

	void setFrog(Frog* f){ frog = f; }
	
	void update(int useless) {
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		bool increase_speed = false;

		delta_time = glutGet(GLUT_ELAPSED_TIME) - total_time;
		total_time += delta_time;

		if ((total_time / 10000)> (int)tens_of_seconds_passed){
			//printf("%f\n", tens_of_seconds_passed );
			increase_speed=true;
			tens_of_seconds_passed++;
		}

		for (iter; iter != _game_objects.end(); iter++){
			if (increase_speed){ (*iter)->getSpeed()->multiplyScale(1.05);}
			(*iter)->update(delta_time);
		}
		frog->checkIfColided(_game_objects);

		increase_speed=false;

	}

	void display(){
		/* Reset Color and DEpth Buffer */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/* reset � posi��o do referencial e redefini��o da posi��o da c�mara e rota��o do mapa */
		if (_activeCamera == 0){
			_cameras[0]->update();
			glTranslatef(movex, movey - 1.0, 0);
			glTranslatef(movex, movey + 6.5, 0);
			glRotatef(rotate_x, 1.0, 0.0, 0.0);
			glRotatef(rotate_y, 0.0, 0.0, 1.0);
			glTranslatef(movex, movey - 6.5, 0);
			glRotatef(180, 0.0, 1.0, 0.0);
		}
		else if (_activeCamera == 1){
			_cameras[1]->update();
		}
		else if (_activeCamera == 2){
			_cameras[2]->setPosition(frog->getPosition()->getX(), frog->getPosition()->getY() - 2, 2.0);
			_cameras[2]->setCenter(frog->getPosition()->getX(), frog->getPosition()->getY(), frog->getPosition()->getZ());
			_cameras[2]->update();
		}
		
		//printf("frame number: %d\ntime:%d\n", ++frame, glutGet(GLUT_ELAPSED_TIME));
		
		std::vector<GameObject* >::iterator iter = _game_objects.begin();
		for (iter; iter != _game_objects.end(); iter++){
			(*iter)->draw();
		}
		glFlush();
	}


	void reshape(int w, int h) { //segue sugest�es dos slides mas muda algumas coisas (glOrtho em vez de gluOrtho2d) e os limites da janela
		double xmax = DRAWLEFT;
		double xmin = DRAWRIGHT;
		double ymin = DRAWBOTTOM;
		double ymax = DRAWTOP;
		float ratio = (xmax - xmin) / (ymax - ymin);
		float aspect = (float) w / h;
		if ( aspect > ratio )
			glViewport( (w-h*ratio)/2, 0, h*ratio, h);
		else
			glViewport( 0, (h-w/ratio)/2, w, w/ratio);
	}

	void keyPressed(unsigned char key, int x, int y, bool down){
		if (down) {
			if ((key == 'h')) movey += 0.5;
			else if (key == 'g') movex -= 0.5;
			else if (key == 'y') movey -= 0.5;
			else if (key == 'j') movex += 0.5;
			else if (key == 'q'){
				frog->moveUp();
			}
			else if (key == 'a'){
				frog->moveDown();
			}
			else if (key == 'o'){
				frog->moveLeft();
			}
			else if (key == 'p'){
				frog->moveRight();
			}
			else if (key == '1'){
				_activeCamera = 0;
			}
			else if (key == '2'){
				_activeCamera = 1;
			}
			else if (key == '3'){
				_activeCamera = 2;
			}
			else if (key == 'n'){

			}
			else if (key == 'c'){

			}
		}
		else{frog->stopMovement(); }
	
	}

	/* - TESTS PURPOSE ONLY */
	void specialKeyPressed(int key, int x, int y){
		//  roda para a direita
		if (key == GLUT_KEY_RIGHT)
			rotate_y += 5;
		//  roda a camara para a esquerda
		else if (key == GLUT_KEY_LEFT)
			rotate_y -= 5;
		else if (key == GLUT_KEY_UP)
			rotate_x += 5;
		else if (key == GLUT_KEY_DOWN)
			rotate_x -= 5;
	}
	
	/* init() - Initialize Color and enables depth buffer.*/
	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glEnable(GL_DEPTH_TEST); // permite desenhar as coisas por ordem de profundidade
		
	}

};


#endif