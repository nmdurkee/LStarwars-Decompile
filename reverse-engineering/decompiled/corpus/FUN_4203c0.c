/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x4203c0; label: FUN_004203c0
 */

bool FUN_004203c0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return true;
  }
  FUN_006d5db0();
  iVar1 = FUN_006d9120(0,0x1a,local_4,local_8,0);
  if (iVar1 < 0) {
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + -1;
    return *(int *)(in_ECX + 0x28) == 0;
  }
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x2c);
  return *(int *)(in_ECX + 0x2c) == 0;
}

