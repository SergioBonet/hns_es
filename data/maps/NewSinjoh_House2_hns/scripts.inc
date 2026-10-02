NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
	.string "Hola, pequeño…\p"
	.string "Bienvenido a la… Bueno, podríamos\n"
	.string "llamarla la biblioteca de NUEVO\l"
	.string "SINJOH.\p"
	.string "En realidad, aquí guardamos todos los\n"
	.string "registros de la historia de nuestro\l"
	.string "pueblo, además de los libros que\l"
	.string "traemos de otras regiones…$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "¿Tooor?$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
	.string "Está repleta de antiguos libros\n"
	.string "encuadernados en cuero.\p"
	.string "El idioma es irreconocible.$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
	.string "Está repleta de libros sobre POKéMON.\p"
	.string "Estos parecen más nuevos y\n"
	.string "familiares.$"
