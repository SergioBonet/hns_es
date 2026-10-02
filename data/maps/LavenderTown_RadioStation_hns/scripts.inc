LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "¿Qué tal? Mira por donde quieras en\n"
	.string "esta planta.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Lo siento, pero sólo puedes dar una\n"
	.string "vuelta por la planta baja.\p"
	.string "Desde que una banda criminal asaltó la\n"
	.string "TORRE RADIO de JOHTO, tuvimos que\l"
	.string "incrementar las medidas de seguridad.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "En la TORRE RADIO hay mucha gente que\n"
	.string "trabaja duramente.\p"
	.string "Seguro que están haciendo todo lo\n"
	.string "posible por emitir buenos programas.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "¡Oh, no, no, no!\p"
	.string "No hemos emitido desde que cerró la\n"
	.string "CENTRAL ENERGÍA.\p"
	.string "Si no emitimos, de nada servirá el\n"
	.string "esfuerzo realizado por la emisora.\p"
	.string "¡Me arruinaré!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! So you're the {PLAYER} who\n"
	.string "solved the POWER PLANT's problem?\p"
	.string "Thanks to you, I never lost my\n"
	.string "job.\p"
	.string "I tell you, you're a real\n"
	.string "lifesaver!\p"
	.string "Please take this as my thanks.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtained the\n"
	.string "RADIO UPGRADE!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "With that thing, you can tune into\n"
	.string "the radio programs here in KANTO.\p"
	.string "Gahahahaha!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Hey there!\p"
	.string "I am the super MUSIC DIRECTOR!\p"
	.string "Huh? Your RADIO can't tune into\n" @POKéGEAR
	.string "my music programs. How unfortunate!\p"
	.string "If you get an EXPN CARD upgrade,\n"
	.string "you can tune in. You'd better get\l"
	.string "one!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "¡Oye, joven!\p"
	.string "¡Soy el Director de programas\n"
	.string "musicales!\p"
	.string "Soy el encargado de las fantásticas\n"
	.string "melodías que se emiten aquí. ¡Atrapa\l"
	.string "la música de las ondas!$"

LavenderTown_RadioStation_Text_Directory:
	.string "PB RECEPCIÓN P1 VENTAS\p"
	.string "P2 PERSONAL P3 PRODUCCIÓN\p"
	.string "P4 DESPACHO DEL DIRECTOR$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Anima a los POKé- MON con la melodía\n"
	.string "de la POKé FLAUTA del CANAL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "¡Uau! Un estante lleno de CD y vídeos\n"
	.string "de POKéMON.\p"
	.string "Debe de ser una biblioteca.$"

