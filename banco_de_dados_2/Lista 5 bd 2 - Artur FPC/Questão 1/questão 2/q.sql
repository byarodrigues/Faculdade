select a1.nome_aluno, a2.nome_aluno 
from aluno as a1, aluno as a2 
where a1.id_aluno<a2.id_aluno 
order by a1.id_aluno;