<?php
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = CS50::query("SELECT * FROM history WHERE user_id=? ORDER BY date DESC", $_SESSION["id"]);
        $records = [];
        foreach($rows as $row)
        {
            $records[] = [
                    "date" => $row["date"],
                    "transaction" => $row["action"],
                    "company" => $row["name"],
                    "symbol" => $row["symbol"],
                    "shares" => $row["shares"],
                    "price" => $row["price"],
                ];
        }
        render("history_view.php", ["title" => "History", "records" => $records, "table_id" => "history_table"]);
    }

?>