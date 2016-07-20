
<?php require("portfolio.php") ?>   
<div id="sell_div" class="text-right">
    <form class="form-inline" action="sell.php" method="post">
        <fieldset>
            <div class="form-group sell_form">
                <select id="symbol_select" name="symbol" class="form-control input-lg">
                     <?php foreach ($positions as $id=>$position): ?>
                         <option> <?= $position["symbol"] ?> </option>
                     <?php endforeach ?>
                </select>
            </div>
            <div class="form-group sell_form">
                <input autocomplete="off" autofocus class="form-control input-lg" name="sell_amount" placeholder="Sell amount" value="0" type="text"/>
            </div>
            <div class="form-group sell_form_left">
                <button class="btn btn-default btn-lg" type="submit">
                    Sell
                </button>
            </div>
        </fieldset>
    </form>
</div>