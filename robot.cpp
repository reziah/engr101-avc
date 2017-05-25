#include<stdio.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include"E101.h"
#include"camera.h"
//#include"maze.h"

using namespace std;

// Global Variables
char GATE_IP[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
int GATE_PORT = 1024;

//Tuning
float KP = 0.7; // proportionality constant
float KD = 0.4; // derivative constant
int BASE_SPEED = 32;

// Log File
//ofstream logfile("./logs/" + time(0) + ".csv");

int stopMotors() {
    // Sets speed of both motors to 0
    set_motor(1, 0);
    set_motor(2, 0);
    cout << "Both motors stopped (speed: 0)\n";
}

int openGate() {

    // Listens for gate to broadcast password, then sends that password to the gate, resulting in the gate opening.

    char password[24]; // receive_from_server() returns an int according to e101.h
    char message[11] = {0x1B, '[', '5', 'm', 'P','l','e','a','s','e'}; 

    connect_to_server(GATE_IP, GATE_PORT);
    
    send_to_server(message);

    // receive password from gate
    int pwInt = receive_from_server(password);
    printf("%s %ld\n",password,pwInt); // convert to char[]

    // send password to gate, should open
    send_to_server(password);

    //TODO: check gate has opened with sensors(+ account for time where gate is above sensors LoS but not fully open)
    //TODO: wrap this in a for loop that waits a reasonable time for gate to open before retrying
//    if (sensors no longer detect gate) {
//        wait x seconds (for gate to fully open)
//        return 1; // return that the gate has successfully opened
//    } else {
//        openGate(); // Try again
//    }
    return 0;
}

//void logData() {
//    //TODO: Maybe main opense log, writes first line. drive calls log each step and passes it's values
//    if (logfile.is_open()) {
//        logfile << "time,KP,KD,PID_sum,leftSpeed,rightSpeed,error,previous_error.\n";
//
//        while () { // vehicle is navigating course
//            logfile <<
//        }
//    }
//}

int drive() {

    int error;
    int previous_error = 0;
    int proportional_signal;
    float prop_component;
    int derivative_signal;
    float deriv_component;
    float PID_sum;
    int leftSpeed;
    int rightSpeed;

    while(true) {
        error = horizontalSample(); // Value between -120 and 120
        proportional_signal = error * KP;
        derivative_signal = (error - previous_error) * KD; // (error - previous): range -240 to 240
        previous_error = error;

	if (whiteness() < 1500) {
		cout << "BLACK";
		leftSpeed = -60;
		rightSpeed = -60;
	} else {
		cout << "Raw Error: " << error << "\n";

		prop_component = ((proportional_signal/(120*1.0))*KP);
		deriv_component = ((derivative_signal/(240*1.0))*KD); // ? - unclear how to calculate derivative component

		PID_sum = prop_component + deriv_component;

        	leftSpeed = (BASE_SPEED + (PID_sum*250));
        	rightSpeed = (BASE_SPEED - (PID_sum*250));
	}

        if (leftSpeed > 250) {
            leftSpeed = 250;
        } else if (leftSpeed < -250) {
            leftSpeed = -250;
        }

        if (rightSpeed > 250) {
            rightSpeed = 250;
        } else if (rightSpeed < -250) {
            rightSpeed = -250;
        }

        set_motor(1, leftSpeed);
        set_motor(2, rightSpeed);

        cout << "Left motor speed: " << leftSpeed <<
                " Right motor speed: " << rightSpeed << "\n";

        sleep1(0,50000); // 0.05 seconds - 20FPS
    }
    return 0;
}

int main() {
    init();

    drive();

    //TODO: Implement a way to break out of drive loop and safely stop motors - Wait for an input in terminal?
    // if (program end condition) {
    //    stopMotors();
    //    stop(); // function from e101 lib - can't find what it does in lecture slides, Arthur's notes or e101 wiki
    //    return 0;
    // }

    return 0;
}

