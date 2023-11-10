ADD_EXECUTABLE(avg-sensor-demo avg-sensor-demo.cpp)
TARGET_LINK_LIBRARIES(avg-sensor-demo fh-ece21-toolcase)

ADD_EXECUTABLE(malloc-free malloc-free.cpp)

#ADD_EXECUTABLE(boiling-pot boiling-pot.cpp)
#TARGET_LINK_LIBRARIES(boiling-pot fh-ece21-toolcase)

ADD_EXECUTABLE(data-logger data-logger.cpp)
TARGET_LINK_LIBRARIES(data-logger fh-ece21-toolcase)

ADD_EXECUTABLE(map map.cpp)
