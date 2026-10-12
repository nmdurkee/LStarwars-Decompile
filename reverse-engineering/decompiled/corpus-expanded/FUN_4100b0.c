/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x4100b0; label: FUN_004100b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004100b0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  int in_EDX;
  int iVar3;
  
  iVar3 = 0;
  if (3 < in_EDX) {
    iVar2 = (in_EDX - 4U >> 2) + 1;
    iVar3 = iVar2 * 4;
    do {
      *(undefined4 *)(in_EAX + 0x404) = *(undefined4 *)(in_EAX + 0x408);
      *(undefined4 *)(in_EAX + 0x518) = *(undefined4 *)(in_EAX + 0x514);
      *(undefined4 *)(in_EAX + 0x934) = *(undefined4 *)(in_EAX + 0x938);
      *(undefined4 *)(in_EAX + 0xa48) = *(undefined4 *)(in_EAX + 0xa44);
      *(undefined4 *)(in_EAX + 0xe64) = *(undefined4 *)(in_EAX + 0xe68);
      *(undefined4 *)(in_EAX + 0xf78) = *(undefined4 *)(in_EAX + 0xf74);
      *(undefined4 *)(in_EAX + 0x1394) = *(undefined4 *)(in_EAX + 0x1398);
      *(undefined4 *)(in_EAX + 0x14a8) = *(undefined4 *)(in_EAX + 0x14a4);
      in_EAX = in_EAX + 0x14c0;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (iVar3 < in_EDX) {
    puVar1 = (undefined4 *)(in_EAX + 0x404);
    iVar3 = in_EDX - iVar3;
    do {
      *puVar1 = puVar1[1];
      puVar1[0x45] = puVar1[0x44];
      puVar1 = puVar1 + 0x14c;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

