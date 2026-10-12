/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x545db0; label: FUN_00545db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00545db0(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  DAT_00924840 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_00924840;
  DAT_00924838 = param_4;
  DAT_0092483c = param_4 * 0x40 + 0xf + *param_1 & 0xfffffff0;
  *param_1 = DAT_0092483c;
  DAT_00924834 = param_3;
  *param_1 = *param_1 + param_3 * 2;
  return;
}

