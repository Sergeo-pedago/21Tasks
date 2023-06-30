# Groups

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

Determination of demanded SKU groups for each customer

1. **Forming a list of SKUs for a customer.**
   A list of all SKUs which the customer purchased during the analyzed period is formed for each customer (for all
   customer's cards). This is done by using data contained in the `SKU_ID` field of
   the [Checks table](../README.md#checks-table). To identify all customer transactions, use the data contained
   in `Transaction_ID` fields of [Checks] (../README.md#checks-table) and [Transactions](../README.
   md#transactions-table) tables, `Customer_Card_ID` field of [Transactions](../README.md#transactions-table)
   and [Cards](../README.md#cards-table) tables, `Customer_ID` of
   table [Personal data table](../README.md#personal-data-table).

2. **SKU list deduplication.**
   After forming the SKU list of each customer, the duplicates are removed so that each customer has a list of unique
   SKUs, which he purchased during the analyzed period.

3. **Determination of the list of demanded groups for a customer.**
   For each customer by each unique SKU using data from the product grid, the group to which this SKU belongs is
   specified. The data contained in the `SKU_ID` and `Group_ID` fields of
   the [product grid table](../README.md#product-grid-table) is used for this purpose.

4. **Group list deduplication.** After forming, the duplicates are removed from the list of groups demanded by the
   customer so that there is a list of unique groups for each customer, which he purchased during the analyzed period.
   The final result is saved in the `Group_ID` field of the [Periods](../README.md#periods-view) and Group tables. The
   tables must contain unique values formed from the pair Customer ID (`Customer_ID`) - Group ID (`Group_ID`).

Calculation of affinity

5. **Determination of the total number of customer transactions.** The total number of customer transactions made by the
   customer between the first and last transactions with the analyzed group (including transactions within which there
   was no analyzed group), including the first and last transactions with the group, is determined by counting the
   number of unique values in the `Transaction_ID` field of
   the [Purchase history table](../README.md#purchase-history-view), for which the date of transactions is more or equal
   to the date of the customer’s first transaction with the group (the value of the
   `First_Group_Purchase_Date`field of [Periods table](../README.md#periods-view)) and less than or equal to the date of
   the customer's last transaction with the group (value of the `Last_Group_Purchase_Date` field
   of [Periods table](../README.md#periods-view)).

6. **Calculation of the group affinity index.** The number of transactions with the analyzed group (value of
   the `Group_Purchase` field of the [Periods table](../README.md#periods-view)) is divided by the total number of
   customer transactions from first to last ones, involving the analyzed group. The final value is saved for the group
   in the `Group_Affinity_Index` field of the Group table.

Calculation of the churn index from a group

7. **Calculation of how long ago the group was purchased.** Subtract the last transaction date of a customer, that
   included the analyzed group, from the [date of analysis formation](../README.md#date-of-analysis-formation-table). To determine the last date of purchase of the group by the
   customer the maximum value of the `Transaction_DateTime` field of
   the [Purchase History table](../README.md#purchase-history-view) is selected for records where values of the
   fields `Customer_ID` and `Group_ID` correspond to values of similar fields of the Group table.

8. **Calculation of the churn rate.** Divide the number of days passed since the customer's last transaction with the
   analyzed group by the average number of days between purchases of the analyzed group by the customer (value of
   the `Group_Frequency` field of the [Periods table](../README.md#periods-view)). The total value is saved in
   the `Group_Churn_Rate` field of the Group table.

Calculation of group consumption stability

9. **Calculation of group consumption intervals.** All intervals (in number of days) between the customer transactions
    containing the analyzed group are determined. This is done by ranking all transactions containing the analyzed group
    in the customer purchases by date
    (value of the `Transaction_DateTime` field in the [Purchase history table](../README.md#-purchase-history-view))
    from the earliest to the latest. Subtract the date of the previous transaction from the date of each subsequent
    transaction. Each interval is treated separately.

10. **Calculation of the absolute deviation of each interval from the average frequency of group purchases.** The
    average number of days between transactions with the analyzed group (the value of the `Group_Frequency` field of
    the [Periods table](../README.md#periods-view)) is subtracted from the value of each interval. If the resulting
    value is negative, it is multiplied by -1.

11. **Calculation of the relative deviation of each interval from the average frequency of group purchases.** The value
    obtained at the previous step for each interval is divided by the average number of days between transactions with
    the analyzed group (value of the `Group_Frequency` field of the [Periods table](../README.md#periods-view)).

12. **Determination of group consumption stability.**
    The group consumption stability index is determined as the average value of all indicators obtained at the previous
    step. The result is saved in the `Group_Stability_Index` field of the Group table.

Calculation of the actual group margin for a customer

13. **Selection of the margin calculation method.**
    By default the margin is calculated for all transactions within the analyzed period (all available data is used).
    But users should be able to make individual settings and choose the actual margin calculation method - by period or
    by number of transactions.

- If the method of margin calculation by period is selected, the user specifies for how many days from the [date of analysis formation](../README.md#date-of-analysis-formation-table)
  in reverse chronological order it is necessary to calculate the margin. It takes all transactions, which contain the
  analyzed group, made by the user during the specified period. The data contained in the `Transaction_DateTime` field
  of the [Purchase history table](../README.md#purchase-history-view) is used for calculations.

- If the method of margin calculation by number of transactions is selected, the user specifies the number of
  transactions for which it is necessary to calculate the margin. Margin is calculated by the specified number of
  transactions, starting from the last one, in reverse chronological order. The data contained in
  the `Transaction_DateTime` field of the Purchase History table is used for calculations.

14. **Calculation of actual margin for the group.**
    To determine the actual margin of the group for the customer within the analyzed or specified by the user period you
    must subtract the prime cost of the purchased product (value of the `Group_Summ_Paid` field of
    the [Purchase history table](../README.md#purchase-history-view)) from the amount at which the product was
    purchased (`Group_Cost` field of the [Purchase history table](../README.md#purchase-history-view). The final value
    is saved as the actual margin for this group for the customer in the `Group_Margin` field of the Groups table.

Analysis of discounts for the group

15. **Determination of the number of discounted customer transactions.** The number of transactions in which the
    analyzed group was purchased by the customer using any discount is determined. Use unique values by
    the `Transaction_ID` field of the [Checks table](../README.md#checks-table) for transactions within which the
    customer purchased the analyzed group, value of the `SKU_Discount` field of
    the [Checks table](../README.md#checks-table) is greater than zero. The discount presented as a part of bonus points
    is not taken into account.

16. **Determination of the share of transactions with a discount.** The number of transactions in which the purchase of
    products from the analyzed group was made with a discount is divided by the total number of customer transactions
    with the analyzed group for the analyzed period (data of the `Group_Purchase` field of
    the [Periods table](../README.md#periods-view) for the analyzed group by the customer). The resulting value is saved
    as a share of transactions for the discounted purchase of the analyzed group in the `Group_Discount_Share` field of
    the Groups table.

17. **Determination of the minimum discount size for a group.** The minimum discount size for each group for each
    customer is determined. This is done by selecting the minimum non-zero value of the `Group_Min_Discount` field of
    the [Periods table](../README.md#periods-view) for the specified customer and group. The result is saved in
    the `Group_Minimum_Discount` field of the Groups table.

18. **Determination of the average group discount size.**
    To determine the average size of the group discount for the customer, the actual amount paid for the group purchase
    within all transactions (the value of the `Group_Summ_Paid` field of
    the [Purchase history table](../README.md#history-purchase-view) for all transactions) is divided by the amount of
    the retail value of this group within all transactions (the group sum by value of the `Group_Summ` field of
    the [Purchase history table](../README.md#history-purchase-view). The result is saved in
    the `Group_Average_Discount` field of the Groups table.
