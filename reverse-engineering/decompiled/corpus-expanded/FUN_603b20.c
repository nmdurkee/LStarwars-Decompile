/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603b20; label: FUN_00603b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603b20(int *param_1)

{
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*param_1 != DAT_0080e9f8) {
    DAT_0080e9f8 = *param_1;
    FUN_005fa330(param_1 + 1,param_1 + 0x11);
    local_18 = FUN_006e6b90();
    local_20 = (undefined4)(longlong)ROUND((float)param_1[0x22]);
    local_14 = local_20;
    local_20 = (undefined4)(longlong)ROUND((float)param_1[0x23]);
    local_10 = local_20;
    local_20 = (undefined4)(longlong)ROUND((float)param_1[0x24]);
    local_c = local_20;
    local_8 = 0;
    local_4 = 0x3f800000;
    FUN_006e57b0(&local_18);
  }
  return;
}

