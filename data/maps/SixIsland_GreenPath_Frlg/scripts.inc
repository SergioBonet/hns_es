SixIsland_GreenPath_Frlg_MapScripts::
	.byte 0

SixIsland_GreenPath_EventScript_RightRouteSign::
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_Text_JaclynIntro::
	.string "¿Mmm?...\p"
	.string "Me pareció haber elegido mi casa\n"
	.string "con TELETRANSPORTE, pero...\l"
	.string "¿dónde estoy?$"

SixIsland_GreenPath_Text_JaclynDefeat::
	.string "¡Auuuuuch!$"

SixIsland_GreenPath_Text_JaclynPostBattle::
	.string "No sé muy bien dónde estoy...\p"
	.string "Debo centrarme en TELETRANSPORTE\n"
	.string "para volver a mi casa...$"

SixIsland_GreenPath_Text_LeftRouteSign::
	.string "VÍA VERDE\n"
	.string "HACIA EL BOSQUEJO$"

SixIsland_GreenPath_Text_RightRouteSign::
	.string "VÍA VERDE\n"
	.string "¡Hay que tener respeto\l"
	.string "hasta por el último seto!$"

