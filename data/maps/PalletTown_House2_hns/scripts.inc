PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "DALIA: ¡Hola! Mi hermano es LÍDER\p"
	.string "del GIMNASIO de CIUDAD VERDE.\p"
	.string "Pero sale tanto de la ciudad que trae\n"
	.string "problemas a los entrenadores.$"

PalletTown_House2_Text_OfferGrooming:
	.string "DALIA: ¡Llegas a tiempo! Iba a tomar\n"
	.string "un té.\p"
	.string "¿Quieres tomarte uno?\p"
	.string "Tus POKéMON están un poco sucios.\p"
	.string "¿Quieres que limpie a uno?$"

PalletTown_House2_Text_WhichMon:
	.string "DALIA: ¿Qué POKéMON limpio?$"

PalletTown_House2_Text_Alright:
	.string "DALIA: Vale, haré que mejore su\n"
	.string "aspecto enseguida.$"

PalletTown_House2_Text_AllDone:
	.string "DAISY: There you go! All done.\p"
	.string "See? Doesn't {STR_VAR_1} look\n"
	.string "nice?\p"
	.string "It's such a cute POKéMON.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "DALIA: Siempre tomo té a esta hora.\n"
	.string "Ven cuando quieras.$"

PalletTown_House2_Text_Refused:
	.string "DALIA: ¿No quieres que limpie a un\p"
	.string "POKéMON? Vale, tan sólo tomaremos té.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "DALIA: Lo siento. No puedo limpiar un\n"
	.string "HUEVO.$"
