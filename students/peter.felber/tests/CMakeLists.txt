ADD_EXECUTABLE(
  test-suite-peter.felber

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-peter.felber

  lib-peter.felber
  gtest_main 
  )
