create temporary table cf as(
    select id_cidade from fornecedor
    union all
    select id_cidade from cliente
);
select c.id_cidade, 
    c.den_cidade,
    count(*)as cadastros
from cidade as c, cf
where c.id_cidade = cf.id_cidade
group by c.id_cidade;