CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "¿Sabías que aquí al lado hay una ZONA\n"
	.string "SAFARI?\p"
	.string "¡Es muy divertida! Verás muchísimas\n"
	.string "clases de POKéMON, ¡y puedes atrapar\l"
	.string "todos los que quieras!\p"
	.string "No hay ningún motivo para no ir,\n"
	.string "¿verdad? Está aquí al lado.$"

CliffEdgeGate_Text_Expectations:
	.string "Me alegra que todo el mundo tenga\n"
	.string "tantas ganas.\p"
	.string "Pero la señora de la recepción parece\n"
	.string "un poco exagerada…\p"
	.string "¡No te hagas demasiadas ilusiones!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "¡Experimenta el mundo salvaje!\n"
	.string "¡Explora el mundo de los POKéMON!\p"
	.string "¡La ZONA SAFARI de Baoba está\n"
	.string "abierta!$"

