/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617540; label: FUN_00617540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00617540(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = in_ECX + 4;
  while( true ) {
    if (iVar2 == in_ECX + 0x1604) {
      return 0;
    }
    if ((((*(int *)(iVar2 + 0xac) != 0) && (iVar1 = FUN_00617180(param_2), iVar1 == 0)) &&
        (iVar1 = FUN_004f8b10(iVar2 + 0xc,param_1), iVar1 == 0)) &&
       ((param_3 == 0 || (*(int *)(iVar2 + 4) == param_3)))) break;
    iVar2 = iVar2 + 0xb0;
  }
  return iVar2;
}

