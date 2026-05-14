param([Parameter(Mandatory)][string]$Version)

$ErrorActionPreference = 'Stop'

$tag = "v$Version"
Write-Host "Starting release for version $Version..."

# Verify we're in the repo root
if (-not (Test-Path '.git')) {
    throw "Not in git repo root (no .git directory found)"
}

# Ensure branches exist locally
Write-Host "Fetching no-queues-synchronous from origin..."
git fetch origin no-queues-synchronous 2>$null

# Derive async lib-only branch from main
Write-Host "Creating $tag-async-lib from main..."
git checkout main
$asyncSha = git subtree split --prefix=libtc6
git branch -f libtc6 $asyncSha

# Derive sync lib-only branch from no-queues-synchronous
Write-Host "Creating $tag-sync-lib from no-queues-synchronous..."
git checkout no-queues-synchronous
$syncSha = git subtree split --prefix=libtc6
git branch -f libtc6-sync $syncSha

git checkout main

# Tag all 4 trees
Write-Host "Creating tags..."
git tag "$tag-async" main
git tag "$tag-async-lib" libtc6
git tag "$tag-sync" no-queues-synchronous
git tag "$tag-sync-lib" libtc6-sync

# Push branches and tags
Write-Host "Pushing branches and tags to origin..."
git push origin main no-queues-synchronous libtc6 libtc6-sync
git push origin "$tag-async" "$tag-async-lib" "$tag-sync" "$tag-sync-lib"

Write-Host ""
Write-Host "✓ Released $tag across all 4 trees."
Write-Host ""
Write-Host "Tags created:"
Write-Host "  $tag-async        → main"
Write-Host "  $tag-async-lib    → libtc6"
Write-Host "  $tag-sync         → no-queues-synchronous"
Write-Host "  $tag-sync-lib     → libtc6-sync"
