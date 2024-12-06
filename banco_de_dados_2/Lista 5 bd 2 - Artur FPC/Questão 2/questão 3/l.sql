select distinct p.id_produto 
from produto as p,
    venda_produto as vp
where (p.id_produto = vp.id_produto)
EXCEPT
select distinct p.id_produto
from produto as p,
    compra_produto as cp,
    compra as c
where (p.id_produto = cp.id_produto)
    and (c.id_compra = cp.id_compra)
    and (c.data >='2011-01-01')
    and (c.data <='2011-01-31');