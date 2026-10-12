/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x586d20; label: FUN_00586d20
 */

void FUN_00586d20(int param_1)

{
  undefined2 uVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  psVar2 = (short *)(DAT_00954404 + 0xd0);
  do {
    if (*psVar2 == -1) {
      if ((iVar4 < 6) && (iVar3 = FUN_004f7fb0(param_1), iVar3 != 0)) {
        uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
        *(undefined2 *)(DAT_00954404 + 0xd0 + iVar4 * 2) = uVar1;
      }
      break;
    }
    iVar4 = iVar4 + 1;
    psVar2 = psVar2 + 1;
  } while (iVar4 < 6);
  if (iVar4 + 1 < 6) {
    *(undefined2 *)(DAT_00954404 + 0xd0 + (iVar4 + 1) * 2) = 0xffff;
  }
  return;
}

