# RetailAnalytics v1.0

Retail analytics data upload, its simple analysis, statistics, customer segmentation and creation of personal offers.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
   2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
   3.1. [Part 1. Creating a database](#part-1-creating-a-database)  
   3.2. [Part 2. Creating views](#part-2-creating-views)  
   3.3. [Part 3. Role model](#part-3-role-model)  
   3.4. [Part 4. Forming personal offers aimed at the growth of the average check](#part-4-forming-personal-offers-aimed-at-the-growth-of-the-average-check)  
   3.5. [Part 5. Forming personal offers aimed at increasing the frequency of visits](#part-5-forming-personal-offers-aimed-at-increasing-the-frequency-of-visits)  
   3.6. [Part 6. Forming personal offers aimed at cross-selling](#part-6-forming-personal-offers-aimed-at-cross-selling)
4. [Chapter IV](#chapter-iv)


## Chapter I

![SQL3_RetailAnalytics_v1.0](misc/images/SQL3.PNG)

Chuck was holding the already slightly crumpled financial statements for the past period and trying to understand the numbers written there. He had been putting off processing, analyzing, and reconciling them for too long. And the paperwork seemed to be growing more and more every day, until finally the number of papers exceeded the critical value, when one can no longer deal with it alone. Chuck was sitting alone at the office, helplessly playing with the sheets in his hands, flipping through the pages as if hoping that this would help reduce their number, trying to figure out what kind of airplanes they could be made into. He wondered if he could make a paper boeing out of that much. He even googled instructions on how to do it.

But that didn't solve the problem, and the statements with numbers were still in front of him. \
`-` "Seems like it's high time to start using my SQL knowledge,'' Chuck thought to himself. - "If I can automate the processing and analysis, I won't need much help from anyone. Remembering SQL wasn't a waste of time after all.”

So Chuck only had a few things to do: formalize the data structure, the processing algorithms, and put it all into code. The key is not to get distracted again somewhere in the process...

## Introduction

In this project you will put into practice your knowledge of SQL.
You will need to create a database with knowledge of retailers' customers, and write the views and procedures needed to create personal offers.


## Chapter II

## General Rules

- Please make sure you are using the latest version of PostgreSQL.
- That is completely OK if you are using IDE to write a source code (aka SQL script).
- To be assessed your solution must be in your GIT repository.
- Your solutions will be evaluated by your peers.
- You should not leave in your directory any other file except sql scripts or csv files. It is recommended that you modify your `.gitignore` to avoid accidents.
- Do you have a question? Ask your neighbor on the right. Otherwise, try with your neighbor on the left.
- Your reference manual: peers / Internet / Google.
- And may the SQL-Force be with you!
- Absolutely everything can be presented in SQL! Let’s start and have fun!

## Logical view of database model

The data described in the [Input Data](#input-data) tables are filled in by the user.

The data described in the [Output Data](#output-data) views are calculated by the program. \
A more detailed description for filling in these views will be given below.

### Input Data

#### Personal information Table

| **Field**                   | **System field name**       | **Format / possible values**                                                     | **Description**                                                                                              |
|:---------------------------:|:---------------------------:|:--------------------------------------------------------------------------------:|:---------------------------------------------------------------------------------------------------------:|
| Customer ID                 | Customer_ID                 | ---                                                                              | ---                                                                                                       |
| Name                        | Customer_Name               | Cyrillic or Latin, the first letter is capitalized, the rest are lower case, dashes and spaces are allowed | ---                                                                                                       |
| Surname                     | Customer_Surname            | Cyrillic or Latin, the first letter is capitalized, the rest are lower case, dashes and spaces are allowed | ---                                                                                                       |
| Customer E-mail             | Customer_Primary_Email      | E-mail format                                                                    | ---                                                                                                                             |
| Customer phone number       | Customer_Primary_Phone      | +7 and 10 Arabic numerals                                                                 | ---                                                                                                       |

#### Cards Table

| **Field**   | **System field name**       | **Format / possible values**    | **Description**                    |
|:-----------:|:---------------------------:|:-------------------------------:|:----------------------------------:|
| Card ID     | Customer_Card_ID            | ---                             | ---                                |
| Customer ID | Customer_ID                 | ---                             | One customer can own several cards |

#### Transactions Table

| **Field**                | **System field name**       | **Format / possible values**    | **Description**                                               |
|:------------------------:|:---------------------------:|:-------------------------------:|:-------------------------------------------------------------------------:|
| Transaction ID           | Transaction_ID              | ---                             | Unique value                                                               |
| Card ID                  | Customer_Card_ID            | ---                             | ---                                                                        |
| Transaction sum          | Transaction_Summ            | Arabic numeral                  | Transaction sum in rubles(full purchase price excluding discounts) |
| Transaction date         | Transaction_DateTime        | dd.mm.yyyy hh:mm:ss             | Date and time when the transaction was made                                |
| Store                    | Transaction_Store_ID        | Store ID                        | The store where the transaction was made                                   |

#### Checks Table

| **Field**                                        | **System field name**  | **Format / possible values** | **Description**                                                                                                                  |
|:------------------------------------------------:|:----------------------:|:----------------------------:|:----------------------------------------------------------------------------------------------------------------:|
| Transaction ID                                   | Transaction_ID         | ---                          | Transaction ID is specified for all products in the check                                                         |
| Product in the check                             | SKU_ID                 | ---                          | ---                                                                                                               |
| Number of pieces or kilograms                    | SKU_Amount             | Arabic numeral               | The quantity of the purchased product                                                                             |
| Total amount for which the product was purchased | SKU_Summ               | Arabic numeral               | The purchase amount of the actual volume of this product in rubles (full price without discounts and bonuses) |
| The paid price of the product                    | SKU_Summ_Paid          | Arabic numeral               | The amount actually paid for the product not including the discount                                            |
| Discount granted                                 | SKU_Discount           | Arabic numeral               | The size of the discount granted for the product in rubles                                                 |

#### Product grid Table

| **Field**                     | **System field name**       | **Format / possible values**                  | **Description**                                                                                                                                                                                                |
|:-----------------------------:|:---------------------------:|:---------------------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| Product ID                    | SKU_ID                      | ---                                           | ---                                                                                                                                                                                                            |
| Product name                  | SKU_Name                    | Cyrillic or Latin, Arabic numerals, special characters | ---                                                                                                                                                                                                            |
| SKU group                     | Group_ID                    | ---                                           | The ID of the group of related products to which the product belongs (for example, same type of yogurt of the same manufacturer and volume, but different flavors). One identifier is specified for all products in the group |


#### Stores Table

| **Field**              | **System field name**    | **Format / possible values** | **Description**                                                  |
|:----------------------:|:------------------------:|:----------------------------:|:----------------------------------------------------------------:|
| Store                  | Transaction_Store_ID     | ---                          | ---                                                              |
| Product ID             | SKU_ID                   | ---                          | ---                                                              |
| Product purchase price | SKU_Purchase_Price       | Arabic numeral               | Purchasing price of products for this store                      |
| Product retail price   | SKU_Retail_Price         | Arabic numeral               | The sale price of the product excluding discounts for this store |


#### SKU group Table

| **Field**         | **System field name** | **Format / possible values**                  | **Description** |
|:-----------------:|:---------------------:|:---------------------------------------------:|:---------------:|
| SKU group         | Group_ID              | ---                                           | ---             |
| Group name        | Group_Name            | Cyrillic or Latin, Arabic numerals, special characters | ---             | 

#### Date of analysis formation Table

| **Field**         | **System field name** | **Format / possible values**                  | **Description** |
|:-----------------:|:---------------------:|:---------------------------------------------:|:---------------:|
| Date of analysis         | Analysis_Formation              | dd.mm.yyyy hh:mm:ss                                           | ---             |


### Output data

#### Customers View

| **Field**                                     | **System field name**          | **Format / possible values**     | **Description**                                                                  |
|:---------------------------------------------:|:------------------------------:|:--------------------------------:|:-----------------------------------------------------------------------------:|
| Customer ID                                   | Customer_ID                    | ---                              | Unique value                                                                   |
| Value of the average check                    | Customer_Average_Check         | Arabic numeral, decimal          | Value of the average check in rubles for the analyzed period                 |
| Average check segment                         | Customer_Average_Check_Segment | High; Medium; Low                | Segment description                                                            |
| Transaction frequency value                   | Customer_Frequency             | Arabic numeral, decimal          | Value of customer visit frequency in the average number of days between transactions |
| Transaction frequency segment                 | Customer_Frequency_Segment     | Often; Occasionally; Rarely      | Segment description                                                            |
| Number of days since the previous transaction | Customer_Inactive_Period       | Arabic numeral, decimal          | Number of days passed since the previous transaction date               |
| Churn rate                                    | Customer_Churn_Rate            | Arabic numeral, decimal          | Value of the customer churn rate                                               |
| Churn rate segment                            | Customer_Churn_Segment         | High; Medium; Low                | Segment description                                                            |
| Segment number                                | Customer_Segment               | Arabic numeral                   | The number of the segment to which the customer belongs                        |
| Main  store ID                                | Customer_Primary_Store         | ---                              | ---                                                                            |

#### Purchase history View

| **Field**                       | **System field name**       | **Format / possible values**     | **Description**                                                       |
|:-------------------------------:|:---------------------------:|:--------------------------------:|:--------------------------------------------------------------------:|
| Customer ID                     | Customer_ID                 | ---                              | ---                                                                   |
| Transaction ID                  | Transaction_ID              | ---                              | ---                                                                   |
| Transaction date                | Transaction_DateTime        | dd.mm.yyyyy hh:mm:ss.0000000     | The date when the transaction was made                                                                                                                                                                                             |
| SKU group                       | Group_ID                    | ---                              | The ID of the group of related products to which the product belongs (for example, same type of yogurt of the same manufacturer and volume, but different flavors). One identifier is specified for all products in the group  |
| Prime cost                      | Group_Cost                  | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |
| Base retail price               | Group_Summ                  | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |
| Actual cost paid                | Group_Summ_Paid             | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |

#### Periods View

| **Field**                                     | **System field name**       | **Format / possible values**     | **Description**                                                                                                                                                                                                 |
|:---------------------------------------------:|:---------------------------:|:--------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| Customer ID                                   | Customer_ID                 | ---                              | ---                                                                                                                                                                                                          |
| SKU group                                     | Group_ID                    | ---                              | The ID of the group of related products to which the product belongs (for example, same type of yogurt of the same manufacturer and volume, but different flavors). One identifier is specified for all products in the group |
| Date of first purchase of the group           | First_Group_Purchase_Date   | yyyy-mm-dd hh:mm:ss.0000000      | ---                                                                                                                                                                                                          |
| Date of last purchase of the group            | Last_Group_Purchase_Date    | yyyy-mm-dd hh:mm:ss.0000000      | ---                                                                                                                                                                                                          |
| Number of transactions with the group         | Group_Purchase              | Arabic numeral, decimal          | ---                                                                                                                                                                                                          |
| Intensity of group purchases                  | Group_Frequency             | Arabic numeral, decimal          | ---                                                                                                                                                                                                          |
| Minimum group discount                        | Group_Min_Discount          | Arabic numeral, decimal | ---                                                                                                                                                                                                          |

#### Groups View

| **Field**                              | **System field name**       | **Format / possible values**     | **Description**                                                                                                                        |
|:--------------------------------------:|:---------------------------:|:--------------------------------:|:-----------------------------------------------------------------------------------------------------------------------------------:|
| Customer ID                            | Customer_ID                 | ---                              | ---                                                                                                                                 |
| Group ID                               | Group_ID                    | ---                              | ---                                                                                                                                 |
| Affinity index                         | Group_Affinity_Index        | Arabic numeral, decimal          | Customer affinity index for this group                                                                                 |
| Churn index                            | Group_Churn_Rate            | Arabic numeral, decimal          | Customer churn index for a specific group                                                                                          |
| Stability index                        | Group_Stability_Index       | Arabic numeral, decimal          | Indicator demonstrating the stability of the customer consumption of the group                                                                |
| Actual margin for the group            | Group_Margin                | Arabic numeral, decimal          | Indicator of the actual margin for the group for a particular customer                                                                       |
| Share of transactions with a discount  | Group_Discount_Share        | Arabic numeral, decimal          | Share of purchasing transactions of the group by a customer, within which the discount was applied (excluding the loyalty program bonuses) |
| Minimum size of the discount           | Group_Minimum_Discount      | Arabic numeral, decimal          | Minimum size of the group discount for the customer                                                                    |
| Average discount                       | Group_Average_Discount      | Arabic numeral, decimal          | Average size of the group discount for the customer                                                                                         |


## Chapter III

## Part 1. Creating a database

Write a *part1.sql* script that creates the database and tables described above in the [Input data](#input-data).

Also, add procedures to the script that allow you to import and export data for each table from/to a file with *.csv* and *.tsv* extensions. \
A separator is specified as a parameter of each procedure for importing from a *csv* file.

Enter at least 5 records in every table.
As you progress through the task, you will need new data to test all of your choices.
This new data should also be added to this script. \
Some test data could be found in the *datasets* folder.

If *csv* or *tsv* files were used to add data to the tables, they must also be uploaded to the GIT repository.

## Part 2. Creating views

Create a *part2.sql* script and write the views described above in the [Output data](#output-data). Also add test queries for each view. It is acceptable to create a separate script starting with *part2_* for each view.

You can find more information for each field in the materials.

## Part 3. Role model

Create roles in the *part3.sql* script and give them permissions as described below.

#### Administrator
The administrator has full permissions to edit and view any information, start and stop the processing.

#### Visitor
Only view information of all tables.

## Part 4. Forming personal offers aimed at the growth of the average check

Create a *part4.sql* script, in which you should add the following function.

### Write a function that determines offers that aimed at the growth of the average check
Function parameters:
- average check calculation method (1 - per period, 2 - per quantity)
- first and last dates of the period (for method 1)
- number of transactions (for method 2)
- coefficient of average check increase
- maximum churn index
- maximum share of transactions with a discount (in percent)
- allowable share of margin (in percent)

##### Offer condition determination

1.  **Choosing the method of calculating the average check.**
    There is an option to choose a method of calculating an average check - for a certain period of time or for a certain number of recent transactions. The calculation method *manually determined* by the user.

    1. The user selects the calculation method **by period**, and then specifies the first and last dates of the period for which you want to calculate the average check for the entire population of customers in the sample. Here, the last date of the specified period must be later than the first one, and the specified period must be within the total analyzed period. If the date is too early or too late, the system automatically substitutes the date of the beginning or the end of the analyzed period respectively. All transactions made by each specific customer during a given period are considered for the calculation.

    2. The user selects the calculation method **by the number of recent transactions**, and then manually specifies the number of transactions for which it is necessary to calculate the average check. To calculate the average check, we take the user-specified number of transactions, starting with the most recent one in reverse chronological order. In case any customer from the sample makes less than the specified number of transactions during the whole analyzed period, the available number of transactions is used for the analysis.

2.  **Determination of the average check.** For each customer, the current value of the average check is determined according to the method selected in step 1. This is done by dividing the total turnover of all transactions of a customer in the sample by the number of these transactions. The final value is saved in the table as the current value of the average check.

3.  **Determination of the target value of the average check.** The calculated value of the average check is multiplied by the coefficient set by the user. The received value is saved in the system as a target value of the average check of the customer and further is used to form the offer condition, which must be fulfilled by the customer to get the reward.

##### Reward determination

4.  **Determination of the group to form the reward.** A group that meets the following criteria in sequence is selected to form the reward:

    -  The affinity index of the group is the highest possible.

- The churn index for this group should not exceed the value set by the user. If the churn index exceeds the set value, the next group by the affinity index is used;

    - The share of transactions with a discount for this group is less than the value set by the user. If the selected group exceeds the set value, the next group by the affinity index that also meets the churn criterion is used. 

5.  **Determination of the maximum allowable size of a discount for the reward.**

The user manually determines the share of margin (in percent) that is allowed to be used to provide a reward for the group. The final value of the maximum allowable discount is calculated by multiplying the set value by the average customer margin for the group.

6.  **Determination of the discount size**. The value obtained at step 5 is compared to the minimum discount that was fixed for the customer for the given group, rounded up in increments of 5%. If the minimum discount after rounding is less than the value obtained at step 5, it is set as a discount for the group within the offer for the customer. Otherwise, this group is excluded from consideration, and to form an offer for the customer the process is repeated, starting with step 4 (the next appropriate group according to the described criteria is used).

Function output:

| **Field**                      | **System field name**      | **Format / possible values**                | **Description**                                                                               |
|--------------------------------|-----------------------------|--------------------------------------------|----------------------------------------------------------------------------------------------|
| Customer ID                    | Customer_ID                 |                                            |                                                                                               |
| Average check target value     | Required_Check_Measure      | Arabic numeral (decimal)                   | Target value of the average check required to receive a reward                               |
| Offer group                    | Group_Name                  |                                            | The name of the offer group, for which the reward is accrued when the condition is met.   |
| Maximum discount depth         | Offer_Discount_Depth        | Arabic numeral (decimal), percent          | The maximum possible discount for the offer                                                   |


## Part 5. Forming personal offers aimed at increasing the frequency of visits

Create a *part5.sql* script and add the following function to it.

### Write a function that determines offers aimed at increasing the frequency of visits
Function parameters:
- first and last dates of the period
- added number of transactions
- maximum churn index
- maximum share of transactions with a discount (in percent)
- allowable margin share (in percent)

##### Offer condition determination

1. **Period determination**.
   The user manually sets the period of validity of the developing offer, specifying its start and end dates.

2. **Determination of the current frequency of customer visits in the specified period.**
   The start date is subtracted from the end date of the specified period, after which the received value is divided by the average intensity of customer transactions (`Customer_Frequency` of the [Customers Table](#customers-view)). The final result is saved as the base intensity of customer transactions during the specified period.

3. **Determination of the reward transaction.**
   The system determines the serial number of the transaction within the specified period, for which the reward should be accrued. For this, the value obtained at step 2 is rounded according to arithmetic rules to an integer, and then the number of transactions specified by the user is added to it. The final value is the target number of transactions that the customer must make to receive the reward.

##### Reward determination

4.  **Determination of the group to form the reward.** A group that meets the following criteria in sequence is selected to form the reward:

    -  The affinity index of the group is the highest possible.

    -  The churn index for this group should not exceed the value set by the user. If the churn rate exceeds the set value, the next group according to the affinity index is selected;

    -  The share of transactions with a discount for this group is less than the user-defined value. If the selected group exceeds the set value, the next group is selected according to the affinity index, which also meets the churn criterion.

5.  **Determination of the maximum allowable discount for the reward.** The user manually determines the share of margin (in percent) that is allowed to be used to provide a reward for the group. The final value of the maximum allowable discount is calculated by multiplying the set value by the average customer margin for the group.

6.  **Determination of the discount size**. The value obtained at step 5 is compared to the minimum discount that was fixed for the customer for the given group, rounded up in increments of 5%. If the minimum discount after rounding is less than the value obtained at step 5, it is set as a discount for the group within the offer for the customer. Otherwise, this group is excluded from consideration, and to form an offer for the customer the process is repeated, starting with step 4 (the next appropriate group according to the described criteria is used).

Function output:

| **Field**                     | **System field name**       | **Format / possible values**      | **Description**
|-------------------------------|-----------------------------|-----------------------------------|--------------------------------------------------------------------------------------------|
| Customer ID                   | Customer_ID                 |                                   |                                                                                            |
| Period start date             | Start_Date                  | yyyy-mm-dd hh:mm:ss.0000000       | The start date of the period during which transactions must be made
| Period end date               | End_Date                    | yyyy-mm-dd hh:mm:ss.0000000       | The end date of the period during which transactions must be made                 |
| Target number of transactions | Required_Transactions_Count | Arabic numeral (decimal)          | Serial number of the transaction to which the reward is accrued                         |
| Offer group                   | Group_Name                  |                                   | The name of the offer group, to which the reward is accrued when the condition is met. |
| Maximum discount depth        | Offer_Discount_Depth        | Arabic numeral (decimal), percent | The maximum possible discount for the offer                                        |


## Part 6. Forming personal offers aimed at cross-selling

Create a *part6.sql* script and add the following function to it.

### Write a function that determines offers aimed at cross-selling (margin growth)
Function parameters:
- number of groups
- maximum churn index
- maximum consumption stability index
- maximum SKU share (in percent)
- allowable margin share (in percent)

Offers aimed at margin growth due to cross-sales involve switching the customer to the highest margin SKU within the demanded group.

1.  **Group selection.** To form offers aimed at margin growth due to cross-sales, several groups  with the maximum affinity index (the number is *set* by the user) are selected for each customer and meet the following conditions:

    1. The churn index for the group is not more than the value set by the user.

    2. The consumption stability index is less than the value set by the user.

2.  **Determination of SKU with maximum margin.** SKU with the maximum margin is determined in each group (in rubles).This is done by subtracting the purchase price (`SKU_Purchase_Price`) from retail price of the product (`SKU_Retail_Price`)  for all SKUs of the group represented in the store, and then selecting one SKU with the maximum value of the specified difference.

3.  **Determination of the SKU share in a group.** The share of transactions where the analyzed SKU is present is determined. This is done by dividing the number of transactions containing this SKU by the number of transactions containing the group as a whole (for the analyzed period). SKU is used to form an offer only if the resulting value does not exceed the value set by the user.

4.  **Determination of the margin share for discount calculation.** The user *manually determines* the margin share (in percent) that is allowable to be used to provide rewards for SKU (a single value is set for the whole set of customers).

5.  **Discount calculation.** The value *set* by the user at step 4 is multiplied by the difference between the retail (`SKU_Retail_Price`) and purchase (`SKU_Purchase_Price`) prices, and the resulting value is divided by the retail SKU price (`SKU_Retail_Price`). All prices are for the customer's main store. If the resulting value is equal to or greater than the minimum user discount for the analyzed group rounded up in increments of 5%, the minimum discount for the group rounded up in increments of 5% is set as a discount for the given SKU for the customer. Otherwise, no offer is formed for the customer for this group.

Function output:

| **Field**              | **System field name** | **Format / possible values**       | **Description**                                                |
|------------------------|-----------------------|------------------------------------|-----------------------------------------------------------------------------------------|
| Customer ID            | Customer_ID           |                                    |                                                       |
| SKU offers             | SKU_Name              |                                    | The name of the SKU offer, to which the reward is accrued when the condition is met. |
| Maximum discount depth | Offer_Discount_Depth  | Arabic numeral (decimal), percent  | The maximum possible discount for the offer                                    |


## Chapter IV

Chuck had been staring at the screen for hours and couldn't figure it out. A certain "AID" department disappears from the statements as fast as appears, literally in the blink of an eye.
All expenses are written off for the development of smart vacuum cleaners, something only the household department has been doing for a long time. Yes, there was a new SP-21 model released at the same time, but still what is this: an innocent typo in the name or an opportune moment? The question that will haunt Chuck in the near future...


💡 [Tap here](https://forms.yandex.ru/cloud/641820bf5d2a060d5d1b2b40/) **to leave your feedback on the project**. Pedago Team really tries to make your educational experience better.
