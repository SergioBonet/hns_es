// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("Información: ventanas de ayuda"),
        .desc = COMPOUND_STRING("Esto es una ventana de ayuda. ¡Puedes\nponer mucho texto en la pantalla que\nlos jugadores no van a leer!\n\n¿A que es genial?"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("Información: más opciones"),
        .desc = COMPOUND_STRING("El reloj se puede cambiar en cualquier\nCENTRO POKéMON sin penalización.\nMira los OBJ. CLAVE de tu MOCHILA\ny el menú de OPCIONES para tener\naún más formas de personalizar el juego.\n¡Que lo disfrutes!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("AVISO: COMPATIBILIDAD"),
        .desc = COMPOUND_STRING("Conectarse mal puede dañar para\nsiempre tu partida guardada.\nConéctate con otra persona solo si:\nLas dos jugáis a Heart & Soul.\nLas dos tenéis la misma versión.\nTenéis los mismos ajustes de desafío.\nNO usáis ningún ajuste aleatorio."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("EXTRA OPCIONAL: TELETRANSPORTADOR"),
        .desc = COMPOUND_STRING("El TELETRANSPORTADOR puede cambiar\nPARA SIEMPRE a los POKéMON a sus\nformas de GALAR. Las formas de GALAR\nNO hacen falta para la historia\nni para completar la POKéDEX NACIONAL.\n"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("EXTRA OPCIONAL: SINJOH"),
        .desc = COMPOUND_STRING("Este personaje da acceso a contenido\nextra opcional: SINJOH.\nNO hace falta para la historia\nni para completar la POKéDEX NACIONAL.\n\nEs solo un extra, por si te apetece."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("EXTRA OPCIONAL: ISLAS"),
        .desc = COMPOUND_STRING("Este personaje da acceso a contenido\nextra opcional: ISLAS.\nNO hace falta para la historia\nni para completar la POKéDEX NACIONAL.\n\nEs solo un extra, por si te apetece."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("HABILIDADES DE LOS POKéMON BEBÉ"),
        .desc = COMPOUND_STRING("PICHU tiene ELEC. ESTÁT.\nCLEFFA tiene GRAN ENCANTO.\nIGGLYBUFF tiene GRAN ENCANTO.\nTYROGUE tiene AGALLAS.\nSMOOCHUM tiene DESPISTE.\nELEKID tiene ELEC. ESTÁT.\nMAGBY tiene CUERPO LLAMA."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("TIPOS DE LOS POKéMON BEBÉ"),
        .desc = COMPOUND_STRING("PICHU es de tipo ELÉCTRICO.\nCLEFFA es de tipo NORMAL.\nIGGLYBUFF es de tipo NORMAL.\nTYROGUE es CRUEL (tipo LUCHA).\nSMOOCHUM es de tipo HIELO.\nELEKID es de tipo ELÉCTRICO.\nMAGBY es de tipo FUEGO."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("GRITOS DE LOS POKéMON BEBÉ"),
        .desc = COMPOUND_STRING("PICHU dice: ¡VAYA!\nCLEFFA dice: ¡LUCHEMOS!\nIGGLYBUFF dice: ¡LA!\nTYROGUE dice: ¡LA, LA!\nSMOOCHUM dice: ¡EH, JE, JE!\nELEKID dice: ¡AY, AY, AY!\nMAGBY dice: ¡TOMA YA!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("COSTUMBRES DE LOS POKéMON BEBÉ"),
        .desc = COMPOUND_STRING("PICHU siempre está ENTRETENIDO.\nCLEFFA QUIERE a la luna.\nCon IGGLYBUFF, ¡yo me DUERMO!\nTYROGUE ENTRENA sin parar.\nSMOOCHUM sabe CONGELAR.\nELEKID sabe GUARDAR energía.\nMAGBY se ENFADA a menudo."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("COMEDEROS: {POKEBLOCK}S NORMALES"),
        .desc = COMPOUND_STRING("Cada color atrae VI perfectos:\nROJ: PS,ATQ,VEL    AZU: PS,AT.E,VEL\nROS: ATQ,AT.E,VEL  VER: PS,DEF,DF.E\nAMA: PS,ATQ,DEF    MOR: ATQ,DEF,DF.E\nAÑI: PS,AT.E,DF.E  MAR: DEF,VEL,DF.E\nCEL: AT.E,VEL,DF.E  OLI: ATQ,DEF,VEL\nGRI: PS,ATQ,AT.E\nTodos atraen la HABILIDAD OCULTA."

                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("COMEDEROS: {POKEBLOCK}S DORADOS"),
        .desc = COMPOUND_STRING("Los {POKEBLOCK}S DORADOS atraen POKéMON con\n5 VI perfectos. El sabor decide\ncuál no es perfecto.\nPICANTE: sin AT.E   SECO: sin ATQ\nDULCE: sin DF.E     AMARGO: sin VEL\nÁCIDO: sin PS\nTodos atraen la HABILIDAD OCULTA."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
