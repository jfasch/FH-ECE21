ADD_EXECUTABLE(
  test-suite-wenzel.lang

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-wenzel.lang

  lib-wenzel.lang
  gtest_main 
  )
