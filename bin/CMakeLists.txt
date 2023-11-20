ADD_EXECUTABLE(avg-sensor-demo avg-sensor-demo.cpp)
TARGET_LINK_LIBRARIES(avg-sensor-demo fh-ece21-toolcase)

ADD_EXECUTABLE(malloc-free malloc-free.cpp)

#ADD_EXECUTABLE(boiling-pot boiling-pot.cpp)
#TARGET_LINK_LIBRARIES(boiling-pot fh-ece21-toolcase)

ADD_EXECUTABLE(data-logger data-logger.cpp)
TARGET_LINK_LIBRARIES(data-logger fh-ece21-toolcase)

ADD_EXECUTABLE(map-demo map.cpp)

ADD_EXECUTABLE(data-logger-test data-logger-test.cpp)
TARGET_LINK_LIBRARIES(data-logger-test fh-ece21-toolcase fh-ece21-logger)

ADD_EXECUTABLE(sysfs-switch-test sysfs-switch-test.cpp)
TARGET_LINK_LIBRARIES(sysfs-switch-test fh-ece21-toolcase)

IF (${MOSQUITTO_FOUND})
  ADD_EXECUTABLE(mosquitto-publish-demo mosquitto-publish-demo.cpp)
  TARGET_LINK_LIBRARIES(mosquitto-publish-demo Mosquitto::Mosquitto)
ENDIF()
