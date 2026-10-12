/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x6690c0; label: FUN_006690c0
 */

void FUN_006690c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_0292319c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_006690a0,"Gravity");
    if (DAT_0292319c != 0) {
      uVar2 = FUN_00625150(0,&local_10,0,&LAB_00662630,(float)DAT_00810ae8 * -10.0,
                           (float)DAT_00810ae8 * 20.0,*(undefined4 *)(iVar1 + 0xa0),"Gravity");
      FUN_00618e10(DAT_0292319c,uVar2);
      FUN_006279b0(param_1,DAT_0292319c);
      *(int *)(DAT_0292319c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0292319c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

