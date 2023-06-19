ADD_EXECUTABLE(
  fh-ece21-suite

  sensor-mock-nopoly-basic.cpp
)

TARGET_LINK_LIBRARIES(
  fh-ece21-suite

  fh-ece21-toolcase
  gtest_main 
)
