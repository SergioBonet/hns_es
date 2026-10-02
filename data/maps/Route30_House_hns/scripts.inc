Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Si sigues ese camino hacia el norte,\n"
	.string "verás la casa del SR. POKéMON.\p"
	.string "Pero antes de que te vayas, ¡deja que\n"
	.string "te hable de las BAYAS!\p"
	.string "Los POKéMON se ponen más sanos\n"
	.string "comiendo BAYAS.\p"
	.string "Incluso pueden comerse las BAYAS que\n"
	.string "llevan durante los combates.\p"
	.string "CÉSAR, de PUEBLO AZALEA, también\n"
	.string "puede convertir las BAYAS en BALLS.\p"
	.string "Toma. ¡Te daré una!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Busca BAYAS en los árboles. Vuelven a\n"
	.string "crecer al cabo de unas horas.$"
