## Customers

#### Customers View

| **Field**                                     | **System field name**          | **Format / possible values**     | **Description**                                                                  |
|:---------------------------------------------:|:------------------------------:|:--------------------------------:|:-----------------------------------------------------------------------------:|
| Customer ID                                   | Customer_ID                    | ---                              | Unique value                                                                   |
| Value of the average check                    | Customer_Average_Check         | Arabic numeral, decimal          | Value of the average check in rubles for the analyzed period                 |
| Average check segment                         | Customer_Average_Check_Segment | High; Medium; Low                | Segment description                                                            |
| Transaction frequency value                   | Customer_Frequency             | Arabic numeral, decimal          | Value of customer visit frequency in the average number of days between transactions. Time is also taken into account, i.e. the result may not be an integer |
| Transaction frequency segment                 | Customer_Frequency_Segment     | Often; Occasionally; Rarely      | Segment description                                                            |
| Number of days since the previous transaction | Customer_Inactive_Period       | Arabic numeral, decimal          | Number of days passed since the previous transaction date. Time is also taken into account, i.e. the result may not be an integer               |
| Churn rate                                    | Customer_Churn_Rate            | Arabic numeral, decimal          | Value of the customer churn rate                                               |
| Churn rate segment                            | Customer_Churn_Segment         | High; Medium; Low                | Segment description                                                            |
| Segment number                                | Customer_Segment               | Arabic numeral                   | The number of the segment to which the customer belongs                        |
| Main  store ID                                | Customer_Primary_Store         | ---                              | ---                                                                            |

Segmentation by average check size

