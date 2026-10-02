Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "¡Espera! ¿Por qué corres?$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}, ¿verdad?\p"
	.string "Un tipo con gafas te buscaba.\p"
	.string "Compruébalo. Te está esperando en el\n"
	.string "CENTRO POKéMON.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "¿Has ido a la TORRE BELLSPROUT?\p"
	.string "Si pasas por CIUDAD MALVA, deberías\n"
	.string "entrenarte allí.\p"
	.string "Es crucial para los entrenadores.\p"
	.string "¡Ve a la TORRE BELLSPROUT!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "¿Has ido al GIMNASIO POKéMON?\p"
	.string "Allí puedes probar a tus POKéMON y a\n"
	.string "ti mismo.\p"
	.string "¡Es un rito para todos los\n"
	.string "entrenadores!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "Tienes POKéMON muy buenos.\p"
	.string "Seguro que es por haberlos entrenado\n"
	.string "en los alrededores de CIUDAD MALVA.\p"
	.string "El entrenamiento en el GIMNASIO ha\n"
	.string "debido de ser de gran ayuda.\p"
	.string "Toma esto como recuerdo de CIUDAD\n"
	.string "MALVA.\p"
	.string "Aumenta el poder de los movimientos\n"
	.string "de tipo planta.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Tu experiencia en CIUDAD MALVA\p"
	.string "debería ayudarte en tu viaje.$"

Route32_Text_SlowpokeTailOffer:
	.string "¿Qué te parecería tener esta sabrosa\n"
	.string "y nutritiva COLA de SLOWPOKE?\p"
	.string "Para ti, ahora mismo, ¡solo ¥1.000.000!\p"
	.string "¡Te va a encantar!$"

Route32_Text_ThoughtKidsLoaded:
	.string "¡Vaya! Pensaba que los niños de hoy en\n"
	.string "día estaban forrados…$"

Route32_Text_RefusedSlowpokeTail:
	.string "¿No la quieres? Pues lárgate.$"

Route32_Text_FisherJustin_Seen:
	.string "¡Vaya!\p"
	.string "¡Se me escapó ese pez por tu culpa!$"

Route32_Text_FisherJustin_Beaten:
	.string "¡Chof!$"

Route32_Text_FisherJustin_After:
	.string "Paciencia…\p"
	.string "El fundamento de la pesca y de los\n"
	.string "POKéMON es el mismo.$"

Route32_Text_FisherRalph1_Seen:
	.string "Soy muy bueno, tanto pescando como\n"
	.string "con los POKéMON.\p"
	.string "¡No voy a perder con alguien tan\n"
	.string "joven!$"

Route32_Text_FisherRalph1_Beaten:
	.string "Intenté acelerar las cosas…$"

Route32_Text_FisherRalph1_After:
	.string "¡Pescar es una pasión eterna y los\n"
	.string "POKéMON son amigos eternos!$"

Route32_Text_RalphRegister:
	.string "¡Pescar es una pasión eterna y los\n"
	.string "POKéMON son amigos eternos!$"

Route32_Text_RalphRematchIntro:
	.string "Soy muy bueno, tanto pescando como\n"
	.string "con los POKéMON.\p"
	.string "¡No voy a perder con alguien tan\n"
	.string "joven!$"

Route32_Text_RalphRematchDefeat:
	.string "Intenté acelerar las cosas…$"

Route32_Text_RalphPostRematch:
	.string "¡Pescar es una pasión eterna y los\n"
	.string "POKéMON son amigos eternos!$"

Route32_Text_FisherHenry_Seen:
	.string "¿Mi POKéMON? ¡Recién pescado!$"

Route32_Text_FisherHenry_Beaten:
	.string "¡Splash!$"

Route32_Text_FisherHenry_After:
	.string "Los POKéMON recién atrapados no son\n"
	.string "comparables con los criados.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "No te había visto antes.\p"
	.string "¿Te crees muy fuerte?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "¡Eres fuerte!$"

