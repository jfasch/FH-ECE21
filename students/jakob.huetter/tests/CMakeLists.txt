ADD_EXECUTABLE(
  test-suite-jakob.huetter

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-jakob.huetter

  lib-jakob.huetter
  gtest_main 
  )
