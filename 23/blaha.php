<!DOCTYPE html>
<html lang="cs">

<head>
    <title></title>
    <meta charset="utf-8">
    <meta name="description" content="">
    <meta name="keywords" content="">
    <meta name="author" content="">
    <meta name="robots" content="all">
    <!-- <meta http-equiv="X-UA-Compatible" content="IE=edge"> -->
    <link href="/favicon.png" rel="shortcut icon" type="image/png">
</head>

<body>
    <h1>Miss 2024</h1>
    <?php
    // db renames: votes -> ph, firstname -> jmeno, surname -> prijmeni, measurements -> miry
    $kam = "mysql:host=localhost;dbname=miss";
    $uzivatel = "root";
    $heslo = "";
    //pripoj se k serveru a zvol databazi
    $databaze = new PDO($kam, $uzivatel, $heslo);

    if (isset($_GET["id"])) {
        $dotaz = $databaze->prepare("UPDATE soutezici SET votes=votes+1 WHERE id = :idPar");
        //nachystej si pole s parametry
        $polePar[":idPar"] = $_GET["id"];
        //posli dotaz do serveru a dodej potřebný parametr
        $dotaz->execute($polePar);
    }

    //priprav si dotaz v SQL
    $dotaz = $databaze->prepare("SELECT * FROM soutezici");
    //posli dotaz do serveru
    $dotaz->execute();
    //do $row dej dalsi nezpracovany radek odpovedi
    while ($radek = $dotaz->fetch()) {
        //tiskni obsah pole s názvem ‘firstname’
        echo $radek["firstname"] . " " . $radek["surname"] . "<br>";
        echo "Miry: " . $radek["measurements"] . " Pocet hlasu: " . $radek["votes"] . "<br>";
        //chceme tisknout <a href="miss.php?id=1">Dat hlas!</a>
        echo "<a href=\"blaha.php?id=" . $radek["id"] . "\">Dát hlas!</a>";
        echo "<hr>";
    }
    ?>

</body>

</html>
