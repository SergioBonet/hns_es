CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
	.string "¡Hola! ¡Éste es el CENTRO COMERCIAL de\n"
	.string "CIUDAD AZULONA!\p"
	.string "El directorio está en la pared.$"

CeladonDeptStore_Text_1FGentleman:
	.string "Este C. COMERCIAL pertenece a la\n"
	.string "misma cadena que el de C. TRIGAL.\p"
	.string "Los dos fueron renovados al mismo\n"
	.string "tiempo.$"

CeladonDeptStore_Text_1FTeacher:
	.string "Es la primera vez que vengo.\p"
	.string "Es muy grande…\p"
	.string "Me da miedo perderme.$"

CeladonDeptStore_Text_1FDirectory:
	.string "PB: INFORMACIÓN\p"
	.string "P1: TIENDA DE ENTRENADORES\p"
	.string "P2: TIENDA DE MT\p"
	.string "P3: REGALOS\p"
	.string "P4: FARMACIA\p"
	.string "P5: AZOTEA$"
