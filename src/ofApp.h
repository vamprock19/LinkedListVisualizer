#pragma once

#include "ofMain.h"

class Node
{
public:
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = nullptr;
	}
	

};

class LinkedList
{
public:
	Node* head;
	LinkedList();

	void insertAtHead(int value);
	void insertAtTail(int value);
	void deleteHead();
	void deleteTail();
	void traverse();
	


};

class ofApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		LinkedList list;
		float panX = 0;       // HORIZONTAL
		float amplitude = 0;  // OSCILLATION
		float time = 0;       // OSCILLATION TIME
		
		
};

