/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62d4a0; label: FUN_0062d4a0
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

