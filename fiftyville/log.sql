-- place at 10:15am
--Earlier this morning by the ATM on Leggett Street there withdrawing some money
-- they called someone who talked to them for less than a minute
--flight out of Fiftyville tomorrow.

-- Keep a log of any SQL queries you execute as you solve the mystery.
--airports              crime_scene_reports   people
--atm_transactions      flights               phone_calls
--bakery_security_logs  interviews
--bank_accounts         passengers
 .schema crime_scene_reports -- the structure of the crime_scene_reports
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

 SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit";
--| activity | license_plate | minute |
--+----------+---------------+--------+
--| exit     | 5P2BI95       | 16     |
--| exit     | 94KL13X       | 18     |
--| exit     | 6P58WS2       | 18     |
--| exit     | 4328GD8       | 19     |
--| exit     | G412CB7       | 20     |
--| exit     | L93JTIZ       | 21     |
--| exit     | 322W7JE       | 23     |
--| exit     | 0NTHK55       | 23     |

 SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw";
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
--+-----+----------------+------+-------+-----+----------------+------------------+--------+
--| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
--| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
--| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
--| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
--| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
--| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
--| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |

SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw");
--+----------------+-----------+---------------+
--| account_number | person_id | creation_year |
--+----------------+-----------+---------------+
--| 49610011       | 686048    | 2010          |
--| 26013199       | 514354    | 2012          |
--| 16153065       | 458378    | 2012          |
--| 28296815       | 395717    | 2014          |
--| 25506511       | 396669    | 2014          |
--| 28500762       | 467400    | 2014          |
--| 76054385       | 449774    | 2015          |
--| 81061156       | 438727    | 2018          |
--+----------------+-----------+---------------+

SELECT * FROM people WHERE license_plate IN
( SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit");
--+--------+---------+----------------+-----------------+---------------+
--|   id   |  name   |  phone_number  | passport_number | license_plate |
--+--------+---------+----------------+-----------------+---------------+
--| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
--| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
--| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
--| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
--| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
--| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
--| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
--| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
--| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
--+--------+---------+----------------+-----------------+---------------+

SELECT * FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw"));
--+--------+---------+----------------+-----------------+---------------+
--|   id   |  name   |  phone_number  | passport_number | license_plate |
--+--------+---------+----------------+-----------------+---------------+
--| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
--| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
--| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
--| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
--| 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       |
--| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
--| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
--| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
--+--------+---------+----------------+-----------------+---------------+

SELECT name , phone_number FROM people WHERE name IN
(SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw")))
AND name IN (SELECT name FROM people WHERE license_plate IN
(SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit"));

--+--------+
--|  name  |
--+--------+
--| Iman   |
--| Taylor |
--| Luca   |
--| Diana  |
--| Bruce  |
-----------+
--------+----------------+
--|  name  |  phone_number  |
--------+----------------+
--| Iman   | (829) 555-5269 |
--| Taylor | (286) 555-6063 |
--| Luca   | (389) 555-5198 |
--| Diana  | (770) 555-1861 |
--| Bruce  | (367) 555-5533 |
-------+----------------+

SELECT name , phone_number FROM people WHERE name IN
(SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw")))
AND name IN (SELECT name FROM people WHERE license_plate IN
(SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit"))
AND phone_number IN (SELECT caller FROM phone_calls  WHERE year = 2021 AND month = 7 AND day =28 AND duration < 60);
--+--------+----------------+
--|  name  |  phone_number  |
--+--------+----------------+
--| Taylor | (286) 555-6063 |
--| Diana  | (770) 555-1861 |
--| Bruce  | (367) 555-5533 |
--------+----------------+
SELECT * FROM passengers WHERE passport_number IN
(SELECT passport_number FROM people WHERE name IN
(SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw")))
AND name IN (SELECT name FROM people WHERE license_plate IN
(SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit"))
AND phone_number IN (SELECT caller FROM phone_calls  WHERE year = 2021 AND month = 7 AND day =28 AND duration < 60));
-----------+-----------------+------+
------------+-----------------+------+
--| flight_id | passport_number | seat |
--+-----------+-----------------+------+
--| 18        | 3592750733      | 4C   |
--| 24        | 3592750733      | 2C   |
--| 36        | 5773159633      | 4A   |
--| 54        | 3592750733      | 6C   |
--+-----------+-----------------+------+
--+--------+----------------+-----------------+
--|  name  |  phone_number  | passport_number |
--+--------+----------------+-----------------+
--| Taylor | (286) 555-6063 | 1988161715      |
--| Diana  | (770) 555-1861 | 3592750733      |
--| Bruce  | (367) 555-5533 | 5773159633      |
--------+----------------+-----------------+
 SELECT * FROM flights WHERE origin_airport_id =8 AND year = 2021 AND month >= 7 AND id IN
 (SELECT flight_id FROM passengers WHERE passport_number IN
(SELECT passport_number FROM people WHERE name IN
(SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
( SELECT account_number FROM atm_transactions  WHERE year = 2021 AND month = 7 AND day =28 AND atm_location LIKE "Leggett Street"  AND transaction_type = "withdraw")))
AND name IN (SELECT name FROM people WHERE license_plate IN
(SELECT  license_plate FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day =28 AND hour = 10  AND minute >=16 AND minute <=26 AND activity = "exit"))
AND phone_number IN (SELECT caller FROM phone_calls  WHERE year = 2021 AND month = 7 AND day =28 AND duration < 60)));
--| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20

 SELECT * FROM airports WHERE id =4;
 --+----+--------------+-------------------+---------------+
--| id | abbreviation |     full_name     |     city      |
--+----+--------------+-------------------+---------------+
--| 4  | LGA          | LaGuardia Airport | New York City |
----+--------------+-------------------+---------------+


SELECT * FROM phone_calls WHERE caller = "(367) 555-5533" AND  year = 2021 AND month = 7 AND day =28 AND duration < 60;
-----+----------------+----------------+------+-------+-----+----------+
--| id  |     caller     |    receiver    | year | month | day | duration |
--+-----+----------------+----------------+------+-------+-----+----------+
--| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
--+------+----------------+----------------+------+-------+-----+----------+

 SELECT * FROM people WHERE phone_number = "(375) 555-8161";
--+--------+-------+----------------+-----------------+---------------+
--|   id   | name  |  phone_number  | passport_number | license_plate |
--+--------+-------+----------------+-----------------+---------------+
--| 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
--+--------+-------+----------------+-----------------+---------------+