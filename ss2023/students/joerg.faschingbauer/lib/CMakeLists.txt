ADD_LIBRARY(
  lib-joerg.faschingbauer

  my-first-code.h
  my-first-code.c
)

TARGET_INCLUDE_DIRECTORIES(
  lib-joerg.faschingbauer

  PUBLIC .
)

TARGET_LINK_LIBRARIES(
  lib-joerg.faschingbauer

  fh-ece21-toolcase
)
