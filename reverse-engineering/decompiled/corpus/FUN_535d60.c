/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x535d60; label: FUN_00535d60
 */

undefined4
FUN_00535d60(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  if (param_3 != 0) {
    if (param_6 != 0) {
      iVar3 = 0;
      *(undefined4 *)(param_3 + 0x180) = 0x3f800000;
      if (0 < param_5) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar2 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar3 * 4),param_3 + 0x13f),
             iVar2 == 0)) {
            fVar4 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar3 * 4));
            *(float *)(param_3 + 0x180) = (float)fVar4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_5);
      }
    }
    iVar3 = *(int *)(param_3 + 0xe4);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      iVar3 = *(int *)(iVar3 + 4);
      uVar1 = *(undefined4 *)(iVar3 + 0x120);
      if ((undefined4 *)(iVar3 + 0x170) != (undefined4 *)0x0) {
        *(undefined4 *)(param_3 + 0x1b4) = *(undefined4 *)(iVar3 + 0x170);
        *(undefined4 *)(param_3 + 0x1b8) = *(undefined4 *)(iVar3 + 0x174);
        *(undefined4 *)(param_3 + 0x1bc) = *(undefined4 *)(iVar3 + 0x178);
      }
      if ((undefined4 *)(iVar3 + 0x158) != (undefined4 *)0x0) {
        *(undefined4 *)(param_3 + 0x1cc) = *(undefined4 *)(iVar3 + 0x158);
        *(undefined4 *)(param_3 + 0x1d0) = *(undefined4 *)(iVar3 + 0x15c);
        *(undefined4 *)(param_3 + 0x1d4) = *(undefined4 *)(iVar3 + 0x160);
        *(undefined4 *)(param_3 + 0x1d8) = *(undefined4 *)(iVar3 + 0x164);
        *(undefined4 *)(param_3 + 0x1dc) = *(undefined4 *)(iVar3 + 0x168);
        *(undefined4 *)(param_3 + 0x1e0) = *(undefined4 *)(iVar3 + 0x16c);
      }
      *(undefined4 *)(param_3 + 0x1c0) = uVar1;
      *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_3 + 0x180);
      *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffffa | 2;
    }
    return 0;
  }
  return 1;
}

