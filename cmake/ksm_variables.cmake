
include(GNUInstallDirs)

set(KSM_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})
set(KSM_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR})
set(KSM_INSTALL_DATADIR ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
set(KSM_INSTALL_INCLUDE ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
set(GETTEXT_PACKAGE ${PROJECT_NAME})

option(SUPPORT_CAJA "Support caja file manager" OFF)

list(APPEND KSM_COMPILER_FLAGS
  -Wno-parentheses                # Disable parentheses warning
)