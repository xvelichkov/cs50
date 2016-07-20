<p>
    <span>A share of </span>
    <?php if (isset($name)): ?>
        <span> <?= htmlspecialchars($name) ?></span>
    <?php else: ?>
        <span> Unknown </span>
    <?php endif ?>
    
    <span> costs </span>
    <?php if (isset($price)): ?>
        <span> <strong> $<?= htmlspecialchars($price) ?> </strong> </span>
    <?php else: ?>
        <span> Unknown </span>
    <?php endif ?>
</p>