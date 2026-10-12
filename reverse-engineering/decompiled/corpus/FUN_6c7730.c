/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c7730; label: FUN_006c7730
 */

void FUN_006c7730(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  float10 fVar6;
  float local_3c;
  undefined1 local_20 [4];
  float local_1c;
  
  bVar1 = false;
  FUN_006c7480();
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  local_3c = 0.0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar2;
    do {
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      fVar6 = (float10)FUN_006bf350(puVar2 + 4,puVar2 + 0xc,puVar3 + 4,puVar3 + 8);
      for (; local_3c < (float)fVar6; local_3c = local_3c + *(float *)(in_ECX + 0x48)) {
        FUN_006bfaa0(local_20,puVar2 + 4,puVar2 + 0xc,puVar3 + 4,puVar3 + 8,local_3c);
        if (*(int *)(in_ECX + 0x50) != 0) {
          local_1c = local_1c - 10.0;
        }
        local_1c = *(float *)(in_ECX + 0x4c) + local_1c;
        FUN_006c73c0(local_20);
      }
      local_3c = local_3c - (float)fVar6;
      puVar4 = (undefined4 *)*puVar3;
      if (bVar1) {
        return;
      }
      if ((puVar4 == (undefined4 *)0x0) && (*(int *)(in_ECX + 0x54) != 0)) {
        puVar4 = *(undefined4 **)(in_ECX + 0x2c);
        bVar1 = true;
      }
      bVar5 = puVar3 != (undefined4 *)0x0;
      puVar2 = puVar3;
      puVar3 = puVar4;
    } while (bVar5);
  }
  return;
}

