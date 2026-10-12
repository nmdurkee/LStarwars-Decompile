/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62d4a0; label: FUN_0062d4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062d4a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_004f1ff0(param_3);
  DAT_029130f0 = param_1;
  DAT_029130f4 = param_2;
  if (iVar1 < 0x40) {
    FUN_004f1f10(s_chars_commonanims__0080fb98,param_3);
    if (*(char *)(iVar1 + -1 + param_3) != '\\') {
      FUN_004f1e80(s_chars_commonanims__0080fb98,&DAT_0075a204);
    }
  }
  return;
}

