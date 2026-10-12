/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420220; label: FUN_00420220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420220(undefined4 *param_1)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  
  piVar4 = (int *)param_1[2];
  *(undefined4 *)(in_ECX + 0x74) = param_1[1];
  *(undefined4 *)(in_ECX + 0xec0) = param_1[3];
  *(undefined1 *)(in_ECX + 10) = 1;
  *(undefined4 *)(in_ECX + 0xa0) = *param_1;
  FUN_006d6740(param_1[4]);
  uVar5 = FUN_005e4e80(2);
  iVar6 = FUN_005e4d00(1);
  *(int *)(in_ECX + 0xebc) = iVar6;
  *(uint *)(iVar6 + 0x40) = *(uint *)(iVar6 + 0x40) & 0xfffffff1 | 1;
  *(uint *)(*(int *)(in_ECX + 0xebc) + 0x40) =
       *(uint *)(*(int *)(in_ECX + 0xebc) + 0x40) & 0xffffefff | 0x2000;
  puVar1 = (uint *)(*(int *)(in_ECX + 0xebc) + 0x40);
  *puVar1 = *puVar1 | 0xc000;
  FUN_005e4b00(*(undefined4 *)(in_ECX + 0xebc));
  FUN_005e4e80(uVar5);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  iVar6 = *piVar4;
  while (iVar6 != 0) {
    *(int *)(in_ECX + 0xac + *(int *)(in_ECX + 0x1c) * 0xc) = iVar6;
    iVar7 = 0;
    cVar3 = *(char *)(iVar6 + 2);
    iVar2 = iVar6;
    while (cVar3 != -1) {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(iVar2 + 4) = 0;
      iVar2 = iVar6 + iVar7 * 8;
      cVar3 = *(char *)(iVar6 + 2 + iVar7 * 8);
    }
    *(int *)(in_ECX + 0xa4 + *(int *)(in_ECX + 0x1c) * 0xc) = iVar7;
    *(undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x1c) + 0xe) * 0xc) = 0;
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
    iVar6 = piVar4[*(int *)(in_ECX + 0x1c)];
  }
  return;
}

