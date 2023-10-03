ADD_LIBRARY(
  lib-peter.felber

  my-first-code.h
  my-first-code.c
)

TARGET_INCLUDE_DIRECTORIES(
  lib-peter.felber

  PUBLIC .
)
