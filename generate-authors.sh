AUTHORS_FILE="AUTHOR"

# Get all unique author names from git commit history
git log --format='%aN' | sort -u > "$AUTHORS_FILE"

echo "successfully: $AUTHORS_FILE"

