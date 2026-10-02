OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh... Hello, {PLAYER}.\p"
	.string "These dishes in front of me are\n"
	.string "not all mine...\p"
	.string "Uh...\p"
	.string "Actually, the person who sat here\n"
	.string "before me ate a lot...\p"
	.string "If you'd like to battle again,\n"
	.string "please visit me at the FIGHTING\l"
	.string "DOJO in SAFFRON CITY.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "¡Ja! ¡Tus POKéMON parecen ser muy\n"
	.string "enclenques!\p"
	.string "No tienen el poder para desplazar\n"
	.string "rocas.\p"
	.string "Mira, ¡usa esto y enséñales FUERZA!$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "On the sea, the only thing you\n"
	.string "can count on is your own self!\p"
	.string "I'm so proud of my buff bod!\n"
	.string "You should train like me!$"

OlivineCity_Text_CafeFishingGuru:
	.string "OLIVINE CAFE's menu is packed\n"
	.string "with hearty fare for beefy\l"
	.string "SAILORS like me!$"

OlivineCity_Text_CafeSailor:
	.string "Cuando estoy de paso, siempre visito\n"
	.string "el CAFÉ OLIVO.\p"
	.string "Todo lo del menú me hace sentir más\n"
	.string "fuerte. ¡No puedo parar de comer!$"

