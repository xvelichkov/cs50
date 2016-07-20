<div id="cash" class="pull-right">
    <h3> Cash: <strong> $<?= htmlspecialchars($cash) ?> </strong></h3>
</div>

<table id=<?= $table_id ?> class="table table-hover">
    <thead>
        <tr>
            <th> # </th>
            <th> Company </th>
            <th> Symbol </th>
            <th> Shares </th>
            <th> Current price </th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($positions as $id=>$position): ?>
            <tr>
                <th scope="role"><?= $id + 1 ?> </th>    
                <td id="name" class="text-left"><?= htmlspecialchars($position["name"]) ?></td>
                <td id="symbol" class="text-left"><?= htmlspecialchars($position["symbol"]) ?></td>
                <td id="shares" class="text-left"><?= htmlspecialchars($position["shares"]) ?></td>
                <td id="price" class="text-left"><?= htmlspecialchars($position["price"]) ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>