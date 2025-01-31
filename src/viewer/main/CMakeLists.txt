# Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
# Project developers.  See the top-level LICENSE file for dates and other
# details.  No copyright assignment is required to contribute to VisIt.

#****************************************************************************
# Modifications:
#  Cyrus Harrison, Tue Jan 10 14:51:38 PST 2012
#  Add link of ${CMAKE_THREAD_LIBS} to the viewer.
#
#  Brad Whitlock, Fri May 18 16:09:34 PST 2012
#  Use different resource file.
#
#  Brad Whitlock, Thu Sep 11 10:45:23 PDT 2014
#  Moved many files to viewercore.
#
#  Kathleen Biagas, Tue Apr 14 14:55:01 MST 2015
#  Only add ViewerSubmitParallEngineToWindowsHPC if we actually have the
#  HPC scheduler.
#
#  Kevin Griffin, Mon Oct 19 09:43:37 PDT 2020
#  Updated the bundle name, icon file name, identifier and copyright
#
#  Eric Brugger, Fri Feb 24 14:57:15 PST 2023
#  Replaced vtkpng with vtkpng_LIBRARIES and vtkjpeg with vtkjpeg_LIBRARIES.
#
#  Kathleen Biagas, Thu Mar 30, 2023
#  Use AUTOMOC target property instead of QT_WRAP_CPP macro.
#
#  Kathleen Biagas, Tue May 5, 2023
#  Disable qt6 forcing of defines for UNICODE.
#
#  Eric Brugger, Tue Jul 25 11:23:55 EDT 2023
#  Change CMAKE_THREAD_LIBS to Threads::Threads.
#
#   Kathleen Biagas, Tue Sep 5, 2023 
#   Remove untested, unused EGL logic.
#
#****************************************************************************

IF(VISIT_PARALLEL AND WIN32 AND HAVE_HPC_SCHEDULER)
    SET(VIEWERLIB_WIN32_SOURCES
        ViewerSubmitParallelEngineToWindowsHPC.cpp
    )
    SET_SOURCE_FILES_PROPERTIES(ViewerEngineManager.C PROPERTIES
        COMPILE_DEFINITIONS VISIT_SUPPORTS_WINDOWS_HPC
    )
ENDIF(VISIT_PARALLEL AND WIN32 AND HAVE_HPC_SCHEDULER)

IF(VISIT_DDT)
SET(VIEWER_DDT
ddt/DDTManager.C
ddt/DDTSession.C
ddt/DDTActions.C
ddt/DDTActionsUI.C
)
ENDIF(VISIT_DDT)

SET(VIEWER_UI
ui/AnimationActionsUI.C
ui/LockActionsUI.C
ui/PlotAndOperatorActionsUI.C
ui/PrintWindowAction.C
ui/SetAppearanceAction.C
ui/ToolbarActionsUI.C
ui/ViewActionsUI.C
ui/ViewerActionManagerUI.C
ui/ViewerActionUI.C
ui/ViewerActionUIMultiple.C
ui/ViewerActionUISingle.C
ui/ViewerActionUIToggle.C
ui/ViewerChangeUsernameUI.C
ui/ViewerConnectionPrinterUI.C
ui/ViewerConnectionProgressDialog.C
ui/ViewerFactoryUI.C
ui/ViewerHostProfileSelectorWithWin.C
ui/ViewerMessagingUI.C
ui/ViewerPasswordWindow.C
ui/ViewerPopupMenu.C
ui/ViewerToolbar.C
ui/ViewerWindowUI.C
ui/VisItChangeUsernameWindow.C
ui/VisItPasswordWindow.C
ui/WindowActionsUI.C
)

SET(VIEWERLIB_SOURCES
${VIEWER_UI}
${VIEWER_DDT}
SharedDaemon.C
ViewerBaseUI.C
ViewerClientConnection.C
ViewerCommandFromSimObserver.C
ViewerEngineManager.C
ViewerEngineManagerImplementation.C
ViewerFactoryMain.C
ViewerFileServer.C
ViewerFileServerImplementation.C
ViewerMasterXfer.C
ViewerMetaDataObserver.C
ViewerObserverToSignal.C
ViewerSILAttsObserver.C
ViewerServerManager.C
ViewerStateBuffered.C
ViewerSubject.C
VisItViewer.C
WebSocketConnection.C
${VIEWERLIB_WIN32_SOURCES}
)

