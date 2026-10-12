/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f0e60; label: FUN_004f0e60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004f0e60(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar2 = 0;
  _DAT_0091eeb8 = 0;
  if (*param_1 == 0x12345678) {
    piVar3 = param_1 + 3;
  }
  else if (*param_1 == 0x1234567a) {
    piVar3 = param_1 + 6;
  }
  else {
    piVar3 = param_1 + 5;
  }
  uVar5 = 0;
  if (param_1[1] != 0) {
    puVar4 = (uint *)(piVar3 + 4);
    do {
      uVar1 = *puVar4;
      if ((uVar1 & 2) == 0) {
        if ((uVar1 & 1) == 0) {
          *puVar4 = uVar1 | 2;
          uVar5 = puVar4[-2] + puVar4[-1] + -1 + uVar5 & ~(puVar4[-1] - 1);
        }
        else if (uVar5 != 0) {
          if (puVar4[-1] != 0) {
            uVar5 = uVar5 & ~(puVar4[-1] - 1);
          }
          if (uVar5 != 0) {
            FUN_004ef660((puVar4[-3] - uVar5) + (int)param_1,puVar4[-3] + (int)param_1,puVar4[-2]);
            puVar4[-3] = puVar4[-3] - uVar5;
          }
        }
      }
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 7;
    } while (uVar2 < (uint)param_1[1]);
  }
  param_1[2] = param_1[2] - uVar5;
  return uVar5;
}

