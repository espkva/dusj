// This #include statement was automatically added by the Particle IDE.
#include <OneWire.h>

// This #include statement was automatically added by the Particle IDE.
#include <spark-dallas-temperature.h>

#define ONE_WIRE_BUS D2  //data on pin d2

OneWire oneWire(ONE_WIRE_BUS);  // Setup a oneWire instance to communicate with any OneWire devices 
DallasTemperature sensors(&oneWire);  // Pass our oneWire reference to Dallas Temperature.

void loop(void) { 
  // Send the command to get temperatures
  sensors.requestTemperatures(); 
  delay(500);
}


void setup(void)
{
     Particle.function("read", readTempManual);

    //Serial.begin(9600);    
    sensors.begin();    // IC defaults to 9 bit. If you have trouble consider changing to 12. 
    Spark.variable("tempc", &tempc, DOUBLE);   //expose vars to web interface  
    //Spark.variable("tempf", &tempf, DOUBLE); 
    //Spark.variable("rssi", &rssi, INT);
    //pinMode(7, OUTPUT);
}  

double readTempManual(String command) {
    sensors.requestTemperatures(); 
    return sensors.getTempCByIndex(0);
}