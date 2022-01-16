import http.requests.*;

String CITY_ID = "400040";
String URL = "https://weather.tsukumijima.net/api/forecast/city/" + CITY_ID;

Boolean isTomorrowRainy = false;
Integer day = null;

void setup() {
  isTomorrowRainy = isTomorrowRainy();
  day = day();
}

void draw() {
  // TODO: send isTomorrowRainy info to arduino 

  // keep the forecast updated
  if (day != day()) {
    isTomorrowRainy = isTomorrowRainy();
    day = day();
  }
  
  delay(500);
}

Boolean isTomorrowRainy() {
  JSONObject res = loadJSONObject(URL);
  String tomorrowWeather = res.getJSONArray("forecasts").getJSONObject(1).getString("telop");

  return tomorrowWeather.contains("雨");
}
