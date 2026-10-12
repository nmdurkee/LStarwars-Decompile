/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5140; label: FUN_005e5140
 */

void FUN_005e5140(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    _memset(param_1,0,0x208);
    param_1[0x6e] = param_1[0x6e] | 0x1000;
    param_1[9] = 0x3f800000;
    param_1[0x4f] = param_1[0x4f] | 0x101;
    *param_1 = 0x1000;
    param_1[5] = 0xff8080ff;
    param_1[0x43] = 0xffffffff;
    param_1[0x44] = 0xffffffff;
    param_1[0x45] = 0xffffffff;
    param_1[0x46] = 0xffffffff;
  }
  return;
}

