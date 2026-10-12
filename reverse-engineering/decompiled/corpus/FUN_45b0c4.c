/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45b0c4; label: FUN_0045b0c4
 */

void FUN_0045b0c4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EBX;
  uint *puVar4;
  int iStack00000004;
  int in_stack_00000010;
  
  DAT_00876dd8 = 0;
  DAT_00876db4._0_2_ = 0;
  puVar4 = (uint *)(in_stack_00000010 + 0x84);
  iStack00000004 = 2;
  do {
    uVar1 = *puVar4;
    if (uVar1 == 0) {
LAB_0045b14b:
      DAT_00876dd8 = DAT_00876dd8 + 1;
    }
    else {
      uVar2 = 100;
      if (99 < uVar1) {
        do {
          uVar2 = uVar2 * 10;
        } while (uVar2 <= uVar1);
      }
      uVar3 = FUN_006e6b90();
      uVar2 = uVar1;
      if ((uVar3 <= uVar1) && (uVar2 = uVar3, (int)uVar3 < 1)) {
        uVar2 = 1;
      }
      *puVar4 = uVar1 - uVar2;
      FUN_005533f0(*(undefined4 *)(in_stack_00000010 + 0x1c),uVar2,(int)uVar2 >> 0x1f,0);
      if (*puVar4 == 0) goto LAB_0045b14b;
    }
    puVar4 = puVar4 + 1;
    iStack00000004 = iStack00000004 + -1;
    if (iStack00000004 == 0) {
      FUN_00681f40("PickupCoin",0);
      if (DAT_00876dd8 == 2) {
        *(undefined4 *)(unaff_EBX + 0x14) = 3;
        *(undefined4 *)(unaff_EBX + 0x18) = 0;
        *(undefined4 *)(unaff_EBX + 0x1c) = 0x3f800000;
        if (*(int *)(in_stack_00000010 + 0x90) + *(int *)(in_stack_00000010 + 0x8c) == 0) {
          FUN_00547930(0x32,0,0);
        }
        else {
          FUN_00681f40("Shop_BuyCheat",0);
        }
        FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      }
      return;
    }
  } while( true );
}

