# MadTracker3 CMake File
# Written by Ethan "flibitijibibo" Lee
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MadTracker3)

# Build optjons
option(MT_DEBUG "Build debug version of MadTracker" ON)

# Compiler flags
# TODO: -pedantic
SET(CMAKE_CXX_FLAGS "-m32 -g -Wall")

# Linker flags
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Include directories
include_directories(include)

# Defines
if (MT_DEBUG)
	add_definitions(-D_DEBUG)
endif (MT_DEBUG)

# Source directories
SET(MT3SRCDIR MT3)
SET(MTAUDIOSRCDIR MTAudio)
SET(MTDSPSRCDIR MTDSP)
SET(MTDISPLAYSRCDIR MTDisplay)
SET(MTGUISRCDIR MTGUI)
SET(MTOBJECTSSRCDIR MTObjects)
SET(MTSYSTEMSRCDIR MTSystem)

# Source lists
SET(MT3SRC
	${MT3SRCDIR}/MT3.cpp
	${MT3SRCDIR}/MTConsole.cpp
	${MT3SRCDIR}/MTData.cpp
	${MT3SRCDIR}/MTExtensions.cpp
	${MT3SRCDIR}/MTInterface.cpp
	${MT3SRCDIR}/MTWC_Main.cpp
	${MT3SRCDIR}/MTWC_Main2.cpp
)
SET(MTAUDIOSRC
	${MTAUDIOSRCDIR}/MTAudio.cpp
	${MTAUDIOSRCDIR}/MTAudio1.cpp
	${MTAUDIOSRCDIR}/MTAudio2.cpp
	${MTAUDIOSRCDIR}/MTDevDSP.cpp
	${MTAUDIOSRCDIR}/MTDirectSound.cpp
	${MTAUDIOSRCDIR}/MTWaveOut.cpp
)
SET(MTDSPSRC
	${MTDSPSRCDIR}/MTDSP_main.cpp
	${MTDSPSRCDIR}/MTBufferASM.cpp
	${MTDSPSRCDIR}/MTCatmullASM.cpp
	${MTDSPSRCDIR}/MTDSP.cpp
	${MTDSPSRCDIR}/MTFilterASM.cpp
	${MTDSPSRCDIR}/MTResamplingASM.cpp
	${MTDSPSRCDIR}/MTShaper.cpp
)
SET(MTDISPLAYSRC
	${MTDISPLAYSRCDIR}/MTDisplay_main.cpp
	${MTDISPLAYSRCDIR}/MTDisplay.cpp
	${MTDISPLAYSRCDIR}/MTDisplayDevice.cpp
)
SET(MTGUISRC
	${MTGUISRCDIR}/MTButton.cpp
	${MTGUISRCDIR}/MTCheckBox.cpp
	${MTGUISRCDIR}/MTControl.cpp
	${MTGUISRCDIR}/MTCustControls.cpp
	${MTGUISRCDIR}/MTDesktop.cpp
	${MTGUISRCDIR}/MTEdit.cpp
	${MTGUISRCDIR}/MTGUI.cpp
	${MTGUISRCDIR}/MTGUI1.cpp
	${MTGUISRCDIR}/MTGUITools.cpp
	${MTGUISRCDIR}/MTItems.cpp
	${MTGUISRCDIR}/MTLabel.cpp
	${MTGUISRCDIR}/MTOSSkin.cpp
	${MTGUISRCDIR}/MTOSWindow.cpp
	${MTGUISRCDIR}/MTPanel.cpp
	${MTGUISRCDIR}/MTProgress.cpp
	${MTGUISRCDIR}/MTSign.cpp
	${MTGUISRCDIR}/MTSkin.cpp
	${MTGUISRCDIR}/MTSysControls.cpp
	${MTGUISRCDIR}/MTTabControl.cpp
	${MTGUISRCDIR}/MTToolBar.cpp
	${MTGUISRCDIR}/MTVisual.cpp
	${MTGUISRCDIR}/MTWinControl.cpp
	${MTGUISRCDIR}/MTWindow.cpp
)
SET(MTOBJECTSSRC
	${MTOBJECTSSRCDIR}/MTAutomation.cpp
	${MTOBJECTSSRCDIR}/MTColumns.cpp
	${MTOBJECTSSRCDIR}/MTDelay.cpp
	${MTOBJECTSSRCDIR}/MTEffect.cpp
	${MTOBJECTSSRCDIR}/MTFilter.cpp
	${MTOBJECTSSRCDIR}/MTGenerator.cpp
	${MTOBJECTSSRCDIR}/MTGraphs.cpp
	${MTOBJECTSSRCDIR}/MTIOInstrument.cpp
	${MTOBJECTSSRCDIR}/MTIOModule_MT2.cpp
	${MTOBJECTSSRCDIR}/MTIOOscillator.cpp
	${MTOBJECTSSRCDIR}/MTInstrEditor.cpp
	${MTOBJECTSSRCDIR}/MTInstrument.cpp
	${MTOBJECTSSRCDIR}/MTModule.cpp
	${MTOBJECTSSRCDIR}/MTObject.cpp
	${MTOBJECTSSRCDIR}/MTObjects.cpp
	${MTOBJECTSSRCDIR}/MTObjects1.cpp
	${MTOBJECTSSRCDIR}/MTObjects2.cpp
	${MTOBJECTSSRCDIR}/MTObjectsASM.cpp
	${MTOBJECTSSRCDIR}/MTOscillator.cpp
	${MTOBJECTSSRCDIR}/MTPattEditor.cpp
	${MTOBJECTSSRCDIR}/MTPattManager.cpp
	${MTOBJECTSSRCDIR}/MTPattern.cpp
	${MTOBJECTSSRCDIR}/MTSeqManager.cpp
	${MTOBJECTSSRCDIR}/MTTest.cpp
	${MTOBJECTSSRCDIR}/MTTrack.cpp
	${MTOBJECTSSRCDIR}/MTXMCommands.cpp
)
SET(MTSYSTEMSRC
	${MTSYSTEMSRCDIR}/MTSystem_main.cpp
	${MTSYSTEMSRCDIR}/MTBase64.cpp
	${MTSYSTEMSRCDIR}/MTConfig.cpp
	${MTSYSTEMSRCDIR}/MTFile.cpp
	${MTSYSTEMSRCDIR}/MTHTTPFile.cpp
	${MTSYSTEMSRCDIR}/MTInternet.cpp
	${MTSYSTEMSRCDIR}/MTKernel.cpp
	${MTSYSTEMSRCDIR}/MTLocalFile.cpp
	${MTSYSTEMSRCDIR}/MTMD5.cpp
	${MTSYSTEMSRCDIR}/MTMemoryFile.cpp
	${MTSYSTEMSRCDIR}/MTMiniConfig.cpp
	${MTSYSTEMSRCDIR}/MTResources.cpp
	${MTSYSTEMSRCDIR}/MTSocket.cpp
	${MTSYSTEMSRCDIR}/MTStructures.cpp
	${MTSYSTEMSRCDIR}/MTSystem.cpp
	${MTSYSTEMSRCDIR}/strnatcmp.cpp
)

