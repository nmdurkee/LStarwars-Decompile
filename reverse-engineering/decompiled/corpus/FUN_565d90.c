/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x565d90; label: FUN_00565d90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565d90(void)

{
  int iVar1;
  
  FUN_00574e20();
  if ((DAT_00950748 != 0) && (DAT_009507a0 == -1)) {
    FUN_005d4290(1);
    if (1.0 <= _DAT_00950678) {
      FUN_005ebd80(0x300,0,0x3f800000);
    }
    else {
      if (DAT_009506f0 == DAT_009506f4) {
        FUN_005ebd80(0xf00,DAT_009506f0);
      }
      else {
        FUN_005feab0(0xf00,DAT_009506f0,DAT_009506f4,0x3f800000);
      }
      FUN_00564af0(1.0 - _DAT_00950678,0);
    }
    FUN_005f3950();
  }
  if ((((DAT_00950770 != 2) && (DAT_00950748 != 0)) && (DAT_0095076c != 0)) && (DAT_009507a0 == -1))
  {
    FUN_00565c00(DAT_00802e30);
  }
  if (DAT_0093b328 == 0) {
    if (DAT_00950768 != 0) {
      DAT_00950748 = 0;
    }
  }
  else if ((DAT_00950768 == 0) && (DAT_009507a0 == -1)) {
    DAT_00950740 = '\x01';
  }
  DAT_00950768 = DAT_0093b328;
  if ((DAT_0093d84c != -1) && (((DAT_00951388 != 0 || (DAT_00951c70 != 0)) || (DAT_0093d850 != 0))))
  {
    DAT_00950748 = 1;
    goto LAB_00565fda;
  }
  if ((DAT_00951b80 == DAT_00951b9c) && (DAT_00951b7c == DAT_00951b98)) {
    DAT_00950748 = 1;
    goto LAB_00565fda;
  }
  if (DAT_00951b80 == DAT_00951b98) {
    if ((*(int *)(PTR_DAT_00802c54 + 0x120) != -1) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x120) * 0x9c + 0x7a +
                  *(int *)(PTR_DAT_00802c54 + 300)) & 2) != 0)) {
      DAT_00950748 = 1;
      goto LAB_00565fda;
    }
    if (DAT_0093b338 == 0) goto LAB_00565f34;
  }
  else {
LAB_00565f34:
    if (DAT_00951b80 != DAT_00951b9c) {
      if (((DAT_00951b80 == DAT_00951b94) && (*(int *)(PTR_DAT_00802c54 + 0x120) != -1)) &&
         ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x120) * 0x9c + 0x7a +
                    *(int *)(PTR_DAT_00802c54 + 300)) & 2) != 0)) {
        DAT_00950748 = 1;
      }
      else if ((_DAT_00950678 <= 0.0) || (1.0 <= _DAT_00950678)) {
        if ((DAT_0093b328 == 0) || (DAT_00950740 != '\0')) {
          if ((DAT_00950770 != 0) && (DAT_00950748 = 1, DAT_00950770 != 1)) goto LAB_00565fda;
        }
        else if ((DAT_00950778 == (code *)0x0) || (iVar1 = (*DAT_00950778)(), iVar1 == 0)) {
          DAT_00950748 = 1;
          goto LAB_00565fda;
        }
        DAT_00950748 = 0;
      }
      else {
        DAT_00950748 = 1;
      }
      goto LAB_00565fda;
    }
  }
  DAT_00950748 = 1;
LAB_00565fda:
  DAT_00950770 = 0;
  DAT_00802e30 = 1;
  if (DAT_00950744 != 0) {
    DAT_00950748 = 0;
  }
  return;
}

