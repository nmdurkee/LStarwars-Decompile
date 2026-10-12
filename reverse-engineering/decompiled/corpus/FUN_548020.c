/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x548020; label: FUN_00548020
 */

void FUN_00548020(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 1) {
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) {
      return;
    }
    iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x16e);
  }
  else if (param_2 == 2) {
    iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x170);
  }
  else if (param_2 == 3) {
    iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x172);
  }
  else if (param_2 == 4) {
    iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x174);
  }
  else {
    if (*(char *)(param_1 + 0x286) != '\0') {
      return;
    }
    if (*(char *)(param_1 + 0x287) != '\0') {
      return;
    }
    iVar1 = FUN_0055f450();
    uVar2 = *(uint *)(*(int *)(iVar1 + 0x128) + 100) & 0x1000;
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x10) == 0) {
      if (param_2 != 0) {
        return;
      }
      if (uVar2 == 0) {
        iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x166);
      }
      else {
        iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x168);
      }
    }
    else if (uVar2 == 0) {
      iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x16a);
    }
    else {
      iVar1 = (int)*(short *)(PTR_DAT_008020bc + 0x16c);
    }
  }
  if (iVar1 != -1) {
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) &&
       ((*(uint *)(param_1 + 0xeec) & 0x8000000) == 0)) {
      FUN_00681eb0(iVar1,param_1 + 0x19c,0x3f000000);
      return;
    }
    FUN_00681e90(iVar1,param_1 + 0x19c);
  }
  return;
}

