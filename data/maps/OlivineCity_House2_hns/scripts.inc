OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "De camino a CIUDAD ORQUÍDEA hay\n"
	.string "cuatro islas desiertas.\p"
	.string "¡A los niños malos los llevan a esas\n"
	.string "islas como castigo!$"

OlivineCity_Text_PunishmentBoy:
	.string "Cada vez que me meto en líos, mi\n"
	.string "hermano mayor me asusta.$"
