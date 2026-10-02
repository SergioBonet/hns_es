Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: ¡SANTO CIELO! ¿Esa sombra era\n"
	.string "de un POKéMON?\p"
	.string "¿La has visto bien? No sé de qué color\n"
	.string "era…$"

Route39_Text_BaobaIntro::
	.string "Qué raro…\p"
	.string "… ¡Oh! Lo que llevas es… lo que llaman…\n"
	.string "¡una POKéDEX!\p"
	.string "Hacía siglos que no veía una.\p"
	.string "¡Me llamo BAOBA! Antes llevaba una\n"
	.string "ZONA SAFARI en CIUDAD FUCSIA, pero se\l"
	.string "estaba quedando anticuada con las\l"
	.string "nuevas formas de entretenimiento que\l"
	.string "iban saliendo.\p"
	.string "Decidí irme al extranjero a aprender\n"
	.string "las últimas tecnologías y abrir una\l"
	.string "ZONA SAFARI de vanguardia en CIUDAD\l"
	.string "ORQUÍDEA.\p"
	.string "Puede que no sea casualidad que\n"
	.string "estemos charlando.\p"
	.string "¿Por qué no registramos nuestros\n"
	.string "números en el POKéGEAR?\p"
	.string "¡Así te llamaré a ti antes que a nadie\n"
	.string "cuando abra la ZONA SAFARI!$"

Route39_Text_Registered:
	.string "¡{PLAYER} ha registrado a Baoba en el\n"
	.string "Pokégear!$"


Route39_Text_WillCall:
	.string "BAOBA: ¡Pronto te avisaré por el\n"
	.string "POKéGEAR!$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Esa sombra… ¿Sería un PIDGEY\n"
	.string "gigante?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "MUU-MUU: ¡Muu!$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Acabo de volver a CIUDAD OLIVO.\p"
	.string "¿Te apetece luchar con los POKéMON?$"

Route39_Text_SailorEugeneBeaten:
	.string "¡Awaaargh!$"

Route39_Text_SailorEugeneAfter:
	.string "Atrapé y crie a mis POKéMON en el\n"
	.string "extranjero.\p"
	.string "Son mis compañeros en esos largos\n"
	.string "viajes.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "¡Es buen momento para alardear de mi\n"
	.string "PIKACHU!$"

Route39_Text_PokefanMDerekBeaten:
	.string "No tuve tiempo de presumir de mi\n"
	.string "PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "¡No pienso escuchar tus\n"
	.string "fanfarronadas!\p"
	.string "¡Los POKéFANS tenemos por norma no\n"
	.string "escuchar fanfarronadas!$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "¡Qué POKéMON más encantadores!\p"
	.string "Enseñemos nuestros POKéMON al mismo\n"
	.string "tiempo.\p"
	.string "$"

Route39_Text_PokefanFRuthBeaten:
	.string "No me importa perder.$"

Route39_Text_PokefanFRuthAfter:
	.string "¿Sabes algo sobre los POKéMON bebés?\p"
	.string "¡Seguro que son adorables!$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Déjame ver de qué son capaces tus\n"
	.string "POKéMON.$"

Route39_Text_PsychicNormanBeaten:
	.string "¡Ooh! Tus POKéMON tienen potencial.$"

Route39_Text_PsychicNormanAfter:
	.string "¿Sabes que cada POKéMON tiene\n"
	.string "habilidades distintas?\p"
	.string "Con las personas pasa lo mismo. Cada\n"
	.string "uno tiene un potencial distinto.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Llegas justo a tiempo.\p"
	.string "Luchemos.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, qué decepcionante…$"

Route39_Text_PokefanFJaimeAfter:
	.string "Conocí a UMBREON de noche, aquí\n"
	.string "mismo, en la RUTA 39.\p"
	.string "No sé muy bien por qué, pero parece\n"
	.string "que le gusta que entrene aquí.\p"
	.string "Parece que entrenar aquí lo hace más\n"
	.string "amistoso que en cualquier otro sitio.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "RUTA 39\p"
	.string "CIUDAD OLIVO - CIUDAD IRIS$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "GRANJA MUU-MUU\p"
	.string "Prueba nuestra rica leche fresca$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "PISTAS ENTRENADOR\p"
	.string "Usa GOLPE CABEZA en los árboles para\n"
	.string "que salgan POKéMON.\p"
	.string "De los árboles pueden caer varios\n"
	.string "tipos de POKéMON$"

Route39_Text_DerekRegister:
	.string "¡No pienso escuchar tus\n"
	.string "fanfarronadas!\p"
	.string "¡Los POKéFANS tenemos por norma no\n"
	.string "escuchar fanfarronadas!$"

Route39_Text_DerekHasItem:
	.string "¡Eh! Estaba presumiendo de mi PIKACHU\n"
	.string "y he encontrado algo.\p"
	.string "¡Toma, para ti!$"

Route39_Text_DerekGaveItem:
	.string "¡PIKACHU es lo más! ¿No crees?$"

Route39_Text_DerekNoRoom:
	.string "Mmm, tienes la MOCHILA llena.\p"
	.string "Vuelve cuando tengas sitio.$"
