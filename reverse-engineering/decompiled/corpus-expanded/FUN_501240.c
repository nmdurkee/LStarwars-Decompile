/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501240; label: FUN_00501240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00501240(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_009213c0 != (int *)0x0) {
    iVar1 = *DAT_009213c0;
    while (iVar1 != 0) {
      iVar1 = FUN_004f8b10();
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = DAT_009213c0[iVar2 * 5];
    }
  }
  return -1;
}

