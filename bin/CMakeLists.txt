ADD_EXECUTABLE(avg-sensor-demo avg-sensor-demo.cpp)
TARGET_LINK_LIBRARIES(avg-sensor-demo fh-ece21-toolcase)

ADD_EXECUTABLE(malloc-free malloc-free.cpp)

<<<<<<< HEAD
ADD_EXECUTABLE(data-logger data-logger.cpp)
TARGET_LINK_LIBRARIES(data-logger fh-ece21-toolcase)

ADD_EXECUTABLE(map map.cpp)
=======
>>>>>>> 54d693c7bbaafb62e77df8f6a197df2e51020cb7
ADD_EXECUTABLE(data-logger-test data-logger-test.cpp)
TARGET_LINK_LIBRARIES(data-logger-test fh-ece21-toolcase fh-ece21-logger)
