Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "A ver…\n"
	.string "¡Vaya! ¡Solo has capturado\l"
	.string "{STR_VAR_3} especies de POKéMON!\p"
	.string "Necesitas {STR_VAR_1} especies\n"
	.string "si quieres el objeto {STR_VAR_2}.$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "…Ah, ya veo.\p"
	.string "Cuando tengas {STR_VAR_1} especies\n"
	.string "de POKéMON, vuelve a por el objeto\l"
	.string "{STR_VAR_2}.$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "¡Oh! Parece que no tienes sitio\n"
	.string "para el objeto {STR_VAR_2}.$"
