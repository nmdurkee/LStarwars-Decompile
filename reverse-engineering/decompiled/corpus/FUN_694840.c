/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x694840; label: FUN_00694840
 */

void FUN_00694840(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = param_1;
  iVar5 = 0;
  *(int *)(in_ECX + 0x1dc) = *param_1;
  param_1 = (int *)0x0;
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    iVar6 = 0;
    do {
      puVar1 = (undefined4 *)(iVar6 + *(int *)(in_ECX + 8));
      uVar3 = FUN_006947c0(*(undefined4 *)(in_ECX + 0x1dc),&param_1,*puVar1,
                           (int)(puVar1[0xe] << 0x1e) >> 0x1f,
                           *(undefined4 *)(iVar6 + 0x28 + *(int *)(in_ECX + 8)));
      *(undefined4 *)(iVar6 + 0xc + *(int *)(in_ECX + 8)) = uVar3;
      iVar4 = *(int *)(in_ECX + 8);
      uVar3 = FUN_006947c0(*(undefined4 *)(in_ECX + 0x1dc),&param_1,
                           *(undefined4 *)(iVar4 + iVar6 + 4),
                           (*(int *)(iVar4 + 0x38 + iVar6) << 0x1e) >> 0x1f,
                           *(undefined4 *)(iVar4 + 0x28 + iVar6));
      *(undefined4 *)(iVar6 + 0x10 + *(int *)(in_ECX + 8)) = uVar3;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x3c;
      iVar4 = (int)param_1;
    } while (iVar5 < *(int *)(in_ECX + 0xc));
  }
  iVar5 = iVar4 * 0x1c;
  *(undefined4 *)(iVar5 + *(int *)(in_ECX + 0x1dc)) = 0;
  *(undefined4 *)(iVar5 + 4 + *(int *)(in_ECX + 0x1dc)) = 0;
  *(undefined4 *)(iVar5 + 8 + *(int *)(in_ECX + 0x1dc)) = 0;
  *(undefined4 *)(iVar5 + 0xc + *(int *)(in_ECX + 0x1dc)) = 0xffffffff;
  *piVar2 = *(int *)(in_ECX + 0x1dc) + (iVar4 + 1) * 0x1c;
  return;
}

