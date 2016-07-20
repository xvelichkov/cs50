<?php
    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $portfolio = get_portfolio($_SESSION["id"]);
        render("sell_form.php", ["positions" => $portfolio["positions"], 
                                 "cash" => number_format($portfolio["cash"], 2),
                                 "title" => "Portfolio",
                                 "table_id" => "sell_table"]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $sell_amount = (int)$_POST["sell_amount"];
        if($sell_amount <= 0)
        {
            apologize("Please enter a number bigger than 0");
        }
        else
        {
            $symbol = $_POST["symbol"];
            
            $rows = CS50::query("SELECT users.cash, portfolios.shares, portfolios.symbol 
                                FROM users JOIN portfolios ON users.id = portfolios.user_id 
                                WHERE users.id = ? AND portfolios.symbol = ?", $_SESSION["id"], $symbol);
                                
            if(!empty($rows))
            {
                $cash = $rows[0]["cash"];
                $shares = $rows[0]["shares"];
                $price = 0;
                
                $stock = lookup($symbol);
                if ($stock !== false)
                {
                    $price = $stock["price"];
                }
                else
                {
                    apologize("Cannot get price for {$symbol}");
                }
                
                if($sell_amount <= $shares)
                {
                    $remaining = $shares - $sell_amount;
                    if($remaining > 0)
                    {
                        CS50::query("UPDATE portfolios SET shares=? WHERE user_id=? AND symbol=?",
                            $remaining,
                            $_SESSION["id"],
                            $symbol
                        );
                    }
                    else
                    {
                        CS50::query("DELETE FROM portfolios WHERE user_id=? AND symbol=?",
                            $_SESSION["id"],
                            $symbol);
                    }
                    
                    CS50::query("UPDATE users SET cash = cash + ? WHERE id=?",
                        $sell_amount*$price,
                        $_SESSION["id"]);
                    
                    CS50::query("INSERT history (user_id, name, symbol, shares, action, price, date) 
                                 VALUES (?, ?, ?, ?, 'Sell', ?, NOW())",
                                 $_SESSION["id"],
                                 $stock["name"],
                                 $symbol,
                                 $sell_amount,
                                 $price);
                    
                    redirect("sell.php");
                }
                else
                {
                    apologize("Not enough shares to sell. Please enter number smaller or equal to {$shares}");
                }
            }
        }
    }

?>