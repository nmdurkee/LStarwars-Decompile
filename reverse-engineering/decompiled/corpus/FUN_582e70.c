/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x582e70; label: FUN_00582e70
 */

int FUN_00582e70(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_4;
  
  if ((param_4 < 0) || (*(int *)(PTR_PTR_008040bc + 4) <= param_4)) {
    if ((PTR_DAT_00802c54 == (undefined *)0x0) ||
       ((iVar2 = *(int *)(PTR_PTR_008040bc + 4), param_4 < iVar2 || (iVar2 + 8 <= param_4)))) {
      puVar1 = (undefined *)0x0;
    }
    else {
      puVar1 = PTR_DAT_00802c54 + (param_4 - iVar2) * 0xa4 + 0x4b14;
    }
  }
  else {
    puVar1 = (undefined *)(param_4 * 0xa4 + *(int *)PTR_PTR_008040bc);
  }
  if ((puVar1 != (undefined *)0x0) && (iVar2 = FUN_005cfac0(puVar1 + 0x68), iVar2 != 0)) {
    iVar2 = FUN_0057fba0();
    if (iVar2 != 0) {
      if (param_1 == 0) {
        local_18 = 0xffff;
      }
      else {
        local_18 = (param_1 - DAT_0093d504) / 0x10d8 & 0xffff;
      }
      local_14 = iVar2;
      FUN_0053d5d0(0x20);
      FUN_0053d3d0(&local_18);
      iVar5 = local_c;
      if (local_c != 0) {
        iVar4 = local_c + local_4;
        FUN_004ef660(iVar4,param_2,0xc);
        if (local_10 != 0) {
          iVar3 = 3;
          do {
            FUN_00621190(iVar4);
            iVar4 = iVar4 + 4;
            iVar3 = iVar3 + -1;
            iVar2 = local_14;
          } while (iVar3 != 0);
        }
        iVar5 = iVar5 + local_4 + 0xc;
        FUN_004ef660(iVar5,param_3,0x40);
        if (local_10 != 0) {
          iVar4 = 0x10;
          do {
            FUN_00621190(iVar5);
            iVar5 = iVar5 + 4;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        local_4 = local_4 + 0x4c;
      }
      FUN_00580d50(&param_4);
      FUN_00580d50(&stack0x00000014);
      FUN_00582470(iVar2,&local_10);
      if (local_c != 0) {
        if (*(uint *)(local_c + 0x4b0) < 2) {
          *(undefined4 *)(local_c + 0x4b0) = 0;
          return iVar2;
        }
        *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
      }
    }
    return iVar2;
  }
  return 0;
}

