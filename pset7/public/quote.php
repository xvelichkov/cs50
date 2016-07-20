<?php
    require("../includes/config.php");
    
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("get_quote_form.php");
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(!empty($_POST["symbol"]))
        {
            $stock = lookup($_POST["symbol"]);
            if (!empty($stock))
            {
                render("show_quote.php", ["name" => $stock["name"],
                                          "price" => number_format($stock["price"], 2)]);
            }
            else
            {
                apologize("symbol {$_POST['symbol']} not found");
            }
        }
        else
        {
            apologize("Please enter a symbol."); 
        }
    }
?>