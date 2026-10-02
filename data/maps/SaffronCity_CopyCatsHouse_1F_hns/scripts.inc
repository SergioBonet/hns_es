SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "A mi hija le gusta imitar a la gente.\p"
	.string "Y por eso la llaman COPIONA.$"

CopycatsHouse1F_Text_PokefanF:
	.string "Mi hija es muy introvertida…\p"
	.string "Tiene muy pocos amigos.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "Acaba de perder el POKé MUÑECO que le\n"
	.string "regaló un niño hace tres años.\p"
	.string "Desde entonces, imita a la gente\n"
	.string "mucho mejor…$"

CopycatsHouse1F_Text_Blissey:
	.string "BLISSEY: ¡Bliisii!$"
