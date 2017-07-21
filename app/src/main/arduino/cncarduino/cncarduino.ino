#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
#include "LaserPrinter.h"
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(10,11); //10 RX, 11 TX.
 int incomingByte = 0;
 int array[50][50];
 int x=0, y=0, xFinal=0, yFinal=0;
 bool arrayOk=false;
 
void setup()
{
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
}
 
void loop()
{
  cargaArray();
     
  
 
  
}



  void cargaArray() {
           
  if(BT.available())
  {
    incomingByte=BT.read();
    Serial.println( incomingByte); 
    if (incomingByte==126) { // inicio
      Serial.println("Inicio");  
     // delay(2000);
      x=0;
      y=0;
      while (true)  {
        if(BT.available()) {
            incomingByte=BT.read();
            if (incomingByte==125)      // nueva fila
            {
               x++;
               y=0;
               Serial.println("Fila"); 
           //    delay(200);
            }
            else
               if (incomingByte==124)   // fin
                {

                  Serial.print("fin ");
                   break;  

                }
               else
                    {
                     // array[x][y++]=incomingByte; // no hay memoria
                    
                     Serial.print("x ");
                     Serial.print(x);
                     Serial.print(" y ");
                     Serial.print(y);
                     Serial.print("  ");
                     array[x][y];
                     Serial.println(incomingByte);  
                      y++;  
                   //  delay(200);
                   }
            }
        }   
        arrayOk=true; 
        xFinal=x-1;
        yFinal=y-1; 
    }
    
    
  }
  
 }


 void imprimir() {
  arrayOk=false;
 }

