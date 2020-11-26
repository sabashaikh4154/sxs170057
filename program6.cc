#include "program6.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

class BinaryFile
{
 public:
  int magic;
  int version;
  int Records;
};

class Binary
{
 public:
  int length;
  char stringBuffer[maxRecordStringLength];
};

int main()
{

  ifstream file("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

  BinaryFile *header = new BinaryFile();

  if(!file.read((char *) header, sizeof(BinaryFile)))
    {
      cout << "Error" << endl;
      cout << "Debugging" << endl;
      cout << "# of Bytes Read: " << file.count() << endl;
      break;
    }

  string ssh;
  ssh << "Records: " << header->Records;
  matrix[1][3] = ssh.str();
  ssh.clear();
   ssh << "Version: " << header->version;
  matrix[1][2] = ssh.str();

  ssh.clear();

  ssh << "Magic: 0x" << hex << uppercase <<  header->magic;
  matrix[1][1] = ssh.str();
  ssh.clear();
  string ssd;
  BinaryFileRecord *record = new BinaryFileRecord();
  int Records = header->Records < 4 ? header->Records : 4;

  for(int i = 2; i < Records + 2; i++)
    {
      if(!file.read((char *) record, sizeof(BinaryFile)))
        {
          cout << "Error " << endl;
          cout << "Debugging " << endl;
          cout << "# of Bytes Read " << file.gcount() << endl;
          break;
        }
      ssd << "strlen: " << (int) record->length;
      matrix[i][1] = ssd.str();
      matrix[i][2] = record->stringBuffer;
      ssd.clear();
    }
  file.close();
  display(matrix);
}
