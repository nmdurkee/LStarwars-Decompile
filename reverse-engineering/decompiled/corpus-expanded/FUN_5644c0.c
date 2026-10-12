/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x5644c0; label: FUN_005644c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005644c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  DAT_00950708 = param_1;
  if (param_1 != 0) {
    iVar1 = FUN_005cf5b0(param_1,&DAT_0095066c,param_2,1);
    if (iVar1 == 0) {
      DAT_00950708 = 0;
    }
  }
  return;
}

