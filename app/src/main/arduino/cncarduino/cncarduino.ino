// #include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
#include "LaserPrinter.h"
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
// SoftwareSerial BT(10,11); //10 RX, 11 TX.
 int incomingByte = 0;
 
 int x=0, y=0, xFinal=10, yFinal=10;
 bool arrayOk=false;
 LaserPrinter laser;
 int xI=0,x2=0, y2=0, yI=0;
 
void setup()
{
 // BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
  
}
 
void loop()
{
 
  // imprimir();  

   
  
  cargaArray();
 // if (arrayOk)
   //  imprimir();
     /*
     int a=0, b=200;
    laser.MoveTo(a,a);
    delay(1000);
    laser.MoveTo(a,b);
    delay(1000);
   // laser.on_laser();
    laser.MoveTo(b,a);
    delay(1000);
    laser.MoveTo(b,b);
    delay(1000);
    laser.off_laser();*/
      
  
 
  
}



  void cargaArray() {

    
  
  //if(BT.available())
  if(Serial.available())
  {
    
    incomingByte=Serial.read();
    if (incomingByte==126) { // inicio
      
      x=0;
      y=0;
      while (true)  {
     
         if(Serial.available()) { 
            //incomingByte=BT.read();
            incomingByte=Serial.read();
            if (incomingByte==125)      // nueva fila
            {
               //x++;
               x=x+2;
               y=0;
            }
            else
               if (incomingByte==124)   // fin
                {

                   break;  

                }
               else
                    {
                    // array2[x][y]=incomingByte;          
                     y=y+2; 
                     
                  laser.MoveTo(x,y);
                  laser.on_laser();
                  delay(incomingByte * 3);
                  laser.off_laser();
                   }
            }
        }   
        while(true) {
          
        }
        arrayOk=true; 
        xFinal=x-1;
        yFinal=y-1; 
        yI=0;
        xI=0;/*
        for (x2=0; x2<xFinal; x2++) {
             for ( y2=0; y2<yFinal; y2++)  {
               if (array2[x2][y2]>10) {
                  laser.MoveTo(xI,yI);
                  laser.on_laser();
                  delay(array2[x2][y2] * 3);
                  laser.off_laser();
                }
              }
     
          }*/
  
      }
    
    
  }
  
 }


 void imprimir() {
 }

