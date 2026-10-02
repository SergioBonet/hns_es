Melemele_House_6_hns_MapScripts::
	.byte 0


Melemele_House6_Hiker::
	lock
	faceplayer
	msgbox Melemele_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_GameboyKid::
	lock
	faceplayer
	msgbox Melemele_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_Hiker_Text_0:
	.string "Compré esta casa para que mi hijo y yo\n"
	.string "pudiéramos explorar al aire libre…\p"
	.string "Y lo único que quiere es jugar con esa\n"
	.string "Game Boy Advance.$"

Melemele_House6_GameboyKid_Text_0:
	.string "¡Tengo un juego en mi Game Boy\n"
	.string "Advance que me deja explorar la región\l"
	.string "de ALOLA!\p"
	.string "Es igual que la de verdad.\p"
	.string "¡Se llama ULTRA ECLIPSE, de\n"
	.string "PHANTONOMY!\p"
	.string "¡Jaja, mira! ¡Voy montado en un\n"
	.string "NOIVERN de hielo!$"
