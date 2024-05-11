<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Škola</title>
</head>

<body>
    <h1>Vyhledávání</h1>
    <form>
        <label for="firstname">Jméno:</label><br>
        <input type="text" name="firstname" id="firstname"><br>
        <label for="surname">Příjmení:</label><br>
        <input type="text" name="surname" id="surname"><br>
        <label for="approbation">Aprobace:</label><br>
        <input type="text" name="approbation" id="approbation"><br>
        <br>
        <input type="submit" value="Hledat">
    </form>
    <h3>Výsledky</h3>
    <table>
        <tr>
            <th>Jméno</th>
            <th>Aprobace</th>
            <th>E-mail</th>
        </tr>
        <?php
        if (isset($_GET["firstname"])) {
            $dbconn = new PDO("mysql:dbname=skola;host=localhost", "root", "");
            $data = $dbconn->prepare("SELECT jmeno, prijmeni, aprob, titul, titul2, email FROM zamest WHERE jmeno LIKE :fname AND prijmeni LIKE :sname AND aprob LIKE :appro");
            $args[":fname"] = $_GET["firstname"] . "%";
            $args[":sname"] = $_GET["surname"] . "%";
            $args[":appro"] = "%" . $_GET["approbation"] . "%";
            $data->execute($args);
            while ($row = $data->fetch()) {
                echo "<tr>";
                echo "<td>" . ($row["titul"] == null ? "" : $row["titul"] . " ") . $row["jmeno"] . " " . $row["prijmeni"] . ($row["titul2"] == null ? "" : ", " . $row["titul2"]) . "</td>";
                echo "<td>" . $row["aprob"] . "</td>";
                echo "<td>" . $row["email"] . "</td>";
                echo "</tr>";
            }
        }
        ?>
    </table>
</body>

</html>
