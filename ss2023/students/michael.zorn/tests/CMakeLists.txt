ADD_EXECUTABLE(
  test-suite-michael.zorn

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-michael.zorn

  lib-michael.zorn
  gtest_main 
  )
