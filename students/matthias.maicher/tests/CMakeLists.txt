ADD_EXECUTABLE(
  test-suite-matthias.maicher

  my-first-test.cpp
  )

TARGET_LINK_LIBRARIES(
  test-suite-matthias.maicher

  lib-matthias.maicher
  gtest_main 
  )
