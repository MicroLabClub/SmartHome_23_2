#ifndef DD_DHT_H_
#define DD_DHT_H_

void dd_dht_loop();
void dd_dht_setup();

float dd_dht_GetTemperature();
float dd_dht_GetHumidity();
int dd_dht_GetError();


#endif
