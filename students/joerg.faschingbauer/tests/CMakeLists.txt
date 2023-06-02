ADD_EXECUTABLE(
  test-suite-joerg.faschingbauer

  my-first-test.cpp
#  sensor-w1-suite.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-joerg.faschingbauer

  lib-joerg.faschingbauer
  gtest_main 
  )
