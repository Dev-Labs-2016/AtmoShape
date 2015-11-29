#include "ofApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void ofApp::setup(){

    // we don't want to be running to fast
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    // create the socket and send to 127.0.0.1:3000
    udpConnectionProjectorA.Create();
    udpConnectionProjectorA.Connect("127.0.0.1", 3000);
    udpConnectionProjectorA.SetNonBlocking(true);

    // create the socket and send to 127.0.0.1:4000
    udpConnectionProjectorB.Create();
    udpConnectionProjectorB.Connect("127.0.0.1", 4000);
    udpConnectionProjectorB.SetNonBlocking(true);

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
    udpConnectionProjectorA.Send(message.c_str(), message.length());
    udpConnectionProjectorB.Send(message.c_str(), message.length());
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
