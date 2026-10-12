/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x654fa0; label: FUN_00654fa0
 */

void FUN_00654fa0(void)

{
  int iVar1;
  int iVar2;
  float local_8;
  undefined2 local_4;
  
  DAT_00810964 = DAT_00810964 + -1;
  if (DAT_00810964 < 1) {
    DAT_00810964 = 6;
    iVar2 = DAT_029620c0;
    if ((&DAT_0292fd30)[DAT_029620c0] == 0) {
      do {
        iVar2 = iVar2 + 1;
        if (4 < iVar2) {
          iVar2 = 0;
        }
      } while ((iVar2 != DAT_029620c0) && ((&DAT_0292fd30)[iVar2] == 0));
      DAT_029620c0 = iVar2;
      if ((&DAT_0292fd30)[iVar2] == 0) {
        DAT_00810964 = 6;
        return;
      }
    }
    for (iVar2 = (&DAT_0292fd30)[DAT_029620bc]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5c)) {
      iVar1 = *(int *)(iVar2 + 8);
      if (iVar1 != 0) {
        if (*(char *)(iVar1 + 0x2f8) == '\0') {
          *(undefined2 *)(iVar2 + 0x60) = *(undefined2 *)(iVar1 + 0x328);
        }
        else {
          local_8 = (float)*(ushort *)(iVar1 + 0x328) + *(float *)(iVar1 + 0x31c) * 25.0;
          if (65535.0 < local_8) {
            local_8 = 65535.0;
          }
          local_4 = (undefined2)(int)ROUND(local_8);
          *(undefined2 *)(iVar2 + 0x60) = local_4;
        }
      }
    }
  }
  return;
}

