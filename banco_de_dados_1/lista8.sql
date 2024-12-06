CREATE DATABASE academico;
CREATE TABLE aluno(
id_aluno SERIAL NULL,
nome_aluno VARCHAR(50) NOT NULL,
cpf CHAR(11),
data_nascimento DATE,
media FLOAT DEFAULT 0.0,
CONSTRAINT aluno_pk PRIMARY KEY (id_aluno),
CONSTRAINT aluno_cpf_key UNIQUE (cpf)
);
CREATE TABLE professor (
id_professor INT NOT NULL,
nome_professor VARCHAR(50) NOT NULL,
sobrenome VARCHAR(50) NOT NULL,
area VARCHAR(20),
CONSTRAINT professor_pk PRIMARY KEY (id_professor)
);
CREATE TABLE disciplina(
id_disciplina INT NOT NULL,
nome_disciplina VARCHAR(30) NOT NULL,
carga_horaria INT NOT NULL,
id_professor INT,
CONSTRAINT disciplina_pk PRIMARY KEY (id_disciplina),
CONSTRAINT disciplina_fk_professor FOREIGN KEY (id_professor) REFERENCES professor(id_professor)
);
CREATE TABLE matriculado(
id_disciplina INT NOT NULL,
id_aluno INT NOT NULL,
nota FLOAT,
CONSTRAINT matriculado_pk PRIMARY KEY (id_disciplina, id_aluno),
CONSTRAINT matriculado_fk_aluno FOREIGN KEY (id_aluno) REFERENCES aluno(id_aluno),
CONSTRAINT matriculado_fk_disciplina FOREIGN KEY (id_disciplina) REFERENCES disciplina(id_disciplina)
);
INSERT INTO aluno(nome_aluno, cpf, data_nascimento, media)
VALUES ('José', NULL , '1990-01-20', 0.0);

INSERT INTO aluno(nome_aluno, data_nascimento)
VALUES
('João', '1993-09-10'),
('Maria', '1989-05-15'),
('Ana', '1992-04-21');

SELECT * FROM aluno;

DELETE FROM aluno
WHERE id_aluno = 2;

UPDATE aluno
SET cpf='01234567890', data_nascimento='1991-12-23'
WHERE id_aluno = 3;

SELECT nome_aluno, data_nascimento FROM aluno;

SELECT a.nome_aluno AS aluno,
a.data_nascimento AS nascimento
FROM aluno AS a;

SELECT 102 * 30 as conta;

SELECT nome_aluno AS aluno,
media * 0.8 + 25 AS media
FROM aluno;

SELECT * FROM aluno
WHERE data_nascimento >= '1991-01-01';

SELECT * FROM disciplina
WHERE carga_horaria IN (40,60);

SELECT * FROM aluno
WHERE data_nascimento BETWEEN '1980-01-01' AND '1989-12-31';

SELECT * FROM aluno
WHERE data_nascimento >= '1990-01-01'
AND media > 80;

SELECT * FROM aluno
WHERE cpf IS NULL;

SELECT * FROM disciplina
ORDER BY carga_horaria DESC, nome_disciplina;

SELECT nome_professor AS nome
FROM professor
UNION
SELECT nome_aluno AS nome
FROM aluno;

SELECT id_aluno, AVG(nota) AS media
FROM matriculado
WHERE id_disciplina = 100 OR id_disciplina = 200
GROUP BY id_aluno
HAVING AVG(nota) > 80;

SELECT p.nome_professor,
d.nome_disciplina
FROM professor AS p,
disciplina AS d
WHERE p.id_professor = d.id_professor;

SELECT a.nome_aluno,
d.nome_disciplina,
m.nota
FROM aluno AS a
JOIN matriculado AS m
ON a.id_aluno = m.id_aluno
JOIN disciplina AS d
ON d.id_disciplina = m.id_disciplina;

SELECT a.nome_aluno,
d.nome_disciplina,
m.nota
FROM aluno AS a
NATURAL JOIN matriculado AS m
NATURAL JOIN disciplina AS d;

SELECT d1.nome_disciplina, p.nome_professor
FROM disciplina AS d1,
professor AS p,
disciplina AS d2
WHERE d1.id_professor = p.id_professor
AND d1.id_professor = d2.id_professor
AND d2.id_disciplina <> d1.id_disciplina;

SELECT a.nome_aluno
FROM aluno AS a
WHERE NOT EXISTS(
SELECT 1
FROM matriculado AS m,
disciplina as D
WHERE m.id_disciplina = d.id_disciplina
AND d.id_professor = 30
AND m.id_aluno = a.id_aluno);

