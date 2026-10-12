/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x6891e0; label: FUN_006891e0
 */

void FUN_006891e0(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  undefined1 local_c [12];
  
  FUN_005da860(local_c,DAT_02962114,(&DAT_0292fe18)[param_1 * 0xb5]);
  pfVar1 = (float *)FUN_005cf9c0(local_c);
  iVar3 = 0;
  if (0 < (int)(&DAT_0292fe20)[param_1 * 0xb5]) {
    pfVar5 = (float *)(&DAT_0293007c + param_1 * 0x2d4);
    piVar4 = &DAT_02930038 + param_1 * 0xb5;
    do {
      if (*piVar4 != -1) {
        if ((DAT_02924af8 == 0) || (DAT_02920aa8 != iVar3)) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = 0xffff0000;
        }
        FUN_0065bf70(pfVar5[-1] + *pfVar1,pfVar1[1] + *pfVar5,pfVar5[1] + pfVar1[2],0x3e800000,uVar2
                     ,DAT_029211f4);
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
      pfVar5 = pfVar5 + 3;
    } while (iVar3 < (int)(&DAT_0292fe20)[param_1 * 0xb5]);
  }
  return;
}

