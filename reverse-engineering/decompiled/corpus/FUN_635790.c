/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635790; label: FUN_00635790
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00635790(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_006355f0(param_1,param_2);
  if (-1 < iVar1) {
    iVar2 = FUN_00635660();
    if (-1 < iVar2) {
      puVar3 = (undefined4 *)FUN_00547560(_DAT_02913970,iVar2);
      puVar5 = (undefined4 *)(iVar1 * 0x8c + 4 + param_1);
      for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar3 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar3 = puVar3 + 1;
      }
      return iVar2;
    }
  }
  return -1;
}

