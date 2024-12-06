import numpy as np
import time
import matplotlib.pyplot as plt


nomes_cidades = np.array(['Belo Horizonte', 'Bambuí', 'São Paulo', 'Rio de Janeiro', 'Campinas', 'Curitiba', 'Oliveira', 'Contagem', 'Betim', 'Juiz de Fora', 'Uberaba', 'Ipatinga', 'Santa Luzia', 'Divinópolis', 'Sabará', 'Ubá', 'Passos', 'Araxá', 'Itajubá', 'Curvelo', 'Outro Preto', 'Formiga', 'Lagoa Sante', 'Frutal', 'Salinas', 'Arcos', 'Buritis'])
quantidade_cidades = len(nomes_cidades)
lista_coordenadas = [[x,y] for x,y in zip(np.random.randint(0,100,quantidade_cidades),np.random.randint(0,100,quantidade_cidades))]
cidades_coordenadas_dici = { x:y for x,y in zip(nomes_cidades,lista_coordenadas)}
#quantidade_populacao = 10
#mutation_rate = 0.1

def distancia_x_y (x, y):
    return np.square((np.power((x[0]-y[0]), 2)+ np.power((x[1]-y[1]), 2)))

def distancia_cidades(cidade1, cidade2, cidades_coordenadas_dici):
    return distancia_x_y(cidades_coordenadas_dici[cidade1], cidades_coordenadas_dici[cidade2])

def populacao(nomes_cidades, k):
    lista_populacao = []
    for i in range(k):
        resultado = nomes_cidades[np.random.choice(list(range(quantidade_cidades)), quantidade_cidades, replace=False)]
        lista_populacao.append(resultado)
    return np.array(lista_populacao)

#lista_populacao = populacao(nomes_cidades, quantidade_populacao)

def media_aptidao(nomes_cidades, cidades_coordenadas_dici):
    total = 0
    for i in range(quantidade_cidades-1):
        x = nomes_cidades[i]
        y = nomes_cidades[i+1]
        total += distancia_cidades(x,y, cidades_coordenadas_dici)
    return total

def get_aptidao(population, cidades_coordenadas_dici, k):
    lista_aptidao = np.zeros(k)

    #Looping over all solutions computing the fitness for each solution
    for i in  range(k):
        lista_aptidao[i] = media_aptidao(population[i], cidades_coordenadas_dici)
    return lista_aptidao

#lista_aptidao = get_aptidao(lista_populacao, cidades_coordenadas_dici)

def progenitor_selection(population,lista_aptidao):
    total = lista_aptidao.sum()
    lista_probalidade = lista_aptidao / total
    
    #Notice there is the chance that a progenitor. mates with oneself
    lista_selecao_a = np.random.choice(list(range(len(population))), len(population),p=lista_probalidade, replace=True)
    lista_selecao_b = np.random.choice(list(range(len(population))), len(population),p=lista_probalidade, replace=True)
    
    lista_selecao_a = population[lista_selecao_a]
    lista_selecao_b = population[lista_selecao_b]
        
    return np.array([lista_selecao_a,lista_selecao_b])


#progenitor_list = progenitor_selection(lista_populacao,lista_aptidao)

def cruzamento(x,y):
    filhos = x[0:5]
    for cidades in y:

        if not cidades in filhos:
            filhos = np.concatenate((filhos,[cidades]))

    return filhos

def cuzamento_populacao(lista):
    nova_populacao = []
    for i in range(lista.shape[1]):
        x, y = lista[0][i], lista[1][i]
        filhos = cruzamento(x, y)
        nova_populacao.append(filhos)
        
    return nova_populacao

#new_population_set = cuzamento_populacao(progenitor_list)

def mutacao(filhos,j):
    for i in range(int(quantidade_cidades * j)):
        x = np.random.randint(0, quantidade_cidades)
        y = np.random.randint(0, quantidade_cidades)

        filhos[x], filhos[y] = filhos[y], filhos[x]

    return filhos
    
    
def mutacao_populacao(nova_populacao,j):
    lista_mutacao = []
    for filhos in nova_populacao:
        lista_mutacao.append(mutacao(filhos,j))
    return lista_mutacao

#mutated_pop = mutacao_populacao(new_population_set)

solucao = [-1,np.inf,np.array([]), 0, 0]
lista_mutacao = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1]
quantidade_populacao = [10,20,30,40,50,60,70,80,90,100]
start = time.time()
for i in range(500):
    for j in lista_mutacao:
        for k in quantidade_populacao:
            lista_populacao = populacao(nomes_cidades, k)
            lista_aptidao = get_aptidao(lista_populacao, cidades_coordenadas_dici, k)
            progenitor_list = progenitor_selection(lista_populacao,lista_aptidao)
            new_population_set = cuzamento_populacao(progenitor_list)
            mutated_pop = mutacao_populacao(new_population_set, j)

            if i % 100 == 0: 
                print(i, lista_aptidao.min(), lista_aptidao.mean(), j, k )
            lista_aptidao = get_aptidao(mutated_pop,cidades_coordenadas_dici,k)
            
            #Saving the best solution
            if lista_aptidao.min() < solucao[1]:
                solucao[0] = i
                solucao[1] = lista_aptidao.min()
                solucao[2] = np.array(mutated_pop)[lista_aptidao.min() == lista_aptidao]
                solucao[3] = j
                solucao[4] = k
            
            progenitor_list = progenitor_selection(lista_populacao,lista_aptidao)
            new_population_set = cuzamento_populacao(progenitor_list)
            
            mutated_pop = mutacao_populacao(new_population_set,j)
    print(i)



print('Tempo: {}'.format(time.time() - start))
print(solucao)