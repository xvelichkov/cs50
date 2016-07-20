<?php
    // configuration
    require("../includes/config.php");
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_password_form.php", ["title" => "Change password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm you password.");
        }

        if($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Passwords are not same.");
        }

        $result = CS50::query("
            UPDATE IGNORE users SET hash=?", 
            password_hash($_POST["password"], PASSWORD_DEFAULT));
            
        redirect("/");
    }
?>