# Targets

ADD_EXECUTABLE(madtracker3 ${MT3SRC})
TARGET_LINK_LIBRARIES(madtracker3 dl)

ADD_LIBRARY(mtaudio SHARED ${MTAUDIOSRC})
SET_TARGET_PROPERTIES(mtaudio PROPERTIES PREFIX "")

ADD_LIBRARY(mtdsp SHARED ${MTDSPSRC})
SET_TARGET_PROPERTIES(mtdsp PROPERTIES PREFIX "")

ADD_LIBRARY(mtdisplay SHARED ${MTDISPLAYSRC})
SET_TARGET_PROPERTIES(mtdisplay PROPERTIES PREFIX "")
TARGET_LINK_LIBRARIES(mtdisplay SDL)
TARGET_LINK_LIBRARIES(mtdisplay SDL_image)

ADD_LIBRARY(mtgui SHARED ${MTGUISRC})
SET_TARGET_PROPERTIES(mtgui PROPERTIES PREFIX "")
# TODO: Still need to decide on a GUI library

ADD_LIBRARY(mtobjects SHARED ${MTOBJECTSSRC})
SET_TARGET_PROPERTIES(mtobjects PROPERTIES PREFIX "")

ADD_LIBRARY(mtsystem SHARED ${MTSYSTEMSRC})
SET_TARGET_PROPERTIES(mtsystem PROPERTIES PREFIX "")
