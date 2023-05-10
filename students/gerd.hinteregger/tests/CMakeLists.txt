ADD_EXECUTABLE(
  test-suite-gerd.hinteregger

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-gerd.hinteregger

  lib-gerd.hinteregger
  gtest_main 
  )
