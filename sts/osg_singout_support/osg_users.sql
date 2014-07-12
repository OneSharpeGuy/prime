SELECT u.uid,
       u.name AS u_name,
       u.mail,
       d.name AS voice_part,
       d.tid,
		 ifnull(m.hit,0) as is_member,
       ifnull(n.hit,1) as is_singer,       
       CASE u.uid
           WHEN 1 THEN 1
           ELSE ifnull(a.hit,0)
       END AS is_admin
FROM users u
LEFT JOIN field_data_field_voice_part p ON u.uid = p.entity_id
LEFT JOIN taxonomy_term_data d ON d.tid = p.field_voice_part_tid
LEFT JOIN
  (SELECT a.uid,
          1 AS hit
   FROM `role` b
   INNER JOIN users_roles a ON a.rid=b.rid
   WHERE b.name='member') m ON u.uid=m.uid
LEFT JOIN
  (SELECT a.uid,
          0 AS hit
   FROM `role` b
   INNER JOIN users_roles a ON a.rid=b.rid
   WHERE b.name='non singer') n ON u.uid=n.uid
LEFT JOIN
  (SELECT a.uid,
          1 AS hit
   FROM `role` b
   INNER JOIN users_roles a ON (a.rid=b.rid)
   WHERE b.name='administrator') a ON u.uid=n.uid