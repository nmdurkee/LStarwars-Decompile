/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654ba0; label: FUN_00654ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00654ba0(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_4;
  
  if (DAT_02962078 != 0) {
    uVar3 = DAT_02962070;
    if (DAT_02962070 == 0) {
      if (param_1 == (uint *)0x0) {
        return;
      }
      uVar3 = *param_1 + 0xf & 0xfffffff0;
      *param_1 = uVar3;
    }
    _memset(DAT_02947d94,0,(DAT_008108ec + DAT_008108e8) * 0x58);
    _memset(DAT_02923198,0,(DAT_008108ec + DAT_008108e8) * 8);
    _memset(DAT_02921200,0,DAT_008108e8 * 4);
    _memset(DAT_029211fc,0,DAT_008108ec * 4);
    _memset(DAT_02961fec,0,(DAT_008108ec + DAT_008108e8) * 100);
    iVar4 = 0;
    if (0 < DAT_008108e8) {
      do {
        uVar1 = FUN_005ffdc0(uVar3,&local_4);
        *(undefined4 *)((int)DAT_02921200 + iVar4 * 4) = uVar1;
        uVar3 = uVar3 + local_4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_008108e8);
    }
    iVar4 = 0;
    if (0 < DAT_008108ec) {
      do {
        uVar1 = thunk_FUN_005ffdc0(uVar3,&local_4);
        *(undefined4 *)((int)DAT_029211fc + iVar4 * 4) = uVar1;
        uVar3 = uVar3 + local_4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_008108ec);
    }
    iVar4 = 0;
    DAT_02948e98 = 0;
    DAT_02947d84 = 0;
    if (0 < DAT_008108fc) {
      do {
        uVar1 = FUN_005ffe80(uVar3,&local_4);
        *(undefined4 *)(DAT_02962090 + iVar4 * 4) = uVar1;
        uVar3 = uVar3 + local_4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_008108fc);
    }
    if (DAT_02962070 == 0) {
      DAT_02962070 = *param_1;
      _DAT_02962074 = uVar3 - *param_1;
      *param_1 = uVar3;
    }
    iVar4 = 0;
    DAT_0292fbfc = 0;
    DAT_0292fc00 = 0;
    if (0 < (DAT_008108ec + DAT_008108e8) * 2) {
      iVar2 = 0;
      do {
        *(int *)((int)DAT_02923198 + iVar4 * 4) = (int)DAT_02947d94 + iVar2;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0x2c;
      } while (iVar4 < (DAT_008108ec + DAT_008108e8) * 2);
    }
    DAT_02947b70 = 0;
    if (0 < DAT_008108ec + DAT_008108e8) {
      iVar4 = 0;
      iVar2 = 0;
      do {
        *(undefined4 *)(iVar4 + (int)DAT_02961fec) = 0;
        *(undefined4 *)(iVar4 + 4 + (int)DAT_02961fec) = 0;
        *(undefined4 *)(iVar4 + 8 + (int)DAT_02961fec) = 0;
        *(undefined4 *)(iVar4 + 0x58 + (int)DAT_02961fec) = 0;
        *(undefined4 *)(iVar4 + 0x5c + (int)DAT_02961fec) = 0;
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 100;
      } while (iVar2 < DAT_008108ec + DAT_008108e8);
    }
    DAT_0292fd30 = 0;
    DAT_0292fd34 = 0;
    _DAT_0292fd38 = 0;
    _DAT_0292fd3c = 0;
    _DAT_0292fd40 = 0;
  }
  return;
}

