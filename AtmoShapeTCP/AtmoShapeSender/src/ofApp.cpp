#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //we run at 60 fps!
	ofSetVerticalSync(true);

	//setup the server to listen on 11999
	TCP.setup(3000);
	//optionally set the delimiter to something else.  The delimter in the client and the server have to be the same, default being [/TCP]
	TCP.setMessageDelimiter("\n");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    string message = "";
    if (key == '1') {
        message = "toTheSea";
    } else if (key == '2') {
        message = "toAnotherLocation";
    } else if (key == '3') {
        message = "behindTheWalls";
    }
    //for each client lets send them a message
	for(int i = 0; i < TCP.getLastID(); i++){
		if (!TCP.isClientConnected(i)) {
            continue;
		}
		TCP.send(i, message);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
