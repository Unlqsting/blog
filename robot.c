#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in7,    lineFollower2,  sensorLineFollower)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_inch)
#pragma config(Motor,  port1,           rMotor,        tmotorVex393_HBridge, openLoop, encoderPort, None)
#pragma config(Motor,  port5,          lMotor,        tmotorVex393_HBridge, openLoop, reversed, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/******************************FUNCTIONS**************************************/

void rightTurn()
	{
			startMotor(port1, 90);
			startMotor(port5, -90);
	}

void leftTurn()
	{
			startMotor(port1, -90);
			startMotor(port5, 90);
	}

void moveForward()
	{
		startMotor(port1, 20);
		startMotor(port5, 20);
	}
void motorStop()
	{
		stopMotor(rMotor);
		stopMotor(lMotor);
	}

void moveBackward()
    {
        startMotor(port1, -20);
        startMotor(port5, -20);
    }

void failSafe() 
	{
		if (SensorValue(in1) > threshold && SensorValue(in2) > threshold)
			{
                while(SensorValue(in1) > threshold && SensorValue(in2) > threshold)
                    {
                        moveBackward();
                        if (SensorValue(in1) < 2050 && SensorValue(in2) < 2050)
                            {
                                moveForward();
                            }
                    }
			}
	}

/******************************FUNCTIONS**************************************/


task main()
	{
		/********************************variables***************************/

		int threshold;
		threshold = 2200;

		/********************************************************************/
		while (1==1)
			{
				startMotor(rMotor, 40);
				startMotor(lMotor, 40);
				wait(0.5);
				/**********************linefollower left*************************/
				if (SensorValue(in7) > threshold)
					{
						while(SensorValue(in7) > threshold)
							{
                                failSafe();
								rightTurn();
								if(SensorValue(in7) < 2050)
									{
										moveForward();
									}
							}
					}
				/**********************linefollower right*************************/
				else
				{
					if (SensorValue(lineFollower) > threshold)
						{
							while(SensorValue(lineFollower) > threshold)
								{
                                    failSafe();
									leftTurn();
									if(SensorValue(lineFollower) < 2050)
										{
											moveForward();
										}
								}
						}
				}
                /**********************linefollower fail safe*************************/
                //! test out the fail safe above, and if there are a lot of errors, try running it below. The below code is going to run last
                
                //!failsafe();

			}

	}
