ADD_LIBRARY(
  fh-ece21-toolcase

  boiling-pot.h
  boilingPot.cpp


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

)

TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-toolcase

  PUBLIC
  .
)