# If the viewer is static then we need some static symbol lookup functions
IF(VISIT_STATIC)
    SET(VIEWER_STATIC_SOURCES ViewerStaticSymbolLocator.C)
ENDIF(VISIT_STATIC)

IF (NOT WIN32)
    # This keeps comm's exceptions visible when using -fvisibility=hidden
    ADD_DEFINITIONS(-DCOMM_EXPORTS)
ENDIF (NOT WIN32)

INCLUDE_DIRECTORIES(
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/ui
${CMAKE_CURRENT_SOURCE_DIR}/ddt
${VISIT_COMMON_INCLUDES}
${VISIT_SOURCE_DIR}/viewer/rpc
${VISIT_SOURCE_DIR}/viewer/core
${VISIT_SOURCE_DIR}/viewer/core/actions
${VISIT_SOURCE_DIR}/avt/DBAtts/MetaData
${VISIT_SOURCE_DIR}/avt/DBAtts/SIL
${VISIT_SOURCE_DIR}/avt/Database/Database
${VISIT_SOURCE_DIR}/avt/FileWriter
${VISIT_SOURCE_DIR}/avt/Filters
${VISIT_SOURCE_DIR}/avt/Math
${VISIT_SOURCE_DIR}/avt/Pipeline/AbstractFilters
${VISIT_SOURCE_DIR}/avt/Pipeline/Data
${VISIT_SOURCE_DIR}/avt/Pipeline/Pipeline
${VISIT_SOURCE_DIR}/avt/Pipeline/Sinks
${VISIT_SOURCE_DIR}/avt/Pipeline/Sources
${VISIT_SOURCE_DIR}/avt/Plotter
${VISIT_SOURCE_DIR}/avt/Plotter/vtk
${VISIT_SOURCE_DIR}/avt/QtVisWindow
${VISIT_SOURCE_DIR}/avt/View
${VISIT_SOURCE_DIR}/avt/VisWindow/Colleagues
${VISIT_SOURCE_DIR}/avt/VisWindow/Interactors
${VISIT_SOURCE_DIR}/avt/VisWindow/Proxies
${VISIT_SOURCE_DIR}/avt/VisWindow/Tools
${VISIT_SOURCE_DIR}/avt/VisWindow/VisWindow
${VISIT_SOURCE_DIR}/engine/proxy
${VISIT_SOURCE_DIR}/engine/rpc
${VISIT_SOURCE_DIR}/launcher/proxy
${VISIT_SOURCE_DIR}/launcher/rpc
${VISIT_SOURCE_DIR}/mdserver/proxy
${VISIT_SOURCE_DIR}/mdserver/rpc
${VISIT_SOURCE_DIR}/visit_vtk/full
${VISIT_SOURCE_DIR}/vtkqt
${VISIT_SOURCE_DIR}/winutil
${VTK_INCLUDE_DIRS}
)


if(HAVE_OSMESA)
    include_directories(${VISIT_SOURCE_DIR}/visit_vtk/offscreen)
endif()

LINK_DIRECTORIES(${LIBRARY_OUTPUT_DIRECTORY})


#*************************** The viewer library ******************************
ADD_LIBRARY(viewer ${VIEWERLIB_SOURCES})

set_target_properties(viewer PROPERTIES AUTOMOC ON)

IF (WIN32)
    SET_TARGET_PROPERTIES(viewer PROPERTIES OUTPUT_NAME viewerlib)
ENDIF (WIN32)

SET(VIEWER_QT_LIBS 
${QT_QTGUI_LIBRARY}
${QT_QTOPENGL_LIBRARY}
${QT_QTCORE_LIBRARY}
${QT_QTNETWORK_LIBRARY}
)
IF(VISIT_STATIC)
    SET(VIEWER_QT_LIBS 
        ${VIEWER_QT_LIBS}
        ${QT_QTGUI_LIB_DEPENDENCIES}
        ${QT_QTOPENGL_LIB_DEPENDENCIES}
        ${QT_QTCORE_LIB_DEPENDENCIES}
        ${QT_QTNETWORK_LIB_DEPENDENCIES}
    )
