-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check crime scene reports for matching date/time
SELECT id, description FROM crime_scene_reports
WHERE street = "Humphrey Street"
AND day = 28 AND month = 7 AND year = 2021;
-- crime_scene_reports id = 295, 10:15 am

-- Get interview transcripts
SELECT * FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021;
-- Ruth:161 "look for cars that left the parking lot", Eugene:162 "before... by the ATM on Leggett Street",
-- Raymond:163 "as leaving talked on phone less than a minute told partner to purchase earliest ticket tomorrow out of Fiftyville[29th]",

-- Look for cars leaving at time of theft
SELECT id, hour, minute, activity, license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year =2021;
--order left starting at 10:14-10:25 "13FNH73", "5P2BI95", "94KLI3X", "6P58WS2", "4328GD8","G412CB7", "L93JTIZ", "322W7JE", "0NTHK55"

-- As per witness 162 "before... by the ATM on Leggett Street" (found account_number in next step and inserted here)
SELECT id, account_number, transaction_type, amount FROM atm_transactions
WHERE day = 28 AND month = 7 AND year =2021 AND atm_location = "Leggett Street";
-- possible dead-end, not much info. Will come back.
-- need to connect atm_account number to bank_accounts/people using license plate
SELECT name, phone_number, passport_number, account_number FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE license_plate IN ("13FNH73", "5P2BI95", "94KLI3X", "6P58WS2", "4328GD8","G412CB7", "L93JTIZ", "322W7JE", "0NTHK55");
--sus name   phone            passport         account
--| Sophia | (027) 555-1068 | 3642612721      | 42445987       |
--| Diana  | (770) 555-1861 | 3592750733      | 26013199       | <---------- only one with phone call on day less than minute @ at bakery @ at ATM
--| Iman   | (829) 555-5269 | 7049073643      | 25506511       |
--| Luca   | (389) 555-5198 | 8496433585      | 28500762       |
--| Barry  | (301) 555-4174 | 7526138472      | 56171033       |


-- Look for first flight out of Fiftyville on 29th
SELECT * FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE day = 29 AND month = 7 AND year =2021;
-- earliest flight is 4|LGA|LaGuardia Airport|New York City|36|origin airport 8| destination airport 4| 8:20am

-- Use passsport_number to find destination of suspect
SELECT full_name, city, day, month, year FROM passengers
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id = airports.id
WHERE passport_number = 3592750733;

-- Use name (Luca) to get assistant per witness statement 163
SELECT * FROM phone_calls
WHERE caller IN ("(389) 555-5198", "(027) 555-1068", "(770) 555-1861", "(301) 555-4174", "(829) 555-5269")
AND day = 28 AND month = 7 AND year = 2021;
-- only person with phone call less than a minute on day of crime is
-- caller          reciever         year   month   day    duration
-- (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49

-- get accomplice name from number
SELECT * FROM people
WHERE phone_number = "(725) 555-3243";
-- id      name     phone number     passport number   license plate
-- 847116 | Philip | (725) 555-3243 | 3391710505      | GW362R6
