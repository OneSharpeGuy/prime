SELECT CONCAT(a.title,' - ', FROM_UNIXTIME(a.start_time_unix,'%W, %M %D, %Y')) AS title
, b.*
, ROUND(yes_count / total_responding * 100) AS pct_yes
, ROUND(no_count / total_responding * 100) AS pct_no
, ROUND((b.maybe_count + b.unlikely_count) / total_responding * 100) AS pct_limbo
, ROUND((responding / user_count) * 100) AS pct_responding
FROM osg_ical_imported a
INNER JOIN osg_voice_part_summary b ON a.nid=b.nid
