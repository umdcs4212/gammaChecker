## Gamma Check Image Generator

This small snippet of code will generate a gamma check image for you to use to test the gamma on your monitor, based on the discussions and demonstrations in class.

### How to Build

The project uses CMake and VCPkg to manage dependencies.


```
cd <path/to/this source>
cmake --preset=default
```

# vcpkg - Generalized Build Instructions for Windows, macos and Linux

Once you have some of the items above, it's time to make sure you've got vcpkg ready on your development machine.

We support a more generalized build system using vcpkg [https://learn.microsoft.com/en-us/vcpkg/get_started/overview](https://learn.microsoft.com/en-us/vcpkg/get_started/overview) and CMake build presets. Vcpkg is a C++ package manager used to pull the dependencies needed to build this code. When used in this way, the cmake build system will pull the needed requirements and not rely on installed system dependencies (meaning you shouldn't have to install all sorts of things, ideally). This can result in the initial build being a little slower as the required dependencies are pulled and compiled, but it does mean that you do not have to manually install our dependencies.

## Setting up vcpkg

To setup vcpkg, you will need to clone the vcpkg repository and setup environment variables that CMake can use to locate your vcpkg install.  More information on vcpkg and specific details for setting it up on different systems (Windows vs. Linux-based systems) can be found here: [https://learn.microsoft.com/en-us/vcpkg/get_started/overview](https://learn.microsoft.com/en-us/vcpkg/get_started/overview). 

Determine a location where you want vcpkg installed. It can be in system location for all users or cloned into your own user account. After cloning, be sure to run the bootstrap batch file in the vcpkg folder.

### TLDR; On Windows

Using git-bash, change directories to where you store your development files. Then, clone vcpkg, as shown below:

```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
```

Next, you will need to create the VCPKG_ROOT environment variable to point to the location of the vcpkg local repository on your system. You should also add the vcpkg root to your PATH variable. The following focuses on Windows, but the same ideas are needed on Unix systems and your shell's environment variables. On Windows, the ideal way to do this so that it is permanent is to set the variables using the Windows System Environment Variables panel from Settings. You can get to this by searching for Environment in the Windows menu. You will need something like the following:

```
VCPKG_ROOT = "C:\path\to\vcpkg"
```
Then, make sure the VCPKG_ROOT is also in your user Path variable.  You should be able to just add another folder path to the VCPKG_ROOT location.

You will need to quit your Powershell (or git-bash) after this and bring up a new window so the PATH variable information gets propoated.


### TLDR; On Linux and macOS

Using a terminal, change directories to where you store your development files. Then, clone vcpkg, as shown below:

```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
```

Next, you will need to create the VCPKG_ROOT environment variable to point to the location of the vcpkg local repository on your system. You should also add the vcpkg root to your PATH variable. On Linux, you will need to determine which shell environment you use.  For bash, you would edit the ~/.bashrc file, and modify the PATH variable a bit, as shown below:

```
export VCPKG_ROOT=/home/willemsn/dev/vcpkg
export PATH="$PATH":"$VCPKG_ROOT"
```

The instructions are similar for macOS. Determine which shell you use (typically zsh), and then add similar lines to the ~/.zprofile file.

Then, when you restart your terminals, you should be able to run the vcpkg program:
```
vcpkg
```



