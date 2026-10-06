# pylint: disable-all

import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain


class Fasafu(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires(
            "spdlog/1.17.0", options={"use_std_fmt": True, "no_exceptions": True}
        )
        self.requires("cli11/2.6.2")
        self.requires("spdlog/1.17.0", options={"use_std_fmt": True, "no_exceptions": True})
