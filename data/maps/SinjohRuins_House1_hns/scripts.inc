SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
	.string "MÁXIMO: ¿Mmm?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Reconocería esos ojos en cualquier\n"
	.string "parte.\p"
	.string "¿Qué te trae tan al norte?\p"
	.string "……\p"
	.string "Ya veo, las CHICAS KIMONO de NUEVO\n"
	.string "SINJOH te han enviado para ayudar en\l"
	.string "nuestra investigación.\p"
	.string "En ese caso, deja que te ponga al día.$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "MÁXIMO: Cuando oí hablar de estas\n"
	.string "ruinas, tuve que venir a verlas con mis\l"
	.string "propios ojos.\p"
	.string "Reuní un equipo de DEVON S.A. y nos\n"
	.string "pusimos en marcha en una expedición\l"
	.string "de investigación.\p"
	.string "Quién sabe qué encontraremos\n"
	.string "enterrado aquí.\p"
	.string "Ya hemos aprendido muchísimo.$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "LINGÜISTA: Aunque todavía no he\n"
	.string "logrado traducir del todo los glifos\l"
	.string "que hay por las ruinas, he podido\l"
	.string "descifrar algunos aspectos.\p"
	.string "Hay 17 TABLAS peculiares.\p"
	.string "Tienen cierta importancia para las\n"
	.string "ruinas, pero de momento solo hemos\l"
	.string "encontrado 1.\p"
	.string "Dicen que las demás las custodian\n"
	.string "POKéMON y ENTRENADORES de un poder\l"
	.string "impresionante.$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "MÁXIMO: Esa es la historia, {PLAYER}.\p"
	.string "Me temo que los POKéMON SEÑORIALES\n"
	.string "que custodian las TABLAS restantes\l"
	.string "son demasiado fuertes para mi equipo.\p"
	.string "Y yo tengo que quedarme aquí a\n"
	.string "supervisar la investigación.\p"
	.string "Pero creo que tú podrías conseguirlo.\n"
	.string "¿Nos ayudarás?$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "Excelente.\p"
	.string "Los glifos dicen que las TABLAS las\n"
	.string "tienen POKéMON SEÑORIALES y\l"
	.string "ENTRENADORES fuertes de todo SINJOH.\p"
	.string "Te llamaré al POKéGEAR si descubrimos\n"
	.string "algo nuevo.\p"
	.string "Gracias, {PLAYER}.$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "¿Estás seguro?\p"
	.string "Quién sabe qué encontraremos\n"
	.string "enterrado aquí.\p"
	.string "¿No te lo vas a pensar mejor?$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Creo que sé lo que va a pasar cuando\n"
	.string "reunamos las 17 TABLAS.\p"
	.string "Siento… ……$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "MÁXIMO: ¡Tengo que verlo con mis\n"
	.string "propios ojos!\p"
	.string "¡Fuera, {PLAYER}!$"

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "De momento, {STR_VAR_1} TABLAS. Nada\n"
	.string "mal.\p"
	.string "Tengo que admitir que me pica la\n"
	.string "curiosidad por saber qué pasará\l"
	.string "cuando estén todas reunidas.\p"
	.string "Bueno, a ver qué encuentras.$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "De momento, {STR_VAR_1} TABLAS. Nada\n"
	.string "mal.\p"
	.string "¿Has investigado ya esa cámara?\p"
	.string "Es todo muy misterioso.$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "MÁXIMO: Ah, {PLAYER}.\p"
	.string "De momento, {STR_VAR_1} TABLAS. Vas\n"
	.string "muy bien.\p"
	.string "Las cámaras que se han abierto se\n"
	.string "parecen muchísimo a una serie de\l"
	.string "cámaras de la región de HOENN.\p"
	.string "Cada una de ellas también era el hogar\n"
	.string "de un POKéMON legendario.\p"
	.string "Pero en HOENN solo se descubrieron 3.\p"
	.string "Y aquí hay al menos 6.\p"
	.string "Quién sabe qué encontraremos ahora.$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "MÁXIMO: ¡{PLAYER}!\p"
	.string "Esta expedición ha sido la experiencia\n"
	.string "de mi vida.\p"
	.string "Desde que oí hablar de estas ruinas,\n"
	.string "tenía esta sensación.\p"
	.string "Pensaba que descubriríamos algo\n"
	.string "asombroso.\p"
	.string "Y mis predicciones suelen cumplirse.\p"
	.string "Gracias por toda tu ayuda, CAMPEÓN.\p"
	.string "¿Adónde irás ahora?\p"
	.string "Espero que volvamos a vernos en algún\n"
	.string "lugar.$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
	.string "El georradar muestra 6 cámaras\n"
	.string "subterráneas en este valle.\p"
	.string "5 de ellas parecen estar más cerca de\n"
	.string "la superficie, y 1 está enterrada a\l"
	.string "más profundidad.$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "Todo este tiempo he apuntado mis\n"
	.string "instrumentos hacia abajo para\l"
	.string "obtener imágenes del subsuelo.\p"
	.string "¡Cuando está claro que debería\n"
	.string "haberlos apuntado hacia arriba!$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "¿¿Esas TABLAS estaban relacionadas\n"
	.string "con el POKéMON más poderoso??\p"
	.string "Ojalá tuviera más tiempo para\n"
	.string "estudiarlas.$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
	.string "Uf…\p"
	.string "Hay tantísimos glifos que traducir…\p"
	.string "En la región de HOENN no tenemos nada\n"
	.string "parecido.$"
