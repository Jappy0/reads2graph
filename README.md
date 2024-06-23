# reads2graph
[![GitHub Release](https://img.shields.io/github/v/release/jappy0/reads2graph)](https://github.com/Jappy0/reads2graph/releases/tag/reads2graph-v1.0.0)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.11388496.svg)](https://doi.org/10.5281/zenodo.11388496)
[![Conda Platform](https://img.shields.io/conda/p/bioconda/reads2graph?style=flat&label=bioconda&labelColor=orange&color=blue)](https://anaconda.org/bioconda/reads2graph)

reads2graph is a practical method for constructing an edit-distance-based read graph for a short-read sequencing dataset via minimizer and order min hash bucketing and graph traversal.

## Installation
### From ```bioconda```
#### Create an environment and install reads2graph via ```conda```

Note: reads2graph installed from ```bioconda``` currently only support linux-64

Add the necessary channels if you are not currently using them.
```
conda config --add channels bioconda
conda config --add channels conda-forge
```

```
conda create -n reads2graph-env
conda activate reads2graph-env
conda install bioconda::reads2graph
```

### From source codes
#### Create an environment and Install dependencies via ```conda```

Note: Given that reads2graph depends on the Seqan3, Boost, and Sharg libraries, and requires a modern C++20 supported compiler, it is recommended to use the Conda environment for configuring and compiling this software, rather than relying on the default compiler of the Linux system. 

Add the necessary channels if you are not currently using them.
```
conda config --add channels bioconda
conda config --add channels conda-forge
```

```
conda create -n reads2graph-env
conda activate reads2graph-env
conda install cmake==3.27.6 gxx_linux-64==13.2.0 sharg==1.1.1 seqan3==3.3.0 boost==1.82.0 openmp==8.0.1
```
#### Compile read2graph
```
git clone https://github.com/Jappy0/reads2graph.git
cd reads2graph
mkdir build
cd build
cmake ..
make
```

## Example

### Installing reads2graph from source codes
```
cd ..
cd example
../bin/reads2graph -i ./data/SRR1543965.umi.fasta -o ./ -x 2 -n 1 -p 64 -k 4 --window_number 2 --omh_times 4 --omh_k 4
```
### Installing reads2graph from ```bioconda```
download the example data(SRR1543965.umi.fasta) from this repo
```
wget https://github.com/Jappy0/reads2graph/blob/main/example/data/SRR1543965.umi.fasta
```
```
reads2graph -i ./SRR1543965.umi.fasta -o ./ -x 2 -n 1 -p 64 -k 4 --window_number 2 --omh_times 4 --omh_k 4
```
### Expected results
Note: The date, time, and commands will reflect the current state when you execute `reads2graph'. The example process will be finished in about 4 minutes by using 64 CPU cores. 

```
2024-05-23 22:46:56: INFO: Welcome to use reads2graph!
2024-05-23 22:46:56: INFO: ../../bin/reads2graph -i ../../data/12/SRR1543964.umi.fasta -o ./ -x 2 -n 1 -p 64 -k 4 --window_number 2 --omh_times 4 --omh_k 4
2024-05-23 22:46:56: INFO: The number of threads: 64 
2024-05-23 22:47:08: INFO: Loading data done!
2024-05-23 22:47:08: INFO: The number of unique reads: 99727, minimum read length: 12.
2024-05-23 22:47:08: INFO: Number of windows: 2, Window size: 6, K size: 4.
2024-05-23 22:49:08: INFO: Pairwise comparison for the small- or medium-size-based buckets done!
2024-05-23 22:49:09: INFO: The number of edges with weight of 1: 196559.
2024-05-23 22:49:09: INFO: The number of edges with weight of 2: 1948494.
2024-05-23 22:49:09: INFO: The total number of edges: 2145053.
2024-05-23 22:49:09: INFO: The number of edges with weight of 1: 196559.
2024-05-23 22:49:09: INFO: The number of edges with weight of 2: 1948494.
2024-05-23 22:49:09: INFO: The total number of edges: 2145053.
2024-05-23 22:49:11: INFO: Bucketing unique reads using OMH done!
2024-05-23 22:50:36: INFO: Graph update for the small- or medium-size-based buckets generated by OMH bucketing done!
2024-05-23 22:50:36: INFO: The number of edges with weight of 1: 196559.
2024-05-23 22:50:36: INFO: The number of edges with weight of 2: 2052195.
2024-05-23 22:50:36: INFO: The total number of edges: 2248754.
2024-05-23 22:50:36: INFO: Edit-distance-based read graph construction done!
```

## Parameters Configuration

### Constructing read graph
If you are constructing graphs for short reads (e.g., with read lengths between 50bp and 300bp), you may only need to customise the following paramters following your needs. Using all the other parameters as default, we have optimised this for you. 

    -x, --max_edit_dis (unsigned 8 bit integer)
          The maximum edit distance for constructing edges between reads Default: 2.
    -n, --min_edit_dis (unsigned 8 bit integer)
          The minimum edit distance for constructing edges between reads. Default: 1.
    -p, --num_process (signed 32 bit integer)
          The number of expected processes. Default: 26.

### Constructing UMI graph
If you are constructing UMI graphs, you must input the following parameters by yourself, as some of the defaults may not work for UMIs. 

    -k, --k_size (unsigned 8 bit integer)
          The size for minimiser. Default: 4.
    -w, --window_number (unsigned 8 bit integer)
          The window number for minimiser. Default: 3.
    -x, --max_edit_dis (unsigned 8 bit integer)
          The maximum edit distance for constructing edges between reads Default: 2.
    -n, --min_edit_dis (unsigned 8 bit integer)
          The minimum edit distance for constructing edges between reads. Default: 1.
    --omh_k (unsigned 32 bit integer)
          K-mer size used in order min hashing. Default: 4.
    --omh_times (unsigned 32 bit integer)
          The number of times to perform permutation in order min hashing. Default: 3.
    -p, --num_process (signed 32 bit integer)
          The number of expected processes. Default: 26.

### Print help
Please use the following commands to view all the options if you need

```
reads2graph -h
```
installed from ```bioconda```

or 

```
xx/bin/reads2graph -h
```
installed from Source codes

#### Expected outputs
```
2024-06-22 13:57:19: INFO: Welcome to use reads2graph!
2024-06-22 13:57:19: INFO: reads2graph -h
reads2graph - Construction of edit-distance graphs from a set of short reads.
=============================================================================

DESCRIPTION
    Construction of edit-distance graphs from large scale sets of short reads through minimizer- and gOMH-bucketing
    and graph traversal.

OPTIONS
    -i, --input_data (std::filesystem::path)
          Please provide a fasta/fastq/ data file. Default: "".
    -o, --output_dir (std::filesystem::path)
          The directory for outputs. Default: "/data/pping/Repo/reads2graph".
    -r, --read_length (unsigned 32 bit integer)
          No need to input this parameter, reads2graph will calculate the minimum read length. Default: 0.
    -k, --k_size (unsigned 8 bit integer)
          The size for minimiser. Default: 4.
    -w, --window_number (unsigned 8 bit integer)
          The window number for minimiser. Default: 3.
    -x, --max_edit_dis (unsigned 8 bit integer)
          The maximum edit distance for constructing edges between reads Default: 2.
    -n, --min_edit_dis (unsigned 8 bit integer)
          The minimum edit distance for constructing edges between reads. Default: 1.
    -p, --num_process (signed 32 bit integer)
          The number of expected processes. Default: 26.
    --pair_wise (bool)
          Brute Force calcualte the pairwise edit distance. Default: 0.
    --bin_size_max (unsigned 32 bit integer)
          The larger threshold used to group buckets of different sizes. Default: 10000.
    --omh_k (unsigned 32 bit integer)
          K-mer size used in order min hashing. Default: 4.
    --omh_times (unsigned 32 bit integer)
          The number of times to perform permutation in order min hashing. Default: 3.
    --omh_seed (unsigned 64 bit integer)
          The seed to generate a series of seeds for OMH bucketing. Default: 2024.
    --omh_flag (bool)
          Do not set this flag by yourself. When the permutation_times larger than the number of k-mer candidates and
          the kmer size are the same one, bucketing the reads using each kmer candidate. Default: 0.
    --bad_kmer_ratio (double)
          The maximum ratio of bad k-mers out of total number of kmers in a window of a read. Default: 0.3.
    --probability (double)
          The expected probability P for grouping two similar reads into same bucket by at least one minimiser that
          does not include the different bases Default: 0.86.
    --visit_depth (unsigned 32 bit integer)
          The maximum distance of nodes from the give node for updating more potential edges. Default: 15.
    --save_graph (bool)
          If ture, reads2graph will save graph to file in graphviz dot format. Default: 0.

VERSION
    Last update: 04.06.2024
    reads2graph version: 1.0.0
    Sharg version: 1.1.1
    SeqAn version: 3.3.0

LEGAL
    reads2graph Copyright: BSD 3-Clause License
    Author: Pengyao Ping
    SeqAn Copyright: 2006-2023 Knut Reinert, FU-Berlin; released under the 3-clause BSDL.
    For full copyright and/or warranty information see --copyright.
```

## Question

Feel free to contact me if you have any questions or bugs on runnning reads2graph or are interested in reads2graph

