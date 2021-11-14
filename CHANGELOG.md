# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).
This project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html)
from `1.0.0` onwards. Releases before that with a version matching `0.y.z` may
increment the `minor` version for breaking changes.

## [Unreleased] [Minor]
### Changed
- moved all feature macros from `have_*_.h` into new `patomic_config.h`
- updated include paths
### Added
- `patomic_config.h` (with default macro definitions)
- created `CompilerFeatureChecks.cmake` to check feature macros
- created `cmake/in` directory for `.in` files
- added `patomic_config.h.in` to generate `_patomic_config.h`
- `_patomic_config.h` is then included in `patomic_config.h`
### Removed
- all `have_*_.h` files from `src/include/patomic/macros`

## [0.1.1] [Patch] - 2021-11-14
### Added
- Enable IPO (if supported) when config is not Debug
- Link `libatomic.so` if it exists
### Fixed
- gcc build example now works correctly
### Changed
- Changed `.cmake` file case from `kebab-case` to `PascalCase`

## [0.1.0] [Major] - 2021-10-28
### Added
- Complete `std` implementation
- Mostly complete `msvc` implementation (missing availability checks for old 
  compiler versions)
- Logic testing (does not check for correctness in multi-threaded environments)
- Workflows for GitHub actions (`on-push.yml` and `on-release.yml`)
- CMake files and presets to portably build and install project
- Information files (`README.md`, `ARCHITECTURE.md`, `CHANGELOG.md`)