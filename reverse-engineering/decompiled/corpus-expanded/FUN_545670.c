/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545670; label: FUN_00545670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00545670(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_02983a50 + param_1;
  if (iVar1 < DAT_00924834) {
    DAT_02983a50 = iVar1;
    return DAT_0092483c + (iVar1 - param_1) * 2;
  }
  return 0;
}

