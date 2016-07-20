<?php require("portfolio.php") ?>   
<div class="text-right">
    <form action="buy.php" class="form-inline" method="post">
        <fieldset>
            <div class="form-group sell_form">
                <input id="symbol_select" autofocus class="form-control input-lg" name="symbol" placeholder="Symbol" type="text"/>
            </div>
            <div class="form-group sell_form">
                <input autocomplete="off" class="form-control input-lg" name="shares" placeholder="Shares" type="tex"/>
            </div>
            <div class="form-group sell_form_left">
                <button class="btn btn-default btn-lg" type="submit">
                    <strong> Buy </strong>
                </button>
            </div>
        </fieldset>
    </form>
</div>