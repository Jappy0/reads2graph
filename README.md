# reads2graph
reads2graph is a practical method for constructing an edit-distance-based read graph for a short-read sequencing dataset via minimizer and order min hash bucketing and graph traversal.

## Installation
### From bioconda
#### Create an environment and install reads2graph via conda
```
conda create -n reads2graph-env
conda activate reads2graph-env
conda install bioconda::reads2graph
```

### From source
#### Create an environment and Install dependencies via conda
```
conda create -n reads2graph-env
conda activate reads2graph-env
conda install -c conda-forge cmake>=3.21 gxx_linux-64==13.2.0 seqan3==3.3.0 sharg==1.1.1 libboost==1.82.0 openmp==8.0.1
```
#### Compile read2graph
```
https://github.com/Jappy0/reads2graph.git
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
### Installing reads2graph from bioconda
download the example data(SRR1543965.umi.fasta) from this repo
```
wget https://github.com/Jappy0/reads2graph/blob/main/example/data/SRR1543965.umi.fasta
```
```
reads2graph -i ./SRR1543965.umi.fasta -o ./ -x 2 -n 1 -p 64 -k 4 --window_number 2 --omh_times 4 --omh_k 4
```
### Expected results
Note: The date, time, and commands will reflect the current state when you execute `reads2graph'. The example process will be finished in about 4 minutes. 

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