Melemele_PlayerHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_STATE, 1, Alola_Melemele_SamsonOakVillaIntro_Trigger
	.2byte 0


Alola_Melemele_SamsonOakVillaIntro_Trigger::
	lock
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3
	waitmovement 0
	setvar VAR_ALOLA_STATE, 2
	release
	end


Alola_Melemele_SamsonOakVilla_Dialogue::
	lock
	faceplayer
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_SamsonOakVilla_Dialogue_4
Alola_Melemele_SamsonOakVilla_Dialogue_2:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_16
Alola_Melemele_SamsonOakVilla_Dialogue_14:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_10
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_SamsonOakVilla_Dialogue_Text_11, Alola_Melemele_SamsonOakVilla_Dialogue_Text_12, Alola_Melemele_SamsonOakVilla_Dialogue_Text_13, Alola_Melemele_SamsonOakVilla_Dialogue_Text_14, Alola_Melemele_SamsonOakVilla_Dialogue_Text_15
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_31
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_32
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_33
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_53
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_34, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_1:
	compare VAR_ALOLA_STATE, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_10
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_3:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_SamsonOakVilla_Dialogue_7
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_4:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_SamsonOakVilla_Dialogue_3
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_7:
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_SamsonOakVilla_Dialogue_1
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_10:
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_0, MSGBOX_AUTOCLOSE
	giveitem ITEM_BEAST_BALL
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_1, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 4
	clearflag FLAG_HIDE_PHANT_OUTSIDE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_13:
	goto_if_set FLAG_DEFEATED_MELEMELE_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_25
Alola_Melemele_SamsonOakVilla_Dialogue_23:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_9, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_15:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_19
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_16:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_15
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_19:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_13
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_22:
	goto_if_set FLAG_DEFEATED_SAMSON_OAK, Alola_Melemele_SamsonOakVilla_Dialogue_40
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_55
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_8, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_24:
	goto_if_set FLAG_DEFEATED_ULAULA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_28
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_25:
	goto_if_set FLAG_DEFEATED_AKALA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_24
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_28:
	goto_if_set FLAG_DEFEATED_PONI_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_22
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_31:
	getcaughtmon SPECIES_MEOWTH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_44
Alola_Melemele_SamsonOakVilla_Dialogue_43:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_23, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_32:
	getcaughtmon SPECIES_MAROWAK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_47
Alola_Melemele_SamsonOakVilla_Dialogue_46:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_27, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_33:
	getcaughtmon SPECIES_VULPIX_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_50
Alola_Melemele_SamsonOakVilla_Dialogue_49:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_30, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_34:
	getcaughtmon SPECIES_RAICHU_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_68
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46
	end

