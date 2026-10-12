/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49b150; label: FUN_0049b150
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b150(int param_1,undefined4 param_2)

{
  short sVar1;
  
  _DAT_007fc220 = 200;
  _DAT_0087b91c = 0x14;
  if (*(float *)(param_1 + 0x784) * _DAT_007fc048 <= *(float *)(param_1 + 0x77c)) {
    return;
  }
  if (*(float *)(param_1 + 0x77c) < *(float *)(param_1 + 0x784) * 0.5 * 0.5) {
    FUN_006e6b90();
    sVar1 = FUN_006e6b90();
    FUN_005b4dd0(param_2,(int)sVar1);
  }
  FUN_006e6b90();
  sVar1 = FUN_006e6b90();
  FUN_005b5240(param_2,(int)sVar1);
  return;
}

