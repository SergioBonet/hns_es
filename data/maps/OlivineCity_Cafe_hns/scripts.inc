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
	.string "Oh… Hola, {PLAYER}.\p"
	.string "Estos platos que tengo delante no son\n"
	.string "todos míos…\p"
	.string "Eh…\p"
	.string "La verdad es que la persona que se\n"
	.string "sentó aquí antes que yo comió\l"
	.string "muchísimo…\p"
	.string "Si quieres volver a luchar, ven a verme\n"
	.string "al DOJO KARATE de CIUDAD AZAFRÁN.$"

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
	.string "¡En el mar solo puedes contar contigo\n"
	.string "mismo!\p"
	.string "¡Estoy muy orgulloso de mi cuerpazo!\n"
	.string "¡Deberías entrenar como yo!$"

OlivineCity_Text_CafeFishingGuru:
	.string "¡El menú de la CAFETERÍA de CIUDAD\n"
	.string "OLIVO está lleno de platos\l"
	.string "contundentes para MARINEROS\l"
	.string "musculosos como yo!$"

OlivineCity_Text_CafeSailor:
	.string "Cuando estoy de paso, siempre visito\n"
	.string "el CAFÉ OLIVO.\p"
	.string "Todo lo del menú me hace sentir más\n"
	.string "fuerte. ¡No puedo parar de comer!$"

