# Let's walk and build binaries

task1_path="reports/task1.txt"
task2_path="reports/task2.txt"
task3_path="reports/task3.txt"
compression_comparison_path="reports/compression_comparison.txt"
width=50

cmd_success_check () {
    if [ $? -ne 0 ]; then
        echo "Process failed."
        exit 1
    else
        echo "Command successful."
    fi
}

if [[ ! -d "src" ]]; then
    echo "Not in the project root."
    exit 1
fi

echo "Walking down to task1..."
cd src/task1/
cmd_success_check

echo "Building task1..."
bash ./build.sh
cmd_success_check

echo "Generating task1 report at $task1_path..."
./out ../../materials/src.txt > ../../"$task1_path"
cmd_success_check

echo "Walking down to task2..."
cd ../task2
cmd_success_check

echo "Building task2..."
bash ./build.sh
cmd_success_check


echo "Generating task2 report at $task2_path..."
./out ../../materials/src.txt | awk -v width=$width '{printf "%-*s\n", width, $0}' > ../../"$task2_path"
cmd_success_check


echo "Walking down to task3..."
cd ../task3
cmd_success_check

echo "Building task3..."
bash ./build.sh
cmd_success_check


echo "Generating task3 report at $task3_path..."
./out ../../materials/src.txt | awk -v width=$width '{printf "%-*s\n", width, $0}' > ../../"$task3_path"
cmd_success_check


echo "Generating compression comparison report..."
echo "Merging task2 and task3 reports..."

cd ../../
paste "$task2_path" "$task3_path" > "$compression_comparison_path"
cmd_success_check

echo "ALL REPORTS READY."

bash ./clean_bins.sh
cmd_success_check
