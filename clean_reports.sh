if [[ ! -d "src" ]]; then
    echo "Not in the project root."
    exit 1
fi

echo "Cleaning reports..."
rm -rf ./reports/*
if [ $? -ne 0 ]; then
    echo "Process failed."
    exit 1
else
    echo "Command successful."
fi
