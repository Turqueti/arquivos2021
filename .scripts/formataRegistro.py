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
        self.nroChaves = arrayBytes[1:5]
        self.rnnNo = arrayBytes[5:9]


        self.rnnSubArvores.append(arrayBytes[9:13])
        self.chaves.append(arrayBytes[13:17])
        self.ponteirosDeDados.append(arrayBytes[17:25])


    def print(self):
        """
        printa um registro
        """
        print("folha: ",self.folha)
        print("numero Chaves: ",self.nroChaves)
        print("RNN no: ",self.rnnNo)

        print("ponteirosSubArvores:")
        for ponteiro in self.rnnSubArvores:
            print(ponteiro)


        print("chaves:")
        for chave in self.chaves:
            print(chave)
        
        
        
        
        
        print("ponteirosDados:")
        for ponteiro2 in self.ponteirosDeDados:
            print(ponteiro2)



if __name__ == "__main__":
    arrayBytes = sys.stdin.readline()
    arrayBytes = arrayBytes.split()
    registroteste = Registro(arrayBytes)
    registroteste.print()

    print(arrayBytes)