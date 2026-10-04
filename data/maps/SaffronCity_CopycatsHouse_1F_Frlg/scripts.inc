SaffronCity_CopycatsHouse_1F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
	.string "¡Mi hija está tan metida en sí\n"
	.string "misma que tiene muy pocos amigos!$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
	.string "A mi hija le gusta imitar a la\n"
	.string "gente.\p"
	.string "¡Y por eso la gente de por aquí\n"
	.string "le llama la COPIONA!$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
	.string "CHANSEY: ¡Chaan! ¡Chaan!$"

