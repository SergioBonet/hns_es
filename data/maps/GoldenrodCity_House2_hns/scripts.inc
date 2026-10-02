GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
	.string "Un día estaba luchando y mis\p"
	.string "POKéMON no se podían mover.\p"
	.string "Sus movimientos no tenían ningún\p"
	.string "PUNTO de PODER o PP.$"

GoldenrodPPSpeechHouse_Text_Lass:
	.string "A veces, un POKéMON sano no puede\n"
	.string "usar sus movimientos.\p"
	.string "Si ocurre esto, cúralo en el\p"
	.string "CENTRO POKéMON o usa un objeto.$"
