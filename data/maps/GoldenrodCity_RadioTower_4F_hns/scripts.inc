GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "PROTÓN: ¡Espera un momento!\p"
	.string "¿No eres tú el que se interpuso en\n"
	.string "nuestro camino en el POZO SLOWPOKE?\p"
	.string "Ya veo… Haces todo esto porque\n"
	.string "quieres que me enfade. ¡Ten cuidado!\p"
	.string "Pero ya que parece que lo deseas, ¡te\n"
	.string "mostraré toda la ira de un EJECUTIVO\l"
	.string "del TEAM ROCKET!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Uf…$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "PROTÓN: Puede que esta vez hayas\n"
	.string "ganado… Pero lo único que has\l"
	.string "conseguido es\p"
	.string "aumentar la ira del TEAM ROCKET.$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "Mientras estaba en las RUINAS oía la\n"
	.string "radio.\p"
	.string "Y escuché un extraño programa.$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "Rosa: ¿Por qué? ¿Por qué ha de\n"
	.string "pasarme esto a mí?\p"
	.string "¡MEOWTH, ayúdame!$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "ROSA: ¡Oh! ¡Eres mi salvación!\p"
	.string "¿Aceptas esto como agradecimiento?$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "ROSA: Es buenísimo para esquivar los\n"
	.string "ataques del enemigo.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "ROSA: ¡Sintonízame en el programa LA\n"
	.string "HORA POKéMON del PROF. OAK!$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MEOWTH: Meowth…$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "¿Pretendes rescatar al DIRECTOR?\p"
	.string "¡Eso no va a ser posible porque voy a\n"
	.string "vencerte!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "¡No! ¡Increíble!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "¡Increíble! ¡He perdido!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "¡Alto ahí! ¡Me llaman la fortaleza del\n"
	.string "TEAM ROCKET!\p"
	.string "¡No des un paso más!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "¡La fortaleza ha caído!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Te has ganado mi respeto, así que te\n"
	.string "daré un consejo.\p"
	.string "No es demasiado tarde. Aún puedes dar\n"
	.string "media vuelta.$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "¿Son buenos mis POKéMON?\p"
	.string "¡Creeré que mis POKéMON son buenos\n"
	.string "cuando derroten a los tuyos!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "¡Oh, no! ¡Son tan inútiles!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "¡Me amo a mí misma!\p"
	.string "¿Qué importan los POKéMON?$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Excelente.\p"
	.string "Esta ESTACIÓN DE RADIO hará realidad\n"
	.string "nuestro gran plan.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "¡Mmmm…!\p"
	.string "Todo gran plan tiene sus pegas.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "¿De verdad crees que puedes detener\n"
	.string "al TEAM ROCKET?$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "P3 PRODUCCIÓN$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "P3 ESTUDIO 2$"
