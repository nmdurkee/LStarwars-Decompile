/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x689060; label: FUN_00689060
 */

void FUN_00689060(int *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  undefined1 local_c [12];
  
  iVar2 = (int)param_1;
  FUN_005da860(local_c,DAT_02962114,(&DAT_0292fe18)[(int)param_1 * 0xb5]);
  pfVar3 = (float *)FUN_005cf9c0(local_c);
  iVar5 = 0;
  if (0 < (int)(&DAT_0292fe1c)[(int)param_1 * 0xb5]) {
    pfVar6 = (float *)(&DAT_0292ff18 + (int)param_1 * 0xb5);
    param_1 = &DAT_0292feb4 + (int)param_1 * 0xb5;
    do {
      if (*param_1 != -1) {
        if ((DAT_02961f7c == 0) || (DAT_0292fd08 != iVar5)) {
          uVar4 = 0xffffffff;
        }
        else {
          iVar1 = *(int *)(DAT_0296209c + *param_1 * 4);
          if (*(char *)(iVar1 + 0x2c) == '\0') {
            FUN_0065bb50(pfVar6[-1] + *pfVar3,pfVar3[1] + *pfVar6,pfVar6[1] + pfVar3[2],
                         *(undefined4 *)(iVar1 + 0x58),*(undefined4 *)(iVar1 + 0x5c),
                         *(undefined4 *)(iVar1 + 0x60),DAT_0296210c,DAT_02962110,0,0,0,0xff008000,
                         DAT_029211f4);
          }
          uVar4 = 0xff00ff00;
        }
        FUN_0065bf70(pfVar6[-1] + *pfVar3,pfVar3[1] + *pfVar6,pfVar6[1] + pfVar3[2],0x3e800000,uVar4
                     ,DAT_029211f4);
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 1;
      pfVar6 = pfVar6 + 3;
    } while (iVar5 < (int)(&DAT_0292fe1c)[iVar2 * 0xb5]);
  }
  return;
}

