select f.den_fornecedor, SUM(c.valor_total) 
from fornecedor as f, 
    compra as c 
where (c.id_fornecedor = f.id_fornecedor) 
GROUP BY (f.id_fornecedor);