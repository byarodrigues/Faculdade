select distinct a.nome_aluno 
from aluno as a, 
    matriculado as m, 
    disciplina as d 
where (a.id_aluno = m.id_aluno) 
    and (m.id_disciplina = d.id_disciplina) 
    and (d.carga_horaria >=60);