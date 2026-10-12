/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60eb10; label: FUN_0060eb10
 */

void FUN_0060eb10(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(in_ECX + 0x2140);
  if (iVar5 != 0) {
    piVar2 = (int *)0x0;
    if (iVar5 == 1) {
      piVar2 = (int *)&DAT_029005fc;
    }
    if (iVar5 == 2) {
      piVar2 = (int *)&DAT_029003dc;
    }
    if (iVar5 == 3) {
      piVar2 = (int *)(*(int *)(in_ECX + 0x110e0) + 0xa0);
    }
    if (piVar2 != (int *)0x0) {
LAB_0060ebf9:
      (**(code **)(*piVar2 + 4))
                (*(undefined4 *)(in_ECX + 0x2144),*(undefined4 *)(in_ECX + 0x2148),
                 *(undefined4 *)(in_ECX + 0x214c),*(undefined4 *)(in_ECX + 0x2150),0);
      return;
    }
    iVar1 = 4;
    for (iVar3 = *(int *)(*(int *)(in_ECX + 0x110e0) + 0x94); iVar4 = iVar1, iVar3 != 0;
        iVar3 = *(int *)(iVar3 + 4)) {
      iVar4 = iVar1 + 1;
      if (iVar5 == iVar1) {
        piVar2 = (int *)(iVar3 + 0x10);
        if (piVar2 != (int *)0x0) goto LAB_0060ebf9;
        break;
      }
      iVar1 = iVar4;
    }
    iVar3 = 0;
    iVar5 = iVar4;
    if (0 < DAT_02973bac) {
      do {
        iVar1 = FUN_006be7f0(iVar3);
        iVar4 = iVar5;
        if ((*(int *)(iVar1 + 0x14) != 0) && (iVar4 = iVar5 + 1, *(int *)(in_ECX + 0x2140) == iVar5)
           ) {
          piVar2 = *(int **)(in_ECX + 0x1105c + iVar3 * 4);
          if (piVar2 != (int *)0x0) goto LAB_0060ebf9;
          break;
        }
        iVar3 = iVar3 + 1;
        iVar5 = iVar4;
      } while (iVar3 < DAT_02973bac);
    }
    piVar2 = *(int **)(in_ECX + -0xc);
    if (piVar2 != (int *)0x0) {
      do {
        if (*(int *)(in_ECX + 0x2140) == iVar4) {
          piVar2 = piVar2 + 0xc;
          if (piVar2 != (int *)0x0) goto LAB_0060ebf9;
          break;
        }
        piVar2 = (int *)*piVar2;
        iVar4 = iVar4 + 1;
      } while (piVar2 != (int *)0x0);
    }
    *(undefined4 *)(in_ECX + 0x2140) = 1;
  }
  return;
}

