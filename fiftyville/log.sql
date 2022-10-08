-- place at 10:15am
--Earlier this morning by the ATM on Leggett Street
-- they called someone who talked to them for less than a minute
--flight out of Fiftyville tomorrow.

-- Keep a log of any SQL queries you execute as you solve the mystery.
--airports              crime_scene_reports   people
--atm_transactions      flights               phone_calls
--bakery_security_logs  interviews
--bank_accounts         passengers
sqlite> .schema crime_scene_reports -- the structure of the crime_scene_reports
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day =28 AND street LIKE "Humphrey Street" ; --info from data
--Theft of the CS50 duck took place at 10:15am
--at the Humphrey Street bakery. Interviews were
--conducted today with three witnesses who were present
--at the time – each of their interview transcripts mentions the bakery.

select name,transcript from interviews  WHERE year = 2021 AND month = 7 AND day =28 AND  transcript LIKE "%bakery%";
-- getting their interview transcripts
--| Ruth    | Sometime within ten minutes of the theft,
-- I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot,
-- you might want to look for cars that left the parking lot in that time frame.

                                                    |
--| Eugene  | I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
                                                                                             |
--| Raymond | As the thief was leaving the bakery,
-- they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest
-- flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket. |

sqlite> SELECT activity , license_plate,minute  FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10 ;
--| activity | license_plate | minute |
--+----------+---------------+--------+
--| entrance | R3G7486       | 8      |
--| entrance | 13FNH73       | 14     |
--| exit     | 5P2BI95       | 16     |
--| exit     | 94KL13X       | 18     |
--| exit     | 6P58WS2       | 18     |
--| exit     | 4328GD8       | 19     |
--| exit     | G412CB7       | 20     |
--| exit     | L93JTIZ       | 21     |
--| exit     | 322W7JE       | 23     |
--| exit     | 0NTHK55       | 23     |
--| exit     | 1106N58       | 35     |
--| entrance | NRYN856       | 42     |
--| entrance | WD5M8I6       | 44     |
--| entrance | V47T75I       | 55     |