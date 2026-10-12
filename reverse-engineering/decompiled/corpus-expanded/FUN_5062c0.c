/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x5062c0; label: FUN_005062c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005062c0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint in_EAX;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x58);
  uVar1 = *(undefined4 *)(iVar2 + 8);
  *(uint *)(in_ECX + 0x88) = (in_EAX & 1) * 2 | *(uint *)(in_ECX + 0x88) & 0xfffffffd | 0x1001;
  *(undefined4 *)(in_ECX + 0x90) = uVar1;
  *(uint *)(in_ECX + 0x8c) = *(uint *)(in_ECX + 0x8c) & 0xffffffbf | (in_EAX & 1) << 6;
  DAT_009737dd = 1;
  if ((*(uint *)(in_ECX + 0x88) & 0x40000) == 0) {
    iVar2 = *(int *)(iVar2 + 0x14);
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x14);
  }
  if (iVar2 != 0) {
    FUN_00502740();
  }
  if (*(int *)(in_ECX + 0xa8) != 0) {
    FUN_00501760(*(int *)(in_ECX + 0xa8));
  }
  DAT_009737dd = 0;
  if ((*(int *)(in_ECX + 0x9c) != 0) && (-1 < *(char *)(*(int *)(in_ECX + 0x9c) + 9))) {
    DAT_00921359 = 0;
  }
  return;
}

