/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8da0; label: FUN_005e8da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8da0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = param_1;
  iVar4 = param_1 - in_ECX;
  param_1 = 2;
  iVar2 = in_ECX;
  do {
    FUN_005c8a00(iVar4 + iVar2);
    iVar2 = iVar2 + 0x380;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  *(undefined4 *)(in_ECX + 0x700) = *(undefined4 *)(iVar1 + 0x700);
  *(undefined4 *)(in_ECX + 0x704) = *(undefined4 *)(iVar1 + 0x704);
  *(undefined4 *)(in_ECX + 0x708) = *(undefined4 *)(iVar1 + 0x708);
  *(undefined4 *)(in_ECX + 0x70c) = *(undefined4 *)(iVar1 + 0x70c);
  *(undefined4 *)(in_ECX + 0x710) = *(undefined4 *)(iVar1 + 0x710);
  *(undefined4 *)(in_ECX + 0x720) = *(undefined4 *)(iVar1 + 0x720);
  *(undefined4 *)(in_ECX + 0x724) = *(undefined4 *)(iVar1 + 0x724);
  *(undefined4 *)(in_ECX + 0x728) = *(undefined4 *)(iVar1 + 0x728);
  *(undefined4 *)(in_ECX + 0x72c) = *(undefined4 *)(iVar1 + 0x72c);
  *(undefined4 *)(in_ECX + 0x730) = *(undefined4 *)(iVar1 + 0x730);
  *(undefined4 *)(in_ECX + 0x734) = *(undefined4 *)(iVar1 + 0x734);
  *(undefined4 *)(in_ECX + 0x738) = *(undefined4 *)(iVar1 + 0x738);
  *(undefined4 *)(in_ECX + 0x73c) = *(undefined4 *)(iVar1 + 0x73c);
  *(undefined4 *)(in_ECX + 0x740) = *(undefined4 *)(iVar1 + 0x740);
  *(undefined4 *)(in_ECX + 0x744) = *(undefined4 *)(iVar1 + 0x744);
  *(undefined4 *)(in_ECX + 0x748) = *(undefined4 *)(iVar1 + 0x748);
  *(undefined4 *)(in_ECX + 0x74c) = *(undefined4 *)(iVar1 + 0x74c);
  *(undefined4 *)(in_ECX + 0x750) = *(undefined4 *)(iVar1 + 0x750);
  *(undefined4 *)(in_ECX + 0x754) = *(undefined4 *)(iVar1 + 0x754);
  *(undefined4 *)(in_ECX + 0x758) = *(undefined4 *)(iVar1 + 0x758);
  *(undefined4 *)(in_ECX + 0x75c) = *(undefined4 *)(iVar1 + 0x75c);
  *(undefined4 *)(in_ECX + 0x760) = *(undefined4 *)(iVar1 + 0x760);
  *(undefined4 *)(in_ECX + 0x764) = *(undefined4 *)(iVar1 + 0x764);
  *(undefined4 *)(in_ECX + 0x768) = *(undefined4 *)(iVar1 + 0x768);
  *(undefined4 *)(in_ECX + 0x76c) = *(undefined4 *)(iVar1 + 0x76c);
  *(undefined4 *)(in_ECX + 0x770) = *(undefined4 *)(iVar1 + 0x770);
  *(undefined4 *)(in_ECX + 0x774) = *(undefined4 *)(iVar1 + 0x774);
  *(undefined4 *)(in_ECX + 0x778) = *(undefined4 *)(iVar1 + 0x778);
  *(undefined4 *)(in_ECX + 0x77c) = *(undefined4 *)(iVar1 + 0x77c);
  puVar3 = (undefined4 *)(iVar1 + 0x780);
  puVar5 = (undefined4 *)(in_ECX + 0x780);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar3 = (undefined4 *)(iVar1 + 0x7c0);
  puVar5 = (undefined4 *)(in_ECX + 0x7c0);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(in_ECX + 0x800) = *(undefined4 *)(iVar1 + 0x800);
  *(undefined4 *)(in_ECX + 0x804) = *(undefined4 *)(iVar1 + 0x804);
  *(undefined4 *)(in_ECX + 0x808) = *(undefined4 *)(iVar1 + 0x808);
  *(undefined4 *)(in_ECX + 0x80c) = *(undefined4 *)(iVar1 + 0x80c);
  *(undefined4 *)(in_ECX + 0x810) = *(undefined4 *)(iVar1 + 0x810);
  *(undefined4 *)(in_ECX + 0x814) = *(undefined4 *)(iVar1 + 0x814);
  *(undefined4 *)(in_ECX + 0x818) = *(undefined4 *)(iVar1 + 0x818);
  *(undefined4 *)(in_ECX + 0x81c) = *(undefined4 *)(iVar1 + 0x81c);
  *(undefined4 *)(in_ECX + 0x820) = *(undefined4 *)(iVar1 + 0x820);
  *(undefined4 *)(in_ECX + 0x824) = *(undefined4 *)(iVar1 + 0x824);
  return;
}

