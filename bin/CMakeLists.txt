ADD_EXECUTABLE(avg-sensor-demo avg-sensor-demo.cpp)
TARGET_LINK_LIBRARIES(avg-sensor-demo fh-ece21-toolcase)

ADD_EXECUTABLE(malloc-free malloc-free.cpp)

ADD_EXECUTABLE(data-logger data-logger.cpp)
TARGET_LINK_LIBRARIES(data-logger fh-ece21-toolcase)