ENDIF(VISIT_STATIC)

set(vtkqtlib VTK::GUISupportQt)


if(QT_VERSION VERSION_GREATER_EQUAL "6.2.0")
    qt6_disable_unicode_defines(viewer)
endif()

TARGET_LINK_LIBRARIES(viewer 
viewerrpc
viewercore_ser
visitcommon
mdserverrpc
mdserverproxy
vclrpc
vclproxy
enginerpc
engineproxy
avtdbatts
avtview
avtmath
avtpipeline_ser
avtplotter_ser
avtfilters_ser
avtviswindow_ser
avtwriter_ser
avtqtviswindow
winutil
${VIEWER_QT_LIBS}
Threads::Threads
${vtkqtlib}
)

if(HAVE_OSMESA)
    target_link_libraries(viewer visit_vtk_offscreen)
endif()

#*************************** The viewer executable ***************************
IF(NOT APPLE)
    ADD_EXECUTABLE(viewer_exe ${VISIT_APPLICATION_STYLE} viewer.C ${VIEWER_STATIC_SOURCES} ${VISIT_VIEWER_RESOURCE_FILE})
ELSE(NOT APPLE)
    SET(VIEWER_ICON_FILE VisItIcon.icns)
    SET_SOURCE_FILES_PROPERTIES(${VISIT_SOURCE_DIR}/common/icons/${VIEWER_ICON_FILE} PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )

    ADD_EXECUTABLE(viewer_exe MACOSX_BUNDLE viewer.C ${VIEWER_STATIC_SOURCES} ${VISIT_SOURCE_DIR}/common/icons/${VIEWER_ICON_FILE})
    
    SET_TARGET_PROPERTIES( viewer_exe PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${VISIT_SOURCE_DIR}/include/ViewerInfo.plist.in)
    SET(MACOSX_BUNDLE_BUNDLE_NAME          "VisIt Viewer ${VISIT_VERSION}")
    SET(MACOSX_BUNDLE_INFO_STRING          "Graphical viewer for VisIt")
    SET(MACOSX_BUNDLE_ICON_FILE            ${VIEWER_ICON_FILE})
    SET(MACOSX_BUNDLE_VIEWER_IDENTIFIER       "gov.llnl.visit.viewer")
    SET(MACOSX_BUNDLE_LONG_VERSION_STRING  "VisIt version ${VISIT_VERSION}")
    SET(MACOSX_BUNDLE_SHORT_VERSION_STRING "VisIt ${VISIT_VERSION}")
    SET(MACOSX_BUNDLE_BUNDLE_VERSION       ${VISIT_VERSION})
    SET(MACOSX_BUNDLE_COPYRIGHT            "Copyright (c) 2000 - 2024, Lawrence Livermore National Security, LLC")
    
    IF(VISIT_STATIC)
        MAC_NIB_INSTALL(viewer)
    ENDIF(VISIT_STATIC)
ENDIF(NOT APPLE)

SET_TARGET_PROPERTIES(viewer_exe PROPERTIES OUTPUT_NAME viewer)

TARGET_LINK_LIBRARIES(viewer_exe
    ${viewer_exe_IOperator}
    ${viewer_exe_VOperator}
    ${viewer_exe_IPlot}
    ${viewer_exe_VPlot}
    viewer
    ${vtkpng_LIBRARIES}
    ${vtkjpeg_LIBRARIES}
)

# If we're building statically then the viewer can't be linked until the plugin
# sources are built
IF(VISIT_STATIC)
    ADD_DEPENDENCIES(viewer_exe
        ${viewer_exe_IOperator}
        ${viewer_exe_VOperator}
        ${viewer_exe_IPlot}
        ${viewer_exe_VPlot}
    )
ENDIF(VISIT_STATIC)

VISIT_INSTALL_TARGETS(viewer_exe viewer)
