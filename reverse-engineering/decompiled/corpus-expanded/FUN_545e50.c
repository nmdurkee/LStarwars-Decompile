/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545e50; label: FUN_00545e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_00545e50(void)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  psVar2 = DAT_00924850;
  if (0 < DAT_0092484c) {
    do {
      if (*psVar2 == 0) {
        DAT_00924850[iVar1 * 0x26] = 1;
        return DAT_00924850 + iVar1 * 0x26;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x26;
    } while (iVar1 < DAT_0092484c);
  }
  return (short *)0x0;
}

