ADD_EXECUTABLE(boiling-pot boiling-pot.cpp)
TARGET_LINK_LIBRARIES(boiling-pot fh-ece21-toolcase)

ADD_EXECUTABLE(data-logger data-logger.cpp)
TARGET_LINK_LIBRARIES(data-logger fh-ece21-toolcase fh-ece21-logger)
