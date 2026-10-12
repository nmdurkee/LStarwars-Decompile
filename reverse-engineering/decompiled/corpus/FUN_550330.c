/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550330; label: FUN_00550330
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

