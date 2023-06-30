## Purchase history

#### Purchase history view

| **Field**                       | **System field name**       | **Format / possible values**     | **Description**                                                       |
|:-------------------------------:|:---------------------------:|:--------------------------------:|:--------------------------------------------------------------------:|
| Customer ID                     | Customer_ID                 | ---                              | ---                                                                   |
| Transaction ID                  | Transaction_ID              | ---                              | ---                                                                   |
| Transaction date                | Transaction_DateTime        | dd.mm.yyyyy hh:mm:ss.0000000     | The date when the transaction was made                                                                                                                                                                                             |
| SKU group                       | Group_ID                    | ---                              | The ID of the group of related products to which the product belongs (for example, same type of yogurt of the same manufacturer and volume, but different flavors). One identifier is specified for all products in the group  |
| Prime cost                      | Group_Cost                  | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |
| Base retail price               | Group_Summ                  | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |
| Actual cost paid                | Group_Summ_Paid             | Arabic numeral, decimal | ---                                                                                                                                                                                                                                         |

1. **Determination of customer transactions .**
   A list of unique transactions via all cards is formed for each customer. Use data contained in the `Transaction_ID`
   field of the [Transactions](../README.md#transactions-table) table. Binding with the customer
   identifier (`Customer_ID` of the [Personal data table](../README.md#personal-data-table)) is performed through
   identifiers of all customer cards (`Customer_Card_ID` field of [Cards] (../README.md#cards-table)
   and [Transactions] (../README.md#transactions-table)). The result is saved in the `Transaction_ID` field of the
   Purchase History table. Unique values of Customer ID (`Customer_ID`) - Transaction ID (`Transaction_ID`) are saved in
   the table.

2. **Determination of transaction dates.**
   The date of each transaction is specified. Use data contained in the `Transaction_DateTime` field of
   the [Transactions table](../README.md#transactions-table) to determine the date of transaction. Identification is
   made by the `Transaction_ID` field of Purchase History and [Transactions](../README.md#transactions-table) tables.
   The result is saved in the `Transaction_DateTime` field of the Purchase History table.

3. **SKU list determination.** A list of SKUs that were purchased by the customer within a particular transaction is
   specified for each transaction. Use data contained in the `SKU_ID` field of
   the [Checks table](../README.md#checks-table). The comparison is made using the data contained in
   the `Transaction_ID` field of Purchase History and [Checks](../README.md#checks-table) tables.

4. **SKU list deduplication.** SKU list is deduplicated individually for each transaction. A list of unique SKUs is
   formed for each transaction.

5. **Group list determination**  A group is specified for each SKU using data from the product grid. Use data contained
   in the `Group_ID` field of the Product grid table. The comparison is made using the `SKU_ID` field of the Purchase
   History and [Product grid](../README.md#product-grid-table) tables.

6. **Group list deduplication.**  A list of groups is deduplicated individually for each transaction. The final result
   is saved in the `Group_ID` field of the Purchase History table. The table must contain unique values formed from the
   aggregate of Customer ID (`Customer_ID`) – Transaction ID (`Transaction_ID`) – Group ID (`Group_ID`). The transaction
   date automatically applies to all groups that were purchased within this transaction.

7. **Calculation of financial indicators for a group.** For each customer the main financial indicators are calculated
   for each group by summing up similar indicators for all SKUs that are part of a particular group. The data from
   the [Checks table](../README.md#checks-table) is summed up. The following indicators are calculated:

    - The prime cost of products purchased by the customer during the analyzed period. The values obtained by
      multiplying the data from the `SKU_Purchase_Price` field by the data from the `SKU_Amount` field for all SKUs of
      the analyzed group for the customer are summed up. The data is saved in the `Group_Cost` field of
      the [Purchase History table](../README.md#purchase-history-view).

    - The base retail value during the analyzed period. The data from the `SKU_Summ` field for all SKUs of the analyzed
      group for the customer is summed up. The data is saved in the `Group_Summ` field of
      the [Purchase History table](../README.md#purchase-history-view).

    - The actual cost paid (including purchases made with loyalty program bonuses, but not including discounts). The
      data of the `SKU_Summ_Paid` field on all SKUs of the analyzed group for the customer is summed up. The data is
      saved in the `Group_Summ_Paid` field of the [Purchase history table](../README.md#purchase-history-view).
