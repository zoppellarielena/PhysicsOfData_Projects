# Mini-Batch K-means on RCV1 dataset using Dask

The objective of this project was to implement a simplified Mini-Batch K-Means algorithm on the RCV1 dataset, which consists of more than 800k articles. Each article is characterized by over 50k features, resulting in a dataset exceeding 250GB in size. To handle this substantial dataset, we leveraged the Dask library in Python, following some initial data reduction assumptions.

The project notebook is structured as follows:
1. **Introduction**:
    1.1. Start cluster
    1.2. Dataset
    1.3. Dask Array
    1.4. Preprocessing
    1.5  Filtering the dataset 
    1.6  Load filtered data
    1.7  Dataset exploration
    1.8  Sihouette analysis
    1.9  Metrics
2. **Mini Batch Clustering**
    2.1. Architecture and Motivations
    2.2. Toy Example
3. **Results**
    3.1. Mini-Batch size graphs
    3.2. Mini-Batch and predict rechunk graphs
    3.3. Number of workers graphs
    3.4. Is the Euclidean Distance the best objective function for RCV1 dataset?

This project was developed during August and September 2023 for the "Management and Analysis of Physics Dataset Module B" course in the academic year 2023-2024. It was undertaken by Group 19, comprised of:
* Golan Rodrigo
* Guercio Tommaso
* Zoppellari Elena

For consultation please contact: elenazoppellari@gmail.com
