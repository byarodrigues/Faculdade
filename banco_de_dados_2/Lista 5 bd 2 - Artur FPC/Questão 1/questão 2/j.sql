select distinct a.nome_aluno 
from aluno as a, 
    matriculado as m, 
    disciplina as d 
where (m.id_aluno = a.id_aluno) 
    and (d.id_disciplina = m.id_disciplina) 
    and (d.id_professor IN (
        select p.id_professor 
        from professor as p 
        where p.area ='Computação'));