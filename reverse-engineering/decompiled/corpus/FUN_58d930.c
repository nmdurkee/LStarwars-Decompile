/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58d930; label: FUN_0058d930
 */

void FUN_0058d930(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if ((cVar1 != -1) && ((cVar1 == DAT_00802864 || (cVar1 == DAT_00802868)))) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  if (((param_2 != 0) && (*(float *)(param_1 + 0xd3c) == 1.0)) &&
     (*(char *)(param_1 + 0xe33) != '\x02')) {
    iVar4 = FUN_0062f1a0(param_1 + 8);
    if (((iVar4 == -1) ||
        (iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 8), *(int *)(iVar2 + iVar4 * 4) == 0)) ||
       ((*(uint *)(*(int *)(iVar2 + iVar4 * 4) + 4) & 0x800) == 0)) {
      uVar3 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
      if ((uVar3 & 8) == 0) {
        if (-1 < (char)uVar3) goto LAB_0058d9f7;
        uVar7 = 1;
        uVar5 = 0;
        uVar6 = 0x42;
      }
      else {
        if ((*(char *)(param_1 + 0x280) == -1) && (DAT_00955594 != 0)) goto LAB_0058d9f7;
        uVar7 = 1;
        uVar5 = FUN_00547820(param_1,1);
        uVar6 = 0x3d;
      }
      FUN_00547930(uVar6,param_1 + 0x80,uVar5,uVar7);
    }
  }
LAB_0058d9f7:
  *(undefined1 *)(param_1 + 0xe33) = 2;
  *(undefined4 *)(param_1 + 0xd40) = 0x40a00000;
  return;
}

