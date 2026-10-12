/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d940; label: FUN_0053d940
 */

void FUN_0053d940(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int unaff_retaddr;
  undefined4 uVar3;
  uint uStack_1c;
  uint uStack_18;
  int iStack_14;
  int local_10;
  int iStack_c;
  int iStack_8;
  
  FUN_0053d5d0(0x20);
  if ((DAT_00876d88 == (code *)0x0) || (iVar1 = (*DAT_00876d88)(), iVar1 != 0)) {
    uStack_18 = (**(code **)(*in_ECX + 0x30))(param_2);
    uStack_18 = uStack_18 & 0xffff;
    uStack_1c = (uint)*(ushort *)(*(int *)(unaff_retaddr + 0x10) + 10);
    param_1 = CONCAT31(param_1._1_3_,1);
    iVar1 = iStack_8;
    if (local_10 != 0) {
      FUN_004ef660(iStack_8 + local_10,&param_1,1);
      FUN_004ef660(iStack_8 + 1 + local_10,&stack0xffffffe2,1);
      iVar1 = iStack_8 + 2 + local_10;
      FUN_004ef660(iVar1,&uStack_1c,2);
      if (iStack_14 != 0) {
        FUN_00621180(iVar1);
      }
      iVar1 = iStack_8 + 4 + local_10;
      FUN_004ef660(iVar1,&uStack_18,2);
      if (iStack_14 != 0) {
        FUN_00621180(iVar1);
      }
      FUN_004ef660(iStack_8 + 6 + local_10,&stack0xffffffe3,1);
      iVar1 = iStack_8 + 7;
    }
    param_1 = 0;
    if (0 < *(int *)(unaff_retaddr + 0xc)) {
      do {
        uVar3 = *(undefined4 *)(*(int *)(unaff_retaddr + 8) + param_1 * 4);
        if (local_10 != 0) {
          iVar2 = FUN_004f1ff0(uVar3);
          *(undefined1 *)(iVar1 + local_10) = (char)iVar2;
          FUN_004ef660((undefined1 *)(iVar1 + local_10) + 1,uVar3,iVar2);
          iVar1 = iVar1 + 1 + iVar2;
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)(unaff_retaddr + 0xc));
    }
    uVar3 = 10;
    iVar2 = local_10;
    if (local_10 == 0) {
      FUN_0060f2d0(iStack_14,0,iStack_c,iVar1,10);
    }
    else {
      *(int *)(local_10 + 0x4b0) = *(int *)(local_10 + 0x4b0) + 1;
    }
    FUN_0060f190(iStack_14,iVar2,iStack_c,iVar1,uVar3);
    if (local_10 != 0) {
      if (1 < *(uint *)(local_10 + 0x4b0)) {
        *(uint *)(local_10 + 0x4b0) = *(uint *)(local_10 + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(local_10 + 0x4b0) = 0;
    }
  }
  else if (iStack_c != 0) {
    if (*(uint *)(iStack_c + 0x4b0) < 2) {
      *(undefined4 *)(iStack_c + 0x4b0) = 0;
      return;
    }
    *(uint *)(iStack_c + 0x4b0) = *(uint *)(iStack_c + 0x4b0) - 1;
    return;
  }
  return;
}

