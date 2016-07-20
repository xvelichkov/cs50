<table id=<?= $table_id ?> class="table table-hover">
    <thead>
        <tr>
            <th> # </th>
            <th> Date </th>
            <th> Transaction </th>
            <th> Company </th>
            <th> Name </th>
            <th> Shares </th>
            <th> Price </th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($records as $id=>$record): ?>
            <tr>
                <th scope="role"><?= $id + 1 ?> </th>
                <td id="date" class="text-left"><?= htmlspecialchars($record["date"]) ?></td>
                <td id="transaction" class="text-left"><?= htmlspecialchars($record["transaction"]) ?></td>
                <td id="name" class="text-left"><?= htmlspecialchars($record["company"]) ?></td>
                <td id="symbol" class="text-left"><?= htmlspecialchars($record["symbol"]) ?></td>
                <td id="shares" class="text-left"><?= htmlspecialchars($record["shares"]) ?></td>
                <td id="price" class="text-left"><?= htmlspecialchars($record["price"]) ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>


