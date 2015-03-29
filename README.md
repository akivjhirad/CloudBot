# CloudBot

EsduinoSerialReading.mcp:
accesses the registers corresponding to the used pins to read in digital data, and then send it out via Serial

OutputFromMyoPoses.ino:
converts Myo hand gesture motions into serial data. Application with all code can be downloaded from the Myo Marketplace.

ServoControlOverSerial.ino:
made to check values for "wave in" and "wave out" gestures. Detects values sent over serial and send a change armature command to the servo to move to a certain position.

TxtStringStream.pde:
takes in a .txt file with comma separated values, sends them to the Arduino via serial one value at a time

OutputMyoToText.m:
takes in a stream of data and outputs it to a .txt file, using comma seperators

