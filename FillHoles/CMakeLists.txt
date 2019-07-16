
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(FillHoles)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonDataModel
  vtkFiltersCore
  vtkFiltersExtraction
  vtkFiltersGeometry
  vtkFiltersModeling
  vtkFiltersSources
  vtkIOGeometry
  vtkIOLegacy
  vtkIOPLY
  vtkIOXML
  vtkInteractionStyle
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingOpenGL2 QUIET)
if (NOT VTK_FOUND)
  message("Skipping FillHoles: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")
if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  add_executable(FillHoles MACOSX_BUNDLE FillHoles.cxx )
  target_link_libraries(FillHoles PRIVATE ${VTK_LIBRARIES})
else ()
  # include all components
  add_executable(FillHoles MACOSX_BUNDLE FillHoles.cxx )
  target_link_libraries(FillHoles PRIVATE ${VTK_LIBRARIES})
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS FillHoles
    MODULES ${VTK_LIBRARIES}
    )
endif () 
