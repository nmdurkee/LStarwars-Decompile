/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66f740; label: FUN_0066f740
 */

void FUN_0066f740(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *param_3;
  local_c = param_3[1];
  local_8 = param_3[2];
  local_4 = 0x3f800000;
  FUN_005c03e0(&local_10,&local_10,*(undefined4 *)(param_2 + 8));
  *param_1 = local_10;
  param_1[1] = local_c;
  param_1[2] = local_8;
  return;
}

