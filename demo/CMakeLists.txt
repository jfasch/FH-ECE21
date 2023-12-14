ADD_EXECUTABLE(avg-sensor-demo avg-sensor-demo.cpp)
TARGET_LINK_LIBRARIES(avg-sensor-demo fh-ece21-base)

ADD_EXECUTABLE(display-demo display-demo.cpp)
TARGET_LINK_LIBRARIES(display-demo fh-ece21-base)

ADD_EXECUTABLE(display_1LED-demo display_1LED-demo.cpp)
TARGET_LINK_LIBRARIES(display_1LED-demo fh-ece21-base)

IF (MOSQUITTO_FOUND)
  ADD_EXECUTABLE(mosquitto-publish-demo mosquitto-publish-demo.cpp)
  TARGET_LINK_LIBRARIES(mosquitto-publish-demo Mosquitto::Mosquitto)
ENDIF()

ADD_EXECUTABLE(sysfs-switch-test sysfs-switch-test.cpp)
TARGET_LINK_LIBRARIES(sysfs-switch-test fh-ece21-base)
