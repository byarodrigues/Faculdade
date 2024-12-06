select p.id_produto,
    p.den_produto,
    ci.uf,
    sum(cp.quantidade) as quantidade,
    sum(cp.valor * cp.quantidade) as total,
    avg(cp.valor) as valor_medio
from cidade as ci,
    fornecedor as f,
    compra as co,
    produto as p,
    compra_produto as cp
where co.id_fornecedor = f.id_fornecedor
    and f.id_cidade = ci.id_cidade
    and co.id_compra = cp.id_compra
    and cp.id_produto = p.id_produto
group by p.id_produto, ci.uf
order by ci.uf;