#!/bin/python3
import sys

class Registro():
    """
    registro
    """
    rnnSubArvores = []
    chaves = []
    ponteirosDeDados = []

    def __init__(self,arrayBytes):
        """
        inicializador
        """
        self.folha = arrayBytes[0]
        self.nroChaves = listToInt(arrayBytes[1:5])
        self.rnnNo = listToInt(arrayBytes[5:9])


        self.rnnSubArvores.append(listToInt(arrayBytes[9:13]))
        self.chaves.append(listToInt(arrayBytes[13:17]))
        self.ponteirosDeDados.append(listToInt(arrayBytes[17:25]))

        self.rnnSubArvores.append(listToInt(arrayBytes[25:29]))
        self.chaves.append(listToInt(arrayBytes[29:33]))
        self.ponteirosDeDados.append(listToInt(arrayBytes[33:41]))

        self.rnnSubArvores.append(listToInt(arrayBytes[41:45]))
        self.chaves.append(listToInt(arrayBytes[45:49]))
        self.ponteirosDeDados.append(listToInt(arrayBytes[49:57]))

        self.rnnSubArvores.append(listToInt(arrayBytes[57:61]))
        self.chaves.append(listToInt(arrayBytes[61:65]))
        self.ponteirosDeDados.append(listToInt(arrayBytes[65:73]))

        self.rnnSubArvores.append(listToInt(arrayBytes[73:77]))


    def print(self):
        """
        printa um registro
        """

        if self.folha == "30":
            print("folha: Não")
        elif self.folha == "31":
            print("folha: Sim")
        else:
            print(self.folha)
        
        print("numero Chaves: ",int.from_bytes(self.nroChaves,byteorder='little',signed=True))
        print("RNN no: ",int.from_bytes(self.rnnNo,byteorder='little',signed=True))

        print("chaves:")
        for chave in self.chaves:
            print(int.from_bytes(chave,byteorder='little',signed=True))
               
        print("ponteirosSubArvores:")
        for ponteiro in self.rnnSubArvores:
            print(int.from_bytes(ponteiro,byteorder='little',signed=True))

        print("ponteirosDados:")
        for ponteiro2 in self.ponteirosDeDados:
            print(int.from_bytes(ponteiro2,byteorder='little',signed=True))



def listToInt(list):
    """
    transforma todos os itens em uma lista em inteiros
    """
    # print(list)
    ret = [int(i,16) for i in list]
    # print(ret)
    return ret


if __name__ == "__main__":
    arrayBytes = sys.stdin.readline()
    arrayBytes = arrayBytes.split()
    registroteste = Registro(arrayBytes)
    registroteste.print()

    # print(arrayBytes)