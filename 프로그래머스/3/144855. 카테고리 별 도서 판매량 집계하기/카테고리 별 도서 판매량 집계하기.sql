select a.category, sum(b.sales)
from book as a
join book_sales as b
on a.book_id = b.book_id
where date_format(b.sales_date, "%Y-%m") = "2022-01"
group by a.category
order by a.category

