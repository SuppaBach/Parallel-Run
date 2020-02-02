#SerialSender_and_DataLogger
#College of Nanotechnology Co-op Education
#TBR AI Image Recognition project of ThaiBev and CMKL University
#Code by NiNouNiaNaNoNa
#Copyright 2019, Suppawat Boonrach

#Library Import
import random #for random testing only
import time #about time :)
import serial #for serial port
import logging #for data logger

#Variable preparation
#i = 0 #for testing only

#Random Type Testing
bottle_type_list = ['A', 'B', 'C'] #for random testing only

#User Input Testing
#bottle_type = str(input('Enter your bottle type : ')) #for user input testing only
#i = 0 #for user input testing only

#Serial Preparation
ser = serial.Serial('COM3', 9600) #Change serial port and baud rate here!!!
time.sleep(2)

def dataLog_and_Send():
    logging.basicConfig(filename='SerialSender.log', filemode='w', format= '%(asctime)s - %(message)s')
    #print(bottle_type) #for testing only

    #In real system. Instead of print, You will send a logic to Microcontroller before PLC lol
    bottle_type = random.choice(bottle_type_list) #Looping random, for testing only
    if bottle_type == 'A':
        logging.warning('Type_A => Ignore...')
        print('Type_A => Ignore...') #for testing only
        ser.write(b'A') #for real system
    if bottle_type == 'B':
        logging.warning('Type_B => Reject with Pusher_1')
        print('Type_B => Reject with Pusher_1') #for testing only
        ser.write(b'B') #for real system
    if bottle_type == 'C':
        logging.warning('Type_C => Reject with Pusher_2')
        print('Type_C => Reject with Pusher_2') #for testing only
        ser.write(b'C') #for real system

#Loop
while 1: #bottle_type != '0': #i >= 0:
    dataLog_and_Send()
    time.sleep(1)
    #i += 1 #for testing only
