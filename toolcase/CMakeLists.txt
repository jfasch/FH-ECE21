ADD_LIBRARY(
  fh-ece21-toolcase

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

  hysteresis.h
  hysteresis.cpp

  display-led-stripe.h
  display-led-stripe.cpp
  sensor-config.h
  sink-logger.h
  sink-terminal.h
  data-logger.h 
  data-logger.cpp

)

TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-toolcase

  PUBLIC
  .
)
