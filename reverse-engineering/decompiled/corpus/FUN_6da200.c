/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6da200; label: FUN_006da200
 */

void FUN_006da200(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined1 local_14 [20];
  
  iVar3 = DAT_02975144;
  iVar4 = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  DAT_029755dc = 0;
  puVar5 = (undefined1 *)(iVar3 + 0x4e61);
  do {
    iVar2 = XInputGetCapabilities(iVar4,1,local_14);
    if (iVar2 == 0) {
      *puVar5 = 1;
      FUN_006d47a0(local_14,puVar5 + -0x2d);
      puVar5[-3] = 1;
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
    }
    else {
      *(undefined4 *)(puVar5 + -0x2d) = 0;
      *puVar5 = 0;
      *(undefined4 *)(puVar5 + -0x29) = 0;
    }
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 0x17c;
  } while (iVar4 < 4);
  piVar6 = (int *)(iVar3 + 0x5428);
  iVar4 = 6;
  do {
    piVar1 = (int *)*piVar6;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1);
      piVar1 = (int *)*piVar6;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar6 = 0;
      }
    }
    piVar6[-1] = 0;
    *(undefined1 *)((int)piVar6 + 0x29) = 0;
    piVar6 = piVar6 + 0x5f;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (DAT_029765a4 != (int *)0x0) {
    (**(code **)(*DAT_029765a4 + 0x20))(DAT_029765a4);
    if (DAT_029765a4 != (int *)0x0) {
      (**(code **)(*DAT_029765a4 + 8))(DAT_029765a4);
      DAT_029765a4 = (int *)0x0;
    }
    puVar5 = (undefined1 *)(iVar3 + 0x5d39);
    iVar3 = 4;
    do {
      *(undefined4 *)(puVar5 + -0x29) = 0;
      *(undefined4 *)(puVar5 + -0x2d) = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 0x17c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  DAT_029755dc = 0;
  (**(code **)(**(int **)(in_ECX + 0x30) + 0x10))(*(int **)(in_ECX + 0x30),3,FUN_006d9df0,0,1);
  (**(code **)(**(int **)(in_ECX + 0x30) + 0x10))(*(int **)(in_ECX + 0x30),2,FUN_006d9df0,0,1);
  (**(code **)(**(int **)(in_ECX + 0x30) + 0x10))(*(int **)(in_ECX + 0x30),4,FUN_006d9df0,0,1);
  return;
}

