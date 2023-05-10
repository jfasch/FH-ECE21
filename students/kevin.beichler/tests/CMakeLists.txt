ADD_EXECUTABLE(
  test-suite-kevin.beichler

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-kevin.beichler

  lib-kevin.beichler
  gtest_main 
  )
