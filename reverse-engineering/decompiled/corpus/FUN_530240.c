/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x530240; label: FUN_00530240
 */

void FUN_00530240(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xdfffffff;
  if ((DAT_00923900 != (code *)0x0) &&
     (iVar2 = (*DAT_00923900)(param_1,param_2,param_3), iVar2 != 0)) {
    *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x80080000;
    return;
  }
  if ((*(int *)(param_2 + 0x158) != 0) && (*(int *)(param_2 + 0x15c) != 0)) {
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_3 + 0x5c);
    *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
    uVar1 = *(undefined4 *)(param_3 + 100);
    *(undefined4 *)(param_2 + 0x110) = 0;
    *(undefined4 *)(param_2 + 0x10c) = uVar1;
    switch(*(uint *)(param_2 + 0x1e8) & 7) {
    case 1:
      FUN_0051d7b0(param_1,param_2,param_3,param_4);
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
      return;
    case 2:
      FUN_00530150(param_1,param_2,param_3,param_4);
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
      return;
    case 3:
      FUN_0051f0a0(param_1,param_2,param_3,param_4);
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
      return;
    case 4:
      FUN_0051f1b0(param_1,param_2,param_3,param_4);
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
      return;
    case 6:
      FUN_0051e8c0(param_1,param_2,param_3,param_4);
      *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
      return;
    case 7:
      FUN_0051f600(param_1,param_2,param_3,param_4);
    }
    *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
    return;
  }
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_3 + 0x5c);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_3 + 0x60);
  uVar1 = *(undefined4 *)(param_3 + 100);
  *(undefined4 *)(param_2 + 0x110) = 0;
  uVar3 = *(uint *)(param_2 + 0x1e8) & 7;
  *(undefined4 *)(param_2 + 0x10c) = uVar1;
  if (((uVar3 == 1) || (uVar3 == 7)) || (uVar3 == 6)) {
    *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(param_2 + 0x1c0);
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_2 + 0x1b4);
    *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_2 + 0x1b8);
    *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_2 + 0x1bc);
  }
  *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xfffffff8;
  return;
}

