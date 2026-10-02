Route43_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN_HNS, Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT_HNS, Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten, Route43_EventScript_RegisterBrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchBrent
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterBrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_BrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BRENT_HNS
	release
	end

Route43_EventScript_RematchBrent::
	trainerbattle_rematch TRAINER_BRENT_HNS, Route43_Text_BrentRematchIntro, Route43_Text_BrentRematchDefeat
	msgbox Route43_Text_BrentPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON_HNS, Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN_HNS, Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER_HNS, Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY_HNS, Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten, Route43_EventScript_RegisterTiffany
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route43_EventScript_RematchTiffany
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RegisterTiffany::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route43_Text_TiffanyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIFFANY_HNS
	release
	end

Route43_EventScript_RematchTiffany::
	trainerbattle_rematch TRAINER_TIFFANY_HNS, Route43_Text_TiffanyRematchIntro, Route43_Text_TiffanyRematchDefeat
	msgbox Route43_Text_TiffanyPostRematch, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
	.string "¡Me encantan los POKéMON!\p"
	.string "¡Ésa es la razón por la que empecé a\n"
	.string "coleccionar POKéMON!$"

Route43_Text_PokemaniacBenBeaten:
	.string "¿Cómo me has podido hacer esto?$"

Route43_Text_PokemaniacBenAfter:
	.string "¿Que qué me gusta además de los\n"
	.string "POKéMON?\p"
	.string "Oír a ROSA en la radio. ¡Seguro que es\n"
	.string "muy guapa!$"

Route43_Text_PokemaniacBrentSeen:
	.string "¡Eh! ¿Tienes algún POKéMON raro?$"

Route43_Text_PokemaniacBrentBeaten:
	.string "¡Oh, mis pobres POKéMON!$"

Route43_Text_PokemaniacBrentAfter:
	.string "Sería feliz con sólo tener un POKéMON\n"
	.string "raro.$"

Route43_Text_BrentRegister:
	.string "Sería feliz con sólo tener un POKéMON\n"
	.string "raro.$"

Route43_Text_BrentRematchIntro:
	.string "¡Eh! ¿Tienes algún POKéMON raro?$"

Route43_Text_BrentRematchDefeat:
	.string "¡Oh, mis pobres POKéMON!$"

Route43_Text_BrentPostRematch:
	.string "Sería feliz con sólo tener un POKéMON\n"
	.string "raro.$"

Route43_Text_PokemaniacRonSeen:
	.string "¿Te lo puedes creer?\p"
	.string "¡{RIVAL} se ha burlado de mi POKéMON!\p"
	.string "¡Maldición! ¡Mi POKéMON es genial!$"

Route43_Text_PokemaniacRonBeaten:
	.string "¡Mi NIDOKING lo ha hecho muy bien!$"

Route43_Text_PokemaniacRonAfter:
    .string "It's okay for people to like\n"
    .string "different types of POKéMON.\p"
    .string "POKéMON isn't just about having the\n"
    .string "most powerful one.$"

Route43_Text_FisherMarvinSeen:
	.string "No estoy en racha.\p"
	.string "Quizá sea por el equipo que uso.\p"
	.string "Luchemos. A ver si cambia mi suerte.$"

Route43_Text_FisherMarvinBeaten:
	.string "He perdido, pero me siento mejor.$"

Route43_Text_FisherMarvinAfter:
	.string "Las CEBO BALL de CÉSAR son las\n"
	.string "mejores para pescar POKéMON.\p"
	.string "Son mucho más efectivas que las ULTRA\n"
	.string "BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "I can do so much with my\n"
    .string "POKéMON--it's super-fun!$"

Route43_Text_CamperSpencerBeaten:
	.string "Perder no es nada divertido…$"

Route43_Text_CamperSpencerAfter:
	.string "¿Qué ocurre en el LAGO DE LA FURIA?\p"
	.string "Teníamos pensado acampar aquí.$"

Route43_Text_PicnickerTiffanySeen:
	.string "¿Tú también vas al LAGO DE LA FURIA?\p"
	.string "¡Juguemos un ratito!$"

Route43_Text_PicnickerTiffanyBeaten:
	.string "¡He jugado mucho!$"

Route43_Text_PicnickerTiffanyWantsPicnic:
	.string "Voy a ir de picnic con mis POKéMON.\p"
	.string "¿No te vienes?$"

Route43_Text_TiffanyRegister:
	.string "Voy a ir de picnic con mis POKéMON.\p"
	.string "¿No te vienes?$"

Route43_Text_TiffanyRematchIntro:
	.string "¿Tú también vas al LAGO DE LA FURIA?\p"
	.string "¡Juguemos un ratito!$"

Route43_Text_TiffanyRematchDefeat:
	.string "¡He jugado mucho!$"

Route43_Text_TiffanyPostRematch:
	.string "Voy a ir de picnic con mis POKéMON.\p"
	.string "¿No te vienes?$"

Route43_Sign1:
	.string "RUTA 43\p"
	.string "LAGO DE LA FURIA - PUEBLO CAOBA$"

Route43_Sign2:
	.string "RUTA 43\p"
	.string "LAGO DE LA FURIA - PUEBLO CAOBA$"

Route43_TrainerTips:
	.string "PISTAS ENTRENADOR\p"
	.string "Todos los POKéMON tienen ventajas y\n"
	.string "desventajas según el tipo.\p"
	.string "Entre dos POKéMON de distinto tipo,\n"
	.string "puede perder el de nivel superior.\p"
	.string "Aprende qué tipos son fuertes o\n"
	.string "débiles contra tu tipo de POKéMON$"
