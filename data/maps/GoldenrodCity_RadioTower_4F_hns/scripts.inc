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
	.string "PROTON: Now wait just one second!\p"
	.string "Aren't you the one who got in our\n"
	.string "way at SLOWPOKE WELL?\p"
	.string "I see... You're doing all this\n"
	.string "because you want to make me angry.\l"
	.string "Be careful!\p"
	.string "But since you seem to wish it, I'll\n"
	.string "show you the full extent of a TEAM\l"
	.string "ROCKET EXECUTIVE's wrath!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Phew...$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "PROTON: You may have won this\n"
	.string "time... But all you did was make\p"
	.string "TEAM ROCKET's wrath grow.$"

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
	.string "MARY: It's good for dodging the\n"
	.string "enemy's attacks.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "MARY: Please tune into me on PROF.\n"
	.string "OAK'S POKéMON TALK show!$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MEOWTH: Meowth…$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "You plan to rescue the DIRECTOR?\p"
	.string "That won't be possible because I'm\n"
	.string "going to beat you!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "¡No! ¡Increíble!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "¡Increíble! ¡He perdido!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "¡Alto ahí! ¡Me llaman la fortaleza del\n"
	.string "TEAM ROCKET!\p"
	.string "¡No des un paso más!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "The fortress came down!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "You've earned my respect, so here's\n"
	.string "some advice.\p"
	.string "It's not too late. You can still turn\n"
	.string "back.$"

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
	.string "Most excellent.\p"
	.string "This RADIO TOWER will fulfill our\n"
	.string "grand design.$"

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
