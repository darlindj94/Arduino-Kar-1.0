boolean a=0,b=1;   // como a y b son valores que valen 1 o 0, asi que los debemos declarer como bolean, no como int. (Importante)

int vel = 255;    // Velocidad de los motores (0-255)
char parado;  // inicia detenido

void setup() 
{        

  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  
         //SALIDAS
   pinMode(8,OUTPUT); // DIRA1 (IN1)     // MOTOR A
   pinMode(9,OUTPUT); // DIRB1 (IN 2)    // MOTOR A
   
   pinMode(6,OUTPUT); // DIRA2 (IN1)     // MOTOR B
   pinMode(7,OUTPUT); // DIRB2 (IN 2)    // MOTOR B
  
       
}
          void ADELANTE()   //  MARCHA ADELANTE
              {
                digitalWrite(8,a); // MOTOR B
                digitalWrite(9,b); // MOTOR B
                
                digitalWrite(6,a); // MOTOR A
                digitalWrite(7,b); // MOTOR A
              }
            
            void ATRAS()  //  MARCHA ATRAS
              { 
                digitalWrite(6,b); // MOTOR A
                digitalWrite(7,a); // MOTOR A

                digitalWrite(8,b); // MOTOR B
                digitalWrite(9,a); // MOTOR B
              }
            
            void STOP()   //  STOP
              {
                digitalWrite(8,a); // MOTOR B
                digitalWrite(9,a); // MOTOR B
                
                digitalWrite(6,a); // MOTOR A
                digitalWrite(7,a); // MOTOR A
              }              

            void MJAIZQ()   //  MICHAEL JACKSSON CON GIRO A DERECHA ADELANTE
              {
                digitalWrite(6,a); // MOTOR A
                digitalWrite(7,a); // MOTOR A
                    
                digitalWrite(8,a); // MOTOR B
                digitalWrite(9,b); // MOTOR B
                    
              }

            void MJADR()   //  MICHAEL JACKSSON CON GIRO A IZQUIERDA ADELANTE
              {
                digitalWrite(6,a); // MOTOR A
                digitalWrite(7,b); // MOTOR A
                    
                digitalWrite(8,a); // MOTOR B
                digitalWrite(9,a); // MOTOR B
                    
              }
                
            void MJBIZQ()   //  MICHAEL JACKSSON CON GIRO A DERECHA ATRAS O BACK
              {
                digitalWrite(6,a); // MOTOR A
                digitalWrite(7,a); // MOTOR A
                    
                digitalWrite(8,b); // MOTOR B
                digitalWrite(9,a); // MOTOR B
                    
              }

            void MJBDR()   //  MICHAEL JACKSSON CON GIRO A IZQUIERDA ATRAS O BACK
              {
                digitalWrite(6,b); // MOTOR A
                digitalWrite(7,a); // MOTOR A
                    
                digitalWrite(8,a); // MOTOR B
                digitalWrite(9,a); // MOTOR B      
              }
                                     
void loop() 
{
     if(Serial.available()>0)   // lee el bluetooth y almacena en estado
     { 
      parado = Serial.read();
     }
      
      switch (parado) 
      {
      case 'F':ADELANTE();break;
      case 'S':STOP();break;
      case 'G':ATRAS();break;

      case 'Q':MJAIZQ();break;
      case 'E':MJADR();break;

      case 'Z':MJBIZQ();break;
      case 'C':MJBDR();break;  
      }
}
