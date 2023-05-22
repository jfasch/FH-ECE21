ADD_EXECUTABLE(
  demo-testsuite

  demo-suite.cpp
  vector-comprehension.cpp
  )

TARGET_LINK_LIBRARIES(
  demo-testsuite

  gtest_main 
  )
