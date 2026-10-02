PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "¡Hola!\p"
	.string "ROJO lleva fuera mucho tiempo.\p"
	.string "Tampoco ha llamado, así que no sé\n"
	.string "dónde está, ni lo que ha estado\l"
	.string "haciendo.\p"
	.string "Dicen que si no hay noticias es que\n"
	.string "todo va bien, pero estoy preocupada\l"
	.string "por él.$"

RedsHouse_Text_Mom2:
	.string "Me preocupa que ROJO esté herido o\n"
	.string "enfermo, pero ya es todo un\l"
	.string "hombrecito. Estoy orgullosa de que\l"
	.string "esté haciendo lo que quiere.$"

RedsHouse_Text_TV:
	.string "Tienen programas que no se emiten en\n"
	.string "JOHTO…$"
