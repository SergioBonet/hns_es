GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "Buuf… Me desafiaron a un combate en\n"
	.string "el piso de abajo. Son muy duros. Ten\l"
	.string "mucho cuidado.$"


GoldenrodUnderground1_Text_Teacher:
	.string "Abajo hay algunas tiendas…\p"
	.string "Pero también hay entrenadores.\p"
	.string "Me da miedo bajar ahí.$"
