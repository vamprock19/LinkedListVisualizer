#include "ofApp.h"
#include<cstdlib>
#include<cmath>
LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::insertAtHead(int value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}
void LinkedList::insertAtTail(int value)
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
void LinkedList::deleteHead()
{
	if (!head)
	{
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
}
void LinkedList::deleteTail()
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
void LinkedList::traverse()
{
	Node* temp = head;

	while (temp)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << "nullptr" << std::endl;
}


//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofBackground(0); //  black background
	
	list = LinkedList();

	for (int i = 0; i < 4; i++)
	{
		list.insertAtHead(rand() % 10 + 1);
	}

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
	float x = 100 + panX;
	float y = ofGetHeight() / 6; 
	float space = 100; 

	Node* temp = list.head; 
	Node* prev = nullptr; 
	int i = 0;
	while (temp)
	{
		float yOffset = amplitude * sin(time + i * 0.05f);

		ofDrawCircle(x, yOffset, 30);
		ofSetColor(255); 
		ofDrawBitmapString(ofToString(temp->data), x - 5, yOffset + 5);
		ofSetColor(0, 120, 60);

		if(prev)
		{
			ofDrawLine(x - space, y +
			amplitude * sin(time + (i - 1) * 0.5), x, yOffset);
		}

		prev = temp; 
		x = x + space; 
		temp = temp->next;
		i++;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key)
	{
	case 'q':
		list.insertAtHead(rand() % 10 + 1);
		break;

	case 'w':
		list.insertAtTail(rand() % 10 + 1);
		break;
		
	case'a':
		list.deleteHead();
		break;

	case's':
		list.deleteTail();
		break;

	case'z':
		amplitude += 5; // increment
		break;

	case'x':
		amplitude = max(5.0f, amplitude - 5); // decrease
		break;

	case OF_KEY_LEFT:
		panX -= 20; 
		break;

	case OF_KEY_RIGHT:
		panX += 20;
		break;
	}
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
