/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65d540; label: FUN_0065d540
 */

void FUN_0065d540(float param_1)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if ((DAT_02947c14 == -1) ||
     (FUN_005b3800(&local_c,&DAT_02924abc,&DAT_02947d9c + DAT_02947c14 * 0x44),
     local_4 * local_4 + local_c * local_c + local_8 * local_8 != 0.0)) {
    DAT_02947c14 = -1;
    iVar3 = 0;
    puVar2 = &DAT_02947d9c;
    do {
      if (*(int *)(puVar2 + -4) != -1) {
        FUN_005b3800(&local_c,&DAT_02924abc,puVar2);
        fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
        if ((param_1 < 0.0) || (fVar1 < param_1)) {
          DAT_02947c14 = iVar3;
          param_1 = fVar1;
        }
      }
      puVar2 = puVar2 + 0x44;
      iVar3 = iVar3 + 1;
    } while ((int)puVar2 < 0x2948e9c);
  }
  return;
}

