ADD_EXECUTABLE(
  test-suite-michael.feldbacher

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-michael.feldbacher

  lib-michael.feldbacher
  gtest_main 
  )
