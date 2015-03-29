% first serial test with the Esduino

s = serial('COM4');     %choose your COM port
set(s, 'Baudrate', 9600);   %sets the Baudrate to the same thing as your Esduino
s.Terminator = 'CR';
%set (s, 'Timeout', 3000);   %I think this help make things look pretty
fopen(s);   %open the port

myoRead = ' ';
myoRead2 = 0;
fid = fopen('Output.txt', 'w');

% t = [1:200];   
% t = t(:);   %I used this to graph a time of 200s

for i=0:100
    myoRead = fscanf(s);  %read the first 200 bits from the esduino
    myoRead2 = str2double(myoRead);
    myoRead2 = myoRead2 - 224
    fprintf(fid, '%d,', myoRead2);
end

fprintf(fid, '\n');



%plot(t, A); %plot esduino output vs time

fclose(fid);
fclose(s);  %CLOSE THE PORT OR ELSE THINGS GET MESSED
delete(s);  
clear s;   
