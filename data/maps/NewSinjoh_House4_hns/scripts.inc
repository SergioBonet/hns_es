NewSinjoh_House4_hns_MapScripts::
	.byte 0

NewSinjoh_Cafe_Script_Sister::
	lock
	faceplayer
	message NewSinjoh_Cafe_Text_ResturantGreeting
	waitmessage
	pokemart NewSinjoh_Cafe_Pokemart_Resturant
	msgbox NewSinjoh_Cafe_Text_ResturantEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Cafe_Pokemart_Resturant:
	.2byte ITEM_YACHE_BERRY
    .2byte ITEM_LANSAT_BERRY
    .2byte ITEM_ROWAP_BERRY
    .2byte ITEM_BERRY_JUICE
	.2byte ITEM_SODA_POP
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_LEEK
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_NONE
	release
	end

NewSinjoh_Cafe_Text_ResturantGreeting:
	.string "¡H-hola! ¡Bienvenido a nuestra\n"
	.string "cafetería! ¿En qué puedo ayudarte?$"

NewSinjoh_Cafe_Text_ResturantEnd:
	.string "¡Vuelve cuando quieras!$"

NewSinjoh_Cafe_EventScript_BaldingMan::
	msgbox NewSinjoh_Cafe_Text_BaldingMan, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_BaldingMan:
	.string "Desde que se tiene memoria, esta\n"
	.string "cafetería la lleva una familia de aquí.\p"
	.string "La más pequeña, la de allí, no está\n"
	.string "acostumbrada a atender a tantos\l"
	.string "forasteros.$"

NewSinjoh_Cafe_EventScript_ScientistF::
	msgbox NewSinjoh_Cafe_Text_ScientistF, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_ScientistF:
	.string "¡Esta bebida está buení--ísima!\p"
	.string "……\p"
	.string "……\p"
	.string "Jajaja\p"
	.string "……$"

NewSinjoh_Cafe_EventScript_ScientistM::
	lock
	faceplayer
	msgbox NewSinjoh_Cafe_Text_ScientistM, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_Cafe_Text_ScientistM:
	.string "Perdona a mi compañera…\p"
	.string "Las bebidas de aquí son más fuertes\n"
	.string "que las que tomamos en HOENN.\p"
	.string "Intenté avisarla, pero dijo que\n"
	.string "necesitaba desconectar.\p"
	.string "Esta expedición de investigación está\n"
	.string "siendo dura para todos.$"

NewSinjoh_Cafe_EventScript_Gentleman::
	msgbox NewSinjoh_Cafe_Text_Gentleman, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_Gentleman:
	.string "¿Qué miras, chaval?\p"
	.string "No tiene nada de malo que un hombre y\n"
	.string "su POKéMON coman en la misma mesa.$"

NewSinjoh_EventScript_Scyther::
	lock
	faceplayer
	playmoncry SPECIES_SCYTHER, 0
	msgbox NewSinjoh_Text_Scyther, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Scyther:
	.string "¡Scyyy!$"
