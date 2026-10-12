/* Ghidra pseudocode, not original source.
 * ev_45200ba16e8ef520c819c849d12b8874968ca721432c6a61fa3b24bce95adf30
 * Entry: 0x6968c0; label: FUN_006968c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006968c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    iVar1 = FUN_00694b80(param_1);
    if (iVar1 != 0) {
      FUN_00694be0(iVar1);
    }
    return iVar1;
  }
  return 0;
}

