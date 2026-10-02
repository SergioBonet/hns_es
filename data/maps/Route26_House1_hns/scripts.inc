Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
	.string "Tus POKéMON parecen cansados.\p"
	.string "Deberías dejarlos descansar un poco.$"

Route26_Text_HealHouseKeepAtIt:
	.string "¡Vaya! ¡Tus POKéMON tienen buen\n"
	.string "aspecto!\p"
	.string "¡Sigue así!$"
