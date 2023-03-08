itkARGUS
=================================

.. image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
    :target: https://github.com/KitwareMedical/POCUS_AI_ARGUS/blob/master/LICENSE
    :alt: License

Overview
--------

Anatomic Reconstruction for Generalizable UltraSound (ARGUS) AI: A library for point-of-care ultrasound AI using MONAI and ITK.

This library includes the itk-ARGUS extension for ITK.   This extension is based on C++ methods used by the ARGUS library.  The itk-ARGUS methods are implemented in C++ for speed, and then wrapped into python for use in the project.

Build Steps
-----------

Option 1: If you don't have a from-source build of ITK:
1. `git clone --depth=1 https://github.com/InsightSoftwareConsortium/ITKPythonPackage`
2. `./ITKPythonPackage/scripts/dockcross-manylinux-download-cache-and-build-module-wheels.sh`
  - If the command errors with "curl: failed to write body", then `chown -R` the `tools/` folder to be your user. Then, re-run the above command.
3. To rebuild, run `./ITKPythonPackage/scripts/dockcross-manylinux-build-module-wheels.sh`

Option 2: If oyu have a from-source build of ITK:
1. `git clone https://github.com/KitwareMedical/POCUS_AI_ARGUS`
2. `mkdir POCUS_AI_ARGUS-Release`
3. `cd POCUS_AI_ARGUS-Release`
4. `cmake-gui ../POCUS_AI_ARGUS`
  - Make certain to specify CMAKE_BUILD_TYPE=Release.
  - It should automatically find your ITK build directory
5. Compile the project.  It should then be wrapped for python and
  available via import itk.

Usage
-----

Sample usage can be found in `usage/resample.py`. It expects a US video in `video.mp4` and outputs a `output.nrrd` file. Be sure to install the packages found in requirements.txt.
