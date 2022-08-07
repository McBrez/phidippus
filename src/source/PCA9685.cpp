#include <PCA9685.hpp>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <unistd.h>

PCA9685::PCA9685(int fd) : fd(fd)
{
	reset();
}

int PCA9685::setupDevice(int address)
{
  wiringPiSetup();
	return wiringPiI2CSetup(address);
}

//! Sets PCA9685 mode to 00
void PCA9685::reset()
{
	wiringPiI2CWriteReg8(this->fd, MODE1, 0x00); //Normal mode
	wiringPiI2CWriteReg8(this->fd, MODE2, 0x05); //totem pole
}
//! Set the frequency of PWM
/*!
 \param freq desired frequency. 40Hz to 1000Hz using internal 25MHz oscillator.
 */
void PCA9685::setPWMFreq(int freq)
{

	int prescale_val = (CLOCK_FREQ / (4096 * freq)) - 1;
  if (prescale_val > 255) prescale_val = 255;
  if (prescale_val < 3) prescale_val = 3;

	wiringPiI2CWriteReg8(this->fd, MODE1, 0x10);			 //sleep
	wiringPiI2CWriteReg8(this->fd, PRE_SCALE, prescale_val); // multiplyer for PWM frequency
	wiringPiI2CWriteReg8(this->fd, MODE1, 0x00);			 //restart
  usleep(500);
	wiringPiI2CWriteReg8(this->fd, MODE2, 0x05);			 //totem pole (default)
}

//! PWM a single channel
/*!
 \param led channel (1-16) to set PWM value for
 \param value 0-4095 value for PWM
 */
void PCA9685::setPWM(uint8_t led, int value)
{
	setPWM(led, 0, value);
}
//! PWM a single channel with custom on time
/*!
 \param led channel (1-16) to set PWM value for
 \param on_value 0-4095 value to turn on the pulse
 \param off_value 0-4095 value to turn off the pulse
 */
void PCA9685::setPWM(uint8_t led, int on_value, int off_value)
{
	wiringPiI2CWriteReg8(this->fd, LED0_ON_L + LED_MULTIPLYER * (led - 1), on_value & 0xFF);
	wiringPiI2CWriteReg8(this->fd, LED0_ON_H + LED_MULTIPLYER * (led - 1), on_value >> 8);
	wiringPiI2CWriteReg8(this->fd, LED0_OFF_L + LED_MULTIPLYER * (led - 1), off_value & 0xFF);
	wiringPiI2CWriteReg8(this->fd, LED0_OFF_H + LED_MULTIPLYER * (led - 1), off_value >> 8);
}