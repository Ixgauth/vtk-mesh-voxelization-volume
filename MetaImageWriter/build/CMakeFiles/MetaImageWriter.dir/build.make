# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build

# Include any dependencies generated for this target.
include CMakeFiles/MetaImageWriter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MetaImageWriter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MetaImageWriter.dir/flags.make

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o: CMakeFiles/MetaImageWriter.dir/flags.make
CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o: ../MetaImageWriter.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o -c /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/MetaImageWriter.cxx

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/MetaImageWriter.cxx > CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.i

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/MetaImageWriter.cxx -o CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.s

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.requires:

.PHONY : CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.requires

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.provides: CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.requires
	$(MAKE) -f CMakeFiles/MetaImageWriter.dir/build.make CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.provides.build
.PHONY : CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.provides

CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.provides.build: CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o


# Object files for target MetaImageWriter
MetaImageWriter_OBJECTS = \
"CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o"

# External object files for target MetaImageWriter
MetaImageWriter_EXTERNAL_OBJECTS =

MetaImageWriter: CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o
MetaImageWriter: CMakeFiles/MetaImageWriter.dir/build.make
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libz.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libjpeg.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libpng.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libtiff.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkImagingSources-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkInteractionStyle-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersExtraction-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersStatistics-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkImagingFourier-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkalglib-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkRenderingFreeType-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libfreetype.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkRenderingOpenGL2-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkIOImage-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkDICOMParser-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkmetaio-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libz.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkImagingCore-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkRenderingCore-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersSources-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeneral-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonComputationalGeometry-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonColor-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersGeometry-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkFiltersCore-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonExecutionModel-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonDataModel-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonTransforms-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonMisc-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonMath-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonSystem-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtkCommonCore-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libvtksys-7.1.so.7.1.1
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libGLEW.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libSM.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libICE.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libX11.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libXext.so
MetaImageWriter: /usr/lib/x86_64-linux-gnu/libXt.so
MetaImageWriter: CMakeFiles/MetaImageWriter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MetaImageWriter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MetaImageWriter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MetaImageWriter.dir/build: MetaImageWriter

.PHONY : CMakeFiles/MetaImageWriter.dir/build

CMakeFiles/MetaImageWriter.dir/requires: CMakeFiles/MetaImageWriter.dir/MetaImageWriter.cxx.o.requires

.PHONY : CMakeFiles/MetaImageWriter.dir/requires

CMakeFiles/MetaImageWriter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MetaImageWriter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MetaImageWriter.dir/clean

CMakeFiles/MetaImageWriter.dir/depend:
	cd /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build /home/ian/ttk/ttk-data-0.9.3/vtkWork/MetaImageWriter/build/CMakeFiles/MetaImageWriter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MetaImageWriter.dir/depend
