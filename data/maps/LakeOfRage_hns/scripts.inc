LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
	.string "{PLAYER}.\p"
	.string "Incluso aquí, el frío me mantiene\n"
	.string "alerta.\p"
	.string "Si quieres volver a luchar, ven al DOJO\n"
	.string "KARATE.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRAGONITE: ¡Gyafuja!$"

LakeOfRage_Text_LanceForcedToEvolve:
	.string "Este lago está lleno de GYARADOS y\n"
	.string "nada más…\p"
	.string "Así que están obligando a los\n"
	.string "MAGIKARP a evolucionar…$"

LakeOfRage_Text_LanceIntro1:
	.string "¿Has venido por los rumores?\p"
	.string "¿Eres {PLAYER}? Soy LANCE, un\n"
	.string "ENTRENADOR como tú.$"

LakeOfRage_Text_LanceIntro2:
	.string "Este hombre me ha hablado de unos\n"
	.string "rumores.\p"
	.string "Así que hemos venido a investigar…$"

LakeOfRage_Text_LanceIntro3:
	.string "Antes he visto cómo luchabas,\n"
	.string "{PLAYER}.\p"
	.string "Se nota que eres un ENTRENADOR con\n"
	.string "mucha habilidad.\p"
	.string "Si no te importa, ¿podrías ayudarnos a\n"
	.string "investigar?$"

LakeOfRage_Text_LanceRadioSignal:
	.string "LANCE: ¡Excelente!\p"
	.string "Parece que están obligando a\n"
	.string "evolucionar a los MAGIKARP del LAGO.\p"
	.string "La causa es una misteriosa emisión de\n"
	.string "radio que llega desde PUEBLO CAOBA.\p"
	.string "Te estaremos esperando, {PLAYER}.$"

LakeOfRage_Text_LanceRefused:
	.string "Oh… Bueno, si cambias de idea,\n"
	.string "ayúdanos, por favor.$"

LakeOfRage_Text_LanceAskHelp:
	.string "LANCE: ¿Mmm? ¿Vas a ayudarnos?$"

LakeOfRage_Text_GyaradosCry:
	.string "GYARADOS: ¡Gyaraa!$"

LakeOfRage_Text_Gramps:
	.string "¡Los GYARADOS están enfadados!\p"
	.string "¡Mal presagio!$"

LakeOfRage_Text_GrampsCleared:
	.string "¡Ajá! ¡Los MAGIKARP pican!$"

LakeOfRage_Text_SuperNerd:
	.string "Dicen que este lago fue obra de\n"
	.string "violentos GYARADOS.\p"
	.string "Me pregunto si eso estará relacionado\n"
	.string "con su aparición masiva.$"

LakeOfRage_Text_CooltrainerF:
	.string "¿Me han engañado mis ojos? He visto\n"
	.string "un GYARADOS rojo en el LAGO…\p"
	.string "Yo pensaba que los GYARADOS eran\n"
	.string "azules.$"


LakeOfRage_Text_FisherAndreSeen:
	.string "¡Déjame luchar con el POKéMON que\n"
	.string "acabo de atrapar!$"

LakeOfRage_Text_FisherAndreBeaten:
	.string "Puede que sea un pescador experto,\n"
	.string "pero soy un mal entrenador…$"

LakeOfRage_Text_FisherAndreAfter:
	.string "¡No perderé como pescador! Me paso el\n"
	.string "día capturando POKéMON.$"


LakeOfRage_Text_FisherRaymondSeen:
	.string "Haga lo que haga, siempre capturo los\n"
	.string "mismos POKéMON…$"

LakeOfRage_Text_FisherRaymondBeaten:
	.string "Mi caña se ha enredado…$"

LakeOfRage_Text_FisherRaymondAfter:
	.string "¿Por qué no atrapo buenos POKéMON?$"

LakeOfRage_Text_CooltrainermAaronSeen:
	.string "Si un entrenador se encuentra con\n"
	.string "otro entrenador, debe desafiarle.\p"
	.string "Ése es nuestro destino.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
	.string "¡Uauu…! Buen combate.$"

LakeOfRage_Text_CooltrainermAaronAfter:
	.string "Los POKéMON y su entrenador se hacen\n"
	.string "más fuertes cuanto más luchan.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
	.string "¿Qué ocurrió con el GYARADOS rojo?\p"
	.string "¿Se ha ido?\p"
	.string "¡Maldición! ¿He venido para nada?\p"
	.string "Ya sé. ¡Luchemos!$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
	.string "¡Muy bien!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
	.string "Pensándolo bien, creo que vi un\n"
	.string "BUTTERFREE rosa.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
	.string "MIGUEL: Bueno, ¿qué tal?\p"
	.string "¡Soy de la familia de los DÍAS de la\n"
	.string "SEMANA! ¿Adivinas cuál es mi día\l"
	.string "favorito?$"

LakeOfRage_Text_WesleyGivesGift:
	.string "Encantado de conocerte. Toma un\n"
	.string "recuerdo.$"

LakeOfRage_Text_WesleyGaveGift:
	.string "MIGUEL: El CINTURÓN NEGRO potencia\n"
	.string "los movimientos de tipo LUCHA.$"

LakeOfRage_Text_WesleyWednesday:
	.string "MIGUEL: Si me has encontrado, habrás\n"
	.string "visto a mis hermanos.\p"
	.string "¿O es que has tenido suerte?$"

LakeOfRage_Text_WesleyNotWednesday:
	.string "MIGUEL: No exactamente…$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
	.string "LAGO DE LA FURIA, conocido como LAGO\n"
	.string "DE GYARADOS$"

LakeOfRage_Text_FishingGuruSign:
	.string "CASA DEL GURÚ PESCADOR$"
