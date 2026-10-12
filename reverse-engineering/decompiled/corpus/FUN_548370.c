/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x548370; label: FUN_00548370
 */

void FUN_00548370(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xe0);
  if (sVar1 == -1) {
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x44002010) != 0) {
      return;
    }
    if ((*(uint *)(param_1 + 0xef4) & 0x800) == 0) {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x182);
    }
    else {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x180);
    }
  }
  else {
    iVar2 = (int)sVar1;
  }
  if (iVar2 != -1) {
    FUN_00681e90(iVar2,param_1 + 0x80);
  }
  return;
}

