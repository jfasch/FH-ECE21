ADD_LIBRARY(
  fh-ece21-base

  sensor-const.h
  sensor-const.cpp
  sensor-mock.h
  sensor-mock.cpp
  sensor-random.h
  sensor-random.cpp
  sensor-avg.h
  sensor-avg.cpp
  sensor-w1.h

  switch-mock.h
  switch-mock.cpp
  switch.h

  hysteresis.h
  hysteresis.cpp

  display-led-stripe.h
  display-led-stripe.cpp

  sysfs-switch.cpp
  sysfs-switch.h

  pwm_controller.h
  pwm_controller.cpp

  composite-display.h
  composite-display.cpp

  MQTT.h    
  MQTT_mock.h
)

IF (MOSQUITTO_FOUND)
  ADD_LIBRARY( 
    MQTTPublisher

    MQTT_publisher.h
    MQTT_publisher.cpp
  )
  TARGET_LINK_LIBRARIES(fh-ece21-base  MQTTPublisher Mosquitto::Mosquitto)
ENDIF()

TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-base

  PUBLIC
  .
)
