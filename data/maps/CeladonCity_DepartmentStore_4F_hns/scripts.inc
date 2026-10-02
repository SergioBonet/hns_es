CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "He venido a comprar CARTAS SURF para\n"
	.string "mandárselas a mi novia.\p"
	.string "¿Cómo? ¿Que se han agotado?$"

CeladonDeptStore4F_Text_Youngster:
	.string "Este es el único sitio donde se pueden\n"
	.string "comprar CARTAS AMOR.\p"
	.string "Bueno, lo era. Dicen que se han\n"
	.string "agotado.$"

CeladonDeptStore4F_Text_Directory:
	.string "¡Dilo con un regalo!\p"
	.string "P3: REGALOS$"
