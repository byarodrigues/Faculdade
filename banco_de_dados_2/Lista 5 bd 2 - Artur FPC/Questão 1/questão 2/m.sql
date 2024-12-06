select a.nome_aluno 
from disciplina as d, 
    matriculado as m, 
    aluno as a 
where (m.id_aluno=a.id_aluno) 
    and (m.id_disciplina = d.id_disciplina) 
GROUP BY (a.id_aluno) 
HAVING (sum(d.carga_horaria)>100);