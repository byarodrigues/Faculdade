CREATE TEMPORARY TABLE media AS 
SELECT id_aluno, 
    AVG(nota) AS media 
FROM matriculado 
GROUP BY id_aluno;

UPDATE aluno AS a 
SET media = m.media 
FROM media AS m WHERE a.id_aluno = m.id_aluno;