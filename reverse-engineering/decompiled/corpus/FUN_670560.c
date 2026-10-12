/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x670560; label: FUN_00670560
 */

void FUN_00670560(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = DAT_0292fc68;
  do {
    if (*(short *)(iVar1 + 0x19c + iVar2) == param_1) {
      *(undefined4 *)(iVar1 + 0x198 + iVar2) = 0;
      iVar2 = DAT_0292fc68;
    }
    iVar1 = iVar1 + 0x18;
  } while (iVar1 < 0x600);
  return;
}

