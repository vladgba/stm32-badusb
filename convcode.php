<?php
$arr = [
    'a' => 4, 'b' => 5, 'c' => 6, 'd' => 7, 'e' => 8, 'f' => 9,
    'g' => 10, 'h' => 11, 'i' => 12, 'j' => 13, 'k' => 14, 'l' => 15, 'm' => 16, 'n' => 17, 'o' => 18, 'p' => 19,
    'q' => 20, 'r' => 21, 's' => 22, 't' => 23, 'u' => 24, 'v' => 25, 'w' => 26, 'x' => 27, 'y' => 28, 'z' => 29,
    '1' => 30, '2' => 31, '3' => 32, '4' => 33, '5' => 34, '6' => 35, '7' => 36, '8' => 37, '9' => 38, '0' => 39,
    "\n" => 40, /*ESC*/ /*BACKSPACE*/ "\t" => 43, ' ' => 44, '-' => 45, '=' => 46, '[' => 47, ']' => 48, '\\' => 49,
    /*HASH*/ ';' => 51, '\'' => 52, '`' => 53, ',' => 54, '.' => 55, '/' => 56,

    'A' => 204, 'B' => 205, 'C' => 206, 'D' => 207, 'E' => 208, 'F' => 209,
    'G' => 210, 'H' => 211, 'I' => 212, 'J' => 213, 'K' => 214, 'L' => 215, 'M' => 216, 'N' => 217, 'O' => 218, 'P' => 219,
    'Q' => 220, 'R' => 221, 'S' => 222, 'T' => 223, 'U' => 224, 'V' => 225, 'W' => 226, 'X' => 227, 'Y' => 228, 'Z' => 229,
    '!' => 230, '@' => 231, '#' => 232, '$' => 233, '%' => 234, '^' => 235, '&' => 236, '*' => 237, '(' => 238, ')' => 239,
    /*ENTER*/ /*ESC*/ /*BACKSPACE*/ /*TAB*/ /*SPACE*/ '_' => 245, '+' => 246, '{' => 247, '}' => 248, '|' => 249,
    ':' => 251, '"' => 252, '~' => 253, '<' => 254, '>' => 255, '?' => 256
];

echo '<meta name="viewport" content="width=device-width"><meta charset="utf-8">
<form>
    <textarea name="code" style="width:100%" rows=10>' . htmlentities(isset($_GET['code']) ? $_GET['code'] : '') . '</textarea>
    <br><input type="submit">
</form>';

if (isset($_GET['code'])) {
    $c = str_split(str_replace("\r", '', $_GET['code']));
    echo '<textarea style="width:100%" rows=10>';
    $l = count($c);
    $keyCount = 7;
    $i = 0;
    $m = -1;
    $res = [];
    $chars = [];
    foreach ($c as $v) {
        if (isset($arr[$v])) {
            $mod = floor($arr[$v] / 100);
            $key = $arr[$v] % 100;
            if ($mod != $m || in_array($key, $chars)) {
                if ($m != - 1) {
                    for ($j = $i;$j < $keyCount;$j++) {
                        $res[] = str_pad('0', 4, ' ', STR_PAD_LEFT);
                    }
                }
                $i = 999;
                $m = $mod;
                $chars = [];
            }

            if (!($i < $keyCount)) {
                $res[] = "\n" . str_pad($mod, 4, ' ', STR_PAD_LEFT);
                $i = 1;
            }
            $chars[] = $key;
            $res[] = str_pad($key, 4, ' ', STR_PAD_LEFT);
            ++$i;
        } else {
            $i = 0;
            echo "\n// " . $v . "\n";
        }
    }
    for ($j = $i;$j < 7;$j++) {
        $res[] = str_pad('0', 4, ' ', STR_PAD_LEFT);
    }
    echo implode(",", $res);
    echo '</textarea>';
}