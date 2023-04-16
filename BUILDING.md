# Building with CMake

## Dependencies

For a list of dependencies, please refer to [vcpkg.json](vcpkg.json).

## Build

This project doesn't require any special command-line flags to build to keep things simple.

Here are the steps for building in release mode with a single-configuration generator, like the Unix Makefiles one:

```sh
cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake --build build
```

Here are the steps for building in release mode with a multi-configuration generator, like the Visual Studio ones:

```sh 
cmake -S . -B build
cmake --build build --config Release
```

### Building with MSVC

Note that MSVC by default is not standards compliant and you need to pass some flags to make it behave properly. See the `flags-windows` preset in the [CMakePresets.json](CMakePresets.json) file for the flags and with what variable to provide them to CMake during configuration.

### Building on Apple Silicon

CMake supports building on Apple Silicon properly since 3.20.1. Make sure you have the [latest version][1] installed.

## Hacking

Here is some wisdom to help you build and test this project as a developer and potential contributor.

### Developer mode

Build system targets that are only useful for developers of this project are hidden if the `rt-challenge_DEVELOPER_MODE` option is disabled. Enabling this option makes tests and other developer targets and options available. Not enabling this option means that you are a consumer of this project and thus you have no need for these targets and options.

#### Presets

This project makes use of [presets][2] to simplify the process of configuring the project. As a developer, you are recommended to always have the [latest CMake version][1] installed to make use of the latest Quality-of-Life additions.

You have a few options to pass `rt-challenge_DEVELOPER_MODE` to the configure command, but this project prefers to use presets.

As a developer, you should create a `CMakeUserPresets.json` file at the root of the project:

```json
{
    "version": 6,
        "cmakeMinimumRequired": {
            "major": 3,
            "minor": 16,
            "patch": 0
        },
        "configurePresets": [
        {
            "name": "dev",
            "binaryDir": "${sourceDir}/build/dev",
            "inherits": [ "dev-mode", "vcpkg", "ci-<os>" ],
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Debug"
            }
        }
        ],
        "buildPresets": [
        {
            "name": "dev",
            "configurePreset": "dev",
            "configuration": "Debug"
        }
        ],
        "testPresets": [
        {
            "name": "dev",
            "configurePreset": "dev",
            "configuration": "Debug",
            "output": {
                "outputOnFailure": true
            }
        }
        ],
        "workflowPresets": [
        {
            "name": "dev",
            "steps": [
            {
                "type": "configure",
                "name": "dev"
            },
            {
                "type": "build",
                "name": "dev"
            },
            {
                "type": "test",
                "name": "dev"
            }
            ]
        }
        ]
}
```

You should replace `<os>` in your newly created presets file with the name of the operating system you have, which may be `win64` or `unix`. You can see what these correspond to in the [`CMakePresets.json`](CMakePresets.json) file.

`CMakeUserPresets.json` is also the perfect place in which you can put all sorts of things that you would otherwise want to pass to the configure command in the terminal.

#### Dependency manager

The above preset will make use of the [vcpkg][vcpkg] dependency manager. vcpkg is included in the project as a git submodule. On  Windows, you might also want to inherit from the `vcpkg-win64-static` preset,  which will make vcpkg install the dependencies as static libraries. This is  only necessary if you don't want to setup `PATH` to run tests.

[vcpkg]: https://github.com/microsoft/vcpkg

#### Configure, build and test

If you followed the above instructions, then you can configure, build and test the project respectively with the following commands from the project root on any operating system with any build system:

```sh
cmake --preset=dev
cmake --build --preset=dev
ctest --preset=dev
```

Alternatively, you can use the specified workflow preset, with the following command:

```sh
cmake --workflow --preset=dev
```

If you are using a compatible editor (e.g. VSCode) or IDE (e.g. CLion, VS), you will also be able to select the above created user presets for automatic integration.

Please note that both the build and test commands accept a `-j` flag to specify the number of jobs to use, which should ideally be specified to the number of threads your CPU has. You may also want to add that to your preset using the `jobs` property, see the [presets documentation][2] for more details.

#### Developer mode targets

##### `format-check` and `format-fix`

These targets run the clang-format tool on the codebase to check errors and to fix them respectively. Customization available using the `FORMAT_PATTERNS` and `FORMAT_COMMAND` cache variables.

##### `run-exe`

Runs the executable target `rt-exe`.

[1]: https://cmake.org/download/
[2]: https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html
