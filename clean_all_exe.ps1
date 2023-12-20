# Set-Location ./bin
# Remove-Item *.exe
# Set-Location ..
$targetPath=Get-ChildItem D:\cppfiles -Filter "bin" -Recurse | 
Select-Object -ExpandProperty FullName 
$cnt=0
foreach ($dir in $targetPath) {
    $exes=Get-ChildItem $dir -Filter *.exe | Select-Object -ExpandProperty FullName 
    $cnt=$cnt+$exes.Count
    $exes | Remove-Item
}
Write-Host find $cnt exe files"," all removed.