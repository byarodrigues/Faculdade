create temporary table disc_sem_m as 
    select d.id_disciplina 
    from disciplina as d, 
    matriculado as m 
    where not exists(
        select m.id_disciplina 
        from matriculado as m 
        where (d.id_disciplina = m.id_disciplina)) 
        GROUP BY (d.id_disciplina);
insert into matriculado (id_disciplina,id_aluno, nota) 
    select dsm.id_disciplina, a.id_aluno, 0 
    from disc_sem_m as dsm, aluno as a;