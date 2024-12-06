select d.nome_disciplina 
from disciplina as d, 
    matriculado as m 
where (d.id_disciplina = m.id_disciplina) 
    and (m.id_aluno = (select id_aluno from aluno where nome_aluno='José')) 
INTERSECT 
select d.nome_disciplina 
from disciplina as d, 
    matriculado as m 
where d.id_disciplina = m.id_disciplina 
GROUP BY d.id_disciplina HAVING count(*) >=2;