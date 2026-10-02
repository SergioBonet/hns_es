const struct EasyChatWordInfo gEasyChatGroup_Greetings[] = {
    [EC_INDEX(EC_WORD_THANKS)] =
    {
        .text = COMPOUND_STRING("GRACIAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APOLOGIZE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES)] =
    {
        .text = COMPOUND_STRING("¿QUÉ TAL?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPRECIATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_GOES)] =
    {
        .text = COMPOUND_STRING("¡AHÍ VA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BYE_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_I_COME)] =
    {
        .text = COMPOUND_STRING("ALLÁ VOY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_OVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_IT_IS)] =
    {
        .text = COMPOUND_STRING("¡NOS VEMOS!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONGRATS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH)] =
    {
        .text = COMPOUND_STRING("¡HASTA OTRA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUNT_ON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELCOME)] =
    {
        .text = COMPOUND_STRING("¡BIENVENIDO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI)] =
    {
        .text = COMPOUND_STRING("¡BIENVENIDA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW_DO)] =
    {
        .text = COMPOUND_STRING("DE NADA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONGRATS)] =
    {
        .text = COMPOUND_STRING("ENHORABUENA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_ME)] =
    {
        .text = COMPOUND_STRING("¡BIEN HECHO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_AHEAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SORRY)] =
    {
        .text = COMPOUND_STRING("¡LO SIENTO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APOLOGIZE)] =
    {
        .text = COMPOUND_STRING("¡DISCULPA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HELLO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGIVE)] =
    {
        .text = COMPOUND_STRING("¡PERDONA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_GOES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_THERE)] =
    {
        .text = COMPOUND_STRING("¡OYE!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_I_COME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HELLO)] =
    {
        .text = COMPOUND_STRING("¡HOLA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_IT_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD_BYE)] =
    {
        .text = COMPOUND_STRING("¡ADIÓS!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THANK_YOU)] =
    {
        .text = COMPOUND_STRING("MIL GRACIAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_THERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE_ARRIVED)] =
    {
        .text = COMPOUND_STRING("¡AQUÍ ESTOY!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARDON)] =
    {
        .text = COMPOUND_STRING("¡PERDÓN!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE)] =
    {
        .text = COMPOUND_STRING("¡QUÉ PENA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOO_HAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE_YA)] =
    {
        .text = COMPOUND_STRING("¡QUÉ BIEN!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW_DO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE_ME)] =
    {
        .text = COMPOUND_STRING("¡QUÉ GUAY!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL_THEN)] =
    {
        .text = COMPOUND_STRING("¡AHORA QUÉ!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE_ARRIVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_AHEAD)] =
    {
        .text = COMPOUND_STRING("TÚ MISMO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPRECIATE)] =
    {
        .text = COMPOUND_STRING("¡ME GUSTAS!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_QUES)] =
    {
        .text = COMPOUND_STRING("¡TÚ MISMA!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT_S_UP_QUES)] =
    {
        .text = COMPOUND_STRING("¿QUÉ PASA?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUH_QUES)] =
    {
        .text = COMPOUND_STRING("¿QUÉ?"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARDON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO)] =
    {
        .text = COMPOUND_STRING("¡VETE!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE_YA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HI)] =
    {
        .text = COMPOUND_STRING("¡TE DEJO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH_YEAH)] =
    {
        .text = COMPOUND_STRING("¡ME LARGO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SORRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BYE_BYE)] =
    {
        .text = COMPOUND_STRING("¡ME VOY!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANK_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEET_YOU)] =
    {
        .text = COMPOUND_STRING("HASTA NUNCA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY)] =
    {
        .text = COMPOUND_STRING("¡OLVÍDAME!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELCOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL)] =
    {
        .text = COMPOUND_STRING("¡OLVÍDATE!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL_THEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENING)] =
    {
        .text = COMPOUND_STRING("¡PASA DE MÍ!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT_S_UP_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOO_HAH)] =
    {
        .text = COMPOUND_STRING("¡PASO DE TI!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAHOO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAHOO)] =
    {
        .text = COMPOUND_STRING("¡ME PIRO!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YO)] =
    {
        .text = COMPOUND_STRING("¡PÍRATE!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_OVER)] =
    {
        .text = COMPOUND_STRING("¡LÁRGATE!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUNT_ON)] =
    {
        .text = COMPOUND_STRING("¡DÉJAME!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YO),
        .enabled = TRUE,
    },
};
