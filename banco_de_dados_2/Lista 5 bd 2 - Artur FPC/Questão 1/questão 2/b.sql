select p.nome_professor, 
    count (*) as num_disciplinas 
from professor as p, 
    disciplina as d 
where p.id_professor = d.id_professor 
GROUP BY p.id_professor 
UNION
select distinct p.nome_professor,
    0
from professor as p,
    disciplina as d
where not exists(
    select d.id_professor 
    from disciplina as d 
    where p.id_professor = d.id_professor 
);