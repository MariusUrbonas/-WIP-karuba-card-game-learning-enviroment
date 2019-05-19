
include_directories(${GOOGLE_TEST_HOME}/include ${GOOGLE_TEST_HOME})

add_executable(runBasicKarubaTests
        card_test.cpp
        hand_test.cpp)

target_link_libraries(runBasicKarubaTests
        gtest
        gtest_main)