Route32_Text_YoungsterAlbert_After:
	.string "Intentaré ser el mejor con mis\n"
	.string "favoritos.\p"
	.string "No uso los mismos POKéMON que todo el\n"
	.string "mundo.$"

Route32_Text_YoungsterGordon_Seen:
	.string "¡He encontrado POKéMON muy buenos en\n"
	.string "la hierba!\p"
	.string "¡Creo que me servirán!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "¡Maldición! Creía que podía ganar.$"

Route32_Text_YoungsterGordon_After:
	.string "En la hierba hay cosas pegajosas.$"

Route32_Text_CamperRoland_Seen:
	.string "Esa mirada… Me intriga.\p"
	.string "$"

Route32_Text_CamperRoland_Beaten:
	.string "¡Mmmm! ¡Qué decepción!$"

Route32_Text_CamperRoland_After:
	.string "Si no quieres luchar, evita el\n"
	.string "contacto visual.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Sí. Y sabes que…\p"
	.string "¿Luchar? ¡Estoy al teléfono!\p"
	.string "Vale. Pero que sea rápido.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "¡Oh! ¡Tengo que aliviar mi enfado!$"

Route32_Text_PicnickerLiz1_After:
	.string "Yo también estaba charlando.$"

Route32_Text_LizRegister:
	.string "Yo también estaba charlando.$"

Route32_Text_LizRematchIntro:
	.string "Sí. Y sabes que…\p"
	.string "¿Luchar? ¡Estoy al teléfono!\p"
	.string "Vale. Pero que sea rápido.$"

Route32_Text_LizRematchDefeat:
	.string "¡Oh! ¡Tengo que aliviar mi enfado!$"

Route32_Text_LizPostRematch:
	.string "Yo también estaba charlando.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "Esa Medalla… ¡Es de CIUDAD MALVA!\n"
	.string "¿Ganaste a PEGASO?\p"
	.string "$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Conozco mis debilidades.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Debería volver a entrenarme en el\p"
	.string "GIMNASIO de CIUDAD MALVA.$"

Route32_Text_RoarIntro:
	.string "¡GRRRRRR! ¡TODOS HUYEN\p"
	.string "CUANDO RUJO! ¡PERO TÚ HAS VENIDO!\p"
	.string "¡ESO ME GUSTA! ¡TOMA ESTO!$"

Route32_Text_RoarOutro:
	.string "¡GROOOOAR! ¡ES RUGIDO!\p"
	.string "¡HASTA LOS POKéMON HUYEN DE UN BUEN\n"
	.string "RUGIDO!$"

Route32_Text_MeetFrieda:
	.string "VICKI: ¡Yuju!\p"
	.string "¡Soy VICKI, de la FAMILIA de los DÍAS\n"
	.string "de la SEMANA! ¡Encantada!\p"
	.string "Si adivinas cuál es mi día favorito, te\n"
	.string "daré una recompensa.$"

Route32_Text_FriedaGivesGift:
	.string "¡Toma una FLECHA VENENOSA!$"

Route32_Text_FriedaGaveGift:
	.string "VICKI: Dásela a un POKéMON de tipo\n"
	.string "veneno.\p"
	.string "¡Oh!\p"
	.string "¡Es terrible!\p"
	.string "¡Te sorprenderá ver cómo mejora los\n"
	.string "movimientos de tipo veneno!$"

Route32_Text_FriedaFriday:
	.string "VICKI: ¡Hola! ¿Qué día prefieres?\p"
	.string "A mí me gusta el viernes. Sin duda.\p"
	.string "¿No crees que es genial?$"

Route32_Text_FriedaNope:
	.string "VICKI: ¡Ese no!$"

Route32_Text_Sign1:
	.string "RUTA 32\p"
	.string "CIUDAD MALVA - PUEBLO AZALEA$"

Route32_Text_Sign2:
	.string "RUINAS ALFA ENTRADA ESTE$"

Route32_Text_Sign3:
	.string "CUEVA UNIÓN\n"
	.string "MÁS ADELANTE$"
