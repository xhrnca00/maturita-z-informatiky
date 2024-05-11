<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Škola</title>
</head>

<body>
    <h1>Škola</h1>
    <?php
    $fname = isset($_GET["firstname"]) && $_GET["firstname"] != "" ? $_GET["firstname"] : null;
    $sname = isset($_GET["surname"]) && $_GET["surname"] != "" ? $_GET["surname"] : null;
    $appro = isset($_GET["approbation"]) && $_GET["approbation"] != "" ? $_GET["approbation"] : null;
    ?>
    <h2>Zaměstnanci</h2>
    <form>
        <label for="firstname">Jméno: </label><br>
        <input type="text" name="firstname" id="firstname" value="<?php echo $fname ?>"><br>
        <label for="surname">Příjmení: </label><br>
        <input type="text" name="surname" id="surname" value="<?php echo $sname ?>"><br>
        <label for="approbation">Aprobace: </label><br>
        <input type="text" name="approbation" id="approbation" value="<?php echo $appro ?>"><br>
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
        $dbconn = new PDO("mysql:dbname=skola;host=localhost", "root", "");
        //! this is way too complicated for maturita
        $conditions = "";
        if ($fname != null) {
            if ($conditions != "") {
                $conditions .= " AND";
            }
            $conditions .= " jmeno LIKE :fname";
        }
        if ($sname != null) {
            if ($conditions != "") {
                $conditions .= " AND";
            }
            $conditions .= " prijmeni LIKE :sname";
        }
        if ($appro != null) {
            if ($conditions != "") {
                $conditions .= " AND";
            }
            $conditions .= " aprob LIKE :appro";
        }
        if ($conditions != "") {
            $conditions = " WHERE" . $conditions;
        }
        $data = $dbconn->prepare("SELECT jmeno, prijmeni, aprob, titul, titul2, email FROM zamest $conditions");
        if ($fname != null) {
            $data->bindParam("fname", $fname);
        }
        if ($sname != null) {
            $data->bindParam("sname", $sname);
        }
        if ($appro != null) {
            $data->bindParam("appro", $appro);
        }
        $data->execute();
        while ($row = $data->fetch()) {
            echo "<tr>";
            echo "<td>" . ($row["titul"] == null ? "" : $row["titul"] . " ") . $row["jmeno"] . " " . $row["prijmeni"] . ($row["titul2"] == null ? "" : ", " . $row["titul2"]) . "</td>";
            echo "<td>" . $row["aprob"] . "</td>";
            echo "<td>" . $row["email"] . "</td>";
            echo "</tr>";
        }
        ?>
    </table>
</body>

</html>
