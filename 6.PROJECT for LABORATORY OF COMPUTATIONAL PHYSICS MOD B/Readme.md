# Rainfall-runoff modeling using Deep Learning
Rainfall-runoff modeling is a long-standing challenge in hydrological sciences, with various approaches attempted over time. 
However, the computational costs and reliability of existing models remain issues, leading to the use of less complex but less reliable models.

In this project, Long Short-Term Memory (LSTM) networks have been used to address this challenge. 
Our main objective is to integrate the training of an LSTM neural network with summary statistics provided by an encoder. 
The goal is to assess whether the encoder, capturing the key characteristics of different hydrological basins, can improve predictions for basins with limited information.

For this analysis, the CAMELS dataset (Catchment Attributes for Large-Sample Studies) was chosen, consisting of daily meteorological data and measured discharge for 
671 minimally disturbed catchments across the United States. 
The dataset spans a 30-year period from 1980, encompassing factors such as precipitation, temperature, and discharge. 
The basins are categorized into 18 hydrological units, reflecting variations in aridity and humidity.

Our findings indicate that the encoder improves the model's hydrological prediction performance, reflected in lower loss values and higher Nash-Sutcliffe efficiency 
(NSE) coefficients. The improvements are particularly evident in arid basins, although better performance is observed across all basin types.

This project has been developed in May/June 2022 by Group 1 for the Laboratory of Computational Physics MOD B course (academic year: 2021-2022) at the University of Padova.
The team was composed by: 
- Cano Amaro German: https://github.com/german-cano
- Monti Sebastiano: https://github.com/MontiSebastiano
- Tonazzo Valentina: https://github.com/ValentinaTonazzo
- Zoppellari Elena: https://github.com/zoppellarielena
