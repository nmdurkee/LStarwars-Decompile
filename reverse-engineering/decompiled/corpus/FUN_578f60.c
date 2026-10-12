/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578f60; label: FUN_00578f60
 */

void FUN_00578f60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004fc900("levelbeforeload",param_2,0xffff);
  if (iVar1 != 0) {
    DAT_00951b74 = param_1;
    FUN_004f1160(iVar1,&PTR_s_mipmapmode_00803bb8,param_3);
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      iVar2 = FUN_004f7fb0(iVar1);
      if (iVar2 != 0) {
        FUN_004fa020(iVar1);
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
  }
  return;
}

