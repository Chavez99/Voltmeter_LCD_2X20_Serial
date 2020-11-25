//Titulo: Voltimetro Serial y con LCD 2X20
//Alumno: Chavez Murga Arturo Alejandro 17491021
//Materia: Introducción a las Telecomunicaciones
//Docente: Ing. Alejandro Ortega Nazario.
#include <LiquidCrystal.h> //Incluyendo la libreria LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Indicamos los pines digitales de conexión LCD
int analogInput = 0; //Definimos el pin analógico A0 para la lectura del voltaje
float vout = 0.0; //Definimos la variable Vout
float vin = 0.0; //Definimos la variable Vin
float R1 = 100000.0; //  R1 (100K) Valor de la resistencia R1 del divisor de tensión
float R2 = 10000.0; //  R2 (10K) Valor de la resistencia R2 del divisor de tención
int value = 0;//Definimos la variable value
void setup(){//////////////////////////////////////////////////////////////////////////////
  
   pinMode(analogInput, INPUT); //Activamos el input del pin analógico A0
   Serial.begin(9600);//Habilitando comunicacion serial a 9600 baudios
   lcd.begin(16, 2); // Activamos LCD
   lcd.print("DC VOLTIMETRO"); //Mostramos en el LCD este mensaje
}
void loop(){//////////////////////////////////////////////////////////////////////////////
   value = analogRead(analogInput); //Leemos el pin analógico A0
   vout = (value * 5.0) / 1024.0; // Cálculo para obtener el Vout
   vin = vout / (R2/(R1+R2)); // Cálculo para obtener Vin del divisor de tensión
   if (vin<0.09) { //Si la lectura de Vin es menor que 0.09V le decimos que nos muestre 0
   vin=0.0;
} 
lcd.setCursor(0, 1); //Posicionamos el cursor en el LCD
lcd.print("INPUT V= ");//Mostramos el texto en el LCD
lcd.print(vin);//Mostramos el valor del Vin en el LCD
delay(500); //Se hace una lectura de voltaje cada 500 ms
Serial.println("V = ");
Serial.println(vin);
}
