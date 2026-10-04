VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "¡Mi PIDGEY volará al norte,\n"
	.string "a CIUDAD AZAFRÁN, para llevar\l"
	.string "una carta!$"

VermilionCity_House3_Text_Pidgey::
	.string "PIDGEY: ¡Pid, pid!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Querido PIPPI:\n"
	.string "Espero verte pronto.\p"
	.string "Dicen que en CIUDAD AZAFRÁN\n"
	.string "tienen problemas con el TEAM\l"
	.string "ROCKET.\p"
	.string "La CIUDAD CARMÍN parece segura.$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "Me gustaría mandarme CARTAS\n"
	.string "con mucha gente.\p"
	.string "He mandado a mi PIDGEY a la\n"
	.string "SALA UNIÓN para que intercambie\l"
	.string "CARTAS por mí.$"

