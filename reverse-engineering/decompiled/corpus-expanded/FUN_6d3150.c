/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d3150; label: FUN_006d3150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d3150(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_02974d30 != '\0') {
    return 1;
  }
  DAT_02974d30 = 1;
  if ((0xfffe0100 < DAT_02976694) && (0xffff0100 < DAT_0297669c)) {
    DAT_02974d1c = 1;
  }
  if (0xfffe01ff < DAT_02976694) {
    if (0xffff01ff < DAT_0297669c) {
      DAT_02974d1c = 2;
    }
    if ((0xfffe0200 < DAT_02976694) && (0xffff0200 < DAT_0297669c)) {
      DAT_02974d1c = 3;
    }
  }
  if ((0xfffe02ff < DAT_02976694) && (0xffff02ff < DAT_0297669c)) {
    DAT_02974d1c = 4;
  }
  iVar1 = DAT_02974d1c;
  if (DAT_02974d1c == 0) {
    if (0xffff00ff < DAT_0297669c) {
      DAT_02976bc0 = 1;
      DAT_02974d1c = 1;
      goto LAB_006d3200;
    }
    if (DAT_02976b94 != 0x8086) goto LAB_006d3200;
    DAT_02976bc0 = 1;
    DAT_02974d1c = 1;
    if ((((DAT_02976b98 == 0x2572) || (DAT_02976b98 == 0x3582)) || (DAT_02976b98 == 0x2562)) ||
       (DAT_02976b98 == 0x3577)) {
      DAT_02974d20 = 1;
    }
LAB_006d326b:
    if (((DAT_02976b98 != 0x2582) && (DAT_02976b98 != 0x2772)) && (DAT_02976b98 != 0x29b2))
    goto switchD_006d321e_caseD_313;
  }
  else {
LAB_006d3200:
    if (DAT_02976b94 != 0x10de) {
      if (DAT_02976b94 != 0x8086) goto switchD_006d321e_caseD_313;
      goto LAB_006d326b;
    }
    switch(DAT_02976b98) {
    case 0x311:
    case 0x312:
    case 0x314:
    case 0x321:
    case 0x322:
    case 0x323:
    case 0x326:
    case 0x341:
    case 0x342:
    case 0x343:
    case 0x344:
      if (iVar1 < 2) goto switchD_006d321e_caseD_313;
      break;
    default:
      goto switchD_006d321e_caseD_313;
    }
  }
  DAT_02974d1c = 1;
switchD_006d321e_caseD_313:
  if (DAT_008264cc == 1) {
    DAT_02974d1c = 1;
  }
  else if (DAT_008264cc == 2) {
    DAT_02974d1c = 2;
  }
  else if (DAT_008264cc == 3) {
    DAT_02974d1c = 4;
  }
  if (iVar1 == 0) {
    uVar2 = FUN_004f5240();
    switch(uVar2) {
    case 2:
      FUN_006e0080(&DAT_02976078,&DAT_007705c0);
      return 1;
    case 3:
      FUN_006e0080(&DAT_02976078,&DAT_007703f0);
      return 1;
    case 4:
      FUN_006e0080(&DAT_02976078,&DAT_00770528);
      return 1;
    case 5:
      FUN_006e0080(&DAT_02976078,&DAT_00770490);
      return 1;
    case 6:
      FUN_006e0080(&DAT_02976078,
                   "Helaas is je pc niet geschikt voor dit spel.\nJe hebt een grafische kaart met Pixel Shaders v1.1-ondersteuning nodig.\nHet spel wordt nu afgesloten."
                  );
      return 1;
    default:
      FUN_006e0080(&DAT_02976078,
                   "Sorry, but your machine is unable to run this game.\nIt requires a graphics card which supports Pixel Shaders v1.1.\nThe game will now exit."
                  );
      break;
    case 8:
      FUN_006e0080(&DAT_02976078,&DAT_00770358);
      return 1;
    }
  }
  return 1;
}

