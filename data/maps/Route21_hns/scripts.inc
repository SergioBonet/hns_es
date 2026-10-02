Route21_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH_HNS, Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI_HNS, Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD_HNS, Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "¡Tierra a la vista! ¡Hay que seguir!$"

Route21_Text_SwimmermSethBeaten:
	.string "¡Glup…!$"

Route21_Text_SwimmermSethAfterBattle:
	.string "Ese chico tan arrogante estaba en el\n"
	.string "volcán de ISLA CANELA.$"

Route21_Text_SwimmerfNikkiSeen:
	.string "¡Si gano, tienes que ayudarme con la\n"
	.string "loción solar!$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "No quiero quemarme…$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "Debería tener cuidado con las\n"
	.string "manchas causadas por el sol.$"

Route21_Text_FisherArnoldSeen:
	.string "Estoy aburrido de pescar. ¡Luchemos!$"

Route21_Text_FisherArnoldBeaten:
	.string "Qué fracaso…$"

Route21_Text_FisherArnoldAfterBattle:
	.string "Voy a volver a pescar…$"

