select a.product_code, a.price * sum(b.sales_amount) as sales
from product as a
join offline_sale as b
on a.product_id = b.product_id
group by a.product_id
order by sales desc, a.product_code asc