SinjohRuins_Lab_Text_LinguistDuring:
	.string "¡Imagínate mi sorpresa al traducir el\n"
	.string "glifo!\p"
	.string "¡Lo comprobé tres y cuatro veces\n"
	.string "antes de decírselo a MÁXIMO!\p"
	.string "O sea, en serio, ¿el Dios de los\n"
	.string "POKéMON?\p"
	.string "Es increíble.$"
SinjohRuins_Lab_Text_LinguistAfter:
	.string "Esta expedición ha sido un placer,\n"
	.string "{PLAYER}.\p"
	.string "Gracias por encargarte de todo el\n"
	.string "trabajo de campo.$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "La existencia de una civilización en\n"
	.string "esta zona cambia todo lo que sabíamos\l"
	.string "de la historia.\p"
	.string "Muchos de los objetos antiguos que\n"
	.string "hemos encontrado tienen más de mil\l"
	.string "años.\p"
	.string "La datación por carbono coincide con\n"
	.string "objetos hallados en la región de\l"
	.string "SINNOH.\p"
	.string "Aunque esa flauta que encontraste…\n"
	.string "parece mucho más antigua.$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Esas tablas… La relación con la región\n"
	.string "de SINNOH… Esa flauta…\p"
	.string "Todo empieza a tener sentido.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "No se puede exagerar el valor\n"
	.string "histórico de lo que nos has ayudado a\l"
	.string "desenterrar aquí, {PLAYER}.\p"
	.string "De verdad, gracias.$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
	.string "¡¡Grauuu!!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
	.string "Parece que es la pelota de GROWLITHE…\n"
	.string "Mejor no tocarla.$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
	.string "¡Mira qué ejemplar tan maravilloso!\p"
	.string "Esta especie de GROWLITHE no se\n"
	.string "parece a las que hay en ningún otro\l"
	.string "lugar del mundo.\p"
	.string "El análisis de ADN revela que tiene un\n"
	.string "antepasado común con los GROWLITHE\l"
	.string "de otras regiones.\p"
	.string "Pero su temperamento y su tipo son\n"
	.string "muy distintos.\p"
	.string "Las descripciones de GROWLITHE de los\n"
	.string "antiguos registros de SINNOH parecen\l"
	.string "coincidir.\p"
	.string "Quizá esta especie ocupó un\n"
	.string "territorio mucho mayor, que se\l"
	.string "extendía hacia el norte por la antigua\l"
	.string "SINNOH.$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Si la criatura de lo alto de esas\n"
	.string "escaleras es de verdad el Dios de\l"
	.string "todos los POKéMON, ¿significa eso que\l"
	.string "es el primer antepasado común?$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "Gracias a esta expedición he podido\n"
	.string "reunir muchísimos datos sobre formas\l"
	.string "regionales y evolución divergente.\l"
	.string "Gracias, {PLAYER}.$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
	.string "Llevo diez años recorriendo estas\n"
	.string "tierras salvajes.\p"
	.string "No, mejor dicho, veinte años.\p"
	.string "Hasta que un día encontré esos\n"
	.string "grandes pilares de piedra y ese templo\l"
	.string "tan siniestro.\p"
	.string "Son las RUINAS DE SINJOH. O eso he\n"
	.string "oído.\p"
	.string "Entonces no sabía nada del pueblo.\p"
	.string "Solo se lo conté a unos cuantos\n"
	.string "amigos. Pero las noticias vuelan.\p"
	.string "Nunca pensé que atraería tanta\n"
	.string "atención a la zona.\p"
	.string "Me hace sentir un poco raro. ¿Sabes?$"
