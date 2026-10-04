CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "¡Hola! Éste es el CENTRO\n"
	.string "COMERCIAL de AZULONA.\p"
	.string "El tablero de la derecha es un\n"
	.string "plano de las tiendas.$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "PB: PUESTO DE INFORMACIÓN\p"
	.string "P1: TIENDA DE ENTRENADORES\p"
	.string "P2: VIDEOJUEGOS\p"
	.string "P3: REGALOS\p"
	.string "P4: FARMACIA\p"
	.string "ÚLTIMO PISO: DISTRIBUIDORES$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "PB: PUESTO DE INFORMACIÓN$"

