/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x432620; label: FUN_00432620
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00432620(int param_1,float param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(char *)(param_1 + 0x7b5) != '\x17') || (*(float *)(param_1 + 0x77c) < param_2)) {
    uVar2 = *(undefined4 *)(param_1 + 0xd30);
    FUN_0055e4a0(param_1,1);
    if (*(char *)(param_1 + 0x7b5) != '>') {
      FUN_0055e4e0(param_1 + 0x6c4);
      iVar1 = param_1 + 0x2c8;
      *(undefined4 *)(param_1 + 0xd30) = uVar2;
      *(undefined1 *)(param_1 + 0x7b5) = 0x17;
      iVar3 = FUN_0052c790(iVar1,"BeenDeactivated");
      if (iVar3 != 0) {
        FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1,iVar1,iVar1,_DAT_00925018);
      }
      if ((((param_3 == 0) || ((*(byte *)(*(int *)(param_3 + 0x54) + 4) & 0x40) == 0)) ||
          (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\x01')) ||
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x188) == 0)) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
        if ((*(int *)(iVar1 + 0x204) == 0) ||
           ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + 0x204) + 4) & 2) != 0)) {
          *(ushort *)(param_1 + 0x7aa) = (-(ushort)(*(int *)(iVar1 + 0x104) != 0) & 0x40) + 1;
        }
        else {
          *(undefined2 *)(param_1 + 0x7aa) = 0x81;
        }
      }
      else {
        *(undefined2 *)(param_1 + 0x7aa) = 0x62;
        param_2 = 4.0;
      }
      if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) != 0) {
        FUN_004aa200(param_1);
      }
      *(float *)(param_1 + 0x77c) = param_2;
      *(undefined4 *)(param_1 + 0x784) = 0;
      *(undefined1 *)(param_1 + 0x7b8) = 0;
      *(undefined4 *)(param_1 + 0x778) = 0;
      FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
      return 1;
    }
  }
  return 0;
}

