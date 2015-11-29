#include "ofApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void ofApp::setup(){
    // we run at 60 fps!
    ofSetVerticalSync(true);

    //are we connected to the server - if this fails we
	//will check every few seconds to see if the server exists
	weConnected = tcpClient.setup("127.0.0.1", 3000);
	//optionally set the delimiter to something else.  The delimiter in the client and the server have to be the same
	tcpClient.setMessageDelimiter("\n");
	tcpClient.setVerbose(true);

    // load videos
    toTheSea.loadMovie("toTheSea.mkv");
    toAnotherLocation.loadMovie("toAnotherLocation.mkv");
    behindTheWalls.loadMovie("behindTheWalls.mkv");

}

//--------------------------------------------------------------
void ofApp::update(){
    //we are connected - lets send our text and check what we get back
    string message = "";
	if (weConnected) {
        message = tcpClient.receive();
        if (message != "") {
            if (message == "toTheSea") {
                currentVideo = toTheSea;
                toAnotherLocation.stop();
                behindTheWalls.stop();
            } else if (message == "toAnotherLocation") {
                currentVideo = toAnotherLocation;
                toTheSea.stop();
                behindTheWalls.stop();
            } else if (message == "behindTheWalls") {
                currentVideo = behindTheWalls;
                toTheSea.stop();
                toAnotherLocation.stop();
            }
            currentVideo.play();
        } else if (!tcpClient.isConnected()) {
			weConnected = false;
		}
	} else {
		//if we are not connected lets try and reconnect every 5 seconds
		deltaTime = ofGetElapsedTimeMillis() - connectTime;
		if ( deltaTime > 5000 ) {
			weConnected = tcpClient.setup("127.0.0.1", 3000);
			connectTime = ofGetElapsedTimeMillis();
		}
	}
	// Decode the new frame if needed
    currentVideo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentVideo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f' || key == 'F') {
        ofToggleFullscreen();
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
