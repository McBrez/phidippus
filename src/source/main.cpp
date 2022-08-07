#include <PCA9685.h>
#include <iostream>
#include <unistd.h>

#define PCA9685_DEFAULT_ADDR 0x40

int main(void)
{
  std::cout << "Hello" << std::endl;
  int fd = PCA9685::setupDevice(PCA9685_DEFAULT_ADDR);
  if (fd == -1)
  {
    std::cout << "Failed init."  << std::endl;
    return -1;
  }
  
  PCA9685 servoDriver(fd);
  servoDriver.setPWMFreq(50);
  while(1) {
  for(int i = 0; i < 4000; i++) {
    std::cout << "Setting "  << i << std::endl;
    servoDriver.setPWM(1,i);
    usleep(100);
  }
  for(int i = 4000 ; i > 0; i--){
    std::cout << "Setting "  << i << std::endl;
    servoDriver.setPWM(1,i);
    usleep(100);
  }
  }
  
  
  
  
  return 0;
}
