% Written by Akiv Jhirad
% For use with Matlab

s = serial('COM4');     %choose your COM port
set(s, 'Baudrate', 9600);   %sets the Baudrate to the same thing as your uC
s.Terminator = 'CR';    %terminator has to match the serial output device
fopen(s);   %open the port

myoRead = ' ';
myoRead2 = 0;
fid = fopen('Output.txt', 'w');

for i=0:100
    myoRead = fscanf(s);  %read the first 200 bits from the esduino
    myoRead2 = str2double(myoRead);
    myoRead2 = myoRead2 - 224
    fprintf(fid, '%d,', myoRead2);
end

fprintf(fid, '\n');

fclose(fid);
fclose(s);
delete(s);  
clear s;   
