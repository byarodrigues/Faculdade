select distinct a.nome_aluno, 
    d.nome_disciplina, 
    p.nome_professor, 
    m.nota 
from aluno as a, 
    disciplina as d, 
    professor as p, 
    matriculado as m 
where (m.id_aluno = a.id_aluno) 
    and (m.id_disciplina = d.id_disciplina) 
    and (p.id_professor = d.id_professor) 
ORDER BY (nome_aluno);