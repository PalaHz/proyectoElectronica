// Pines utilizados
#define LedVerdeP 3
#define LedAmaril1oP 4
#define LedRojoP 5
#define LedVerdeS 6
#define LedAmarrilloS 7
#define LedRojoS 8
#define LedVerdePeaton 10
#define LedRojoPeaton 9
#define PulsadorA 0
#define PulsadorB 1
#define SensorC 2


// Variables
bool activo1 = true; // Indica si el semáforo 1 está activo, de lo contrario será el semáforo 2

int tiempoEspera = 5000; // Tiempo de espera hasta comenzar transición

void setup() {
  // Iniciamos el monitor serie
  Serial.begin(9600);

  // Modo entrada/salida de los pines
  pinMode(LedVerdeP, OUTPUT);
  pinMode(LedAmaril1oP, OUTPUT);
  pinMode(LedRojoP, OUTPUT);
  pinMode(LedVerdeS, OUTPUT);
  pinMode(LedAmarrilloS, OUTPUT);
  pinMode(LedRojoS, OUTPUT);
  pinMode(LedVerdePeaton, OUTPUT);
  pinMode(LedRojoPeaton, OUTPUT);
  pinMode(PulsadorA, INPUT);
  pinMode(PulsadorB, INPUT);
  pinMode(SensorC, INPUT);

  // Apagamos todos los LEDs
  digitalWrite(LedVerdeP, LOW);
  digitalWrite(LedAmaril1oP, LOW);
  digitalWrite(LedRojoP, LOW);
  digitalWrite(LedVerdeS, LOW);
  digitalWrite(LedAmarrilloS, LOW);
  digitalWrite(LedRojoS, LOW);
  digitalWrite(LedVerdePeaton, LOW);
  digitalWrite(LedRojoPeaton, LOW);

  // Estado inicial: semáforo 1 activo, semáforo 2 no activo
  digitalWrite(LedVerdeP, HIGH);
  digitalWrite(LedRojoS, HIGH);
  digitalWrite(LedRojoPeaton, HIGH);
}

void loop() {
  // Dependiendo del semáforo que tengamos activo
  do {

    // Está encendido el semáforo 1, comprobamos el pulsador 2
    int valor2 = analogRead(PulsadorA);
    int valor3 = analogRead(PulsadorB);
    int valor4 = analogRead(SensorC);
    // Si hay un coche esperando, pulsador pulsado
    if (valor2 > 100 || valor3 >100 || valor4 > 100)
    {
      // Encender semáforo 2
      ecenderSemaforo2();

      // Semáforo 2 activo
      activo1 = false;
    }

  } while (activo1);

  do {
    // Está encendido el semáforo 1, comprobamos el pulsador 1
    int valor1 = HIGH;

    // Si hay un coche esperando, pulsador pulsado
    if (valor1 == HIGH)
    {
      // Encender semáforo 1
      ecenderSemaforo1();

      // Semáforo 1 activo
      activo1 = true;
    }
  } while (!activo1);
}

void ecenderSemaforo2()
{
  // Apagamos semáforo 1
  // Esperamos
  delay(tiempoEspera);

  // Pasamos a luz amarilla
  digitalWrite(LedVerdeP, LOW);
  digitalWrite(LedAmaril1oP, HIGH);

  // Esperamos
  delay(2000);

  // Pasamos a luz roja
  digitalWrite(LedAmaril1oP, LOW);
  digitalWrite(LedRojoP, HIGH);

  // Encendemos semáforo 2
  // Esperamos
  delay(100);

  // Pasamos a luz verde
  digitalWrite(LedRojoPeaton, LOW);
  digitalWrite(LedRojoS, LOW);
  digitalWrite(LedVerdeS, HIGH);
  digitalWrite(LedVerdePeaton, HIGH);



}

void ecenderSemaforo1()
{
  // Apagamos semáforo 2
  // Esperamos
  delay(tiempoEspera);

  // Pasamos a luz amarilla
  digitalWrite(LedVerdeS, LOW);
  digitalWrite(LedAmarrilloS, HIGH);

  // Esperamos
  delay(2000);

  // Pasamos a luz roja
  digitalWrite(LedAmarrilloS, LOW);
  digitalWrite(LedVerdePeaton, LOW);
  digitalWrite(LedRojoPeaton, HIGH);
  digitalWrite(LedRojoS, HIGH);

  // Encendemos semáforo 1
  // Esperamos
  delay(100);

  // Pasamos a luz amarilla
  digitalWrite(LedRojoP, LOW);
  digitalWrite(LedVerdeP, HIGH);
}
