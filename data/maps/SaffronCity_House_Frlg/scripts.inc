SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "Gracias por escribir.\n"
	.string "¡Espero verte pronto!\p"
	.string "¡Oye!\n"
	.string "¡No mires mi carta!$"

SaffronCity_House_Text_Pidgey::
	.string "PIDGEY: ¡Pid, pid!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "¡La COPIONA es muy mona!\n"
	.string "¡Voy a darle un POKé MUÑECO!$"

SaffronCity_House_Text_ExplainPPUp::
	.string "Recibí MÁS PP como regalo.\p"
	.string "¡Sirve para aumentar los PP de\n"
	.string "un movimiento de un POKéMON!\p"
	.string "Creo que voy a usarlo con un\n"
	.string "movimiento potente, que tenga\l"
	.string "pocos PP.$"

