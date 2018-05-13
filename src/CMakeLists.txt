project(hex)

set(HEADER_FILES
        InputProcessor.h)

set(SOURCE_FILES
        InputProcessor.cpp Parser.cpp Parser.h Splitter.cpp Splitter.h Output.cpp Output.h)

add_library(hex STATIC ${SOURCE_FILES} ${HEADER_FILES})