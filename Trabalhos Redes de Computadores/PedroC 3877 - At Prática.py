# PEDRO CARDOSO DE CARVALHO MUNDIM - 3877

# Links de auxílio:
# https://www.tutorialspoint.com/p-persistent-csma-protocol
# https://webeduclick.com/csma-in-computer-network/
# https://www.ti-enxame.com/pt/python/repetir-tarefas-do-aipo-com-recuo-exponencial/941879299/

# Importações
from __future__ import annotations # https://docs.python.org/3/library/__future__.html

import time # https://www.programiz.com/python-programming/time
import timeit

from typing import List # https://docs.python.org/3/library/typing.html
from random import randint # https://docs.python.org/3/library/random.html
from random import uniform # Mesma referência do import acima

# Número de máquinas (N).
# Aqui precisamos mudar o tamanho de N para verificar todos os casos (20, 40, 100).
N = 20

# Título. Referência de cores: https://raccoon.ninja/pt/dev-pt/tabela-de-cores-ansi-python/
print("""\033[1;31m
 _____ _                 _           _            _____         _   
/  ___(_)               | |         | |          | ___ \       | |     
\ `--. _ _ __ ___  _   _| | __ _  __| | ___  _ __| |_/ /___  __| | ___  ___
 `--. \ | `_ ` _ \| | | | |/ _` |/ _` |/ _ \| `__| | //  _ \/ _` |/ _ \/ __|
/\__/ / | | | | | | |_| | | (_| | (_| | (_) | |  | |\ \  __/ (_| |  __/\__ \ 
\____/|_|_| |_| |_|\__,_|_|\__,_|\__,_|\___/|_|  \_| \_\___|\__,_|\___||___/
\033[0m""")


class Estacao: # Definindo a classe Estação https://docs.python.org/pt-br/3/tutorial/classes.html
    # O self é um parâmetro obrigatório que receberá a instância criada.
    def __init__(self, id: int): 
        self.id = id # self.id = id, pois id está dentre os parâmetros de init.
        self.canal = None
        self.dadosTransmitidos = False
        self.espera = 0  # Não aguarda nenhum slot no primeiro momento.
        self.colisao = 0 # No início não há colisões.

    # Esta função diz respeito à conexão do canal que utiliza o meio de Difusão.
    def canalConexao(self, meioDifusao: Difusao): 
        self.canal = meioDifusao 


    def realizarTransmissao(self): # Função responsável pela transmissão de dados.
        # Se não existir canal e não houver dados transmitidos.
        if (self.canal != None) and (self.dadosTransmitidos == False):
            if self.espera == 0:
                self.canal.realizarTransmissao(self)
            else:
                self.espera -= 1
        elif self.dadosTransmitidos == True:
            print() # Print apenas para não ocorrer erro aqui.

    # Uma função para limpar o que foi feito e evitar erros mais a frente.
    def realizarLimpeza(self): 
        self.dadosTransmitidos = False
        self.espera = 0
        self.colisao = 0

# Fim da classe


class Difusao: # Classe para o meio de Difusão.
    def __init__(self, nome, cenario: int):
        self.nome = nome # Nome que será passado para a função Difusao.
        self.cenario = cenario # Aqui teremos os cenários possíveis: CSMA ou Recuo.
        self.tentativaDeTransmissao: List[Estacao] = []

    # Função de transmissão entre as estações.
    def realizarTransmissao(self, estacao: Estacao):  
        if self.cenario == 1:  # CSMA p-persistente.
            # uniform aqui veio dos imports.
            if uniform(0, 1) <= 0.01: # p foi dado na especificação como 1%.
                # Enviando dados da máquina com controle CSMA p-persistente.
                self.tentativaDeTransmissao.append(estacao)
        elif self.cenario == 2: # Recuo exponencial.
            # Enviando dados da máquina com controle Recuo binário exponencial.
            self.tentativaDeTransmissao.append(estacao)


    def VerificarColisao(self): # Função para verificar colisões.
        qtdMaquinas = len(self.tentativaDeTransmissao)
        exp: int # Expoente para utilizar no caso do Recuo exponencial.
        transmitiu = False

        if self.cenario != 2: # Caso seja o CSMA p-persistente.
            if qtdMaquinas == 1:
                self.tentativaDeTransmissao[0].dadosTransmitidos = True
                transmitiu = True
            elif qtdMaquinas > 1:
                for estacao in self.tentativaDeTransmissao:
                    estacao.espera = randint(1, N) # Seleção randômica.
            else:
                '''print()''' # Se não colocar esse print aqui teremos erro.
        
        else:  # Caso seja recuo exponencial.
            if qtdMaquinas == 1:
                self.tentativaDeTransmissao[0].dadosTransmitidos = True
                self.colisao = 0 # Colisões = 0.
                transmitiu = True
            elif qtdMaquinas > 1:
                for estacao in self.tentativaDeTransmissao:
                    estacao.colisao += 1  # Aumenta o número de colisões.
                    # Se houver mais de 10 colisões, consideramos o expoente como 10.
                    # Sem o expoente, o cenário do recuo binário não funcionaria.
                    if estacao.colisao > 10:
                        exp = 10
                    else: # Do contrário, o expoente será o mesmo valor da qtd de colisões.
                        exp = estacao.colisao
                        # Número aleatório entre 0 e 2 elevado ao expoente - 1.
                    estacao.espera = randint(0, 2 ** exp - 1)   
            else:
                '''print()''' # O mesmo que o caso acima aqui.
        self.tentativaDeTransmissao.clear()
        return transmitiu

