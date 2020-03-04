import serial
import matplotlib.pyplot as plt
from drawnow import *
import json

Xavalues = []
Yavalues = []
Zavalues = []

Xgvalues = []
Ygvalues = []
Zgvalues = []

plt.ion()
cnt=0

serialArduino = serial.Serial('/dev/ttyUSB0', 115200)

def plotAValues():
    plt.figure(1)
    plt.subplot(211)
    plt.title('Serial value from BBB\'s ACCEL')
    plt.grid(True)
    plt.ylabel('Values')
    plt.plot(Xavalues, 'r--', label='X')
    plt.plot(Yavalues, 'g--', label='Y')
    plt.plot(Zavalues, 'b--', label='Z')
    plt.legend(loc='upper right')

# def plotGValues():
    plt.subplot(212)
    plt.title('Serial value from BBB\'s GYRO')
    plt.grid(True)
    plt.ylabel('Values')
    plt.plot(Xgvalues, 'r--', label='X')
    plt.plot(Ygvalues, 'g--', label='Y')
    plt.plot(Zgvalues, 'b--', label='Z')
    plt.legend(loc='upper right')

#pre-load dummy data
for i in range(0,26):
    Xavalues.append(0)
    Yavalues.append(0)
    Zavalues.append(0)
    Xgvalues.append(0)
    Ygvalues.append(0)
    Zgvalues.append(0)
    
while True:
    while (serialArduino.inWaiting()==0):
        pass
    valueRead = serialArduino.readline()
    pyDict = json.loads(valueRead.decode())
    #check if valid value can be casted
    try:
        Xa = (float(pyDict['Acelera']['x']))
        Ya = (float(pyDict['Acelera']['y']))
        Za = (float(pyDict['Acelera']['z']))
        Xg = (float(pyDict['Giro']['x']))
        Yg = (float(pyDict['Giro']['y']))
        Zg = (float(pyDict['Giro']['z']))
        
        print('X - acelra: ',Xa,' - giro: ',Xg)
        print('Y - acelra: ',Ya,' - giro: ',Yg)
        print('Z - acelra: ',Za,' - giro: ',Zg)

        if Xa <= 65535 or Ya <= 65535 or Za <= 65535 or Xg <= 65535 or Yg <= 65535 or Zg <= 65535:
            Xavalues.append(Xa)
            Yavalues.append(Ya)
            Zavalues.append(Za)
            Xgvalues.append(Xg)
            Ygvalues.append(Yg)
            Zgvalues.append(Zg)
            Xavalues.pop(0)
            Yavalues.pop(0)
            Zavalues.pop(0)
            Xgvalues.pop(0)
            Ygvalues.pop(0)
            Zgvalues.pop(0)
            # plt.show()
            drawnow(plotAValues)
            # drawnow(plotGValues)
        else:
            print("Invalid! too large")
    except ValueError:
        print("Invalid! cannot cast")
