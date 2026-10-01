const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Ninguna en particular."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("HEDOR"),
        .description = COMPOUND_STRING("Puede hacer retroceder."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("LLOVIZNA"),
        .description = COMPOUND_STRING("Hace que llueva en combate."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("IMPULSO"),
        .description = COMPOUND_STRING("Va subiendo la Velocidad."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("ARMADURA BATALLA"),
        .description = COMPOUND_STRING("Bloquea golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("ROBUSTEZ"),
        .description = COMPOUND_STRING("Anula golpes fulminantes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("HUMEDAD"),
        .description = COMPOUND_STRING("Evita la autodestrucción."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("FLEXIBILIDAD"),
        .description = COMPOUND_STRING("Evita la parálisis."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("VELO ARENA"),
        .description = COMPOUND_STRING("Más Evasión en torm. arena."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("ELEC. ESTÁTICA"),
        .description = COMPOUND_STRING("Paraliza al mín. contacto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("ABSORBE ELEC"),
        .description = COMPOUND_STRING("Cambia electricidad en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("ABSORBE AGUA"),
        .description = COMPOUND_STRING("Convierte el agua en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("DESPISTE"),
        .description = COMPOUND_STRING("Evita la atracción."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("ACLIMATACIÓN"),
        .description = COMPOUND_STRING("Anula los efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("OJO COMPUESTO"),
        .description = COMPOUND_STRING("Aumenta la Precisión."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("INSOMNIO"),
        .description = COMPOUND_STRING("Evita el quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("CAMBIO COLOR"),
        .description = COMPOUND_STRING("Toma el tipo del mov. rival."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("INMUNIDAD"),
        .description = COMPOUND_STRING("Evita el envenenamiento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("ABSORBE FUEGO"),
        .description = COMPOUND_STRING("Se carga si recibe fuego."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("POLVO ESCUDO"),
        .description = COMPOUND_STRING("Evita efectos secundarios."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("RITMO PROPIO"),
        .description = COMPOUND_STRING("Evita la confusión."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("VENTOSAS"),
        .description = COMPOUND_STRING("Fija el cuerpo con firmeza."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("INTIMIDACIÓN"),
        .description = COMPOUND_STRING("Baja el Ataque del rival."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("SOMBRA TRAMPA"),
        .description = COMPOUND_STRING("Evita que el enemigo huya."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("PIEL TOSCA"),
        .description = COMPOUND_STRING("Hiere al tacto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("SUPERGUARDA"),
        .description = COMPOUND_STRING("Solo teme lo “muy eficaz”."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("LEVITACIÓN"),
        .description = COMPOUND_STRING("No sufre at. tipo Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("EFECTO ESPORA"),
        .description = COMPOUND_STRING("Deja esporas al contacto."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("SINCRONÍA"),
        .description = COMPOUND_STRING("Transmite problem. estado."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("CUERPO PURO"),
        .description = COMPOUND_STRING("Evita que baje la habilidad."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("CURA NATURAL"),
        .description = COMPOUND_STRING("Se cura al salir."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("PARARRAYOS"),
        .description = COMPOUND_STRING("Frena ataques eléctricos."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("DICHA"),
        .description = COMPOUND_STRING("Añade efectos secundarios."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("NADO RÁPIDO"),
        .description = COMPOUND_STRING("Con lluvia, sube Velocidad."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("CLOROFILA"),
        .description = COMPOUND_STRING("Con sol, sube la Velocidad."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("ILUMINACIÓN"),
        .description = COMPOUND_STRING("Facilita el encuentro."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("CALCO"),
        .description = COMPOUND_STRING("Copia habilidad especial."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("POTENCIA"),
        .description = COMPOUND_STRING("Aumenta el Ataque."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("PUNTO TÓXICO"),
        .description = COMPOUND_STRING("Envenena al mín. contacto."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("FUERZA MENTAL"),
        .description = COMPOUND_STRING("Evita el retroceso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("ESCUDO MAGMA"),
        .description = COMPOUND_STRING("Evita el congelamiento."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("VELO AGUA"),
        .description = COMPOUND_STRING("Evita las quemaduras."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("IMÁN"),
        .description = COMPOUND_STRING("Atrapa Pokémon de Acero."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("INSONORIZAR"),
        .description = COMPOUND_STRING("Evita ataques de sonido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("CURA LLUVIA"),
        .description = COMPOUND_STRING("Sube PS cuando llueve."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("CHORRO ARENA"),
        .description = COMPOUND_STRING("Crea una tormenta de arena."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("PRESIÓN"),
        .description = COMPOUND_STRING("Baja los PP del enemigo."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("SEBO"),
        .description = COMPOUND_STRING("Protege del frío y calor."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("MADRUGAR"),
        .description = COMPOUND_STRING("Despierta rápido al Pkmn."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("CUERPO LLAMA"),
        .description = COMPOUND_STRING("Quema al mínimo contacto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("FUGA"),
        .description = COMPOUND_STRING("Facilita la huida."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("VISTA LINCE"),
        .description = COMPOUND_STRING("Evita que baje Precisión."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("CORTE FUERTE"),
        .description = COMPOUND_STRING("Evita que baje el Ataque."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("RECOGIDA"),
        .description = COMPOUND_STRING("Puede tomar objetos."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("PEREZA"),
        .description = COMPOUND_STRING("Interviene cada 2 rondas."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("ENTUSIASMO"),
        .description = COMPOUND_STRING("Cambia Precis. por energía."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("GRAN ENCANTO"),
        .description = COMPOUND_STRING("Emboba al mínimo contacto."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("MÁS"),
        .description = COMPOUND_STRING("Mejora con habilidad Menos."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("MENOS"),
        .description = COMPOUND_STRING("Mejora con habilidad Más."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("PREDICCIÓN"),
        .description = COMPOUND_STRING("Cambia con el clima."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("VISCOSIDAD"),
        .description = COMPOUND_STRING("Evita el robo de objetos."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("MUDAR"),
        .description = COMPOUND_STRING("Se cura mudando la piel."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("AGALLAS"),
        .description = COMPOUND_STRING("Sube el Ataque si sufre."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("ESCAMA ESPECIAL"),
        .description = COMPOUND_STRING("Sube la Defensa si sufre."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("VISCOSECRECIÓN"),
        .description = COMPOUND_STRING("Al verterlo, hiere."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("ESPESURA"),
        .description = COMPOUND_STRING("Sube ataques tipo Planta."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("MAR LLAMAS"),
        .description = COMPOUND_STRING("Sube ataques tipo Fuego."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("TORRENTE"),
        .description = COMPOUND_STRING("Sube ataques tipo Agua."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("ENJAMBRE"),
        .description = COMPOUND_STRING("Sube ataques tipo Bicho."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("CABEZA ROCA"),
        .description = COMPOUND_STRING("Evita el daño de retroceso."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("SEQUÍA"),
        .description = COMPOUND_STRING("Toma luz solar en batalla."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("TRAMPA ARENA"),
        .description = COMPOUND_STRING("Evita la huida."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("ESPÍRITU VITAL"),
        .description = COMPOUND_STRING("Evita el quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("HUMO BLANCO"),
        .description = COMPOUND_STRING("Evita que baje la habilidad."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("ENERGÍA PURA"),
        .description = COMPOUND_STRING("Aumenta el Ataque."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("CAPARAZÓN"),
        .description = COMPOUND_STRING("Bloquea golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("ESCLUSA DE AIRE"),
        .description = COMPOUND_STRING("Anula los efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("TUMBOS"),
        .description = COMPOUND_STRING("Más Evasión si confuso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("ELECTROMOTOR"),
        .description = COMPOUND_STRING("La electricidad lo acelera."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("RIVALIDAD"),
        .description = COMPOUND_STRING("Más fuerza ante rivales."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("IMPASIBLE"),
        .description = COMPOUND_STRING("Retroceder sube Velocidad."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("MANTO NÍVEO"),
        .description = COMPOUND_STRING("Más Evasión con nieve."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("GULA"),
        .description = COMPOUND_STRING("Come Bayas antes."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("IRASCIBLE"),
        .description = COMPOUND_STRING("Un crítico sube su Ataque."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("LIVIANO"),
        .description = COMPOUND_STRING("Sin objeto, más Velocidad."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("IGNÍFUGO"),
        .description = COMPOUND_STRING("Resiste el fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("SIMPLE"),
        .description = COMPOUND_STRING("Dobla cambios de caract."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("PIEL SECA"),
        .description = COMPOUND_STRING("Prefiere humedad al calor."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("DESCARGA"),
        .description = COMPOUND_STRING("Ajusta su poder al rival."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("PUÑO FÉRREO"),
        .description = COMPOUND_STRING("Potencia los puñetazos."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("ANTÍDOTO"),
        .description = COMPOUND_STRING("Recupera PS si se envenena."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("ADAPTABLE"),
        .description = COMPOUND_STRING("Potencia su propio tipo."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("ENCADENADO"),
        .description = COMPOUND_STRING("Golpes múltiples: 5 veces."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("HIDRATACIÓN"),
        .description = COMPOUND_STRING("Cura estados si llueve."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("PODER SOLAR"),
        .description = COMPOUND_STRING("Más fuerte con sol."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("PIES RÁPIDOS"),
        .description = COMPOUND_STRING("Más Velocidad si sufre."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("NORMALIDAD"),
        .description = COMPOUND_STRING("Ataques de tipo Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("FRANCOTIRADOR"),
        .description = COMPOUND_STRING("Potencia los críticos."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("MURO MÁGICO"),
        .description = COMPOUND_STRING("Solo le dañan los ataques."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("INDEFENSO"),
        .description = COMPOUND_STRING("Todo ataque acierta."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("REZAGADO"),
        .description = COMPOUND_STRING("Siempre ataca el último."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("EXPERTO"),
        .description = COMPOUND_STRING("Potencia ataques débiles."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("DEFENSA HOJA"),
        .description = COMPOUND_STRING("Evita estados con sol."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("ZOQUETE"),
        .description = COMPOUND_STRING("No puede usar objetos."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("ROMPEMOLDES"),
        .description = COMPOUND_STRING("Ignora habilidades."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("AFORTUNADO"),
        .description = COMPOUND_STRING("Más golpes críticos."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("DETONACIÓN"),
        .description = COMPOUND_STRING("Debilitado, daña al rival."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("ANTICIPACIÓN"),
        .description = COMPOUND_STRING("Intuye ataques peligrosos."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("ALERTA"),
        .description = COMPOUND_STRING("Averigua un ataque rival."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("IGNORANTE"),
        .description = COMPOUND_STRING("Ignora cambios de caract."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("CROMOLENTE"),
        .description = COMPOUND_STRING("Potencia lo “poco eficaz”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("FILTRO"),
        .description = COMPOUND_STRING("Reduce lo “muy eficaz”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("INICIO LENTO"),
        .description = COMPOUND_STRING("Tarda en arrancar."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("INTRÉPIDO"),
        .description = COMPOUND_STRING("Golpea a tipo Fantasma."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("COLECTOR"),
        .description = COMPOUND_STRING("Atrae ataques de tipo Agua."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("GÉLIDO"),
        .description = COMPOUND_STRING("Cura PS en granizo o nieve."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("ROCA SÓLIDA"),
        .description = COMPOUND_STRING("Reduce lo “muy eficaz”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("NEVADA"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Hace nevar en combate."),
    #else
        .description = COMPOUND_STRING("Summons hail in battle."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("RECOGEMIEL"),
        .description = COMPOUND_STRING("Puede recoger Miel."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("CACHEO"),
        .description = COMPOUND_STRING("Mira el objeto del rival."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("AUDAZ"),
        .description = COMPOUND_STRING("Potencia golpes de riesgo."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("MULTITIPO"),
        .description = COMPOUND_STRING("Cambia de tipo según tabla."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("DON FLORAL"),
        .description = COMPOUND_STRING("Con sol, potencia al equipo."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("MAL SUEÑO"),
        .description = COMPOUND_STRING("Daña a Pokémon dormidos."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("HURTO"),
        .description = COMPOUND_STRING("Roba el objeto del rival."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("POTENCIA BRUTA"),
        .description = COMPOUND_STRING("Sin efectos, más potencia."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("RESPONDÓN"),
        .description = COMPOUND_STRING("Invierte cambios de caract."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("NERVIOSISMO"),
        .description = COMPOUND_STRING("El rival no come Bayas."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("COMPETITIVO"),
        .description = COMPOUND_STRING("Bajadas suben su Ataque."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("FLAQUEZA"),
        .description = COMPOUND_STRING("Se rinde a mitad de PS."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("CUERPO MALDITO"),
        .description = COMPOUND_STRING("Anula ataques al tocarle."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("ALMA CURA"),
        .description = COMPOUND_STRING("Cura al Pokémon aliado."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("COMPIESCOLTA"),
        .description = COMPOUND_STRING("Reduce el daño al aliado."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("ARMADURA FRÁGIL"),
        .description = COMPOUND_STRING("Golpes cambian sus caract."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("METAL PESADO"),
        .description = COMPOUND_STRING("Duplica su peso."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("METAL LIVIANO"),
        .description = COMPOUND_STRING("Reduce su peso a la mitad."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("MULTIESCAMAS"),
        .description = COMPOUND_STRING("Mitad de daño con PS llenos."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("ÍMPETU TÓXICO"),
        .description = COMPOUND_STRING("Sube Ataque si envenenado."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("ÍMPETU ARDIENTE"),
        .description = COMPOUND_STRING("Sube At. Esp. si quemado."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("COSECHA"),
        .description = COMPOUND_STRING("Puede reciclar una Baya."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("TELEPATÍA"),
        .description = COMPOUND_STRING("Inmune a ataques aliados."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("VELETA"),
        .description = COMPOUND_STRING("Caract. cambian al azar."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("FUNDA"),
        .description = COMPOUND_STRING("Bloquea clima y polvos."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("TOQUE TÓXICO"),
        .description = COMPOUND_STRING("Envenena al mín. contacto."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("REGENERACIÓN"),
        .description = COMPOUND_STRING("Se cura al salir."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("SACAPECHO"),
        .description = COMPOUND_STRING("Evita bajadas de Defensa."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("ÍMPETU ARENA"),
        .description = COMPOUND_STRING("Más Velocidad con arena."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("PIEL MILAGRO"),
        .description = COMPOUND_STRING("Puede evitar estados."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("CÁLCULO FINAL"),
        .description = COMPOUND_STRING("Atacar último da potencia."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("ILUSIÓN"),
        .description = COMPOUND_STRING("Se disfraza de un aliado."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("IMPOSTOR"),
        .description = COMPOUND_STRING("Se transforma en el rival."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("ALLANAMIENTO"),
        .description = COMPOUND_STRING("Atraviesa barreras."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("MOMIA"),
        .description = COMPOUND_STRING("Se contagia por contacto."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("AUTOESTIMA"),
        .description = COMPOUND_STRING("Derrotar sube su Ataque."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("JUSTICIERO"),
        .description = COMPOUND_STRING("Siniestro sube su Ataque."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("COBARDÍA"),
        .description = COMPOUND_STRING("Se asusta y sube Velocidad."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("ESPEJO MÁGICO"),
        .description = COMPOUND_STRING("Refleja ataques de estado."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("HERBÍVORO"),
        .description = COMPOUND_STRING("Lo Planta sube su Ataque."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("BROMISTA"),
        .description = COMPOUND_STRING("Ataques de estado primero."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("PODER ARENA"),
        .description = COMPOUND_STRING("Más fuerza con arena."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("PUNTA ACERO"),
        .description = COMPOUND_STRING("Hiere al tacto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("MODO DARUMA"),
        .description = COMPOUND_STRING("Cambia a mitad de PS."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("TINOVICTORIA"),
        .description = COMPOUND_STRING("Más Precisión al equipo."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("TURBOLLAMA"),
        .description = COMPOUND_STRING("Ignora habilidades."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("TERRAVOLTAJE"),
        .description = COMPOUND_STRING("Ignora habilidades."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("VELO AROMA"),
        .description = COMPOUND_STRING("Evita que limiten ataques."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("VELO FLOR"),
        .description = COMPOUND_STRING("Protege a los tipo Planta."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("CARRILLO"),
        .description = COMPOUND_STRING("Comer Bayas recupera PS."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("MUTATIPO"),
        .description = COMPOUND_STRING("Toma el tipo del ataque."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("PELAJE RECIO"),
        .description = COMPOUND_STRING("Sube la Defensa."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("PRESTIDIGITADOR"),
        .description = COMPOUND_STRING("Roba el objeto del rival."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("ANTIBALAS"),
        .description = COMPOUND_STRING("Evita algunos proyectiles."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("TENACIDAD"),
        .description = COMPOUND_STRING("Bajadas suben su At. Esp."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("MANDÍBULA FUERTE"),
        .description = COMPOUND_STRING("Potencia los mordiscos."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("PIEL HELADA"),
        .description = COMPOUND_STRING("Lo Normal pasa a ser Hielo."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("VELO DULCE"),
        .description = COMPOUND_STRING("Evita que el equipo duerma."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("CAMBIO TÁCTICO"),
        .description = COMPOUND_STRING("Cambia de forma al luchar."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("ALAS VENDAVAL"),
        .description = COMPOUND_STRING("Ataques Volador primero."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("MEGADISPARADOR"),
        .description = COMPOUND_STRING("Potencia los pulsos."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("MANTO FRONDOSO"),
        .description = COMPOUND_STRING("Más Defensa con hierba."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("SIMBIOSIS"),
        .description = COMPOUND_STRING("Pasa su objeto a un aliado."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("GARRA DURA"),
        .description = COMPOUND_STRING("Potencia golpes directos."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("PIEL FEÉRICA"),
        .description = COMPOUND_STRING("Lo Normal pasa a ser Hada."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("BABA"),
        .description = COMPOUND_STRING("Contacto baja Velocidad."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("PIEL CELESTE"),
        .description = COMPOUND_STRING("Lo Normal pasa a Volador."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("AMOR FILIAL"),
        .description = COMPOUND_STRING("Ataca dos veces."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("AURA OSCURA"),
        .description = COMPOUND_STRING("Potencia lo Siniestro."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("AURA FEÉRICA"),
        .description = COMPOUND_STRING("Potencia ataques Hada."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("ROMPEAURA"),
        .description = COMPOUND_STRING("Invierte las auras."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("MAR DEL ALBOR"),
        .description = COMPOUND_STRING("Desata lluvia torrencial."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("TIERRA DEL OCASO"),
        .description = COMPOUND_STRING("Desata sol abrasador."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("RÁFAGA DELTA"),
        .description = COMPOUND_STRING("Desata vientos fuertes."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("FIRMEZA"),
        .description = COMPOUND_STRING("Si le dan, sube Defensa."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("HUIDA"),
        .description = COMPOUND_STRING("Huye a mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("RETIRADA"),
        .description = COMPOUND_STRING("Huye a mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("HIDRORREFUERZO"),
        .description = COMPOUND_STRING("Lo Agua sube su Defensa."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("ENSAÑAMIENTO"),
        .description = COMPOUND_STRING("Crítico a envenenados."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("ESCUDO LIMITADO"),
        .description = COMPOUND_STRING("Pierde coraza a mitad de PS."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("VIGILANTE"),
        .description = COMPOUND_STRING("Fuerte si el rival cambia."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("POMPA"),
        .description = COMPOUND_STRING("Evita fuego y quemaduras."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("ACERO TEMPLADO"),
        .description = COMPOUND_STRING("Potencia ataques Acero."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("CÓLERA"),
        .description = COMPOUND_STRING("Sube At. Esp. con pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("QUITANIEVES"),
        .description = COMPOUND_STRING("Rápido con granizo o nieve."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("REMOTO"),
        .description = COMPOUND_STRING("Nunca ataca por contacto."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("VOZ FLUIDA"),
        .description = COMPOUND_STRING("Sonido pasa a tipo Agua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("PRIMER AUXILIO"),
        .description = COMPOUND_STRING("Ataques curativos primero."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("PIEL ELÉCTRICA"),
        .description = COMPOUND_STRING("Lo Normal pasa a Eléctrico."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("COLA SURF"),
        .description = COMPOUND_STRING("Rápido en campo eléctrico."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("BANCO"),
        .description = COMPOUND_STRING("Forma banco si es fuerte."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("DISFRAZ"),
        .description = COMPOUND_STRING("Su disfraz le protege 1 vez."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("FUERTE AFECTO"),
        .description = COMPOUND_STRING("Cambia de forma tras un KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("AGRUPAMIENTO"),
        .description = COMPOUND_STRING("Sus células le ayudan."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("CORROSIÓN"),
        .description = COMPOUND_STRING("Envenena a cualquier tipo."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("LETARGO PERENNE"),
        .description = COMPOUND_STRING("Siempre está adormilado."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("REGIA PRESENCIA"),
        .description = COMPOUND_STRING("Bloquea la prioridad."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("REVÉS"),
        .description = COMPOUND_STRING("Daña al rival al caer."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("PAREJA DE BAILE"),
        .description = COMPOUND_STRING("Baila junto a los demás."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("BATERÍA"),
        .description = COMPOUND_STRING("Sube At. Esp. del aliado."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("PELUCHE"),
        .description = COMPOUND_STRING("Resistente pero inflamable."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("CUERPO VÍVIDO"),
        .description = COMPOUND_STRING("Bloquea la prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("CORÁNIMA"),
        .description = COMPOUND_STRING("Derrotar sube su At. Esp."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("RIZOS REBELDES"),
        .description = COMPOUND_STRING("Contacto baja Velocidad."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("RECEPTOR"),
        .description = COMPOUND_STRING("Copia la habilidad aliada."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("REACCIÓN QUÍMICA"),
        .description = COMPOUND_STRING("Copia la habilidad aliada."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("ULTRAIMPULSO"),
        .description = COMPOUND_STRING("Un KO sube su mejor caract."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("SISTEMA ALFA"),
        .description = COMPOUND_STRING("Los discos cambian su tipo."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("ELECTROGÉNESIS"),
        .description = COMPOUND_STRING("Activa un campo eléctrico."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("PSICOGÉNESIS"),
        .description = COMPOUND_STRING("Activa un campo psíquico."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("NEBULOGÉNESIS"),
        .description = COMPOUND_STRING("Activa un campo de niebla."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("HERBOGÉNESIS"),
        .description = COMPOUND_STRING("Activa un campo de hierba."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("GUARDIA METÁLICA"),
        .description = COMPOUND_STRING("Evita bajadas de caract."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("GUARDIA ESPECTRO"),
        .description = COMPOUND_STRING("Mitad de daño con PS llenos."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("ARMADURA PRISMA"),
        .description = COMPOUND_STRING("Reduce lo “muy eficaz”."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("FUERZA CEREBRAL"),
        .description = COMPOUND_STRING("Potencia lo “muy eficaz”."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("ESPADA INDÓMITA"),
        .description = COMPOUND_STRING("Sube Ataque al entrar."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("ESCUDO RECIO"),
        .description = COMPOUND_STRING("Sube Defensa al entrar."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LÍBERO"),
        .description = COMPOUND_STRING("Toma el tipo del ataque."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("RECOGEBOLAS"),
        .description = COMPOUND_STRING("Recoge Poké Ball fallida."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("PELUSA"),
        .description = COMPOUND_STRING("Si le dan, baja Velocidad."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("HÉLICE CAUDAL"),
        .description = COMPOUND_STRING("Ignora redirecciones."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("CORAZA REFLEJO"),
        .description = COMPOUND_STRING("Refleja bajadas de caract."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("TRAGAMISIL"),
        .description = COMPOUND_STRING("Si le dan, escupe una presa."),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("ACÉRRIMO"),
        .description = COMPOUND_STRING("Ignora redirecciones."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("COMBUSTIBLE"),
        .description = COMPOUND_STRING("Fuego/Agua sube Velocidad."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("PUNK ROCK"),
        .description = COMPOUND_STRING("Potencia y resiste sonido."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("EXPULSARENA"),
        .description = COMPOUND_STRING("Si le dan, levanta arena."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("ESCAMA DE HIELO"),
        .description = COMPOUND_STRING("Mitad de daño especial."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("MADURACIÓN"),
        .description = COMPOUND_STRING("Dobla el efecto de Bayas."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("CARA DE HIELO"),
        .description = COMPOUND_STRING("Nieve o granizo lo reparan."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("FUENTE ENERGÍA"),
        .description = COMPOUND_STRING("Potencia ataques aliados."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("MIMETISMO"),
        .description = COMPOUND_STRING("Cambia tipo según campo."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("ANTIBARRERA"),
        .description = COMPOUND_STRING("Quita barreras de luz."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("ALMA ACERADA"),
        .description = COMPOUND_STRING("Potencia Acero del equipo."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("CUERPO MORTAL"),
        .description = COMPOUND_STRING("Si le tocan, KO en 3 turnos."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("ALMA ERRANTE"),
        .description = COMPOUND_STRING("Cambia habilidad al tocar."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("MONOTEMA"),
        .description = COMPOUND_STRING("Sube Ataque, fija ataque."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("GAS REACTIVO"),
        .description = COMPOUND_STRING("Anula las habilidades."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("VELO PASTEL"),
        .description = COMPOUND_STRING("Equipo inmune al veneno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("MUTAPETITO"),
        .description = COMPOUND_STRING("Cambia de forma cada turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("MANO RÁPIDA"),
        .description = COMPOUND_STRING("A veces ataca primero."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("PUÑO INVISIBLE"),
        .description = COMPOUND_STRING("Ignora protecciones."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("MEDICINA EXTRAÑA"),
        .description = COMPOUND_STRING("Quita cambios de aliados."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("TRANSISTOR"),
        .description = COMPOUND_STRING("Potencia lo Eléctrico."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("MANDÍBULA DRAGÓN"),
        .description = COMPOUND_STRING("Potencia ataques Dragón."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("RELINCHO BLANCO"),
        .description = COMPOUND_STRING("Un KO sube su Ataque."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("RELINCHO NEGRO"),
        .description = COMPOUND_STRING("Un KO sube su At. Esp."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("UNIDAD ECUESTRE"),
        .description = COMPOUND_STRING("Nerviosismo y R. Blanco."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("UNIDAD ECUESTRE"),
        .description = COMPOUND_STRING("Nerviosismo y R. Negro."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("OLOR PERSISTENTE"),
        .description = COMPOUND_STRING("Se contagia por contacto."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("DISEMILLAR"),
        .description = COMPOUND_STRING("Si le dan, cambia el campo."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("TERMOCONVERSIÓN"),
        .description = COMPOUND_STRING("El fuego sube su Ataque."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("CORAZA IRA"),
        .description = COMPOUND_STRING("Se enfada a mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("SAL PURIFICADORA"),
        .description = COMPOUND_STRING("Lo protege la sal pura."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("CUERPO HORNEADO"),
        .description = COMPOUND_STRING("El fuego lo fortalece."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("SURCAVIENTOS"),
        .description = COMPOUND_STRING("El viento sube su Ataque."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("PERRO GUARDIÁN"),
        .description = COMPOUND_STRING("No se deja intimidar."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("TRANSPORTARROCAS"),
        .description = COMPOUND_STRING("Potencia ataques Roca."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("ENERGÍA EÓLICA"),
        .description = COMPOUND_STRING("El viento lo carga."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("CAMBIO HEROICO"),
        .description = COMPOUND_STRING("Cambia de forma al salir."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("COMANDAR"),
        .description = COMPOUND_STRING("Da órdenes desde Dondozo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("DINAMO"),
        .description = COMPOUND_STRING("Se carga al ser golpeado."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("PALEOSÍNTESIS"),
        .description = COMPOUND_STRING("Sol sube su mejor caract."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("CARGA CUARK"),
        .description = COMPOUND_STRING("C. Eléct. sube mejor caract."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("CUERPO ÁUREO"),
        .description = COMPOUND_STRING("Evita ataques de estado."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("CALDERO DEBACLE"),
        .description = COMPOUND_STRING("Baja el At. Esp. rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("ESPADA DEBACLE"),
        .description = COMPOUND_STRING("Baja la Defensa rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("TABLILLA DEBACLE"),
        .description = COMPOUND_STRING("Baja el Ataque rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("ABALORIO DEBACLE"),
        .description = COMPOUND_STRING("Baja la Def. Esp. rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("LATIDO ORICALCO"),
        .description = COMPOUND_STRING("Toma luz solar en batalla."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("MOTOR HADRÓNICO"),
        .description = COMPOUND_STRING("Activa un campo eléctrico."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("OPORTUNISTA"),
        .description = COMPOUND_STRING("Copia mejoras del rival."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("RUMIA"),
        .description = COMPOUND_STRING("Repite una Baya ya comida."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("CORTANTE"),
        .description = COMPOUND_STRING("Potencia los cortes."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("GENERAL SUPREMO"),
        .description = COMPOUND_STRING("Hereda fuerza de caídos."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("UNÍSONO"),
        .description = COMPOUND_STRING("Copia cambios del aliado."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("CAPA TÓXICA"),
        .description = COMPOUND_STRING("Si le dan, siembra púas."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("COLA ARMADURA"),
        .description = COMPOUND_STRING("Bloquea la prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("GEOFAGIA"),
        .description = COMPOUND_STRING("Come tierra y recupera PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("PODER FÚNGICO"),
        .description = COMPOUND_STRING("Sus estados nunca fallan."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("HOSPITALIDAD"),
        .description = COMPOUND_STRING("Recupera PS del aliado."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("OJO MENTAL"),
        .description = COMPOUND_STRING("Vista Lince e Intrépido."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("EVOCARRECUERDOS"),
        .description = COMPOUND_STRING("Sube la Velocidad."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("EVOCARRECUERDOS"),
        .description = COMPOUND_STRING("Aumenta el Ataque."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("EVOCARRECUERDOS"),
        .description = COMPOUND_STRING("Sube la Def. Esp."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("EVOCARRECUERDOS"),
        .description = COMPOUND_STRING("Sube la Defensa."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("CADENA TÓXICA"),
        .description = COMPOUND_STRING("Puede envenenar al atacar."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("NÉCTAR DULCE"),
        .description = COMPOUND_STRING("Baja la Evasión del rival."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("TERACAMBIO"),
        .description = COMPOUND_STRING("Se teracristaliza al entrar."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("TERACAPARAZÓN"),
        .description = COMPOUND_STRING("Resiste todo con PS llenos."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("TERAFORMACIÓN 0"),
        .description = COMPOUND_STRING("Anula clima y campo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("TÍTERE TÓXICO"),
        .description = COMPOUND_STRING("Confunde a envenenados."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
