ADD_EXECUTABLE(my-first-program-joerg.faschingbauer my-first-program.cpp)
TARGET_LINK_LIBRARIES(my-first-program-joerg.faschingbauer lib-joerg.faschingbauer)

ADD_EXECUTABLE(onewire-temperature-monolithic-joerg.faschingbauer onewire-temperature-monolithic.cpp)

ADD_EXECUTABLE(onewire-temperature-modular-joerg.faschingbauer onewire-temperature-modular.cpp)
TARGET_LINK_LIBRARIES(onewire-temperature-modular-joerg.faschingbauer lib-joerg.faschingbauer)












# ADD_EXECUTABLE(onewire-temperature-joerg.faschingbauer onewire-temperature.cpp)

