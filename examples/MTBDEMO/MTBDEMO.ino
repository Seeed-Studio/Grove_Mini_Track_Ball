/*
 * MTBDEMO.ino
 * A simple demo for Grove - Mini Track ball v1.0
 * Description:  Get the track data on removable, include up, down, left, right, click.
 *
 * Copyright (c) 2015 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Ruibin Wu
 * Modified Time: Nov 2015
 */


#include "MiniTrackball.h"
#include "Wire.h"

MiniTrackBall miniTrackball;

void setup() 
{ 
    Wire.begin();
    Serial.begin(115200);
}

void loop() 
{
    uint8_t track_data[5];
    
    miniTrackball.GetTrackData(track_data);
    
    Serial.println("+------------------------------------------------------+");
    Serial.print("MOTION_UP:    ");
    Serial.print(track_data[0], DEC);
    Serial.print("\t");
    Serial.print("MOTION_DOWN:  ");
    Serial.println(track_data[1], DEC);
    Serial.print("MOTION_LEFT:  ");
    Serial.print(track_data[2], DEC);
    Serial.print("\t");
    Serial.print("MOTION_RIGHT: ");
    Serial.println(track_data[3], DEC);
    Serial.print("MOTION_CLICK: ");
    Serial.println(track_data[4], DEC);
    Serial.println("+------------------------------------------------------+");
    Serial.println(" ");
    
    delay(1000);
}

