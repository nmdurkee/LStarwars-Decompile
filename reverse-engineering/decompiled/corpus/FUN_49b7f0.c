/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49b7f0; label: FUN_0049b7f0
 */

void FUN_0049b7f0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x7b5) == '*') {
    FUN_0049b150(param_1,param_2);
  }
  else if (*(char *)(param_1 + 0x7b5) == ':') {
    FUN_006e6b90();
    iVar1 = FUN_006e6b90();
    if (*(char *)(param_1 + 0x7b3) == '\0') {
      FUN_005b5240(param_2,iVar1);
    }
    else {
      FUN_005b5240(param_2,-iVar1);
    }
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f1afc) {
    FUN_005b4dd0(param_2,0xffffc000);
    FUN_005b5060(param_2,0x8000);
  }
  return;
}

