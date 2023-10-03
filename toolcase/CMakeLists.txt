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
)

TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-toolcase

  PUBLIC
  .
)
