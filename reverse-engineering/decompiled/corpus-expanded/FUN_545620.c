/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545620; label: FUN_00545620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_00545620(void)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  psVar2 = DAT_00924840;
  if (0 < DAT_00924838) {
    do {
      if (*psVar2 == 0) {
        DAT_00924840[iVar1 * 0x20] = 1;
        return DAT_00924840 + iVar1 * 0x20;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x20;
    } while (iVar1 < DAT_00924838);
  }
  return (short *)0x0;
}

