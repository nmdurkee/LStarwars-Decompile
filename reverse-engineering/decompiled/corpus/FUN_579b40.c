/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579b40; label: FUN_00579b40
 */

void FUN_00579b40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004fc900("levelafterload",param_2,0xffff);
  if (iVar1 != 0) {
    DAT_00951b74 = param_1;
    FUN_004f1160(iVar1,&PTR_s_backr_00803be0,param_3);
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      iVar2 = FUN_004f7fb0(iVar1);
      if (iVar2 != 0) {
        FUN_004fa020(iVar1);
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
    if (*(byte *)(param_1 + 0xca) < *(byte *)(param_1 + 0xc9)) {
      *(byte *)(param_1 + 0xc9) = *(byte *)(param_1 + 0xca);
    }
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 1;
  }
  return;
}