1. **Card list formation.**
   For each client the list of all its cards is formed using data in fields `Customer_ID` and `Customer_Card_ID`
   of [Cards table](../README.md#cards-table).

2. **Calculation of the average check.**
   The size of the average check for the analyzed period is determined for each customer. Data source is
   the [Transactions table](../README.md#transactions-table). All card transactions of each customer by
   the  `Transaction_Summ` field of the [Transactions table](../README.md#transactions-table) are summed up, and then
   the resulting amount is divided by the number of transactions. The received data is saved in
   the `Customer_Average_Check` field of the Customers table .

3. **Customers ranking.**
   All customers in the sample are ranked by the average check size (`Customer_Average_Check` of the Customers table)
   from the highest to the lowest values.

4. **Determination of the segment.**
   10% of customers with the highest average check are in the `High` segment. The next 25% of customers with the highest
   average check are in the `Medium` segment. The remaining customers with the lowest average check are in the `Low`
   segment. The data is specified in the `Customer_Average_Check_Segment` field of the Customers table.

Segmentation by frequency of visits

5. **Determination of transactions intensity.** The current frequency of customer visits in the average interval between
   the visits in days is determined for each customer. This is done by subtracting the date of the earliest transaction
   for the analyzed period from the date of the latest transaction at the moment of forming the analysis. Use data from
   the `Transaction_DateTime` field of [Transactions table](../README.md#transactions-table). The received value is
   divided by the total number of customer transactions for the analyzed period. The number of customer transactions is
   defined as the number of unique values in the `Transaction_ID` field for all customer cards. The received data is
   saved in the `Customer_Frequency` field of the Customers table.

6. **Customers ranking.**
   All customers in the sample are ranked by frequency of visits (`Customer_Frequency` of Customers table) from the
   lowest to the highest values.

7. **Determination of the segment.** 10% of customers with the shortest visit intervals have the highest frequency of
   visits and belong to the `Often` segment. The next 25% of customers with the shortest visit intervals are in
   the `Occasionally` segment. The remaining 65% of customers are in the `Rarely` segment. The data is specified in the `Customer_Frequency_Segment` field of the Customers table.

Segmentation by churn probability

8. **Determination of the period after the previous transaction.** It is necessary to determine the number of days
   passed since the latest transaction at the moment of analysis for each customer. This is done by subtracting the date
   of the latest customer transaction from the [date of analysis formation](../README.md#date-of-analysis-formation-table). Use data from
   the `Transaction_DateTime` field of [Transactions table](../README.md#transactions-table) for all cards of the
   customer.

9. **Calculation of churn rate.** For each customer, the number of days passed since the previous transaction (value of
   the `Customer_Inactive_Period` field of the Customers table) is divided by the customer past transaction intensity (
   value of the `Customer_Frequency` field of the Customers table). The result is saved in the `Customer_Churn_Rate`
   field of the Customers table.

10. **Determination of churn probability.**
    If the received coefficient is in the range from 0 to 2, the probability of the customer churn is considered `Low`.
    If the coefficient is in the range from 2 to 5, the probability of churn is considered `Medium`. If the value
    exceeds 5, it is considered to be `High`. The result is saved in the `Customer_Churn_Segment` field of the Customers
    table.

Assigning a segment number to a customer

11. **Segment number assignment.**
    Based on the combination of customer values in the fields `Customer_Average_Check_Segment`
    , `Customer_Frequency_Segment` and `Customer_Churn_Segment` of the Customers table, the customer is assigned a
    segment number according to the following table:

| **Segment** | **Average check** | **Frequency of purchases** | **Churn probability** |
|-------------|-------------------|----------------------------|-----------------------|
| 1           | Low               | Rarely                     | Low                   |
| 2           | Low               | Rarely                     | Medium                |
| 3           | Low               | Rarely                     | High                  |
| 4           | Low               | Occasionally               | Low                   |
| 5           | Low               | Occasionally               | Medium                |
| 6           | Low               | Occasionally               | High                  |
| 7           | Low               | Often                      | Low                   |
| 8           | Low               | Often                      | Medium                |
| 9           | Low               | Often                      | High                  |
| 10          | Medium            | Rarely                     | Low                   |
| 11          | Medium            | Rarely                     | Medium                |
| 12          | Medium            | Rarely                     | High                  |
| 13          | Medium            | Occasionally               | Low                   |
| 14          | Medium            | Occasionally               | Medium                |
| 15          | Medium            | Occasionally               | High                  |
| 16          | Medium            | Often                      | Low                   |
| 17          | Medium            | Often                      | Medium                |
| 18          | Medium            | Often                      | High                  |
| 19          | High              | Rarely                     | Low                   |
| 20          | High              | Rarely                     | Medium                |
| 21          | High              | Rarely                     | High                  |
| 22          | High              | Occasionally               | Low                   |
| 23          | High              | Occasionally               | Medium                |
| 24          | High              | Occasionally               | High                  |
| 25          | High              | Often                      | Low                   |
| 26          | High              | Often                      | Medium                |
| 27          | High              | Often                      | High                  |

Determination of the customer main store

12. **Determination of the customer store list.**
    A list of stores is formed for each customer for all his cards, where he has made transactions during the analyzed
    period. One customer can have more than one store. Use data contained in the `Transaction_Store_ID` field of
    the [Transactions table](../README.md#transactions-table). After formation the list is deduplicated.

13. **Calculation of the share of transactions in each store.** The share of transactions is specified for each store in
    which the customer made purchases. This is done by dividing the number of unique transactions in each particular
    store by the total number of unique customer transactions. Use data contained in the `Transaction_ID`
    and `Transaction_Store_ID` fields of the [Transactions table](../README.md#transactions-table).

14. **Determination of the store(s) in which the customer has made the three most recent transactions.**
    The store(s) in which the three most recent transactions have been made is determined for each customer for all his
    cards. Use data contained in the `Transaction_Store_ID` and `Transaction_DateTime` fields.

15. **Determination of the customer main store.**
    The main store is determined for each customer. If the three most recent transactions have been made in the same
    store, that store is set as the main store of the customer. Otherwise, the store with the largest share of all
    customer transactions is set as the main one. If several stores have the same share of transactions, the store with
    the most recent transaction is selected as the main one. The resulting value is specified in
    the `Customer_Primary_Store` field of the Customers table.

