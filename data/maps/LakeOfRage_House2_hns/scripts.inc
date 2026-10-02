LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
	.string "En realidad, el LAGO DE LA FURIA es un\n"
	.string "cráter que hicieron unos GYARADOS\l"
	.string "desbocados.\p"
	.string "El cráter se llenó de agua de lluvia y\n"
	.string "así se formó el LAGO.\p"
	.string "Esa es la historia que nos ha llegado\n"
	.string "desde el tatarabuelo de mi abuelo.\p"
	.string "Antes se podían pescar MAGIKARP muy\n"
	.string "vivarachos, pero…\p"
	.string "No entiendo qué está pasando.$"

LakeOfRage_House2_Text_MenInBlack:
	.string "En el LAGO pasan cosas raras desde\n"
	.string "que llegaron esos hombres de negro.$"

LakeOfRage_House2_Text_LastMon:
	.string "¡No dejes que me quede con tu último\n"
	.string "POKéMON!$"

LakeOfRage_House2_Text_WorldsLargest:
	.string "El LAGO DE LA FURIA ha vuelto a la\n"
	.string "normalidad.\p"
	.string "Los MAGIKARP han vuelto.\p"
	.string "Quizás aún pueda cumplir mi sueño de\n"
	.string "tener el MAGIKARP más grande del\l"
	.string "mundo.\p"
	.string "De hecho… ¡te pagaré ¥2000 por cada\n"
	.string "MAGIKARP que me des, y ¥100.000 por un\l"
	.string "MAGIKARP ENORME!$"

LakeOfRage_House2_Text_ForMe:
	.string "Bueno… ¿Tienes un MAGIKARP para mí?$"

LakeOfRage_House2_Text_HaveMagikarp:
	.string "¡Ah, tienes un MAGIKARP! A ver lo\n"
	.string "grande que es ese bebé.$"

LakeOfRage_House2_Text_BigPayout:
	.string "¡Uau! ¡Este es extraordinario!\p"
	.string "¡Me quito el sombrero!\p"
	.string "Aquí tienes algo por las molestias.$"

LakeOfRage_House2_Text_Bonus:
	.string "Lo importante es el récord. ¡Piensa en\n"
	.string "él como una bonificación!$"

LakeOfRage_House2_Text_TooShort:
	.string "¡Uau! ¡Este es extraordinario!\p"
	.string "… Ojalá pudiera decirlo, pero he visto\n"
	.string "uno más grande.\p"
	.string "Supongo que algo vale.$"

LakeOfRage_House2_Text_NotMagikarp:
	.string "¿Qué? ¡Eso no es un MAGIKARP!$"

LakeOfRage_House2_Text_Refused:
	.string "¿No tienes ninguno bueno que\n"
	.string "enseñarme? Quizá la próxima vez.$"
