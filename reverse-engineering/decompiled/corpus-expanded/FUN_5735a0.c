/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5735a0; label: FUN_005735a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005735a0(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  param_1 = param_1 * 0x130;
  iVar1 = (int)*(char *)(param_1 + 0xa3 + DAT_00951b78);
  iVar3 = (int)*(char *)(param_1 + 200 + DAT_00951b78);
  if ((iVar1 != -1) && (iVar4 = *(byte *)(iVar1 * 0x9c + 0x7d + DAT_00951354) - 1, iVar3 < iVar4)) {
    psVar2 = (short *)(DAT_00951354 + 0x60 + (iVar1 * 0x4e + iVar3) * 2);
    do {
      if ((*(byte *)(DAT_00951b78 + 100 + *psVar2 * 0x130) & 0xe0) == 0) {
        return *psVar2 * 0x130 + DAT_00951b78;
      }
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 1;
    } while (iVar3 < iVar4);
  }
  return param_1 + DAT_00951b78;
}

