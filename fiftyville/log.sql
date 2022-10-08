-- Keep a log of any SQL queries you execute as you solve the mystery.
--airports              crime_scene_reports   people
--atm_transactions      flights               phone_calls
--bakery_security_logs  interviews
--bank_accounts         passengers
sqlite> .schema crime_scene_reports -- the structure of the crime_scene_reports
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day =28 ; --info from data 

