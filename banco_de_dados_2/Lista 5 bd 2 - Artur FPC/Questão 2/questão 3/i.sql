create temporary table movimentacao as (
    select id_produto, 
        quantidade 
    from venda_produto
    union all
    select id_produto, 
        quantidade 
    from compra_produto
);
select p.id_produto,
    p.den_produto,
    sum(m.quantidade) as quantidade
from produto as p,
    movimentacao as m 
where p.id_produto = m.id_produto
group by (p.id_produto)
order by quantidade DESC
limit 10;