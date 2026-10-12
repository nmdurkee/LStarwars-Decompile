/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547f30; label: FUN_00547f30
 */

void FUN_00547f30(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
  if ((uVar1 & 0x40) == 0) {
    if ((uVar1 & 8) == 0) {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x158);
    }
    else {
      switch(param_2) {
      case 0:
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x15c);
        break;
      case 1:
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x15e);
        break;
      case 2:
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x164);
        break;
      case 3:
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x160);
        break;
      case 4:
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x162);
        break;
      default:
        goto switchD_00547f5e_default;
      }
    }
  }
  else {
    iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x15a);
  }
  if (iVar2 != -1) {
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) ||
       ((*(uint *)(param_1 + 0xeec) & 0x8000000) != 0)) {
      FUN_00681e90();
      return;
    }
    FUN_00681eb0(iVar2,param_1 + 0x19c,0x3f000000);
  }
switchD_00547f5e_default:
  return;
}