Alola_Melemele_SamsonOakVilla_Dialogue_52:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_33, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_40:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_44:
	getcaughtmon SPECIES_PERSIAN_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_58
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_47:
	getcaughtmon SPECIES_DIGLETT_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_60
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_50:
	getcaughtmon SPECIES_NINETALES_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_62
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_53:
	getcaughtmon SPECIES_GEODUDE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_64
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_55:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_4
	trainerbattle_no_intro TRAINER_SAMSON_OAK_HNS, Alola_Melemele_SamsonOakVilla_Dialogue_Text_5
	special GivePartyMonMarineRibbon
	special HealPlayerParty
	setflag FLAG_DEFEATED_SAMSON_OAK
	setflag FLAG_FLYOVER_TAPU_KOKO
	setflag FLAG_FLYOVER_TAPU_LELE
	setflag FLAG_FLYOVER_TAPU_BULU
	setflag FLAG_FLYOVER_TAPU_FINI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_6, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_7, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 3
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_58:
	getcaughtmon SPECIES_RATTATA_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_66
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_60:
	getcaughtmon SPECIES_DUGTRIO_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_34
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_62:
	getcaughtmon SPECIES_SANDSHREW_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_70
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_64:
	getcaughtmon SPECIES_GRAVELER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_72
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_66:
	getcaughtmon SPECIES_RATICATE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_74
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_68:
	goto_if_unset FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_76
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_26, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_70:
	getcaughtmon SPECIES_SANDSLASH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_79
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_72:
	getcaughtmon SPECIES_GOLEM_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_81
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_74:
	goto_if_unset FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_83
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_22, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_76:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_86
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_79:
	getcaughtmon SPECIES_GRIMER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_93
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_81:
	getcaughtmon SPECIES_EXEGGUTOR_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_95
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_83:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_97
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_86:
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_107
Alola_Melemele_SamsonOakVilla_Dialogue_105:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_93:
	getcaughtmon SPECIES_MUK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_113
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_95:
	goto_if_unset FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_115
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_32, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_97:
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_121
Alola_Melemele_SamsonOakVilla_Dialogue_119:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_104:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_106:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_110
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_107:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_106
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_110:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_104
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_113:
	goto_if_unset FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_127
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_29, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_115:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_118:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_20, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_120:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_124
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_121:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_120
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_124:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_118
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_127:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_137
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_130:
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_147
Alola_Melemele_SamsonOakVilla_Dialogue_145:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_137:
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_156
Alola_Melemele_SamsonOakVilla_Dialogue_154:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_144:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_146:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_150
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_147:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_146
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_150:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_144
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_153:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_155:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_159
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_156:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_155
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_159:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_153
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154


Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0:
	emote_exclamation_mark
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1:
	walk_down
	walk_left
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3:
	walk_right
	walk_up
	face_right
	step_end

Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0:
	emote_exclamation_mark
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0:
	.string "¡Alola, {PLAYER}!$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1:
	.string "¡Me alegro de que estés aquí!\n"
	.string "¡Bienvenido a mi villa!\p"
	.string "Me alojo aquí mientras estudio el\n"
	.string "parecido de las ISLAS ALOLA con la\l"
	.string "región de ALOLA.\p"
	.string "Me interesa especialmente el\n"
	.string "fenómeno de las “formas regionales”.$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2:
	.string "Pareces muy capaz.\p"
	.string "¡Serías perfecto para ayudarme con mi\n"
	.string "estudio de las ISLAS ALOLA!\p"
	.string "Explora todo lo que las ISLAS pueden\n"
	.string "ofrecer y, si encuentras POKéMON que\l"
	.string "se parezcan a los de KANTO… ¡vuelve y\l"
	.string "enséñame tu POKéDEX!\p"
	.string "Te esperaré aquí con paciencia para\n"
	.string "que me cuentes tus progresos.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_0:
	.string "¡Uau! ¡Has visto a las deidades\n"
	.string "guardianas!\p"
	.string "Un trabajo increíble, {PLAYER}.\p"
	.string "Encontré esto mientras paseaba.\p"
	.string "No sé muy bien para qué sirve, pero\n"
	.string "deberías quedártelo.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_1:
	.string "¡Las ISLAS ALOLA deben de ser muy\n"
	.string "especiales si los mismísimos\l"
	.string "guardianes las han visitado!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_2:
	.string "¡Gracias por ayudarme con mi\n"
	.string "investigación, {PLAYER}!\p"
	.string "¡Gracias a ti, ahora sabemos mucho más\n"
	.string "de las ISLAS ALOLA!\p"
	.string "Espero que sigas explorando las ISLAS\n"
	.string "para descubrir todos los secretos que\l"
	.string "guardan.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_3:
	.string "¡Alola, {PLAYER}!\p"
	.string "Así que has vencido a todos los\n"
	.string "POKéMON dominantes de las ISLAS, ¿eh?\p"
	.string "¡Todo un logro!\p"
	.string "Ya ha pasado bastante tiempo…\p"
	.string "Creo que ya va siendo hora de que\n"
	.string "luchemos, ¿no crees?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_4:
	.string "¡Genial! ¡No pienso ponértelo fácil!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_5:
	.string "¡Increíble, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_6:
	.string "¡Uau, {PLAYER}! ¡Eres un ENTRENADOR\n"
	.string "muy poderoso!\p"
	.string "Has demostrado ser digno de un\n"
	.string "secreto que guardo sobre estas\l"
	.string "ISLAS…\p"
	.string "No soy el único que se ha dado cuenta\n"
	.string "del enorme parecido entre las ISLAS\l"
	.string "ALOLA y la región de ALOLA…\p"
	.string "Parece que los mismísimos Tapus\n"
	.string "guardianes han estado visitando las\l"
	.string "ISLAS.\p"
	.string "Si los ves volar sobre las ISLAS, ve a\n"
	.string "los tótems… ¡Puede que te estén\l"
	.string "esperando allí!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_7:
	.string "¿A qué esperas, {PLAYER}? ¡Sal ahí\n"
	.string "fuera y explora!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_8:
	.string "¡No te preocupes, {PLAYER}!\p"
	.string "Tómate tu tiempo para prepararte para\n"
	.string "el combate y vuelve cuando estés\l"
	.string "listo.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_9:
	.string "¡Alola, {PLAYER}!\p"
	.string "Así que has encontrado todas las\n"
	.string "formas de ALOLA de las ISLAS, pero\l"
	.string "¿has vencido ya a todos los POKéMON\l"
	.string "dominantes?\p"
	.string "Busca un pilar extraño en cada isla.\n"
	.string "¡Los POKéMON dominantes lo estarán\l"
	.string "protegiendo!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_10:
	.string "¡Hola otra vez, {PLAYER}!\p"
	.string "¿Qué tal va tu investigación de las\n"
	.string "ISLAS ALOLA?\p"
	.string "¿Quieres contarme tus progresos en\n"
	.string "alguna isla en concreto?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_11:
	.string "ISLA MELEMELE$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_12:
	.string "ISLA AKALA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_13:
	.string "ISLA ULA-ULA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_14:
	.string "ISLA PONI$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_15:
	.string "Ahora no.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_16:
	.string "Déjame ver tu POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_17:
	.string "¡Uau, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_18:
	.string "¡Has encontrado todas las formas de\n"
	.string "ALOLA que viven en la ISLA MELEMELE!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_19:
	.string "¡Y parece que también has encontrado\n"
	.string "todas las formas de ALOLA de las\l"
	.string "otras ISLAS!\p"
	.string "¡Es increíble, {PLAYER}!\p"
	.string "¡Deberías estar muy orgulloso!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_20:
	.string "¡Me has ayudado a confirmar que todas\n"
	.string "las formas de ALOLA están presentes\l"
	.string "en las ISLAS ALOLA!\p"
	.string "Me gustaría que me ayudaras con una\n"
	.string "cosa más…\p"
	.string "¿Podrías ayudarme a investigar a los\n"
	.string "POKéMON dominantes que, según dicen,\l"
	.string "protegen los tótems de cada ISLA?\p"
	.string "¡Pero cuidado! Dicen que estos\n"
	.string "POKéMON dominantes son mucho más\l"
	.string "fuertes que los normales…\p"
	.string "¡Nunca se sabe quién puede estar\n"
	.string "observando para ver si eres un rival\l"
	.string "digno!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_21:
	.string "¡Sigue explorando las otras ISLAS y\n"
	.string "cuéntame tus progresos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_22:
	.string "¡Parece que ya has encontrado todas\n"
	.string "las formas de ALOLA de la ISLA\l"
	.string "MELEMELE!\p"
	.string "¡Buen trabajo!\p"
	.string "¡Sigue explorando las otras ISLAS y\n"
	.string "cuéntame tus progresos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_23:
	.string "Déjame ver tu POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Parece que aún no has encontrado\n"
	.string "todas las formas de ALOLA de la ISLA\l"
	.string "MELEMELE.\p"
	.string "He oído que en la ISLA MELEMELE hay {COLOR RED}4\n"
	.string "{COLOR DARK_GRAY}formas de ALOLA por encontrar…\p"
	.string "{COLOR RED}RATTATA{COLOR DARK_GRAY}, {COLOR RED}RATICATE{COLOR DARK_GRAY}, {COLOR RED}MEOWTH{COLOR DARK_GRAY} y {COLOR RED}PERSIAN{COLOR DARK_GRAY}.\p"
	.string "¡Sigue buscando y vuelve cuando los\n"
	.string "hayas atrapado a todos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_24:
	.string "¡Has encontrado todas las formas de\n"
	.string "ALOLA que viven en la ISLA AKALA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_25:
	.string "Ahora que me has ayudado a confirmar\n"
	.string "que todas las formas de ALOLA están\l"
	.string "presentes en las ISLAS ALOLA…\p"
	.string "Me gustaría que me ayudaras con una\n"
	.string "cosa más…\p"
	.string "¿Podrías ayudarme a investigar a los\n"
	.string "POKéMON dominantes que, según dicen,\l"
	.string "protegen los tótems de cada isla?\p"
	.string "¡Pero cuidado! Dicen que estos\n"
	.string "POKéMON dominantes son mucho más\l"
	.string "fuertes que los normales…\p"
	.string "¡Nunca se sabe quién puede estar\n"
	.string "observando para ver si eres un rival\l"
	.string "digno!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_26:
	.string "¡Parece que ya has encontrado todas\n"
	.string "las formas de ALOLA de la ISLA AKALA!\p"
	.string "¡Buen trabajo!\p"
	.string "¡Sigue explorando las otras ISLAS y\n"
	.string "cuéntame tus progresos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_27:
	.string "Déjame ver tu POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Parece que aún no has encontrado\n"
	.string "todas las formas de ALOLA de la ISLA\l"
	.string "AKALA.\p"
	.string "He oído que en la ISLA AKALA hay {COLOR RED}4\n"
	.string "{COLOR DARK_GRAY}formas de ALOLA por encontrar…\p"
	.string "{COLOR RED}RAICHU{COLOR DARK_GRAY}, {COLOR RED}MAROWAK{COLOR DARK_GRAY}, {COLOR RED}DIGLETT{COLOR DARK_GRAY} y {COLOR RED}DUGTRIO{COLOR DARK_GRAY}.\p"
	.string "¡Sigue buscando y vuelve cuando los\n"
	.string "hayas atrapado a todos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_28:
	.string "¡Has encontrado todas las formas de\n"
	.string "ALOLA que viven en la ISLA ULA-ULA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_29:
	.string "¡Parece que ya has encontrado todas\n"
	.string "las formas de ALOLA de la ISLA\l"
	.string "ULA-ULA!\p"
	.string "¡Buen trabajo!\p"
	.string "¡Sigue explorando las otras ISLAS y\n"
	.string "cuéntame tus progresos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_30:
	.string "Déjame ver tu POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Parece que aún no has encontrado\n"
	.string "todas las formas de ALOLA de la ISLA\l"
	.string "ULA-ULA.\p"
	.string "He oído que en la ISLA ULA-ULA hay {COLOR RED}6\n"
	.string "{COLOR DARK_GRAY}formas de ALOLA por encontrar…\p"
	.string "{COLOR RED}VULPIX{COLOR DARK_GRAY}, {COLOR RED}NINETALES{COLOR DARK_GRAY}, {COLOR RED}SANDSHREW{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}SANDSLASH{COLOR DARK_GRAY}, {COLOR RED}GRIMER{COLOR DARK_GRAY} y {COLOR RED}MUK{COLOR DARK_GRAY}.\p"
	.string "¡Sigue buscando y vuelve cuando los\n"
	.string "hayas atrapado a todos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_31:
	.string "¡Has encontrado todas las formas de\n"
	.string "ALOLA que viven en la ISLA PONI!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_32:
	.string "¡Parece que ya has encontrado todas\n"
	.string "las formas de ALOLA de la ISLA PONI!\p"
	.string "¡Buen trabajo!\p"
	.string "¡Sigue explorando las otras ISLAS y\n"
	.string "cuéntame tus progresos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_33:
	.string "Déjame ver tu POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Parece que aún no has encontrado\n"
	.string "todas las formas de ALOLA de la ISLA\l"
	.string "PONI.\p"
	.string "He oído que en la ISLA PONI hay {COLOR RED}4\n"
	.string "{COLOR DARK_GRAY}formas de ALOLA por encontrar…\p"
	.string "{COLOR RED}GEODUDE{COLOR DARK_GRAY}, {COLOR RED}GRAVELER{COLOR DARK_GRAY}, {COLOR RED}GOLEM{COLOR DARK_GRAY} y\n"
	.string "{COLOR RED}EXEGGUTOR{COLOR DARK_GRAY}.\p"
	.string "¡Sigue buscando y vuelve cuando los\n"
	.string "hayas atrapado a todos!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_34:
	.string "¡No te preocupes, {PLAYER}!\p"
	.string "Vuelve cuando quieras contarme lo que\n"
	.string "hayas descubierto sobre las ISLAS\l"
	.string "ALOLA.$"
