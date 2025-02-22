#include "ofApp.h"
#include<cstdlib>




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
	
	srand(static_cast<unsigned int>(time(nullptr)));

	/*for (int i = 0; i < 4; i++)
	{
		list.insertAtHead(rand() % 10 + 1);
	}

	Node* head = new Node{ rand() % 10,nullptr};
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
	float px = 100;
	float py = ofGetHeight() / 2;
	float space = 100;

	Node* temp = list.head;
	vector<ofVec2f> position;

	while (temp)
	{
		float x = px + position.size() * space;
		position.push_back(ofVec2f(x, py));

		ofDrawCircle(x, py, 30);
		ofSetColor(255);
		ofDrawBitmapString(ofToString(temp->data), x - 5, py + 5);
		ofSetColor(0, 120, 60);
		temp = temp->next; // like a variable
	}

	for (int i = 0; i < position.size() - 1; i++)
	{
		ofDrawLine(position[i], position[i + 1]);
	}




	/*LinkedList list;

	list.insertAtHead(rand() % 10 + 1);
	
	
	

	
	float space = ofGetWidth() / 10;
	float y = ofGetHeight() / 6;
	
	vector<ofVec2f> circlePositions;


	for (int i = 0; i < 4; i++)
	{
		
		

		float x = (i + 1) * space;
		circlePositions.push_back(ofVec2f(x, y));

		ofDrawCircle(x,y,35);
		ofSetColor(255);
		ofDrawBitmapString(ofToString("20"), x, y);
		ofSetColor(0, 120, 60);

	}

	
	for (int i = 0; i < circlePositions.size() - 1; i++)
	{
		ofDrawLine(circlePositions[i], circlePositions[i + 1]);
	}*/
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
