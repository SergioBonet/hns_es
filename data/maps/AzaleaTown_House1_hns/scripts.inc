AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Todos los SLOWPOKE del pueblo han\n"
	.string "desaparecido.\p"
	.string "Quizá el guardián del ENCINAR esté\n"
	.string "enfadado…\p"
	.string "Puede ser un mal presagio. Será mejor\n"
	.string "no salir.$"

CharcoalKiln_Text_Boss2:
	.string "The SLOWPOKE have returned…$"

CharcoalKiln_Text_Boss3:
	.string "Los SLOWPOKE han vuelto…\p"
	.string "Pero mi APRENDIZ no ha vuelto del\n"
	.string "ENCINAR.\p"
	.string "¿Dónde demonios está ese vago?$"

CharcoalKiln_Text_Boss4:
	.string "¿Expulsaste al TEAM ROCKET y fuiste\n"
	.string "solo al ENCINAR?\p"
	.string "¡Qué valiente! Me gustas. Entrena con\n"
	.string "nosotros.$"

CharcoalKiln_Text_Apprentice1:
	.string "¿Adónde han ido los SLOWPOKE?\p"
	.string "¿Están jugando fuera?$"

CharcoalKiln_Text_Apprentice2:
	.string "The SLOWPOKE came back!$"

CharcoalKiln_Text_Apprentice3:
	.string "Lo siento. Olvidé darte las gracias.\p"
	.string "Éste es el CARBÓN que he fabricado.\p"
	.string "A los POKéMON de fuego les gustará\n"
	.string "llevarlo.$"

CharcoalKiln_Text_Apprentice4:
	.string "Los SLOWPOKE han vuelto, hasta\n"
	.string "FARFETCH'D.\p"
	.string "¡Eres lo mejor, de verdad!$"

CharcoalKiln_Text_Farfetchd:
	.string "FARFETCH'D: ¡Farf!$"
