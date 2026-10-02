SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
	.string "Intento olvidar a mis enemigos.\n"
	.string "¡Luchemos!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
	.string "Estoy desolada…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "A voyage is best for getting over\n"
    .string "a broken heart.\p"
    .string "But a FAST SHIP trip is too short\n"
    .string "for grieving.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
	.string "Voy a una audición de mis canciones en\n"
	.string "la EMISORA de CIUDAD TRIGAL.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
	.string "¡Uauu! ¡Distorsión total!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
	.string "Iba a hacer mi debut en la TORRE\n"
	.string "BATALLA…\p"
	.string "Debo regresar a CIUDAD CARMÍN para\n"
	.string "volver a entrenar…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
	.string "Hablando de la ESTACIÓN de RADIO,\n"
	.string "¿cuál es el número de la suerte de\l"
	.string "esta semana?$"
