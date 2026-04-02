$src = "C:\Users\Shreyasi Sarkar\Documents\opencode\Ipp\temp_extract\Ipp-main"
$dst = "C:\Users\Shreyasi Sarkar\Documents\opencode\Ipp"

Get-ChildItem -Path $src | ForEach-Object {
    $destPath = Join-Path $dst $_.Name
    if ($_.Name -eq ".git") { return }
    if (Test-Path $destPath) {
        Remove-Item $destPath -Recurse -Force
    }
    Copy-Item -Path $_.FullName -Destination $dst -Recurse -Force
    Write-Host "Copied: $($_.Name)"
}
Write-Host "Done copying files."
