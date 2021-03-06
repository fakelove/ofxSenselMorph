//
//  ofxSenselMorph.h
//  simpleExample
//
//  Created by Blair Neal on 9/28/15.
//
//

#pragma once

#include "ofMain.h"
#include "sensel.h"
//#include "sensel_serial.h"

class ofxSenselMorph{
public:
    struct SenselContact{
        
        //uid_t  uid;
        //uint16 x_pos;  // raw x position
        //uint16 y_pos;  // raw y position
        
        ofPoint position; //mapped to sensel area to screen area - probably need to make this 0->1
        float force;
        int area;// area multiplied by 65536
        int orientation;// angle from -90 to 90 multiplied by 256
        int majorAxis;// length of the major axis multiplied by 256
        int minorAxis;// length of the minor axis multiplied by 256
        //vel_t dx; // change in x from last frame
        //vel_t dy; // change in y from last frame
        int contactID;
        string contactType;

    };
    
    
    ofxSenselMorph() { };
    ~ofxSenselMorph() { };
    
    contact_t contacts[MAX_CONTACTS];
    int numContacts;
    
    void setup();
    void update();
    void draw();
    
    vector<SenselContact> senselContacts;
    
    vector<SenselContact> getContacts(){ return senselContacts;}
    
    ofVec3f getAccelData() {return accelData;}
    
    ofVec3f accelData;
    
    void close();
};