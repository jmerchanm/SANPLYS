// * Copyright 2017 Francisco Javier Merchán Macías.
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU Affero General Public License as published
// * by the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// * GNU Affero General Public License for more details.
// *
// * You should have received a copy of the GNU Affero General Public License
// * along with this program.  If not, see <http://www.gnu.org/licenses/>.

//Constantes y variables
long distancia;
long tiempo;
const int TRIGER = 13;
const int ECHO = 12;
const int LEDROJO = 2;
const int LEDVERDE = 3;
const int LEDAZUL = 4;

void setup(){
  Serial.begin(9600);
  pinMode(TRIGER, OUTPUT); //Enviamos el ping por el puerto 13.
  pinMode(ECHO, INPUT); //Recibimos la señal del ping del puerto 13 en el puerto 12.
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
}

void loop(){
  digitalWrite(TRIGER,LOW); //Inicializamos el sensor
  delayMicroseconds(5);
  digitalWrite(TRIGER, HIGH); //Enviamos un pulso de 10 microsegundos.
  delayMicroseconds(10);
  tiempo=pulseIn(ECHO, HIGH); //Función para medir la longitud del pulso entrante.
  distancia= int(0.017*tiempo); //Calculamos la distancia obteniendo un valor entero.
  //Enviamos la distancia por el puerto serie para poderlo ver en el PC.
  Serial.println("Distancia en cm");
  Serial.println(distancia);
  if (distancia <=10){
	  //Si la distancia es menor o igual a 10 cms, encendemos el Rojo, Verde y Azul, es decir,
	  //conseguimos un LED BLANCO.
    digitalWrite(LEDROJO, LOW);
    digitalWrite(LEDAZUL, LOW);
    digitalWrite(LEDVERDE, LOW);
  }
  else if (distancia>10 && distancia<=20){
	  //Si la distancia está entre 10 cms (excluido) y 20 cms (incluido), encendemos el led ROJO.
    digitalWrite(LEDROJO, LOW);
    digitalWrite(LEDAZUL, HIGH);
    digitalWrite(LEDVERDE, HIGH);
  }
  else if (distancia>20 && distancia <= 35) {
	  //Si la distancia está entre 20 cms (excluido) y 35 cms (incluido), encendemos el led AZUL.
    digitalWrite(LEDROJO, HIGH);
    digitalWrite(LEDAZUL, LOW);
    digitalWrite(LEDVERDE, HIGH);
  }
  else{
	  //Si la distancia es mayor o igual que 35cms encendemos el led VERDE.
    digitalWrite(LEDROJO, HIGH);
    digitalWrite(LEDAZUL, HIGH);
    digitalWrite(LEDVERDE, LOW);
  }
  delay(500);
}
