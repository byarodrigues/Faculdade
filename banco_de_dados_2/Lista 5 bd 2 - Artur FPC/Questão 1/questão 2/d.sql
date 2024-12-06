select d.nome_disciplina, 
    AVG(m.nota) 
from disciplina as d, 
    matriculado as m 
where d.id_disciplina = m.id_disciplina 
GROUP BY d.id_disciplina;