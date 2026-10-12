/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x501030; label: FUN_00501030
 */

void FUN_00501030(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x50) + 0xc);
  if (sVar1 == 4) {
    ppuVar5 = (undefined **)&DAT_008008b4;
  }
  else {
    ppuVar5 = &PTR_DAT_008008b8;
    if (sVar1 != 8) {
      ppuVar5 = (undefined **)&DAT_008008bc;
    }
  }
  iVar3 = FUN_005ce7e0(*(int *)(param_1 + 0x50),0,param_2,ppuVar5);
  iVar2 = *(int *)(param_1 + 0x50);
  if (*(short *)(iVar2 + 0xc) == 4) {
    if (*(float *)(iVar3 + 0xc) < 0.0) {
      FUN_006e6b90();
      return;
    }
    FUN_006e6b90();
    return;
  }
  iVar4 = FUN_006e6b90();
  if ((iVar4 != 0) && (param_3 != (undefined4 *)0x0)) {
    *param_3 = *(undefined4 *)(iVar3 + 0x18);
  }
  if (param_4 != (undefined4 *)0x0) {
    if (*(ushort *)(iVar2 + 0xc) < 9) {
      *param_4 = 0x3f800000;
      return;
    }
    *param_4 = *(undefined4 *)(iVar3 + 0x20);
  }
  return;
}

