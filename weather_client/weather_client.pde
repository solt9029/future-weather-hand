import http.requests.*;
import processing.serial.*;

String CITY_ID = "400040";
String URL = "https://weather.tsukumijima.net/api/forecast/city/" + CITY_ID;

Boolean isTomorrowRainy = false;
Integer day = null;
Serial port = null;

void setup() {
  isTomorrowRainy = isTomorrowRainy();
  day = day();
  port = new Serial(this, Serial.list()[0], 9600);
}

Boolean isTomorrowRainy() {
  JSONObject res = loadJSONObject(URL);
  String tomorrowWeather = res.getJSONArray("forecasts").getJSONObject(1).getString("telop");

  return tomorrowWeather.contains("雨");
}

void serialEvent (Serial p) {
  p.read();

  if (day != day()) {
    isTomorrowRainy = isTomorrowRainy();
    day = day();
  }

  if (isTomorrowRainy) {
    port.write(1);
  }
}
