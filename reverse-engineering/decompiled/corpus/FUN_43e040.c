/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43e040; label: FUN_0043e040
 */

void FUN_0043e040(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 local_4cc [4];
  undefined1 *local_4c8;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined1 local_214 [332];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_4cc;
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) && (param_3 != (undefined4 *)0x0)) {
    _memset(local_4cc,0,0x2b8);
    _memset(local_214,0,0x210);
    local_470 = *param_2;
    local_46c = param_2[1];
    local_4c8 = local_214;
    local_468 = param_2[2];
    local_c8 = local_470;
    local_c4 = local_46c;
    local_c0 = local_468;
    FUN_0052f800(param_1,local_4cc,local_214,0xff,1);
    *param_3 = local_bc;
    param_3[1] = local_b8;
    param_3[2] = local_b4;
    param_3[3] = local_b0;
    param_3[4] = local_ac;
    param_3[5] = local_a8;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_a4;
      param_4[1] = local_a0;
      param_4[2] = local_9c;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_4cc);
  return;
}

