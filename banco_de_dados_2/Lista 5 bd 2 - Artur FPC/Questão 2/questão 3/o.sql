select p.den_produto,
    (select SUM(vp.quantidade) as total_vendido
    from venda_produto as vp
    where (p.id_produto = vp.id_produto)
    GROUP BY (p.id_produto)),
    (select SUM(cp.quantidade) as total_comprado
    from compra_produto as cp
    where (p.id_produto = cp.id_produto)
    GROUP BY (p.id_produto))
from produto as p;