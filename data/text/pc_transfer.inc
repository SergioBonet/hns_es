gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} fue enviado al PC\n"
	.string "de alguien.\p"
	.string "Se ha guardado en la CAJA\n"
	.string "“{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} was transferred to\n"
#if IS_FRLG || IS_HNS
	.string "BILL'S PC.\p"
#else
	.string "LANETTE'S PC.\p"
#endif
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "La CAJA “{STR_VAR_3}” del PC\n"
	.string "de alguien estaba llena.\p"
	.string "{STR_VAR_2} fue enviado a la CAJA\n"
	.string "“{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "BOX “{STR_VAR_3}” on\n"
#if IS_FRLG || IS_HNS
	.string "BILL'S PC was full.\p"
#else
	.string "LANETTE'S PC was full.\p"
#endif
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} ha sido enviado al PC de\n"
	.string "{B_PC_CREATOR_NAME}.\p"
	.string "Se ha colocado en la CAJA\n"
	.string "“{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "¡{PLAYER} ha obtenido {STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "¡No queda sitio para más POKéMON!\p"
	.string "¡Las CAJAS POKéMON están llenas!$"

gText_NicknameThisPokemon::
	.string "¿Quieres darle un mote\n"
	.string "a tu {STR_VAR_1}?$"
