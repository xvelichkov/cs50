<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    if($_SERVER["REQUEST_METHOD"] == "GET" && !empty($_GET["geo"]))
    {
        $params = array_map('trim', explode(",", urldecode($_GET["geo"])));
        
        foreach($params as &$param)
        {
           $param = "+" . "$param" . "*";
        }
        
        $geo = implode(' ', $params);
        
        if(count($params) > 2)
        {
            $places = CS50::query("SELECT * FROM places WHERE MATCH(country_code,
                                                                    postal_code,
                                                                    place_name,
                                                                    admin_name1) AGAINST(? IN BOOLEAN MODE )", $geo);
        }
        else
        {
            $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code,
                                                                    place_name) AGAINST(? IN BOOLEAN MODE )", $geo);
        }
                                                            
    }
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json; charset=utf8");
    print(json_encode($places, JSON_PRETTY_PRINT | JSON_UNESCAPED_UNICODE));

?>