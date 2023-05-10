ADD_EXECUTABLE(
  test-suite-christian.berger

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-christian.berger

  lib-christian.berger
  gtest_main 
  )
