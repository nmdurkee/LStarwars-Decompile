/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57b200; label: FUN_0057b200
 */

void FUN_0057b200(int param_1)

{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_00578da0(*(undefined4 *)(param_1 + 0x510),&local_8);
    iVar1 = local_8;
    if (((local_8 != -1) && (local_8 * 0x130 + DAT_00951b78 == DAT_00951b94)) &&
       (DAT_00951bec != -1)) {
      FUN_00573520(DAT_00951bec * 0x9c + DAT_00951354,&local_4);
      iVar1 = local_4;
      if (local_4 == -1) {
        iVar1 = local_8;
      }
    }
    *(short *)(DAT_00951c4c + 0xec) = (short)iVar1;
  }
  return;
}

