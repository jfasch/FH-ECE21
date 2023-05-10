ADD_EXECUTABLE(
  test-suite-andreas.heindl

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-andreas.heindl

  lib-andreas.heindl
  gtest_main 
  )
