CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "¡Hola!\p"
	.string "¡Soy el DISEÑADOR DEL JUEGO!\p"
	.string "Te costará completar tu\p"
	.string "POKéDEX, pero… ¡no te rindas!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "¡Uau! ¡Excelente! ¡Has completado tu\n"
	.string "POKéDEX!\p"
	.string "¡Enhorabuena!$"

GameFreak_Text_GraphicArtist:
	.string "Soy el DISEÑADOR GRÁFICO.\p"
	.string "¡Yo te he dibujado!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Soy el DISEÑADOR GRÁFICO.\p"
	.string "¿Has completado tu POKéDEX?\p"
	.string "¿Quieres imprimir tu DIPLOMA?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Avísame si quieres que te imprima tu\n"
	.string "DIPLOMA.$"

GameFreak_Text_GraphicArtistError:
	.string "Algo va mal. Tendré que cancelar la\n"
	.string "impresión.$"

GameFreak_Text_Programmer:
	.string "¿Quién? ¿Yo? Soy el PROGRAMADOR.\p"
	.string "¡Juega a las tragaperras!$"

GameFreak_Text_CharacterDesigner:
	.string "¿A que las GEMELAS son adorables?\p"
	.string "Y YASMINA también es muy guapa.\p"
	.string "¡Me encantan!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "SALA DE DESARROLLO DE GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "Es un dibujo detallado de una chica\n"
	.string "guapa.$"

CeladonMansion3F_Text_GameProgram:
	.string "Es el programa del juego. ¡Si lo tocas,\n"
	.string "podrías meter un fallo en el juego!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "Está lleno de material de referencia:\n"
	.string "hasta un POKé MUÑECO.$"
