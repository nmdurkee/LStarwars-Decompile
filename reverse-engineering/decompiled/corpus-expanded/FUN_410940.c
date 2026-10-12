/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x410940; label: FUN_00410940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00410940(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (*(int *)(in_EAX + 0xd4) != 0) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0xd4) + 0x51c);
    if (iVar1 == -1) {
      *(undefined2 *)(in_EAX + 0x100) = 0xffff;
      *(undefined2 *)(in_EAX + 0x102) = 0;
      *(undefined4 *)(in_EAX + 0x104) = 0;
      return;
    }
    if (iVar1 == -2) {
      *(undefined2 *)(in_EAX + 0x100) = 0xfffe;
      *(undefined4 *)(in_EAX + 0x104) = 0;
      *(undefined2 *)(in_EAX + 0x102) = 1;
      return;
    }
    if (iVar1 == -3) {
      *(undefined2 *)(in_EAX + 0x100) = 0xfffd;
      *(undefined4 *)(in_EAX + 0x104) = 0;
      *(undefined2 *)(in_EAX + 0x102) = 1;
      return;
    }
    iVar2 = *(int *)(PTR_DAT_00802c54 + 0x511c) + 0x564d0;
    *(undefined2 *)(in_EAX + 0x102) = 0;
    *(undefined2 *)(in_EAX + 0x100) = 0xffff;
    iVar3 = 0;
    while ((*(int *)(iVar2 + 0x110) == 0 || (*(int *)(iVar2 + 0x108) != iVar1))) {
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x130;
      if (0x5f < iVar3) {
        return;
      }
    }
    *(short *)(in_EAX + 0x100) = (short)iVar1;
    *(int *)(in_EAX + 0x104) = iVar2;
    *(undefined2 *)(in_EAX + 0x102) = 1;
  }
  return;
}

