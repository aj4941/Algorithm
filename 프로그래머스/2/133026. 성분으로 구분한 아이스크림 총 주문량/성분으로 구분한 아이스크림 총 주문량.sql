select b.ingredient_type, sum(a.total_order)
from first_half as a
join icecream_info as b
on a.flavor = b.flavor
group by b.ingredient_type
order by sum(a.total_order)