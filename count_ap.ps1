$cpp_files=Get-ChildItem D:\cppfiles -Filter *.cpp -Recurse
Write-Host find ($cpp_files.Count) cpp files.
