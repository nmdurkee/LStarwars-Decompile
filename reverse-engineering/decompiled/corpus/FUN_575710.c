/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575710; label: FUN_00575710
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00575710(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xf8) == 0) {
    if (*(char *)(param_1 + 0x80) == '\0') {
      DAT_00951420 = 0;
      return;
    }
    if ((int)*(short *)(param_1 + 0xf0) == *(int *)(PTR_DAT_00802c54 + 0x11c)) {
      DAT_00951420 = 0;
      return;
    }
    DAT_00951420 = 1;
    FUN_004f1f10(&DAT_009513f8,param_1 + 0x80);
  }
  else {
    DAT_00951420 = 1;
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0xf8) + 8);
    DAT_0095138c = *puVar1;
    DAT_00951390 = puVar1[1];
    DAT_00951394 = puVar1[2];
    iVar2 = *(int *)(*(int *)(param_1 + 0xf8) + 8);
    DAT_009513a0 = *(undefined4 *)(iVar2 + 0xc);
    DAT_009513a4 = *(undefined4 *)(iVar2 + 0x10);
    DAT_009513a8 = *(undefined4 *)(iVar2 + 0x14);
  }
  DAT_00951424 = *(byte *)(param_1 + 0xf5) & 2;
  _DAT_009513ac = *(undefined4 *)(param_1 + 0x100);
  _DAT_0095139c = *(undefined4 *)(param_1 + 0xfc);
  _DAT_00951380 = *(undefined4 *)(param_1 + 0xfc);
  return;
}

