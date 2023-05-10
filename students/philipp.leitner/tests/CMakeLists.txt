ADD_EXECUTABLE(
  test-suite-philipp.leitner

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-philipp.leitner

  lib-philipp.leitner
  gtest_main 
  )
