cmake_minimum_required(VERSION 3.22)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME mc_triorb)
set(PROJECT_DESCRIPTION "TriOrb omnidirectional base robot module for mc_rtc")
set(PROJECT_URL "")

project(
  ${PROJECT_NAME}
  LANGUAGES CXX
  VERSION 1.0.0)
include(CTest)
enable_testing()

if(MSVC AND _VCPKG_INSTALLED_DIR)
  set(VCPKG_INSTALL_PREFIX "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_PREFIX}")
  # Only debug actually exists but we make sure it's first in that case
  set(CMAKE_MSVCIDE_RUN_PATH
      "${VCPKG_INSTALL_PREFIX}/\$(Configuration)/bin;${VCPKG_INSTALL_PREFIX}/bin;${CMAKE_MSVCIDE_RUN_PATH}"
  )
endif()

find_package(mc_rtc REQUIRED)

# Locate the triorb description package (provides urdf/triorb.urdf). This sets
# the MC_TRIORB_DESCRIPTION_PATH variable.
find_description_package(mc_triorb_description REQUIRED)

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
