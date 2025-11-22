## DSA HW3: HashTable using separate chaining and compression functions

```
Ownership Note.

I, as the author of this work, confirm my sole ownership over this property
and that no code/idea/design&decision/documenetation/assistance was included from AI excluding
two minor exception cases (look below).
```

* tricky case of bash scripting: merging files while ensuring they're padded for consistency. I learned how to do so from AI using `awk` utility. Still, I wrote the solution/code and included additions.
* some logic errors were caught with the help of AI.


**Tip:** I included bash scripts for better experience (ex.: automated report generation). Go to [Quick Tips](#quick-tips).


### About benchmarking
For benchmarking purposes, 1999 & 2003 (both prime) were chosen as the size of a hash table for two tests. Though there was no specification of chosing more than one size, I was interested in how would the collisions and their extrema behave as the size changed.

For calculating collisions, algorithm of summing up `current_bucket_size - 1` for all buckets with `size > 1` was used.

For MAD compression, arbitrary constants a=11 and b=23 (both prime, a mod size != 0) were used.

### Notes on Load Factors in this settings
```

Size = 1999
lf = 4011/1991 = ~2.0146

Size = 2003
lf = 4011/2003 = ~2.0025

Not good, but it is still very fast since the report shows maximum hash collision bucket with size < 10 on naive compression.

```

### Summary of the findings

```
Size = 1999
Keys = 4011

Compression: Naive

Max collisions: 2297 (a=39)
Min collisions: 2279 (a=41)

Compression: MAD

Max collisions: 2301 (a=33)
Min collisions: 2279 (a=37)

Size = 2003
Keys = 4011

Compression: Naive

Max collisions: 2281 (a=37)
Min collisions: 2242 (a=33)

Compression: MAD

Max collisions: 2282 (a=37)
Min collisions: 2266 (a=41)
```

In conclusion, it is impossible to define which polynomial constant or compression is better as the data set is too much small. For instance, a=33 was expected to be better, but in this benchmarking -- clearly, no. Also, this shows that the naive method is better than MAD.

Therefore, this data is inconclusive due to scarcity of information and diversity.

### Quick Tips
- ATTENTION: all reports are contained in the `./reports` directory
- If there is `build.sh` in any directory, it means you can build files there, and the created binary is named as `out`.
    - **Note:** the place where you run them is important!
- The binaries for `task1`, `task2`, and `task3` accept the data file path as command line argument.
- Run `bash gen_reports.sh` from the project root to **generate reports automatcally**.
    * **Note:** you can find the resulting files in `./reports` directory.
- Run `bash clean_bins.sh` to remove the binary files named `out` from the project.
- Run `bash clean_reports.sh` to remove any file in `./reports`.

### Structure

- hashtable
    * includes implementations of the underlying hash table
- hashutils
    * implementations of Compression interface and specific compression classes
    * polynomial accumulation function implementation
- utils
    * utility functions including:
        * function to populate a hash table from a file
        * other printing utilities
- src
    * the directory for tasks
    - common
        * implementation of the benchmarker with flexibility of plugging in different compression functions
    - task1
        * prints what was specified in task1 of the homework
    - task2
        * benchmarks collisions for different polynomial accumulation constant values with `naive compression function` (I call so)
    - task3
        * repeats task2 with `MAD compression function`
- reports
    * this directory contains the reports
    - `compression_comparison.txt` contains `task2.txt` and `task3.txt` contents merged for comparison

Author: Oyatillo Axadjonov