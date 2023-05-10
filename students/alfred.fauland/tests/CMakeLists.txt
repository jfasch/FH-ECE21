ADD_EXECUTABLE(
  test-suite-alfred.fauland

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-alfred.fauland

  lib-alfred.fauland
  gtest_main 
  )
