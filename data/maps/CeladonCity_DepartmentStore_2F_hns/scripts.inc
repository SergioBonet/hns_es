CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Hace poco que soy entrenador. Mi hijo\n"
	.string "me animó a serlo.\p"
	.string "Estoy impresionado por la cantidad de\n"
	.string "objetos útiles que hay.$"

CeladonDeptStore2F_Text_Youngster:
	.string "A mi padre le está costando aprender\n"
	.string "los nombres de los objetos y cómo se\l"
	.string "supone que debe utilizarlos…$"

CeladonDeptStore2F_Text_Directory:
	.string "¡Objetos de máxima calidad para\n"
	.string "entrenadores!\p"
	.string "P1: TIENDA DE ENTRENADORES$"

