/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x584640; label: FUN_00584640
 */

int FUN_00584640(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_004fc900("redirect");
  if (iVar1 != 0) {
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      iVar2 = FUN_0054be70(*(undefined4 *)(iVar1 + 0x50c),*(undefined4 *)(iVar1 + 0x50c),1);
      if ((iVar2 != 0) && (iVar2 = FUN_004f7fb0(iVar1), iVar2 != 0)) {
        iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"txt_file");
        if (iVar2 == 0) {
          if (((iVar3 == 0) && (iVar2 = FUN_004f7fb0(iVar1), iVar2 != 0)) &&
             (iVar2 = FUN_004f1ff0(*(undefined4 *)(iVar1 + 0x510)), iVar2 < param_2)) {
            FUN_004f1f10(param_1,*(undefined4 *)(iVar1 + 0x510));
            iVar3 = 1;
          }
        }
        else if (iVar3 != 0) {
          FUN_004fa300(iVar1);
          return 2;
        }
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
  }
  return iVar3;
}

