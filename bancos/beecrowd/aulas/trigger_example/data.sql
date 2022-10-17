CREATE TABLE Produto (
 cod_prod INT PRIMARY KEY,
 descricao VARCHAR(50) UNIQUE,
 qtde_disponivel INT NOT NULL DEFAULT 0
);

CREATE TABLE ItensVenda (
 cod_venda  INT,
 id_produto VARCHAR(3),
 qtde_vendida INT,
 FOREIGN KEY (cod_venda) REFERENCES Produto(cod_prod) ON DELETE CASCADE
);

INSERT INTO Produto VALUES (1, 'Feijão', 10);
INSERT INTO Produto VALUES (2, 'Arroz', 5);
INSERT INTO Produto VALUES (3, 'Farinha', 15);
