/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aba50; label: FUN_005aba50
 */

void FUN_005aba50(int param_1)

{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  
  *(ushort *)(in_EAX + 0x13a) = *(ushort *)(in_EAX + 0x13a) | 6;
  *(undefined1 *)(in_EAX + 0x12e) = *(undefined1 *)(in_EAX + 0x12f);
  *(undefined1 *)(in_EAX + 0x132) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  if (*(int *)(in_EAX + 0x18) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)(in_EAX + 0x18) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar6 = puVar1[9];
      if (*(char *)(iVar6 + 1) == '\x01') {
        *(undefined4 **)(in_EAX + 0x1c) = puVar1;
      }
      else if (*(char *)(iVar6 + 1) == '\x02') {
        *(undefined4 **)(in_EAX + 0x20) = puVar1;
      }
      *(undefined2 *)(iVar6 + 2) = 0xffff;
      if (*(int *)(param_1 + 0x295c) != 0) {
        iVar4 = FUN_005cfac0(puVar1 + 1);
        if (iVar4 != 0) {
          uVar5 = FUN_005cffb0(puVar1 + 1);
          sVar2 = FUN_0067c760(uVar5);
          *(short *)(iVar6 + 2) = sVar2;
          if (sVar2 != -1) {
            *(ushort *)(in_EAX + 0x13a) = *(ushort *)(in_EAX + 0x13a) | 0x200;
          }
        }
      }
    }
    if (*(int *)(param_1 + 0x13c) == 0) {
      uVar3 = 0xffff;
    }
    else {
      uVar3 = FUN_005d92b0(*(int *)(param_1 + 0x13c),in_EAX + 0x24);
    }
    *(undefined2 *)(in_EAX + 0x10e) = uVar3;
    if ((*(byte *)(in_EAX + 0x108) & 2) != 0) {
      puVar1 = (undefined4 *)(in_EAX + 0x30);
      *puVar1 = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0x2c);
      FUN_005a0b00(*(undefined4 *)(in_EAX + 0x18),puVar1,0,1,1);
      *(undefined4 *)(in_EAX + 0x3c) = *puVar1;
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(in_EAX + 0x34);
      *(undefined4 *)(in_EAX + 0x44) = *(undefined4 *)(in_EAX + 0x38);
    }
    if ((*(uint *)(in_EAX + 0x108) & 0x800) != 0) {
      *(undefined4 *)(in_EAX + 0xf0) = *(undefined4 *)(in_EAX + 0xec);
      *(undefined4 *)(in_EAX + 0x3c) = *(undefined4 *)(in_EAX + 0x30);
      *(undefined4 *)(in_EAX + 0x40) = *(undefined4 *)(in_EAX + 0x34);
      *(undefined4 *)(in_EAX + 0x44) = *(undefined4 *)(in_EAX + 0x38);
    }
    FUN_005a0670(*(undefined4 *)(in_EAX + 0x18));
    if ((((*(int *)(in_EAX + 0x1c) != 0) &&
         (iVar6 = FUN_005cfac0(*(int *)(in_EAX + 0x1c) + 4), iVar6 != 0)) &&
        (*(int *)(in_EAX + 0x20) != 0)) &&
       (iVar6 = FUN_005cfac0(*(int *)(in_EAX + 0x20) + 4), iVar6 != 0)) {
      uVar5 = FUN_005cfa20(*(int *)(in_EAX + 0x1c) + 4);
      uVar7 = FUN_005cfa20(*(int *)(in_EAX + 0x20) + 4);
      iVar6 = in_EAX + 0xa4;
      FUN_005b5a40(iVar6,uVar7);
      FUN_005b5430(iVar6,uVar5,iVar6);
    }
  }
  return;
}

