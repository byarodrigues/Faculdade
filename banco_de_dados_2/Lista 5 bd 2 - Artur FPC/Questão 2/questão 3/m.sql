select distinct p.den_produto
from produto as p, 
    compra_produto as cp, 
    compra as c
where (p.id_produto = cp.id_produto) 
    and (cp.id_compra = c.id_compra)
    and (c.data>='2010-01-01') 
    and (c.data<='2010-12-31');