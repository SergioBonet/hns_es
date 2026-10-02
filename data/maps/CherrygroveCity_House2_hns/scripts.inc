CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "¡Cuando era niño, era un brillante\n"
	.string "entrenador!\p"
	.string "Éste es mi consejo: ¡atrapa muchos\n"
	.string "POKéMON!\p"
	.string "¡Y trátalos con mucho cariño!$"
