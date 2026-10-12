/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7660; label: FUN_006c7660
 */

void FUN_006c7660(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_006c7480();
  for (puVar1 = *(undefined4 **)(in_ECX + 0x2c); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    local_20 = puVar1[4];
    local_1c = (float)puVar1[5];
    local_18 = puVar1[6];
    local_14 = puVar1[7];
    if (*(int *)(in_ECX + 0x50) != 0) {
      local_1c = local_1c - 10.0;
    }
    local_1c = local_1c + *(float *)(in_ECX + 0x4c);
    FUN_006c73c0(&local_20);
  }
  if ((*(int *)(in_ECX + 0x54) != 0) && (iVar2 = *(int *)(in_ECX + 0x2c), iVar2 != 0)) {
    local_20 = *(undefined4 *)(iVar2 + 0x10);
    local_1c = *(float *)(iVar2 + 0x14);
    local_18 = *(undefined4 *)(iVar2 + 0x18);
    local_14 = *(undefined4 *)(iVar2 + 0x1c);
    if (*(int *)(in_ECX + 0x50) != 0) {
      local_1c = local_1c - 10.0;
    }
    local_1c = *(float *)(in_ECX + 0x4c) + local_1c;
    FUN_006c73c0(&local_20);
  }
  return;
}

