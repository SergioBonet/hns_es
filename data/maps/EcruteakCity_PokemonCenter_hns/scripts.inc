EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Hola, soy BILL. ¿Quién eres tú? ¿Eh?\n"
	.string "¿{PLAYER}?\p"
	.string "¡Has llegado justo a tiempo!$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Acabo de terminar los ajustes de mi\n"
	.string "SISTEMA de ALMACENAMIENTO POKéMON.\p"
	.string "¿Sabes ese PC que usas para guardar\n"
	.string "todos tus POKéMON?\p"
	.string "¡Lo desarrollé yo!\p"
	.string "Ahora que he instalado este, mi PC\n"
	.string "funciona en todos los CENTROS\l"
	.string "POKéMON de JOHTO y KANTO.\p"
	.string "Tengo que volver corriendo a CIUDAD\n"
	.string "TRIGAL a ver a mis padres. ¡Pásate\l"
	.string "cuando quieras!\p"
	.string "¡Adiós!$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "La forma de bailar de las CHICAS\n"
	.string "KIMONO es maravillosa.\p"
	.string "Igual que su forma de usar a sus\n"
	.string "POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Seguro que esperas luchar con más\n"
	.string "gente, ¿verdad? Parece que hay un\l"
	.string "sitio en el que se reúnen los\l"
	.string "entrenadores.\p"
	.string "Te preguntarás dónde.\p"
	.string "Es pasando CIUDAD OLIVO.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTI, el LÍDER del GIMNASIO, es taaan\n"
	.string "guay.\p"
	.string "Y sus POKéMON también son muy duros.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAGO DE LA FURIA.\p"
	.string "Un montón de GYARADOS…\p"
	.string "¡Esto huele a conspiración!$"

