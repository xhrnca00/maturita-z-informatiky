<!DOCTYPE html>
<html lang='cs'>

<head>
    <title></title>
    <meta charset='utf-8'>
    <meta name='description' content=''>
    <meta name='keywords' content=''>
    <meta name='author' content=''>
    <meta name='robots' content='all'>
    <!-- <meta http-equiv='X-UA-Compatible' content='IE=edge'> -->
    <link href='/favicon.png' rel='shortcut icon' type='image/png'>
</head>

<body>
    <h1>Foto ze Zoo</h1>
    <?php
    // db renames: path -> soubor, description -> popisek
    $kam = 'mysql: host=localhost;dbname=zoo';
    $uzivatel = 'root';
    $heslo = '';
    //pripoj se k serveru a zvol databazi
    $databaze = new PDO($kam, $uzivatel, $heslo);
    //priprav si dotaz v SQL
    $dotaz = $databaze->prepare("SELECT * FROM foto");
    //posli dotaz do serveru
    $dotaz->execute();
    //do $row dej dalsi nezpracovany radek odpovedi
    while ($radek = $dotaz->fetch()) {
        //tiskni obsah pole s názvem ‘jmeno’
        echo '<a href="';
        echo $radek["path"];
        echo '">';
        echo $radek["description"];
        echo "</a><br>\n"; // this '\n' is irrelevant
    }


    ?>
</body>

</html>
