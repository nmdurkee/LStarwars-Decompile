/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9980; label: FUN_005f9980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f9980(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_02854bf4 = *param_1;
  DAT_02854bf8 = param_1[1];
  _DAT_00973fe0 = param_3;
  DAT_02854bfc = param_1[2];
  _DAT_00973fe4 = param_4;
  DAT_02854c00 = (param_2 >> 1 & 0x7f7f7f) + (param_2 & 0xff000000) * 2;
  return;
}

