# Mini-Batch K-means on RCV1 dataset using Dask

The objective of this project was to implement a simplified Mini-Batch K-Means algorithm on the RCV1 dataset, which consists of more than 800k articles. Each article is characterized by over 50k features, resulting in a dataset exceeding 250GB in size. To handle this substantial dataset, we leveraged the Dask library in Python and three Virtual Machines on CloudVeneto cluster, following some initial data reduction assumptions based on Natural Language Processing that brought to the choice of $k=4$. The results have been analyzed considering the best configuration in terms of performances (therefore number of workers, number of partitions, rechunk of the minibatch) instead of focusing on the K-means efficency through dask dashboard analysis, execution time and capacity of the workers.

The project notebook is structured as follows:
1. **Introduction**:<br>
    1.1. Start cluster<br>
    1.2. Dataset<br>
    1.3. Dask Array<br>
    1.4. Preprocessing<br>
    1.5  Filtering the dataset <br>
    1.6  Load filtered data<br>
    1.7  Dataset exploration<br>
    1.8  Sihouette analysis<br>
    1.9  Metrics<br>
2. **Mini Batch Clustering**<br>
    2.1. Architecture and Motivations<br>
    2.2. Toy Example<br>
3. **Results**<br>
    3.1. Mini-Batch size graphs<br>
    3.2. Mini-Batch and predict rechunk graphs<br>
    3.3. Number of workers graphs<br>
    3.4. Is the Euclidean Distance the best objective function for RCV1 dataset?<br>

This project was developed during August and September 2023 for the "Management and Analysis of Physics Dataset Module B" course in the academic year 2022-2023. It was undertaken by Group 19, comprised of:
* Golan Rodrigo
* Guercio Tommaso
* Zoppellari Elena

For consultation please contact: elenazoppellari@gmail.com
