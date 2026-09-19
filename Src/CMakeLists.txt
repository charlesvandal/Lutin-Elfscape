set(CORE_LIBRARY core-library)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(CORE_LIBRARY
Board/Board.cpp
Builder/BoardBuilder.cpp
Builder/SimulatorBuilder.cpp
Controller/Controller.cpp
GUI/GameBoardWidget.cpp
GUI/GameWorker.cpp
GUI/Inc/GameBoardWidget.hpp
GUI/Inc/GameState.hpp
GUI/Inc/GameWorker.hpp
Object/Cat.cpp
Object/Elf.cpp
Object/Empty.cpp
Object/Fire.cpp
Object/Flower.cpp
Object/Object.cpp
Object/PathLink.cpp
Simulator/Simulator.cpp
Strategy/Strategy.cpp
Strategy/FlowerStrategy.cpp
)

set_target_properties(CORE_LIBRARY PROPERTIES
    AUTOMOC ON
)

target_include_directories(CORE_LIBRARY PUBLIC
    ${CMAKE_SOURCE_DIR}/Inc
    ${CMAKE_SOURCE_DIR}/Src/Board/Inc
    ${CMAKE_SOURCE_DIR}/Src/Builder/Inc
    ${CMAKE_SOURCE_DIR}/Src/Controller/Inc
    ${CMAKE_SOURCE_DIR}/Src/GUI/Inc
    ${CMAKE_SOURCE_DIR}/Src/Object/Inc
    ${CMAKE_SOURCE_DIR}/Src/Simulator/Inc
    ${CMAKE_SOURCE_DIR}/Src/Strategy/Inc
)

target_link_libraries(CORE_LIBRARY PRIVATE
Qt6::Core
Qt6::Widgets
)