# Fim da classe

if __name__ == "__main__": # http://devfuria.com.br/python/entenda-__name__-__main__/
    
    print("""\033[1;36m
     _____                                    
    |  ___|                                   
    | |____  _____  ___ _   _  ___ __ _  ___  
    |  __\ \/ / _ \/ __| | | |/ __/ _` |/ _ \ 
    | |___>  <  __/ (__| |_| | (_| (_| | (_) |
    \____/_/\_\___|\___|\__,_|\___\__,_|\___/
    
    \033[0m""")
    
    print("""\033[1;36m
    ╔══════════════════════════════╗
    ║      Escolha uma Opção       ║
    ╠══════════════════════════════╣
    ║ 1) CSMA p-persistente        ║
    ║ 2) Recuo binário exponencial ║
    ╚══════════════════════════════╝
    \033[0m""")
    opcao = int(input())

    if opcao == 1:
        print("""\033[1;34m
    ╔════════════════════════════════════════╗
    ║ Você escolheu o cenário para o CSMA!!! ║
    ╚════════════════════════════════════════╝
        \033[0m""")
    else:
        print("""\033[1;34m
    ╔═════════════════════════════════════════════════╗
    ║ Você escolheu o cenário para o Recuo Binário!!! ║
    ╚═════════════════════════════════════════════════╝
        \033[0m""")
    
    # As opções são as mostradas no menu acima.
    # 1 - CSMA p-persistente
    # 2 - Recuo binário exponencial
    # parâmetros: nome do meio e qual opção
    meio = Difusao('Cenario', opcao)

    listaEstacoes = []
    listaTransmissoes = []  # As estacões possuem indice nessa lista.

    # Variáveis para execução:
    temposTotais = []
    primeirosTempos = []
    contadorTempo = 0
    primeiroTempo = 0

    for i in range(N):  # Inicializando estações (de acordo com a qtd selecionada).
        listaEstacoes.append(Estacao(i))
        listaTransmissoes.append(listaEstacoes[i].dadosTransmitidos)

    for maquina in listaEstacoes:
        maquina.canalConexao(meio)

    for j in range(N): # Aqui também utilizamos a qtd de estações.
        i = 0
        primeiroEnvio = False

        while False in listaTransmissoes:
            if(i != 0):
                for estacao in listaEstacoes:
                    listaTransmissoes[estacao.id] = estacao.dadosTransmitidos
                    if (not estacao.dadosTransmitidos):
                        estacao.realizarTransmissao()

                colidiu = meio.VerificarColisao()
                if colidiu and not primeiroEnvio:
                    primeiroTempo = contadorTempo + 1
                    primeiroEnvio = True
            else:
                i += 1
            contadorTempo += 1

        temposTotais.append(contadorTempo - 1)
        primeirosTempos.append(primeiroTempo)

        # Realizando uma limpeza nas estruturas.
        for indice in range(N):
            listaTransmissoes[indice] = False
            listaEstacoes[indice].realizarLimpeza()
        contadorTempo = 0
        primeiroTempo = 0

    print('\n')
    print('Primeiro tempo de envio dentre as estações: ', primeirosTempos[0])
    print('\n')
    print('Todos os tempos totais das N estações: ', temposTotais)

# Designs feitos utilizando:
    # -> https://ozh.github.io/ascii-tables/
    # -> https://ascii.today/