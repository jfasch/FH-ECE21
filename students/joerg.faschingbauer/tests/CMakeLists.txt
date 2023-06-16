ADD_EXECUTABLE(
  test-suite-joerg.faschingbauer

  sensor-w1-suite.cpp
  sensor-random-suite-basic.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-joerg.faschingbauer

  lib-joerg.faschingbauer
  gtest_main 
  )
