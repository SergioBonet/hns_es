Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "Estoy mejorando mis POKéMON.\p"
	.string "¿Quieres luchar contra mí?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "¡Argh! He perdido esta vez…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Si hay un POKéMON concreto que\n"
	.string "quieres criar, sácalo el primero y\l"
	.string "luego cámbialo enseguida.\p"
	.string "Así se hace.$"

Route4_Text_PicnickerHope_Seen:
	.string "Presiento que puedo ganar.\p"
	.string "¡Veamos si tengo razón!$"

Route4_Text_PicnickerHope_Beaten:
	.string "¡Uau! Eres demasiado fuerte.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "Dicen que CLEFAIRY aparece en el\p"
	.string "MT. MOON. ¿Pero dónde?$"

Route4_Text_PicnickerSharon_Seen:
	.string "¡Umm…! Yo…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "…Creo que seguiré entrenándome…$"

Route4_Text_MtMoonSquareSign:
	.string "NUEVA ENTRADA AL MT. MOON\n"
	.string "POR UN DERRUMBE\p"
	.string "MIRA DÓNDE PISAS$"

