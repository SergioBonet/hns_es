Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Soy el hermano pequeño del GURÚ\n"
	.string "PESCADOR.\p"
	.string "Veo que te gusta pescar.\p"
	.string "¡No tengo ninguna duda!\p"
	.string "Sé que tengo razón.$"

Route12_House_Text_GiveSuperRod:
	.string "Sí, sí. ¡Justo lo que pensaba!\p"
	.string "¡Toma, aficionado a la pesca! Llévate\n"
	.string "esto: es una SUPERCAÑA.$"

Route12_House_Text_GaveSuperRod:
	.string "Intenta pescar allí donde veas agua.\p"
	.string "Recuerda: puedes capturar POKéMON\p"
	.string "diferentes usando distintas CAÑAS.$"

Route12_House_Text_DontWantSuperRod:
	.string "¿Eh? ¿Me engañan mis ojos?$"

