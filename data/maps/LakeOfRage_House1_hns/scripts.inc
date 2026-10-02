LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
	.string "Te has perdido…\p"
	.string "Yo he estado aquí meditando y un\n"
	.string "nuevo poder ha nacido dentro de mí.\p"
	.string "Déjame compartir mi poder con tus\p"
	.string "POKéMON. Toma esto, joven.$"

HiddenPowerGuy_Text_Explanation:
	.string "¿Lo ves? ¡Es PODER OCULTO!\p"
	.string "Saca el poder de los POKéMON para\n"
	.string "atacar.\p"
	.string "Recuerda: su tipo y poder dependen\n"
	.string "del POKéMON que lo usa.$"

HiddenPowerGuy_Text_Meditating:
	.string "Estoy meditando…$"
