/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c3a0; label: FUN_0043c3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0043c3a0(int param_1,int param_2)

{
  int iVar1;
  float local_c [3];
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(byte *)(param_2 + 0x138) != 0xff)) {
    if ((*(byte *)(param_2 + 0x1ec) & 8) == 0) {
      iVar1 = (uint)*(byte *)(param_2 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
      local_c[0] = (float)((*(byte *)(param_2 + 0x149) + 1) / 2) * *(float *)(iVar1 + 0x5c);
      if ((*(byte *)(param_2 + 0x149) & 1) != 0) {
        local_c[0] = -local_c[0];
      }
      local_c[1] = 0.0;
      local_c[2] = (float)*(byte *)(param_2 + 0x14a) * -*(float *)(iVar1 + 0x60);
      FUN_005b3620(local_c,local_c,*(undefined4 *)(iVar1 + 0x2c));
      FUN_005b37d0(param_2 + 0xf8,local_c,iVar1 + 0x20);
      *(uint *)(param_2 + 0x1ec) = *(uint *)(param_2 + 0x1ec) | 8;
    }
    return param_2 + 0xf8;
  }
  return 0;
}

