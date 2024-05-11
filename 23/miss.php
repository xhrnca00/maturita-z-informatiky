<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Miss</title>
</head>

<body>
    <h1>Miss</h1>
    <?php
    $dbconn = new PDO("mysql:dbname=miss;host=localhost", "root", "");
    if (isset($_GET["id"])) {
        // we are voting
        $increment = $dbconn->prepare("UPDATE soutezici SET votes = votes + 1 WHERE id = :id");
        $increment->bindParam("id", $_GET["id"], PDO::PARAM_STR);
        $increment->execute();
    }
    $contestants = $dbconn->prepare("SELECT * FROM soutezici");
    $contestants->execute();
    while ($row = $contestants->fetch()) {
        echo "<p>";
        echo "<h3>" . $row["firstname"] . " " . $row["surname"] . "</h3>";
        echo "Míry: " . $row["measurements"] . "<br>";
        echo "Počet hlasů: " . $row["votes"] . "<br>";
        echo '<a href="' . basename(__FILE__) . "?id=" . $row["id"] . '">Hlasovat</a>';
        echo "</p>";
        echo "<hr>";
    }
    ?>
</body>

</html>
