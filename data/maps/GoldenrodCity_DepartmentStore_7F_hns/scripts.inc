GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
	.string "Uf, estoy cansada. A veces vengo a la\n"
	.string "azotea a tomarme un respiro.$"

GoldenrodDeptStore_Text_RoofFisher:
	.string "¿Perdona? ¿Quién dijo que un adulto\n"
	.string "no podía meterse en esto?\p"
	.string "¡Voy a volver todos los días para\n"
	.string "coleccionar todos los muñecos!$"

GoldenrodDeptStore_Text_RoofTwin:
	.string "Aquí suelen tener gangas a menudo.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
	.string "¡Oh, uau!$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
	.string "¿Vas a dejarme en paz?$"

GoldenrodDeptStore_Text_RoofPokefanM:
	.string "Hay algo que quiero realmente, pero no\n"
	.string "tengo el dinero suficiente…\p"
	.string "Es posible que venda las BAYAS que he\n"
	.string "recogido…$"

GoldenrodDeptStore_Text_RoofTeacher:
	.string "¡Oh, todo está tan barato!\p"
	.string "¡Compré tanto que mi MOCHILA está\n"
	.string "abarrotada!$"

GoldenrodDeptStore_Text_RoofBugCatcher:
	.string "Mis POKéMON siempre se paralizan o se\n"
	.string "envenenan en el peor momento…\p"
	.string "Así que he venido a comprar CURA\n"
	.string "TOTAL.\p"
	.string "¿Les quedará alguna?$"
