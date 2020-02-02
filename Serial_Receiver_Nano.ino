/*
 * SerialReciever_and_LogicController w/ Arduino Nano
 * College of Nanotechnology Co-op Education
 * TBR AI Image Recognition project of ThaiBev and CMKL University
 * Code by NiNouNiaNaNoNa
 * Copyright 2019, Suppawat Boonrach
 */
 
//Global variable preparation
int baud_rate = 9600; //change baud rate here!!!!
//int Digital_in = xx; //Edit Input pin from Encoder here!!!
char bottle_type; //variable for store character from python
//int Digital_out = 13; //for testing on LED pin 13
int Digital_out_1 = 2; //for Channel 1(Pusher_1)
//int Digital_out_2 = 3; //for Channel 2(Pusher_2)
//int Digital_out_3 = 4; //for Channel 3(Pusher_2)



//Setup Function
void setup() {
  //setup serial and digital output
  Serial.begin(baud_rate); //you can change baud rate above...
  //pinMode(Digital_out, OUTPUT); //for testing on LED pin 13, you can change Digital Output pin above...
  pinMode(Digital_out_1, OUTPUT); //for CH1, you can change Digital Output pin above...
  //pinMode(Digital_out_2, OUTPUT); //for CH2, you can change Digital Output pin above...
  //pinMode(Digital_out_3, OUTPUT); //for CH3, you can change Digital Output pin above...
}

//Loop Function
void loop() {
  //digitalWrite(Digital_out_1, HIGH); //test
  //Read data from serial port(to receive data from python)
  if(Serial.available()>0){ //If data is available
    bottle_type = Serial.read(); //store recieved data to bottle_type variable
    /*
     * In real system, we would be use pulse to send data to plc and input data from Conveyor Encoder
     * Using different Channel(CH1 or CH2) for different category...
     */
     
    //For category A => Ignore on main conveyor
    if(bottle_type == 'A'){
      digitalWrite(Digital_out_1, LOW); //for testing logic only
      //delay(500);
      //digitalWrite(Digital_out_1, LOW); //
      //delay(500);
      //Serial.print("Ignore...\n"); //for testing only
      //delay(1000); //for testing only
      //delay(30000); //for testing logic with voltmeter only
    }
    //For testing only, in real system, we will separate condition for B and C
    //For category B and C => reject from main conveyor with pusher to another conveyor
    if(bottle_type == 'B' || bottle_type == 'C'){ //Reject bottle!!!
      digitalWrite(Digital_out_1, HIGH); //for testing logic only
      //Serial.print("Reject!!!\n"); //for testing only
      //delay(1000); //for testing only
      //delay(30000); //for testing logic with voltmeter only
    }
    /*
     * For real system
     * 
    //For category A => Ignore on main conveyor
    if(bottle_type == 'A'){
      digitalWrite(Digital_out_1, LOW); 
      digitalWrite(Digital_out_2, LOW);
      //Serial.print("Ignore...\n"); //for testing only
      //delay(1000); //for testing only
      //delay(30000); //for testing logic with voltmeter only
    }  
    //For category B => reject from main conveyor with pusher_1 to another conveyor
    if(bottle_type == 'B'){ //Reject bottle with Pusher_1!!!
      digitalWrite(Digital_out_1, HIGH); //for testing logic only
      //Serial.print("Reject on pusher_1!!!\n"); //for testing only
      //delay(1000); //for testing only
      //delay(30000); //for testing logic with voltmeter only
    //For category C => reject from main conveyor with pusher_2 to another conveyor
    if(bottle_type == 'C'){ //Reject bottle with Pusher_2!!!
      digitalWrite(Digital_out_2, HIGH); //for testing logic only
      //Serial.print("Reject on pusher_2!!!\n"); //for testing only
      //delay(1000); //for testing only
      //delay(30000); //for testing logic with voltmeter only
    }
     *
     */ 
    //while(Serial.available()>0) 
      //bottle_type=Serial.read(); //while loop for reading data from serial port
  }
  
  /*
   * Don't use this code below because it will be jam your serial port :)
  else{
    Serial.print("No data available...\n");
    delay(1000);
  */
  
}
