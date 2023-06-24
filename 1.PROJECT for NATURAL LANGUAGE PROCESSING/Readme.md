# BiLSTM vs BERT in feature extraction for Neural Dependency Parsing
This project explores two different architectures for enhancing an ArcEager parser through contextual feature extraction and utilizing a feedforward network 
for action prediction. The two architectures implemented are as follows:

1. BiLSTM: This architecture employs a bidirectional Long Short-Term Memory (BiLSTM) network to capture contextual information from both the left and right sentences. It achieved an Unlabeled Attachment Score (UAS) of 82%.
2. BERT: The second architecture utilizes the Bidirectional Encoder Representations from Transformers (BERT) pretrained model, which is fine-tuned to the Multilayer Perceptron (MLP). Considering the average of the output layers a representative contextual information, the model achieved a UAS of 85%.

Both models were trained and tested on the English EWT dataset from the Universal Dependency project.
They were also compared with the State-of-the-Art UAS scores, which, at the time of writing, is equal to 93%.

In the initial phase of the project, the dataset was explored by visualizing important information such as vocabulary size, word frequency, ù
relation with Zipf/Mandelbrot law, lemmas vocabulary and frequencies, POS tag distribution and sentence length distribution.

For the BERT model, a small statistical analysis of the predicted moves from the trained model is provided, highlighting its higher performance scores on the 
two actions that do not attach a dependency to the element in the configuration (shift and reduce).

This project was developed in June 2023 for the course *Natural Language Processing* offered by the University of Padova (academic year 2022-2023).

Team Members:
- Mahfouz Auriane
- Zoppellari Elena: https://github.com/zoppellarielena
