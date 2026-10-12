/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x488660; label: FUN_00488660
 */

void FUN_00488660(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((((param_1 != 0) && ((*(uint *)(param_1 + 0x1fc) & 1) != 0)) && (param_2 != 0)) &&
      (((*(byte *)(param_2 + 0x1fc) & 1) != 0 && (*(int *)(param_1 + 0xcd0) == 0)))) &&
     (*(int *)(param_2 + 0xcd0) == 0)) {
    if ((*(byte *)(param_1 + 0xef4) & 2) == 0) {
      if (((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234) || (DAT_009253a4 != 0)) ||
         (uVar2 = 1, -1 < (char)*(uint *)(param_1 + 0x1fc))) {
        uVar2 = param_3;
      }
      FUN_0059f990(param_2);
      iVar1 = FUN_004876a0(param_1,param_2,1,uVar2,1);
    }
    else {
      iVar1 = FUN_004873d0(param_1,param_2,param_3,1);
    }
    if (iVar1 == 2) {
      *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) | 0xc;
      *(undefined4 *)(param_1 + 0x7c0) = 0x3f800000;
      *(int *)(param_1 + 0x7c8) = param_2;
    }
  }
  return;
}

