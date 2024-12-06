select id_conta_pagar 
from conta_pagar
where (data_vencimento <= '2011-12-31')
    and pago <>'S';