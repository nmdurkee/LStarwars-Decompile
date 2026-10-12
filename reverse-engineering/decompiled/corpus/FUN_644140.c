/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x644140; label: FUN_00644140
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00644140(void)

{
  int *piVar1;
  int iVar2;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_0292097c == 0) {
    if (DAT_02920888 != -1) {
      FUN_0065bb50((&DAT_0291f7a8)[DAT_02920888 * 0x1b],(&DAT_0291f7ac)[DAT_02920888 * 0x1b],
                   (&DAT_0291f7b0)[DAT_02920888 * 0x1b],0x3f000000,0x3f000000,0x3f000000,0,0,0,0,0,
                   0xffffffff,DAT_02913a54);
      return;
    }
  }
  else {
    DAT_02920980 = 0;
    piVar1 = &DAT_0291f7f0;
    do {
      if ((*piVar1 != -1) && (*piVar1 != 99999)) {
        FUN_005b3800(&local_24,&DAT_0291f714,piVar1 + -0x12);
        if ((ABS(local_24) <= _DAT_00810198) &&
           ((ABS(local_20) < _DAT_00810198 != (ABS(local_20) == _DAT_00810198) &&
            (ABS(local_1c) < _DAT_00810198 != (ABS(local_1c) == _DAT_00810198))))) {
          DAT_02920980 = DAT_02920980 + 1;
          FUN_0065bf70(piVar1[-0x12],piVar1[-0x11],piVar1[-0x10],0x3d4ccccd,0xffffffff,DAT_02913a54)
          ;
        }
      }
      piVar1 = piVar1 + 0x1b;
    } while ((int)piVar1 < 0x292cff0);
    if ((0 < DAT_02920984) && (iVar2 = 0, 0 < DAT_02920984)) {
      do {
        FUN_005b3800(local_18,&DAT_0291f7a8 + (&DAT_0291f754)[iVar2] * 0x1b,&DAT_0291f744);
        FUN_005b3620(local_18,local_18,DAT_02920a64);
        FUN_005b37d0(&local_c,&DAT_0291f714,local_18);
        FUN_0065bf70(local_c,local_8,local_4,0x3d4ccccd,0xff808080,DAT_02913a54);
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_02920984);
    }
  }
  return;
}

