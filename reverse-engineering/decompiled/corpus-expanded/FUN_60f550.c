/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x60f550; label: FUN_0060f550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f550(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar1 = FUN_00617a00();
  if (1000 < (uint)(iVar1 - *(int *)(in_ECX + 0x1c))) {
    iVar1 = *(int *)(in_ECX + 0x18) + 1;
    if (0x1d < iVar1) {
      iVar1 = 0;
    }
    iVar2 = (iVar1 + 4) * 0x10;
    *(undefined4 *)(iVar2 + in_ECX) = *(undefined4 *)(in_ECX + 8);
    piVar3 = (int *)(iVar2 + in_ECX);
    piVar3[1] = *(int *)(in_ECX + 0xc);
    piVar3[2] = *(int *)(in_ECX + 0x10);
    piVar3[3] = *(int *)(in_ECX + 0x14);
    *piVar3 = *piVar3 - *(int *)(in_ECX + 0x30);
    piVar3[1] = piVar3[1] - *(int *)(in_ECX + 0x34);
    piVar3[2] = piVar3[2] - *(int *)(in_ECX + 0x38);
    piVar3[3] = piVar3[3] - *(int *)(in_ECX + 0x3c);
    FUN_0060f500(piVar3);
    *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(in_ECX + 0x14);
    *(int *)(in_ECX + 0x18) = iVar1;
    uVar4 = FUN_00617a00();
    *(undefined4 *)(in_ECX + 0x1c) = uVar4;
  }
  return;
}

