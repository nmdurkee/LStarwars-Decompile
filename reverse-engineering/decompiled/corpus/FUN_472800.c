/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x472800; label: FUN_00472800
 */

void FUN_00472800(int param_1,float *param_2)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if ((param_1 != 0) && (param_2 != (float *)0x0)) {
    local_c = *(float *)(param_1 + 0x70);
    local_8 = *(float *)(param_1 + 0x74);
    local_4 = *(float *)(param_1 + 0x78);
    FUN_005b3620(&local_c,&local_c,*(undefined2 *)(param_1 + 0x5c));
    fVar1 = *(float *)(param_1 + 0x58);
    *param_2 = *(float *)(param_1 + 0x50) + local_c;
    param_2[1] = local_8;
    param_2[2] = fVar1 + local_4;
  }
  return;
}