SinjohRuins_Lab_Text_HikerDuringAfter:
	.string "No se lo digas a nadie, {PLAYER}, pero\n"
	.string "vi ese templo en lo alto de la montaña\l"
	.string "cuando descubrí este lugar.\p"
	.string "Me lo guardé para mí.\p"
	.string "Ya he hablado bastante de estas\n"
	.string "ruinas.\p"
	.string "Al menos parece que todo ha salido\n"
	.string "bien.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
	.string "Diario de investigación 1: 3 de mayo de\n"
	.string "1975\p"
	.string "Hemos llegado al lugar de las ruinas.\p"
	.string "El frío intenso del MT. PLATEADO se\n"
	.string "nota incluso aquí abajo…\p"
	.string "Pronto el equipo principal de\n"
	.string "excavación atravesará la montaña…\l"
	.string "¡Estoy deseando ver qué nos espera\l"
	.string "bajo nuestros pies!$"

SinjohRuins_Lab_Text_Note2:
	.string "Diario de investigación 2: 10 de mayo\n"
	.string "de 1975\p"
	.string "Una semana excavando no ha dado\n"
	.string "ningún resultado.\p"
	.string "El hielo de aquí es increíblemente\n"
	.string "grueso, y la roca destroza por\l"
	.string "completo nuestro equipo.\p"
	.string "Ni siquiera MACHAMP ha conseguido\n"
	.string "hacerle una mella.\p"
	.string "¿Qué es este lugar?\p"
	.string "Tenemos que averiguarlo.$"

SinjohRuins_Lab_Text_Note3:
	.string "Diario de investigación 3: 14 de mayo\n"
	.string "de 1975\p"
	.string "En la vida no se progresa quedándose\n"
	.string "de brazos cruzados.\p"
	.string "Solo soy un trabajador.\p"
	.string "Pero se me ocurrió cómo podríamos\n"
	.string "atravesar el hielo.\p"
	.string "O, mejor dicho, derretirlo.\p"
	.string "Necesitamos POKéMON de tipo FUEGO, y\n"
	.string "muchos.\p"
	.string "Pero ¿cómo los traeremos hasta aquí\n"
	.string "desde SINNOH?$"

SinjohRuins_Lab_Text_Note4:
	.string "Diario de investigación 4: 21 de mayo\n"
	.string "de 1975\p"
	.string "Hemos estado ocupados.\p"
	.string "Mi idea funcionó para atravesar el\n"
	.string "hielo. Solo que no trajimos los\l"
	.string "POKéMON de tipo FUEGO de casa.\p"
	.string "El jefe insistió en conseguirlos aquí.\p"
	.string "Encontramos una fuente termal junto\n"
	.string "a una aldea cercana…\p"
	.string "Y nos llevamos lo que necesitábamos…\p"
	.string "No me siento orgulloso. Pero a veces el\n"
	.string "progreso exige sacrificios.\p"
	.string "En fin, el hielo ha desaparecido.\p"
	.string "Hay 6 cámaras y un templo sellado en\n"
	.string "el centro.\p"
	.string "La arquitectura de la estructura\n"
	.string "principal indica que podría ser del\l"
	.string "antiguo pueblo celestica…\p"
	.string "Nuestros antepasados. Antes de que\n"
	.string "se trasladaran al norte.\p"
	.string "El jefe quiere abrir ese templo cuanto\n"
	.string "antes…$"

SinjohRuins_Lab_Text_Note5:
	.string "Diario de investigación 5: 2 de junio\n"
	.string "de 1975\p"
	.string "Conseguimos abrirlo…\p"
	.string "Pensaba que me alegraría muchísimo…\p"
	.string "Pero perdimos a buenos hombres en la\n"
	.string "explosión de energía que surgió del\l"
	.string "templo.\p"
	.string "Por no hablar de los POKéMON que nos\n"
	.string "ayudaron a abrirlo. Descansen en paz…\p"
	.string "……\p"
	.string "En cualquier caso.\p"
	.string "El templo está abierto, pero solo nos\n"
	.string "quedan más preguntas.\p"
	.string "Dentro no hay ningún POKéMON\n"
	.string "legendario. Ningún tesoro.\p"
	.string "Se nos están acabando las provisiones\n"
	.string "y no tenemos nada que mostrar por\l"
	.string "nuestros esfuerzos…$"

SinjohRuins_Lab_Text_Note6:
	.string "Diario de investigación 6: 10 de junio\n"
	.string "de 1975\p"
	.string "La expedición ha terminado. Los demás\n"
	.string "están recogiendo.\p"
	.string "Pero yo no puedo.\p"
	.string "No puedo abandonar esta misión. No\n"
	.string "después de todo lo que hemos perdido.\p"
	.string "Me quedaré aquí.$"

