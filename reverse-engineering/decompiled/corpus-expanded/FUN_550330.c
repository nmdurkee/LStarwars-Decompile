/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550330; label: FUN_00550330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00550330(undefined4 param_1,undefined4 param_2,short param_3,short param_4,short param_5)

{
  switch(param_2) {
  case 0:
    if (param_3 != 0) {
      FUN_005b4cf0(param_1,param_3);
    }
    if (param_4 != 0) {
      FUN_005b4f70(param_1,param_4);
    }
    if (param_5 != 0) {
      FUN_005b5160(param_1,param_5);
      return;
    }
    break;
  case 1:
    if (param_4 != 0) {
      FUN_005b4f70(param_1,param_4);
    }
    if (param_3 != 0) {
      FUN_005b4cf0(param_1,param_3);
    }
    if (param_5 != 0) {
      FUN_005b5160(param_1,param_5);
      return;
    }
    break;
  case 2:
    if (param_4 != 0) {
      FUN_005b4f70(param_1,param_4);
    }
    if (param_5 != 0) {
      FUN_005b5160(param_1,param_5);
    }
    if (param_3 != 0) {
      FUN_005b4cf0(param_1,param_3);
      return;
    }
    break;
  case 3:
    if (param_5 != 0) {
      FUN_005b5160(param_1,param_5);
    }
    if (param_3 != 0) {
      FUN_005b4cf0(param_1,param_3);
    }
    if (param_4 != 0) {
      FUN_005b4f70(param_1,param_4);
    }
  }
  return;
}

