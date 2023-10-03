ADD_EXECUTABLE(
  test-suite-daniel.rotter

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-daniel.rotter

  lib-daniel.rotter
  gtest_main 
  )
