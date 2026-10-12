/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x5576c0; label: FUN_005576c0
 */

void FUN_005576c0(int param_1)

{
  undefined4 *puVar1;
  byte *pbVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 0x9c) = *(uint *)(unaff_ESI + 0x9c) & 0xffffff03;
  *(undefined4 *)(unaff_ESI + 0x48) = 0x3f800000;
  *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) & 0xfffffff3 | 3;
  if (*(int *)(unaff_ESI + 0x34) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 0x34) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      pbVar2 = (byte *)puVar1[9];
      pbVar2[2] = 0xff;
      pbVar2[3] = 0xff;
      if ((*(int *)(param_1 + 0x295c) != 0) && ((*pbVar2 & 1) == 0)) {
        iVar5 = FUN_005cfac0(puVar1 + 1);
        if (iVar5 != 0) {
          uVar6 = FUN_005cffb0(puVar1 + 1);
          sVar3 = FUN_0067c760(uVar6);
          *(short *)(pbVar2 + 2) = sVar3;
          if (sVar3 != -1) {
            *(uint *)(unaff_ESI + 0x9c) = *(uint *)(unaff_ESI + 0x9c) | 0x10;
          }
        }
      }
      if ((*pbVar2 & 2) != 0) {
        *(uint *)(unaff_ESI + 0x9c) = *(uint *)(unaff_ESI + 0x9c) | 0x20;
      }
    }
    if (*(int *)(param_1 + 0x13c) == 0) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = FUN_005d92b0(*(int *)(param_1 + 0x13c),unaff_ESI + 0x10);
    }
    *(undefined2 *)(unaff_ESI + 0x86) = uVar4;
    if ((*(byte *)(unaff_ESI + 0x68) & 2) != 0) {
      FUN_005a0b00(*(undefined4 *)(unaff_ESI + 0x34),unaff_ESI + 0x1c,0,1,1);
    }
    FUN_005a0670(*(undefined4 *)(unaff_ESI + 0x34));
    *(undefined4 *)(unaff_ESI + 0x58) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x28) = *(undefined4 *)(unaff_ESI + 0x10);
    *(undefined4 *)(unaff_ESI + 0x2c) = *(undefined4 *)(unaff_ESI + 0x14);
    *(undefined4 *)(unaff_ESI + 0x30) = *(undefined4 *)(unaff_ESI + 0x18);
    FUN_005a0c20(*(undefined4 *)(unaff_ESI + 0x34),(undefined4 *)(unaff_ESI + 0x28),unaff_ESI + 0x58
                 ,2,1,1);
  }
  return;
}

