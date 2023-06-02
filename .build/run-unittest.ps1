<#
.DESCRIPTION
Runs unit tests on Windows
#>

# Standard boilerplate
Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$PSDefaultParameterValues['*:ErrorAction']='Stop'

Push-Location ..\build

# Use ctest
#ctest -C Debug --output-on-failure

# Run gtest-generated binary directly, produces more detailed output
./tests/Debug/unittest.exe

Pop-Location
