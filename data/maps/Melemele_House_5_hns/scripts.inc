Melemele_House_5_hns_MapScripts::
	.byte 0


Melemele_House5_Mom::
	lock
	faceplayer
	msgbox Melemele_House5_Mom_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House5_Son::
	lock
	faceplayer
	msgbox Melemele_House5_Son_Text_0
	applymovement melemele_elio Melemele_House5_Son_Movement
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement
	msgbox Melemele_House5_Son_Text_1, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_MEOWTH, 0
	waitmoncry
	release
	end


Melemele_House5_Cat::
	lock
	faceplayer
	playmoncry SPECIES_MEOWTH, 0
	msgbox Melemele_House5_Cat_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

Melemele_House5_Son_Movement:
	jump_in_place_down
	jump_in_place_down
	step_end

Melemele_House5_Mom_Text_0:
	.string "Estoy pensando en mudarme a la región\n"
	.string "de ALOLA con mi hijo, ELIO.\p"
	.string "¡Aquí, en las ISLAS, estamos probando\n"
	.string "un poquito cómo es!$"

Melemele_House5_Son_Text_0:
	.string "Jeje… ¡Qué divertido es jugar a pillar!$"

Melemele_House5_Son_Text_1:
	.string "¡A que no me pillas, MEOWTH!$"

Melemele_House5_Cat_Text_0:
	.string "¡¡¡Miaaauuurrrrrr!!!$"
