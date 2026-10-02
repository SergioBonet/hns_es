CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Si ves una bifurcación dentro de una\n"
	.string "cueva, lo más probable es que un\l"
	.string "camino sea el bueno y el otro no lleve\l"
	.string "a ninguna parte.\p"
	.string "Pero la gente no puede evitar probar\n"
	.string "los dos.$"
