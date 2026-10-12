/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x499ca0; label: FUN_00499ca0
 */

void FUN_00499ca0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar3 = FUN_0055f450();
  *(undefined4 *)(param_1 + 0xc4c) = 0;
  iVar4 = (int)*(char *)(param_1 + 0x671);
  if ((((iVar4 != -1) && (*(int **)(iVar3 + 0x2988) != (int *)0x0)) &&
      (iVar2 = **(int **)(iVar3 + 0x2988), *(float *)(iVar4 * 0x13c + 0x70 + iVar2) != 0.0)) &&
     ((param_2 != 0 || ((DAT_0087b0f8 != 0 && (*(int *)(iVar3 + 0x128) == DAT_0087b0f8)))))) {
    *(undefined4 *)(param_1 + 0xc4c) = *(undefined4 *)(iVar4 * 0x13c + 0x70 + iVar2);
    local_8 = 0;
    local_c = 0;
    if ((*(uint *)(param_1 + 0xef4) & 0x200000) == 0) {
      local_4 = *(float *)(param_1 + 0xc44);
    }
    else {
      local_4 = *(float *)(param_1 + 0xec8);
    }
    local_4 = local_4 * *(float *)(param_1 + 0xc4c);
    puVar1 = (undefined4 *)(param_1 + 0x68);
    if (param_3 == 0) {
      FUN_005b3620(puVar1,puVar1,*(undefined2 *)(param_1 + 0x27a));
    }
    else {
      FUN_005b35a0(puVar1,&local_c,*(undefined2 *)(param_1 + 0x694));
      FUN_005b3620(puVar1,puVar1,*(undefined2 *)(param_1 + 0x696));
    }
    *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xfffbffff;
    *(undefined4 *)(param_1 + 0xf18) = *puVar1;
    *(undefined4 *)(param_1 + 0xf1c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 0xf20) = *(undefined4 *)(param_1 + 0x70);
    return;
  }
  return;
}

