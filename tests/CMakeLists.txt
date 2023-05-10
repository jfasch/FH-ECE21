ADD_EXECUTABLE(
  test-suite

  fail.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite

  gtest_main 
  )
