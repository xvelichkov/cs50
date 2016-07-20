<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    $portfolio = get_portfolio($_SESSION["id"]);

    render("portfolio.php", ["positions" => $portfolio["positions"], 
                             "cash" => number_format($portfolio["cash"], 2), 
                             "title" => "Portfolio",
                             "table_id" => "portfolio_table"]);

?>
