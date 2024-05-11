<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Zoo</title>
</head>

<body>
    <h1>Zoo</h1>
    <ul>
        <?php
        $dbconn = new PDO("mysql:host=localhost;dbname=zoo", "root", "");
        $photos = $dbconn->prepare("SELECT * FROM foto");
        $photos->execute();
        while ($row = $photos->fetch()) {
            echo "<li>";
            echo "<a href='" . $row["path"] . "'>" . $row["description"] . "</a>";
            echo "</li>";
        }
        ?>
    </ul>
</body>

</html>
