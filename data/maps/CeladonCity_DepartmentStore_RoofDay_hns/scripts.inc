CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "¡Una máquina expendedora!$"

CeladonDeptStore6F_Text_Clang:
	.string "¡Clonc!\p"
	.string "¡Ha salido {STRING}!$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "¡Uups, no tienes bastantes fichas!$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "No hay sitio para nada más…$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "Una máquina expendedora con una\n"
	.string "ruleta de premios…\p"
	.string "Nunca verás nada igual.$"

CeladonDeptStore6F_Text_Youngster:
	.string "¡Auu! ¡Aquí no hay juegos!\p"
	.string "Quería jugar…$"

CeladonDeptStore6F_Text_Directory:
	.string "6.ª P.: MÁQUINAS EXPENDEDORAS DE LA\n"
	.string "AZOTEA$"
