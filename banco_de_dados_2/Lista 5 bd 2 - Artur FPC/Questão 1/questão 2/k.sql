select p.nome_professor, 
    SUM(d.carga_horaria) as carga_total 
from professor as p, 
    disciplina as d 
where p.id_professor = d.id_professor 
GROUP BY p.id_professor 
UNION 
select p.nome_professor, 
    0 
FROM professor as p, 
    disciplina as d 
WHERE NOT EXISTS (
    SELECT d.id_professor 
    FROM disciplina AS d 
    WHERE p.id_professor = d.id_professor);