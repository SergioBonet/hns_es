RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "¡Este oscuro túnel recorre\n"
	.string "un largo camino!$"

RockTunnel_1F_Text_LennyDefeat::
	.string "¡Vaya!\n"
	.string "¡Tú ganas!$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "Cuidado con ONIX.\n"
	.string "¡Podría apretarte las tuercas!$"

RockTunnel_1F_Text_OliverIntro::
	.string "Mmm.\n"
	.string "Puede que me haya perdido...$"

RockTunnel_1F_Text_OliverDefeat::
	.string "A ver, con calma. \n"
	.string "¿Qué hago?\l"
	.string "¿Por dónde salgo?$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "Ese POKéMON dormido de la RUTA 12\n"
	.string "me obligó a desviarme.$"

RockTunnel_1F_Text_LucasIntro::
	.string "¡Los forasteros como tú deben\n"
	.string "mostrarme algo de respeto!$"

RockTunnel_1F_Text_LucasDefeat::
	.string "¡Me rindo!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "¡Tienes madera para el senderismo!$"

RockTunnel_1F_Text_AshtonIntro::
	.string "¡Combate POKéMON!\n"
	.string "¿Listos? ¡Ya!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "¡Fin de la partida!$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "¡Conseguiré un ZUBAT por el\n"
	.string "camino!$"

RockTunnel_1F_Text_LeahIntro::
	.string "¡Oye!\p"
	.string "¡No hagas tonterías en la\n"
	.string "oscuridad!$"

RockTunnel_1F_Text_LeahDefeat::
	.string "¡Estaba demasiado oscuro!$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "¡Vi a un MACHOP en este túnel!$"

RockTunnel_1F_Text_DanaIntro::
	.string "¡Vine hasta aquí por los POKéMON!$"

RockTunnel_1F_Text_DanaDefeat::
	.string "¡Me he quedado sin POKéMON!$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "Parecías mono e inofensivo.\n"
	.string "¡Qué equivocado estaba!$"

RockTunnel_1F_Text_ArianaIntro::
	.string "¡Tienes POKéMON!\n"
	.string "¡Empecemos!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "¡Juegas duro!$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "¡Uf!\n"
	.string "Ahora estoy sudando.$"

RockTunnel_1F_Text_RouteSign::
	.string "TÚNEL ROCA:\n"
	.string "CIUDAD CELESTE - PUEBLO LAVANDA$"

