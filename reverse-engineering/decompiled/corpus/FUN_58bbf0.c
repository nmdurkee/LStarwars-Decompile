/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58bbf0; label: FUN_0058bbf0
 */

undefined4 FUN_0058bbf0(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if ((param_1 != 0) && (0 < *(int *)(param_1 + 4))) {
    psVar2 = (short *)(param_1 + 0x16);
    do {
      if ((*(int *)(psVar2 + 1) != 0) && (*psVar2 == param_2)) {
        return *(undefined4 *)(param_1 + 0x18 + iVar1 * 0x14);
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 10;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return 0;
}

