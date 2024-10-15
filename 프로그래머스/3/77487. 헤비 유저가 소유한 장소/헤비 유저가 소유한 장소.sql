# host_id -> 개수를 저장하는 테이블
# host_id 끼리 조인해서 개수가 2 이상인 것들 출력

with sq as (
    select host_id
    from places
    group by host_id
    having count(host_id) >= 2
)

select id, name, host_id
from places
where host_id in (SELECT host_id FROM sq)
order by id