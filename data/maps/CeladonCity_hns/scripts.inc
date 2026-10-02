CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}.\n"
	.string "Isn't the fountain lovely today?\p"
	.string "If you wish for another battle,\n"
	.string "I'll be at the FIGHTING DOJO.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "Este POLIWRATH es mi compañero.\p"
	.string "Me pregunto si algún día evolucionará\n"
	.string "en una rana POKéMON.$"

CeladonCity_Text_Poliwrath:
	.string "POLIWRATH: ¡Polii!$"

CeladonCity_Text_Teacher1:
	.string "Volví a perder en las tragaperras.\p"
	.string "Las chicas también jugamos a las\n"
	.string "tragaperras. Prueba tú también.$"

CeladonCity_Text_Gramps1:
	.string "Últimamente han aparecido GRIMER.\p"
	.string "¿Ves esa charca que hay delante de la\n"
	.string "casa? Ahí viven GRIMER.\p"
	.string "¿De dónde han venido? Es un grave\n"
	.string "problema…$"

CeladonCity_Text_Gramps2:
	.string "¡Bravo! ¡Este GIMNASIO es genial! ¡Es\n"
	.string "sólo para chicas!$"

CeladonCity_Text_Youngster1:
	.string "¿Te cuento un secreto?\p"
	.string "La MANSIÓN AZULONA tiene una puerta\n"
	.string "trasera secreta.$"

CeladonCity_Text_Youngster2:
	.string "Hay un concurso de tragones en el\n"
	.string "restaurante.\p"
	.string "Sólo verlo hace que me sienta lleno…$"

CeladonCity_Text_Teacher2:
	.string "El C. COMERCIAL de CIUDAD AZULONA\p"
	.string "dispone de los mejores artículos.\p"
	.string "Si no encuentras algo aquí, no lo\n"
	.string "encontrarás en ningún otro sitio.\p"
	.string "¡Vaya…! Parezco una vendedora.$"

CeladonCity_Text_Lass:
	.string "Mirar al suelo mientras camino me\n"
	.string "marea.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CIUDAD AZULONA\p"
	.string "La ciudad de los sueños de arco iris$"

CeladonGym_Text_Sign:
	.string "LÍDER DEL GIMNASIO POKéMON DE\n"
	.string "CIUDAD AZULONA: ERIKA\p"
	.string "La princesa amante de la naturaleza$"

CeladonCity_Text_DeptStoreSign:
	.string "¡Encuentra lo que necesitas en el\p"
	.string "CENTRO COMERCIAL de CIUDAD AZULONA!$"

CeladonCity_Text_MansionSign:
	.string "MANSIÓN AZULONA$"

CeladonCity_Text_GameCornerSign:
	.string "The Playground for Everybody--\n"
	.string "CELADON GAME CORNER$"

CeladonCity_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "GUARD SPEC. protects POKéMON\n"
	.string "against SPECIAL attacks such as\l"
	.string "FLAMETHROWER and SURF.\p"
	.string "Get your items at CELADON DEPT.\n"
	.string "STORE!$"
