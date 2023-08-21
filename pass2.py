class Pass2:
    def __init__(self) -> None:
        self.symtab = []
        self.littab = []
        pass
    def readFiles(self):
        with open("SymTab.txt", "r") as File:
            data = File.readlines()
            for line in data:
                word = line.split()
                self.symtab.append(int(word[2][:-1]))
        with open("LitTab.txt", "r") as File:
            data = File.readlines()
            for line in data:
                word = line.split()
                self.littab.append(int(word[2][:-1]))
