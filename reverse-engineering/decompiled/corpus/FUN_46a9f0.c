/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46a9f0; label: FUN_0046a9f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046a9f0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  float **ppfVar3;
  float10 fVar4;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float *local_50 [6];
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_2a;
  int local_28;
  
  local_5c = _DAT_007fc31c;
  if (in_EAX == 0) {
    local_5c = -_DAT_007fc31c;
  }
  fVar4 = (float10)FUN_004b7120();
  local_58 = (float)(fVar4 + (float10)_DAT_007fc310);
  puVar2 = &DAT_00802cd8;
  ppfVar3 = local_50;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppfVar3 = (float *)*puVar2;
    puVar2 = puVar2 + 1;
    ppfVar3 = ppfVar3 + 1;
  }
  local_54 = 0x3f800000;
  local_2a = 0x35;
  local_50[3] = (float *)0x3f19999a;
  local_28 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x350;
  local_50[1] = &local_5c;
  local_50[4] = (float *)0x0;
  local_34 = 0x3e99999a;
  local_38 = 0x20;
  FUN_00560b60(local_50);
  return;
}

