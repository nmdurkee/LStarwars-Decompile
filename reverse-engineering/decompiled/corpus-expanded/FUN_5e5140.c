/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5140; label: FUN_005e5140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

