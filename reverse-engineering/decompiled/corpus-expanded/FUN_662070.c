/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662070; label: FUN_00662070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00662070(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_02962a30 == 0) {
    if (DAT_029231a8 != -1) {
      FUN_0065bb50((&DAT_02924b50)[DAT_029231a8 * 0x16],(&DAT_02924b54)[DAT_029231a8 * 0x16],
                   (&DAT_02924b58)[DAT_029231a8 * 0x16],0x3f000000,0x3f000000,0x3f000000,0,0,0,0,0,
                   0xffffffff,DAT_02947c68);
    }
    if (DAT_02962a40 != 0) {
      iVar2 = 0;
      puVar3 = &DAT_02924b58;
      do {
        if ((0 < (int)puVar3[1]) && (iVar2 != DAT_029231a8)) {
          FUN_0065bb50(puVar3[-2],puVar3[-1],*puVar3,0x3f000000,0x3f000000,0x3f000000,0,0,0,0,0,
                       0xff000000,DAT_02947c68);
        }
        puVar3 = puVar3 + 0x16;
        iVar2 = iVar2 + 1;
      } while ((int)puVar3 < 0x292fb58);
    }
  }
  else {
    DAT_02962a34 = 0;
    piVar1 = &DAT_02924b60;
    do {
      if ((*piVar1 != -1) && (*piVar1 != 99999)) {
        FUN_005b3800(&local_24,&DAT_02920abc,piVar1 + -4);
        if ((ABS(local_24) <= _DAT_00810adc) &&
           ((ABS(local_20) < _DAT_00810adc != (ABS(local_20) == _DAT_00810adc) &&
            (ABS(local_1c) < _DAT_00810adc != (ABS(local_1c) == _DAT_00810adc))))) {
          DAT_02962a34 = DAT_02962a34 + 1;
          FUN_0065bf70(piVar1[-4],piVar1[-3],piVar1[-2],0x3d4ccccd,0xffffffff,DAT_02947c68);
        }
      }
      piVar1 = piVar1 + 0x16;
    } while ((int)piVar1 < 0x292fb60);
    if ((0 < DAT_02962a38) && (iVar2 = 0, 0 < DAT_02962a38)) {
      do {
        FUN_005b3800(local_18,&DAT_02924b50 + (&DAT_02924acc)[iVar2] * 0x16,&DAT_02947b3c);
        FUN_005b3620(local_18,local_18,DAT_02962acc);
        FUN_005b37d0(&local_c,&DAT_02920abc,local_18);
        FUN_0065bf70(local_c,local_8,local_4,0x3d4ccccd,0xff808080,DAT_02947c68);
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_02962a38);
      return;
    }
  }
  return;
}

