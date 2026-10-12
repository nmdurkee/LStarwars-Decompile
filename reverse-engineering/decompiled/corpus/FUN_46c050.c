/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c050; label: FUN_0046c050
 */

void FUN_0046c050(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = (int)param_1;
  fVar2 = DAT_00950f60 * 0.1;
  fVar3 = DAT_00950f60 * 2.5;
  fVar5 = (float10)FUN_005bec80((int)param_1 + 0x80);
  fVar1 = (float)fVar5;
  if (fVar3 < fVar1 == (fVar3 == fVar1)) {
    if ((fVar2 < fVar1 == (fVar2 == fVar1)) ||
       (param_1 = (fVar1 - fVar2) / (fVar3 - fVar2), param_1 <= 0.0)) {
      return;
    }
  }
  else {
    param_1 = 1.0;
  }
  FUN_00651470("Gungan_BlueOrbBounce",iVar4 + 0x30,param_1);
  return;
}