SinjohRuins_Lab_Text_Note7:
	.string "Diario de investigación 7: 10 de\n"
	.string "septiembre de 1975\p"
	.string "Han pasado meses desde que llegamos.\n"
	.string "Desde que llegué.\p"
	.string "Los demás se han ido.\p"
	.string "Ahora solo quedamos yo y los POKéMON\n"
	.string "que capturamos para ayudarnos en el\l"
	.string "trabajo.\p"
	.string "Los he estado entrenando para que se\n"
	.string "hagan más fuertes.\p"
	.string "Sobre todo a mi TYPHLOSION.\p"
	.string "Tenemos que averiguar qué hay debajo\n"
	.string "del templo.$"

SinjohRuins_Lab_Text_Note8:
	.string "Diario de investigación 8: 15 de\n"
	.string "septiembre de 1975\p"
	.string "Fracaso.\p"
	.string "……\p"
	.string "Mis POKéMON…\p"
	.string "Juntos, mis 6 POKéMON consiguieron\n"
	.string "derribar una pared falsa del templo.\p"
	.string "Pero nos estaba esperando…\p"
	.string "Algo parecido a un titán gigante…\p"
	.string "La energía que liberó fue igual que la\n"
	.string "de la otra vez.\p"
	.string "Acabó con todos…\p"
	.string "Y lo peor de todo: esa bestia volvió a\n"
	.string "sellar la pared.\p"
	.string "No puedo volver a casa. Ya no me\n"
	.string "reconocerían…\p"
	.string "Este lugar me ha cambiado…\p"
	.string "Voy a hablar con los aldeanos.\p"
	.string "No saben lo que he hecho.\p"
	.string "Como los demás se fueron hace tiempo,\n"
	.string "pensarán que solo soy un\l"
	.string "excursionista perdido.\p"
	.string "Ya no me queda otro lugar que este.$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
	.string "¡Es una vitrina bien ordenada, llena de\n"
	.string "muestras y objetos antiguos!$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
	.string "Laboratorio de rayos X e impresión.$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
	.string "¡Es un objeto antiguo encontrado\n"
	.string "dentro de las ruinas!$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "La FLAUTA AZUR está reaccionando.\n"
	.string "¿Tocar la flauta?$"

SinjohRuins_Lab_Text_DropedItem:
	.string "El {STR_VAR_1} SEÑORIAL ha dejado\n"
	.string "caer un objeto…$"

SinjohRuins_Lab_Text_StevenName:
	.string "MÁXIMO$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "Acabamos de notar un temblor en las\n"
	.string "ruinas.\p"
	.string "Estamos todos bien, no te preocupes.\p"
	.string "Es muy curioso: una de las cámaras\n"
	.string "subterráneas de debajo de las ruinas\l"
	.string "se ha abierto.\p"
	.string "Las marcas del interior me recuerdan a\n"
	.string "algo de HOENN.\p"
	.string "Deberías venir a echar un vistazo\n"
	.string "cuando puedas.$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "¿Qué tal va la búsqueda?\p"
	.string "Aquí ha habido otro temblor. Esta vez\n"
	.string "se ha abierto una segunda cámara.\p"
	.string "Le he pedido a nuestro geólogo que\n"
	.string "tenga sus instrumentos preparados\l"
	.string "por si vuelve a pasar.\p"
	.string "Cuanto más excavamos… más preguntas\n"
	.string "encontramos.$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "Otro temblor aquí, en las ruinas.\p"
	.string "Los datos muestran algo muy curioso.\p"
	.string "No ha sido un terremoto.\p"
	.string "Una especie de energía se acumuló\n"
	.string "bajo tierra y agrietó la roca desde\l"
	.string "dentro.\p"
	.string "¿Qué podría causar algo así…? La\n"
	.string "verdad es que no lo sé.$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "Otro temblor. Otra cámara que se abre.\p"
	.string "Seguimos sin entender qué patrón\n"
	.string "siguen.\p"
	.string "Oye, {PLAYER}… No estarás haciendo tú\n"
	.string "algo que provoque todo esto, ¿verdad?\p"
	.string "No, no puede ser.$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "¿Acabas de encontrar otra TABLA?\p"
	.string "……\p"
	.string "Claro.\p"
	.string "Los POKéMON legendarios que yacen en\n"
	.string "estas ruinas… te están respondiendo\l"
	.string "a ti, ¿verdad?\p"
	.string "Como si quisieran que los encontraran.\p"
	.string "Mis predicciones suelen cumplirse. No\n"
	.string "debería haber dudado de ti.$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "MÁXIMO: {PLAYER}.\p"
	.string "Ya estamos muy cerca. Lo noto.\p"
	.string "……\p"
	.string "Deberías venir a verlo con tus propios\n"
	.string "ojos.$"

