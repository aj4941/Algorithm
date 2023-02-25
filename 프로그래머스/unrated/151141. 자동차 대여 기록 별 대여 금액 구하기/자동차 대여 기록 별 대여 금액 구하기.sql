with sub as (
    select a.car_id, b.history_id, a.daily_fee, datediff(end_date, start_date) + 1 as duration,
        case 
            when datediff(end_date, start_date) >= 90 then '90일 이상'
            when datediff(end_date, start_date) >= 30 then '30일 이상'
            when datediff(end_date, start_date) >= 7 then '7일 이상'
            else '0일 이상'
        end as duration_type
    from CAR_RENTAL_COMPANY_CAR as a
    join CAR_RENTAL_COMPANY_RENTAL_HISTORY as b
    on a.car_id = b.car_id
    where a.car_type = '트럭'
)

select a.history_id, 
    case
        when a.duration_type = '0일 이상' then a.daily_fee * a.duration
        else round(a.daily_fee * a.duration * (100 - b.discount_rate) / 100)
    end as fee
from sub as a
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as b
on a.duration_type = b.duration_type
where b.car_type = '트럭' or a.duration_type = '0일 이상'
group by a.history_id
order by fee desc, a.history_id desc