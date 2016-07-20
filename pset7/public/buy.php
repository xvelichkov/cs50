<?php
    
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $portfolio = get_portfolio($_SESSION["id"]);    
        render("buy_form.php", ["positions" => $portfolio["positions"], 
                         "cash" => number_format($portfolio["cash"], 2),
                         "title" => "Portfolio",
                         "table_id" => "buy_table"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(!empty($_POST["shares"]))
        {
            if(!empty($_POST["symbol"]))
            {
                $shares = $_POST["shares"];
                $stock = lookup($_POST["symbol"]);
                if (!empty($stock))
                {
                    $price = $stock["price"];
                    $rows = CS50::query("SELECT cash FROM users WHERE id=?", $_SESSION["id"]);
                    
                    $cash = 0.0;
                    if(!empty($rows))
                    {
                         $cash = $rows[0]["cash"];
                    }
                    else
                    {
                        apologize("Cannot get cash");
                    }
                    
                    if($cash >= $shares*$price)
                    {
                        CS50::query("INSERT portfolios (user_id, symbol, shares) VALUES (?, ?, ?)
                                    ON DUPLICATE KEY UPDATE
                                    shares = shares + ?", $_SESSION["id"], $_POST["symbol"], $shares, $shares);
                        
                        CS50::query("UPDATE users SET cash=cash-? WHERE id=?", $shares*$price, $_SESSION["id"]);
                        
                        CS50::query("INSERT history (user_id, name, symbol, shares, action, price, date) 
                                     VALUES (?, ?, ?, ?, 'Buy', ?, NOW())",
                                     $_SESSION["id"],
                                     $stock["name"],
                                     $_POST["symbol"],
                                     $shares,
                                     $price);
                                     
                        redirect("buy.php");
                    }
                    else
                    {
                        apologize("Not enough cash. You can deposit new funds.", "<a href='deposit.php'> Deposit </a>");
                    }
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
        else
        {
            apologize("Plase enter shares.");
        }
    }
?>