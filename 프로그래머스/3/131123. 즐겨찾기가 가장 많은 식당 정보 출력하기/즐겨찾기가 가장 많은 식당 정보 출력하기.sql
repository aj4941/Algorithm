with sub as (
    select food_type, max(favorites) as favorites
    from rest_info
    group by food_type
)

select a.food_type, a.rest_id, a.rest_name, a.favorites
from rest_info as a
join sub as b
on (a.food_type = b.food_type) and (a.favorites = b.favorites)
order by a.food_type desc
