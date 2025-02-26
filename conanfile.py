from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.cmake import cmake_layout

class PysortBuild(ConanFile):
    name = "the_sort"
    version = "1.0"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    requires = "fmt/11.0.2", "nlohmann_json/3.11.3"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()