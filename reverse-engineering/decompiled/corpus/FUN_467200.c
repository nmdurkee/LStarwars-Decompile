/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467200; label: FUN_00467200
 */

void FUN_00467200(int param_1)

{
  undefined4 *puVar1;
  byte *pbVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x58) = 0x3f800000;
  *(uint *)(unaff_ESI + 0xa0) = *(uint *)(unaff_ESI + 0xa0) & 0xffe2049f | 3;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  if (*(int *)(unaff_ESI + 0x28) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 0x28) + 0x18); puVar1 != (undefined4 *)0x0;
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
            *(uint *)(unaff_ESI + 0xa0) = *(uint *)(unaff_ESI + 0xa0) | 0x100;
          }
        }
      }
    }
    if (*(int *)(param_1 + 0x13c) == 0) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = FUN_005d92b0(*(int *)(param_1 + 0x13c),unaff_ESI + 0x10);
    }
    *(undefined2 *)(unaff_ESI + 0x80) = uVar4;
    FUN_005a1480(*(undefined4 *)(unaff_ESI + 0x28),&DAT_0093b0cc);
    *(undefined4 *)(unaff_ESI + 0x68) = 0x3f800000;
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x10);
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x14);
    *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(unaff_ESI + 0x18);
    FUN_005a0c20(*(undefined4 *)(unaff_ESI + 0x28),(undefined4 *)(unaff_ESI + 0x1c),unaff_ESI + 0x68
                 ,2,1,1);
    FUN_005a0670();
    return;
  }
  return;
}

