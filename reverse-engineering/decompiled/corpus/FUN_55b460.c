/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b460; label: FUN_0055b460
 */

void FUN_0055b460(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_4;
  
  if ((DAT_0093b27c != 0) && (local_4 = 0, 0 < *(int *)(DAT_029130e4 + 0x10))) {
    do {
      iVar1 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x18) + local_4 * 0x54);
      if ((*(int *)(iVar1 * 0x10 + DAT_0093b27c) == 0) &&
         ((((*(byte *)(iVar1 * 0x4c + 0x40 + DAT_0093b274) & 1) != 0 &&
           (iVar1 = FUN_00630680(param_1,iVar1,&local_4), iVar1 != 0)) &&
          (*(short *)(param_1 + 2 + local_4 * 4) != 0)))) {
        FUN_0055b300(param_2,param_3);
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(DAT_029130e4 + 0x10));
  }
  return;
}

