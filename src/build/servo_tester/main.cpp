#include <PCA9685.hpp>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>

#define PCA9685_DEFAULT_ADDR 0x40

int main(void)
{

  initscr();
  std::cout << "Starting servo_tester" << std::endl;
  int fd = PCA9685::setupDevice(PCA9685_DEFAULT_ADDR);
  if (fd == -1)
  {
    std::cout << "Failed init."  << std::endl;
    return -1;
  }
  else {
	  std::cout << "Connected to PCA9685."  << std::endl;
	}
  
  PCA9685 servoDriver(fd);
  servoDriver.setPWMFreq(50);
  
  while(1) {
	  std::cout << "Which Servo address shall be used?" << std::endl;
		int servoAddress;
		std::cin >> servoAddress;
	  if('q' == servoAddress) {
		  break;
		}					 
						 																   
		std::cout << "Hit left arrow or right arrow to move the servo. Hit q to exit." << std::endl;
	  cbreak();
	  noecho();
	  keypad(stdscr, TRUE);
	  int key;
	  bool done = false;
	  int pwmValue = 0;
	  while(!done) {
		  key = getch();
			if(KEY_LEFT == key) {
			  pwmValue--;
			}
			else if(KEY_RIGHT == key){
			  pwmValue++; 
			}
			else if('q' == key){
			  done = true;
			}
	    std::cout << "Current PWM value: " << pwmValue << std::endl;
	    servoDriver.setPWM(servoAddress, pwmValue);
		}
	
	}
  endwin();
  return 0;
}
