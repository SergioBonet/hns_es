GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "Es la ranura de la LLAVE MAGNÉTICA.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} usó la LLAVE MAGNÉTICA.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "The gate is open.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "P2 PERSONAL$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MÚSICA POKéMON con el DJ NARDO$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "We have recordings of the cries\n"
	.string "of all POKéMON that have been\l"
	.string "found.\p"
	.string "We must have about 400 kinds.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Los POKéMON son muy queridos por sus\n"
	.string "entrenadores.\p"
	.string "Es horrible ver cómo trata el\p"
	.string "TEAM ROCKET a los POKéMON.$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "Emitimos programas de\n"
	.string "entretenimiento las 24 horas del día.\p"
	.string "¡Intentaremos hacerlo lo mejor\n"
	.string "posible!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Nuestro jefe se ha encerrado bajo\n"
	.string "llave tras esa puerta.\p"
	.string "¡Pero el Director puede abrirla! ¡Está\n"
	.string "en el cuarto piso!\p"
	.string "¡Sálvalo, por favor!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "¿Está a salvo el DIRECTOR?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "¡Gracias! ¡Eres genial!\p"
	.string "Toma esto como agradecimiento.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "It's SUNNY DAY.\p"
	.string "It powers up fire-type moves\n"
	.string "for a while.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "¡Has estado genial!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "He recibido órdenes.\p"
	.string "¡Aplastaré a todo aquel que desafíe\n"
	.string "al TEAM ROCKET!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "¿¡Qué!?$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "I failed in my duties…\p"
	.string "ARCHER will be so upset...$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "Me encanta ordenar a los POKéMON que\n"
	.string "cometan delitos.$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "¿Bromeas?$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "I feel lousy over losing!\p"
	.string "Darn it! I hate useless POKéMON!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "¿Por qué se abrió la puerta?\p"
	.string "¿Acaso has tenido algo que ver?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "¡Es mi fin!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "¿Qué? ¿Esquivaste a nuestros hombres\n"
	.string "del SUBTERRÁNEO?\p"
	.string "¿Cómo lo hiciste?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "¿Qué haces merodeando por aquí?\p"
	.string "¿Quién eres?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "¡Vaya! ¡No te tomé muy en serio!$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "¡Ja, ja, ja! Desde aquí puedo\n"
	.string "transmitir todo tipo de señales.$"

