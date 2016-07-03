my_clickaction = compile preprocessFileLineNumbers "\vtn_aire_fix_su25_cf\gavno.sqf"; ["my_clickid", "onEachFrame", "my_clickaction"] call
BIS_fnc_addStackedEventHandler;

