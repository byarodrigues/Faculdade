select distinct p.nome_professor 
FROM professor as p, 
    disciplina as d 
WHERE NOT EXISTS (
    SELECT d.id_professor 
    FROM disciplina AS d 
    WHERE p.id_professor = d.id_professor);