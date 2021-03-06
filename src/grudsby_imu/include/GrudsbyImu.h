#ifndef GrudsbyImu_H
#define GrudsbyImu_H

#include "GrudsbyImuReg.h"

#include <cstddef>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <cstdlib>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

class GrudsbyImuBase
{
public:
  GrudsbyImuBase(const unsigned int address);
  ~GrudsbyImuBase();
  bool init();

protected:
  int x, y, z;
  int readyReg;
  int statusReg;

  int error()
  {
    return myError;
  }

  int addr()
  {
    return myAddr;
  }

  int readRegister(int reg_to_read);

  int writeRegister(int reg_to_write, int data_to_write);

  bool readInternal(int high_reg, int low_reg, int *value, bool read_status);


private:
  unsigned char myI2CBus ;
  int myI2CFileDescriptor ;
  int myAddr;
  int myError;
};

class GrudsbyImuAccel : GrudsbyImuBase
{
public:
  GrudsbyImuAccel();
  ~GrudsbyImuAccel();
  bool activate();
  bool deactivate();
  bool begin();
  double readX();
  double readY();
  double readZ();
};

class GrudsbyImuMag : GrudsbyImuBase
{
public:
  GrudsbyImuMag();
  ~GrudsbyImuMag();
  bool activate();
  bool deactivate();
  bool begin();
  double readX();
  double readY();
  double readZ();
};

class GrudsbyImuGyro : GrudsbyImuBase
{
public:
  GrudsbyImuGyro();
  ~GrudsbyImuGyro();
  bool activate();
  bool deactivate();
  bool begin();
  double readX();
  double readY();
  double readZ();
};
#endif //GrudsbyImu_H
