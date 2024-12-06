select d.id_disciplina, 
    d.nome_disciplina 
from disciplina as d, 
    matriculado as m 
where not exists(
    select m.id_disciplina 
    from matriculado as m 
    where (d.id_disciplina = m.id_disciplina)) 
    GROUP BY (d.id_disciplina);