<?php
class foo {}
var_dump (is_scalar (TRUE));
var_dump (is_scalar (1));
var_dump (is_scalar (1.0));
var_dump (is_scalar ("Hi!"));
var_dump (is_scalar (NULL));
var_dump (is_scalar (array ()));
var_dump (is_scalar (new foo()));
var_dump (is_scalar (opendir('.')));
?>
