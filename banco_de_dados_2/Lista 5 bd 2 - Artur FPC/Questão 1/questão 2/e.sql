select d.nome_disciplina, 
    MAX(m.nota), 
    MIN(m.nota) 
FROM disciplina as d, 
    matriculado as m 
where d.id_disciplina = m.id_disciplina 
GROUP BY d.id_disciplina;