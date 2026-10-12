/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce020; label: FUN_004ce020
 */

void FUN_004ce020(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0x4680) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar2 = FUN_004fc900("teleports",param_2,0xffff), iVar2 != 0)) {
    uVar4 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar4;
    *(uint *)(param_1 + 0x4680) = uVar4;
    FUN_004f10e0(iVar2,&PTR_s_spline_007fd1e8);
    bVar1 = false;
    iVar3 = FUN_004fc5b0(iVar2);
    while (iVar3 != 0) {
      iVar3 = FUN_004f7fb0(iVar2);
      if (iVar3 != 0) {
        if (bVar1) {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"teleport_end");
          if (iVar3 == 0) {
            bVar1 = false;
            iVar3 = FUN_004f1ff0(DAT_00880608);
            if (iVar3 == 0) {
              FUN_004f1f10(DAT_00880608,PTR_DAT_007fd1e4);
              FUN_004f1e80(DAT_00880608,"TeleportNoSpline!");
              FUN_0055aa60(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_007fd1e4,DAT_00880608,
                           DAT_00880608,0x40);
            }
            if (*(int *)(uVar4 + 0x40) != 0) {
              uVar4 = uVar4 + 0xfc;
              *(int *)(param_1 + 0x4684) = *(int *)(param_1 + 0x4684) + 1;
            }
          }
          else {
            FUN_004fa020(iVar2);
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"teleport_start");
          if (iVar3 == 0) {
            bVar1 = true;
            DAT_00880610 = param_1;
            DAT_00880608 = uVar4;
            FUN_004f1f10(uVar4,&DAT_007516c0);
            *(undefined4 *)(uVar4 + 0x44) = 0x40a00000;
            *(undefined1 *)(uVar4 + 0x4e) = 1;
            *(undefined4 *)(uVar4 + 0x40) = 0;
            *(undefined4 *)(uVar4 + 0x48) = 0;
            *(undefined2 *)(uVar4 + 0x4c) = 0;
            *(undefined1 *)(uVar4 + 0x4f) = 0;
            *(undefined4 *)(uVar4 + 0x50) = 0;
            *(undefined4 *)(uVar4 + 0x54) = 0;
            *(undefined4 *)(uVar4 + 0x58) = 0;
            *(undefined4 *)(uVar4 + 0x5c) = 0;
            *(undefined4 *)(uVar4 + 0x60) = 0;
            *(undefined4 *)(uVar4 + 100) = 0;
            *(undefined4 *)(uVar4 + 0x68) = 0;
            *(undefined4 *)(uVar4 + 0x6c) = 0;
            *(undefined4 *)(uVar4 + 0x70) = 0;
          }
        }
      }
      iVar3 = FUN_004fc5b0(iVar2);
    }
    FUN_004fa300(iVar2);
    if (0 < *(int *)(param_1 + 0x4684)) {
      *(uint *)(param_1 + 0x104) = uVar4 + 0xf & 0xfffffff0;
      return;
    }
    *(undefined4 *)(param_1 + 0x4680) = 0;
  }
  return;
}

