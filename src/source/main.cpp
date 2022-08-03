#include <wiringPiI2C.h>
#include <iostream>

int main(void) {
  int fd = wiringPiI2CSetup(0x40);
  if(fd == -1) {
    std::cout << "Failed init.";
  }
  int writeSuccess = wiringPiI2CWriteReg8(fd, 0x00, 0x01);
  if(writeSuccess == -1) {
    std::cout << "Failed write.";
  }
  return 0;
}
