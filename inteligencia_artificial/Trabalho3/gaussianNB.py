from sklearn.model_selection import train_test_split, cross_val_score, cross_val_predict
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import f1_score

arquivo = open('classifica.csv', "r")
arquivo_csv_target = pd.read_csv('classifica.csv')
arquivo_csv_data = pd.read_csv('classifica.csv', usecols=[0,1,2,3])

X = []
Y = []
for linha in arquivo_csv_target['class']:
    Y.append(linha)
Y = np.array(Y)
for linha in arquivo_csv_data.itertuples():
    X.append(linha[1:])
X = np.array(X)


plt.title('Gráfico X - Usando Gaussian NB')
plt.plot(X)
plt.show()
plt.clf()

plt.title('Gráfico Y - Usando Gaussian NB')
plt.plot(Y)
plt.show()
plt.clf()
# Classificador gau
gau = GaussianNB()
X_treino, X_teste, Y_treino, Y_teste = train_test_split(X, Y, train_size=0.7)
# Classificação dos dados originais

acuracia = []
score = []
acuracia2 = []


for i in range(5, 20):
    gau.fit(X_treino, Y_treino)
    k = gau.score(X_teste, Y_teste)
    acuracia.append(k)
    print('Acurácia sem validação cruzada:', k)
    previsoes = cross_val_predict(gau, X, Y, cv=i)
    t = f1_score(Y, previsoes, average='weighted')
    score.append(t)
    u = np.mean(cross_val_score(gau, X, Y, cv=i))
    acuracia2.append(u)
    print('Acurácia com validação cruzada: {} = {}'.format(i, u))
    print('F1_score: {} = {}'.format(i, t))
    print('')


plt.title('Gráfico Acurácia sem validação cruzada')
plt.plot(acuracia)
plt.show()
plt.clf()


plt.title('Gráfico Acurácia com validação cruzada')
plt.plot(acuracia2)
plt.show()
plt.clf()

plt.title('Gráfico F1_score')
plt.plot(score)
plt.show()
plt.clf()





