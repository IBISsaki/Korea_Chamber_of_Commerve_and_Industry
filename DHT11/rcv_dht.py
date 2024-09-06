import serial
import pymysql

sp = serial.Serial( port='COM3', baudrate=9600, timeout=1) 
conn = pymysql.connect(host='172.16.0.12', user='user1', password='1234', db='dht11', charset='utf8')
#localhost 120.0.0.1은 자기자신을 가르킴
curs = conn.cursor() 
sql = "delete from dht11.location1 where id=13"
curs.execute(sql) 
conn.commit()

humi = 0
temp = 0

while True:
    if sp.readable():
        rcv = sp.readline()
       
        if (rcv.decode()[0:4]=="humi"): #0:4는 0부터 3까지 4는 포함 안됨 0<4
            humi = int(rcv.decode()[4:6])
            print(humi)
        if (rcv.decode()[0:4]=="temp"):
            temp = int(rcv.decode()[4:6])
            print(temp)
        
        sql = "insert into dht11.location1(Temperature, Humidity) values(%s, %s)"
        curs.execute(sql, (temp, humi))
        conn.commit()
        
        #print(rcv.decode() [4:6])
        #print(rcv.decode() [:len(rcv)-1])
        #print(rcv.decode() [0:4]) #0부터 ~ 4번째 글자까지 프린트