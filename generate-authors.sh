#!/bin/bash

# Output file path for the authors file
AUTHORS="AUTHORS"

# Get all unique author names from git commit history
git log --format='%aN' | sort -u > "$AUTHORS"

echo "Authors file generated: $AUTHORS"

