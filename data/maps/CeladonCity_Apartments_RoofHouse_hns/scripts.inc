CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Te contaré una historia de miedo.$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Pero no te dará tanto miedo si aún es\n"
	.string "de día.\p"
	.string "Vuelve cuando anochezca, ¿vale?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Érase una vez un niño al que le\n"
	.string "regalaron una BICICLETA nueva…\p"
	.string "Quería probarla enseguida…\p"
	.string "Se lo estaba pasando tan bien que no\n"
	.string "se dio cuenta de que se había puesto\l"
	.string "el sol…\p"
	.string "Mientras volvía a casa en plena noche,\n"
	.string "¡la bici empezó a ir más despacio de\l"
	.string "repente!\p"
	.string "¡Los pedales le pesaban!\p"
	.string "Y cuando dejó de pedalear, ¡la bici\n"
	.string "empezó a ir hacia atrás!\p"
	.string "¡Era como si la bici estuviera maldita\n"
	.string "y quisiera arrastrarlo al olvido!\p"
	.string "…\p"
	.string "…\p"
	.string "¡AAAAAAAH!\p"
	.string "¡El niño iba cuesta arriba por el\n"
	.string "CAMINO de BICIS!\p"
	.string "… ¡Chan, chan!\p"
	.string "Por escucharme con tanta paciencia,\n"
	.string "puedes quedarte esto: ¡la MT82!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La MT82 es SONÁMBULO.\p"
	.string "Permite a tu POKéMON usar un\n"
	.string "movimiento al azar mientras duerme.\p"
	.string "¡Pero a ver quién duerme después de\n"
	.string "esta historia tan terrorífica!$"

