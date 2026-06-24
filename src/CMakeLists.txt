# Here we find the triorb description package, this sets the
# MC_TRIORB_DESCRIPTION_PATH CMake variable
find_description_package(mc_triorb_description)
if(EXISTS "${MC_TRIORB_DESCRIPTION_PATH}/share/mc_triorb_description")
  set(MC_TRIORB_DESCRIPTION_PATH
      "${MC_TRIORB_DESCRIPTION_PATH}/share/mc_triorb_description")
endif()

# Generate the config header carrying the description path
configure_file(config.in.h
               "${CMAKE_CURRENT_BINARY_DIR}/include/mc_triorb/config.h")

set(triorb_SRC triorb.cpp)
set(triorb_HDR triorb.h)

add_robot(triorb ${triorb_SRC} ${triorb_HDR})
target_include_directories(
  triorb PUBLIC $<INSTALL_INTERFACE:include>
                $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)
target_include_directories(
  triorb PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

install(FILES ${triorb_HDR}
              "${CMAKE_CURRENT_BINARY_DIR}/include/mc_triorb/config.h"
        DESTINATION include/mc_triorb)
