ADD_EXECUTABLE(
  test-suite-joerg.faschingbauer

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-joerg.faschingbauer

  lib-joerg.faschingbauer
  gtest_main 
  )
