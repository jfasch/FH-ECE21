ADD_EXECUTABLE(
  test-suite-joerg.faschingbauer

  sensor-w1-suite.cpp
  sensor-random-suite-basic.cpp

  sensor-avg-nopoly-basic.cpp
  sensor-avg-nopoly-change-temperatures.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-joerg.faschingbauer

  lib-joerg.faschingbauer
  fh-ece21-toolcase
  gtest_main 
  )
