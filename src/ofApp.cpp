#include "ofApp.h"
#include<cstdlib>



class Node
{
public:

	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr)
	{

	}
};

class LinkedList
{
private :
	Node* head; // ptr

public:

	
	LinkedList() : head(nullptr){}

	void insertAtHead(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void insertAtTail(int value)
	{
		Node* newNode = new Node(value);

		if (!head)
		{
			head = newNode;
			return;
		}
		Node* temp = head;

		while (temp->next)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void deleteHead()
	{
		if (!head) return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void deleteTial()
	{
		if (!head)
		{
			return; // it just returns that it doesn't have a tail
		}
		

		if (!head->next)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;

		while (temp->next->next)
		{
			temp = temp->next;
		}

		delete temp->next; // deletes the temp node (like a variable)

		temp->next = nullptr; // data is deleted
	}
	void traverse()
	{
		Node* temp = head;

		while(temp)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}

		cout << "nullptr" << std::endl;
	}
};

//--------------------------------------------------------------
void ofApp::setup()
{
	LinkedList list;

	list.insertAtHead(rand() % 10 + 1);
	list.insertAtHead(rand() % 10 + 1);
	list.insertAtHead(rand() % 10 + 1);
	list.insertAtHead(rand() % 10 + 1);


	list.traverse();
	/*Node* head = new Node{ rand() % 10,nullptr};
	head->next = new Node{ rand() % 20,nullptr};
	head->next->next = new Node{ rand() % 30,nullptr};

	cout << head->data << " -> " << head->next->data << " -> " << head->next->next->data << endl;

	delete head->next;
	delete head;*/

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    
	ofSetColor(0, 120, 60);
	float space = ofGetWidth() / 10;
	float y = ofGetHeight() / 6;
	

	for (int i = 0; i < 3; i++)
	{
		float x = (i + 1) * space;
		ofDrawCircle(x,y,35);
		ofDrawLine(x, y, x, y);

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
