ADD_EXECUTABLE(
  fh-ece21-suite

  boiling-pot-test.cpp

  sensor-const-basic.cpp
  sensor-random-basic.cpp
  sensor-mock-basic.cpp

  sensor-avg-basic.cpp
  sensor-avg-change-temperatures.cpp

  sensor-w1-suite.cpp

  switch-mock-basic.cpp

  composite-switch-basic.cpp

  hysteresis-falls_below_range.cpp
  hysteresis-nop_when_within_range.cpp
  hysteresis-rises_above_range.cpp
  hysteresis-rises_above_range_when_on.cpp
  hysteresis-set-range.cpp

  #display_led_stripe_suite__above_range.cpp
  #display_led_stripe_suite__below_range.cpp
  display_led_stripe_suite__movement.cpp
  #display_led_stripe_suite__somewhere_in_the_middle.cpp
  #display_led_stripe_suite__variations.cpp
  hysteresis-set-range.cpp

  sensor-config-suite.cpp
  sensor-values-suite.cpp
  sink-suite.cpp
  logger-suite.cpp

  # fixtures
  fixture-tmpdir.h
  fixture-tmpdir.cpp  

  # misc
  felber.cpp
)

TARGET_LINK_LIBRARIES(
  fh-ece21-suite

  fh-ece21-data-logger
  fh-ece21-boiling-pot
  fh-ece21-base

  gtest_main 
)
