NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "¡Hola, {PLAYER}!\p"
	.string "Mi marido siempre está muy ocupado.\n"
	.string "Espero que esté bien.\p"
	.string "Cuando se embebe en la investigación\n"
	.string "de POKéMON, se olvida hasta de comer.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "¡Cuando sea mayor, ayudaré a mi padre!\p"
	.string "¡Voy a ser un gran profesor POKéMON!$"
