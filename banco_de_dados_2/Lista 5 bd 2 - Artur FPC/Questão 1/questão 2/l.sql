select d.nome_disciplina, 
    count(*) 
from disciplina as d, 
    matriculado as m 
where (d.id_disciplina = m.id_disciplina) 
GROUP BY (d.nome_disciplina);