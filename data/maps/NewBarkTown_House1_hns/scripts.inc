NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU es un POKéMON evolucionado.\p"
	.string "El descubrimiento del PROF. ELM me\n"
	.string "deja impresionada.\p"
	.string "Es muy famoso por su investigación\n"
	.string "sobre la evolución POKéMON.\p"
	.string "(Suspiro…)\p"
	.string "Ojalá fuera una investigadora como\n"
	.string "él…$"


NewBarkTown_House1_Text_Neighbor:
	.string "My daughter is adamant about\n"
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!\p"
	.string "But then, so do I!$"

