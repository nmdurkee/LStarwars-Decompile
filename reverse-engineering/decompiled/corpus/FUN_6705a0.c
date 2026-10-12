/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x6705a0; label: FUN_006705a0
 */

int FUN_006705a0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (DAT_0292fc68 != 0) {
    piVar2 = (int *)(DAT_0292fc68 + 0x198);
    do {
      if (*piVar2 == 0) {
        return DAT_0292fc68 + (iVar1 * 3 + 0x33) * 8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 < 0x40);
  }
  return 0;
}

