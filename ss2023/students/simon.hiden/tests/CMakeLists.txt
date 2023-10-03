ADD_EXECUTABLE(
  test-suite-simon.hiden

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-simon.hiden

  lib-simon.hiden
  gtest_main 
  )
