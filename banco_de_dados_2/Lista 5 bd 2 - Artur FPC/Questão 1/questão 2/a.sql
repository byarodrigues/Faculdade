select a.nome_aluno, 
    d.nome_disciplina, 
    m.nota 
from aluno as a, 
    disciplina as d, 
    matriculado as m 
where a.id_aluno = m.id_aluno and d.id_disciplina = m.id_disciplina
ORDER BY (a.id_aluno);