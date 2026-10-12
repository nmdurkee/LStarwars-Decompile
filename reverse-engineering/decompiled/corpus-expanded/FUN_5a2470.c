/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2470; label: FUN_005a2470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2470(void)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  undefined4 uVar2;
  
  iVar1 = *(int *)(in_EAX + 8);
  uVar2 = *(undefined4 *)(in_EAX + 0xc);
  if (*(short *)(in_EAX + 2) != 0) {
    if (*(int *)(in_ECX + 0x7c) == 0) {
      uVar2 = *(undefined4 *)(in_ECX + 0x78);
    }
    else {
      *(undefined4 *)(*(int *)(in_ECX + 0x7c) + 0x78) = *(undefined4 *)(in_ECX + 0x78);
    }
    if (*(int *)(in_ECX + 0x78) != 0) {
      *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x7c) = *(undefined4 *)(in_ECX + 0x7c);
    }
    if (iVar1 == 0) {
      *(int *)(in_ECX + 0x7c) = in_ECX;
      *(int *)(in_ECX + 0x78) = in_ECX;
    }
    else {
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar1 + 0x78);
      *(int *)(iVar1 + 0x78) = in_ECX;
      *(int *)(in_ECX + 0x7c) = iVar1;
      *(int *)(*(int *)(in_ECX + 0x78) + 0x7c) = in_ECX;
    }
    *(short *)(in_EAX + 2) = *(short *)(in_EAX + 2) + -1;
    *(int *)(in_EAX + 8) = in_ECX;
    *(undefined4 *)(in_EAX + 0xc) = uVar2;
    if (*(short *)(in_EAX + 2) == 0) {
      *(undefined4 *)(in_EAX + 0xc) = 0;
      *(undefined4 *)(in_EAX + 0x10) = 0;
    }
  }
  return;
}

